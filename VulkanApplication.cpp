//
// Created by siddharth on 1/10/17.
//

#include "VulkanApplication.h"

#ifndef GLFW_IMPLEMENTATION
#define GLFW_IMPLEMENTATION
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#endif

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/hash.hpp>
#include <glm/ext.hpp>


#include <fstream>
#include <set>
#include <chrono>
#include <cstring>

VulkanApplication::VulkanApplication() {
}

VulkanApplication::VulkanApplication(int width, int height, glm::mat4 *cameraTransformPointer, GLFWwindow **inUserWindow, void *inApp, void (*loop)(float, void *inApp), void (*window)(void *app)) {
  WIDTH = width;
  HEIGHT = height;
  userLoop = loop;
  windowSetup = window;
  cameraTransform = cameraTransformPointer;
  userWindow = inUserWindow;
  app = inApp;
}


void VulkanApplication::run(std::vector<Mesh*> inMeshes, std::vector<Texture*> inTextures) {
  inputMeshes = inMeshes;
  inputTextures = inTextures;
  initWindow();
  initVulkan();
}

void VulkanApplication::startMainLoop() {
  mainLoop();
}

/*
 * Initializes the glfwWindow and sets up the cursor
 */
void VulkanApplication::initWindow() {
  glfwInit();

  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

  window = glfwCreateWindow(WIDTH, HEIGHT, "Siddharth's Rendering Engine", nullptr, nullptr);
  *userWindow = window;


  //glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

  standardCursor = glfwCreateStandardCursor(GLFW_ARROW_CURSOR);

  glfwSetCursor(window, standardCursor);
  windowSetup(app);
}

/*
 * Recreates the swapchain whenever the window is resized. Allows the display to be resizeable
 */
void VulkanApplication::onWindowResized(GLFWwindow *window, int width, int height, VulkanApplication *app) {
  if (width == 0 || height == 0) return;
  app->recreateSwapChain();
}


void VulkanApplication::initVulkan() {
#ifdef ENUMERATE_EXTENSIONS
  enumerateExtensions();
#endif //ENUMERATE_EXTENSIONS
  createInstance();
  setupDebugCallback();
  createSurface();
  pickPhysicalDevice();
  createLogicalDevice();
  loadModels();
  createSwapChain();
  createImageViews();
  createRenderPass();
  createDescriptorSetLayout();
  createGraphicsPipeline();
  createCommandPool();
  createDepthResources();
  createFramebuffers();
  createTextureImage(); //Create per texture
  createTextureImageView(); //Create per texture
  createTextureSampler(); //Create per texture
  createVertexBuffer(); //Create per object
  createIndexBuffer(); //Create per object
  createUniformBuffer(); //Create per object
  createDescriptorPool();
  createDescriptorSet(); //Create per object
  createCommandBuffers();
  createSemaphores();
}

void VulkanApplication::mainLoop() {
  while (!glfwWindowShouldClose(window)) {
    //Update the input events
    glfwPollEvents();

    //Get the current system time
    long currentTime = std::chrono::duration_cast< std::chrono::milliseconds > (
        std::chrono::system_clock::now().time_since_epoch()
    ).count();

    //Calculate a change in time so that movement speed is independent of framerate
    long deltaTime = currentTime - lastTime;
    float deltaSeconds = deltaTime / 1000.0f;

    if (deltaSeconds > 2.0f) deltaSeconds = 0.0f;
    if (deltaSeconds < 0.0f) deltaSeconds = 0.0f;

    //The user loop is called to let the user update the transforms of meshes
    (*userLoop)(deltaSeconds, app);
    //Copies the user changes of the object transforms to GPU memory
    updateUniformBuffer();
    //Runs the previously recorded command buffers to draw the updated frame
    drawFrame();
    lastTime = currentTime;
  }
  vkDeviceWaitIdle(device);
}

/*
 * Used for debugging to list the extensions available on the system
 */
#ifdef ENUMERATE_EXTENSIONS
void VulkanApplication::enumerateExtensions() {
        uint32_t extensionCount = 0;
        vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
        std::vector<VkExtensionProperties> extensions(extensionCount);
        vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());

        std::cout << "available extensions:" << std::endl;

        for (const auto& extension : extensions) {
            std::cout << "\t" << extension.extensionName << std::endl;
        }
    }
#endif //ENUMERATE_EXTENSIONS

/*
 * Gets the required extensions from the OS to display the Vulkan output
 */
std::vector<const char*> VulkanApplication::getRequiredExtensions() {
	std::vector<const char*> extensions;

	unsigned int glfwExtensionCount = 0;
	const char** glfwExtensions;
	glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

	for (unsigned int i = 0; i < glfwExtensionCount; i++) {
		extensions.push_back(glfwExtensions[i]);
	}

	if (enableValidationLayers) {
		extensions.push_back(VK_EXT_DEBUG_REPORT_EXTENSION_NAME);
	}

	return extensions;
}

/*
 * Make sure all of the requested validation layers are actually available on the system. Only used for debugging
 */
bool VulkanApplication::checkValidationLayerSupport() {
  uint32_t layerCount;
  vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

  std::vector<VkLayerProperties> availableLayers(layerCount);
  vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

  for (const char* layerName : validationLayers) {
    bool layerFound = false;

    for (const auto& layerProperties : availableLayers) {
      if (strcmp(layerName, layerProperties.layerName) == 0) {
        layerFound = true;
      }
    }

    if (!layerFound) {
      return false;
    }
  }
  return true;
}

/*
 * Creates the VkInstance, the main vulkan instance. It requires data from structures VkApplicationInfo and VkInstanceCreateInfo, using the passed application name and version. It also loads any vulkan extensions the user needs, which are required for vulkan to interface with different operating systems. If desired, validation layers can also be loaded, which facillitate the reporting of errors within Vulkan.
 */
void VulkanApplication::createInstance() {
  if (enableValidationLayers && !checkValidationLayerSupport()) {
    printf("Checking if validation layers are available");
    throw std::runtime_error("validation layers requested, but not available!");
  }

  VkApplicationInfo appInfo = {};
  appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
  appInfo.pNext = NULL;
  appInfo.pApplicationName = "Hello Triangle";
  appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
  appInfo.pEngineName = "No Engine";
  appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
  appInfo.apiVersion = VK_API_VERSION_1_0;

  VkInstanceCreateInfo createInfo = {};
  createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
  createInfo.pNext = NULL;
  createInfo.flags = 0;
  createInfo.pApplicationInfo = &appInfo;

  if (enableValidationLayers) {
    createInfo.enabledLayerCount = validationLayers.size();
    createInfo.ppEnabledLayerNames = validationLayers.data();
  } else {
    createInfo.enabledLayerCount = 0;
    createInfo.ppEnabledLayerNames = NULL;
  }


  auto extensions = getRequiredExtensions();
  createInfo.enabledExtensionCount = extensions.size();
  createInfo.ppEnabledExtensionNames = extensions.data();


  if (vkCreateInstance(&createInfo, nullptr, instance.replace()) != VK_SUCCESS) {
    throw std::runtime_error("failed to create instance!");
  }

}

/*
 * Creates a window surface that the final rendered image is loaded to.
 */
void VulkanApplication::createSurface() {
  if (glfwCreateWindowSurface(instance, window, nullptr, surface.replace()) != VK_SUCCESS) {
    throw std::runtime_error("Failed to create window surface\n");
  }
}

/*
 * Only called if validation layers are requested. Sets up a callback that is called whenever debug information needs to be reported by a validation layer.
 */
void VulkanApplication::setupDebugCallback() {
  if (!enableValidationLayers) return;

  VkDebugReportCallbackCreateInfoEXT createInfo = {};
  createInfo.sType = VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT;
  createInfo.flags = VK_DEBUG_REPORT_ERROR_BIT_EXT | VK_DEBUG_REPORT_WARNING_BIT_EXT;
  createInfo.pfnCallback = debugCallback;

  if (CreateDebugReportCallbackEXT(instance, &createInfo, nullptr, callback.replace())
      != VK_SUCCESS) {
    throw std::runtime_error("Failed to setup debug callback");
  }
}

/*
 * Many desktop systems have more than one physical device. This function picks the first device that has support for the requested extensions. It also makes sure that the device has the correct types of queues in order to be able to recieve all the data we want to send.
 */
void VulkanApplication::pickPhysicalDevice() {
  uint32_t deviceCount = 0;
  vkEnumeratePhysicalDevices(instance, &deviceCount, nullptr);
  if (deviceCount == 0) {
    throw std::runtime_error("Failed to find GPUs with Vulkan support.");
  }
  std::vector<VkPhysicalDevice> devices(deviceCount);
  vkEnumeratePhysicalDevices(instance, &deviceCount, devices.data());

  for (const auto &device : devices) {
    if (isDeviceSuitable(device)) {
      physicalDevice = device;
      break;
    }
  }
}

/*
 * Makes sure the passed device has the proper support for rendering the final frames on the swapchain
 */
SwapChainSupportDetails VulkanApplication::querySwapChainSupport(VkPhysicalDevice device) {
  SwapChainSupportDetails details;

  vkGetPhysicalDeviceSurfaceCapabilitiesKHR(device, surface,
                                            &details.capabilities);

  uint32_t formatCount;
  vkGetPhysicalDeviceSurfaceFormatsKHR(device, surface, &formatCount, nullptr);

  if (formatCount != 0) {
    details.formats.resize(formatCount);
    vkGetPhysicalDeviceSurfaceFormatsKHR(device, surface, &formatCount,
                                         details.formats.data());
  }

  uint32_t presentModeCount;
  vkGetPhysicalDeviceSurfacePresentModesKHR(device, surface, &presentModeCount,
                                            nullptr);

  if (presentModeCount != 0) {
    details.presentModes.resize(presentModeCount);
    vkGetPhysicalDeviceSurfacePresentModesKHR(device, surface,
                                              &presentModeCount, details.presentModes.data());
  }
  return details;
}

/*
 * Checks if the device supports everything we need it to, i.e. swapchain, extensions, validation layers (if debugging)
 */
bool VulkanApplication::isDeviceSuitable(VkPhysicalDevice device) {
  QueueFamilyIndices indices = findQueueFamilies(device);


  bool extensionsSupported = checkDeviceExtensionSupport(device);

  bool swapChainAdequate = false;
  if (extensionsSupported) {
    SwapChainSupportDetails swapChainSupport = querySwapChainSupport(device);
    swapChainAdequate = !swapChainSupport.formats.empty() &&
        !swapChainSupport.presentModes.empty();
  }

  return indices.isComplete() && extensionsSupported && swapChainAdequate;
}

/*
 * Finds the queues that the physical device we are using supports. Queues are used to submit the commands we want to run on the GPU through command buffers
 */
QueueFamilyIndices VulkanApplication::findQueueFamilies(VkPhysicalDevice device) {
  QueueFamilyIndices indices;

  uint32_t queueFamilyCount = 0;
  vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, nullptr);

  std::vector<VkQueueFamilyProperties> queueFamilies(queueFamilyCount);
  vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, queueFamilies.data());

  int i = 0;
  for (const auto &queueFamily : queueFamilies) {
    if (queueFamily.queueCount > 0 && queueFamily.queueFlags & VK_QUEUE_GRAPHICS_BIT) {
      indices.graphicsFamily = i;
    }

    VkBool32 presentSupport = false;
    vkGetPhysicalDeviceSurfaceSupportKHR(device, i, surface, &presentSupport);

    if (queueFamily.queueCount > 0 && presentSupport) {
      indices.presentFamily = i;
    }

    if (indices.isComplete()) {
      break;
    }

    i++;

  }

  return indices;
}

/*
 * Makes sure that the requested extensions are supported
 */
bool VulkanApplication::checkDeviceExtensionSupport(VkPhysicalDevice device) {
  uint32_t extensionCount;
  vkEnumerateDeviceExtensionProperties(device, nullptr, &extensionCount,
                                       nullptr);
  std::vector<VkExtensionProperties> availableExtensions(extensionCount);
  vkEnumerateDeviceExtensionProperties(device, nullptr, &extensionCount,
                                       availableExtensions.data());

  std::set<std::string> requiredExtensions(deviceExtensions.begin(),
                                           deviceExtensions.end());

  for (const auto &extension : availableExtensions) {
    requiredExtensions.erase(extension.extensionName);
  }
  return requiredExtensions.empty();
}

/*
 * Logical devices are allocated to physical devices. Creation requires a description of the features being used, and enumeration of the queues that this logical device will be using.
 */
void VulkanApplication::createLogicalDevice() {
  QueueFamilyIndices indices = findQueueFamilies(physicalDevice);

  std::vector<VkDeviceQueueCreateInfo> queueCreateInfos;
  std::set<int> uniqueQueueFamilies = {indices.graphicsFamily, indices.presentFamily};


  float queuePriority = 1.0f;
  for (int queueFamily : uniqueQueueFamilies) {
    VkDeviceQueueCreateInfo queueCreateInfo = {};
    queueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
    queueCreateInfo.queueFamilyIndex = queueFamily;
    queueCreateInfo.queueCount = 1;
    queueCreateInfo.pQueuePriorities = &queuePriority;
    queueCreateInfos.push_back(queueCreateInfo);
  }

  VkPhysicalDeviceFeatures deviceFeatures = {};

  VkDeviceCreateInfo createInfo = {};
  createInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;

  createInfo.pQueueCreateInfos = queueCreateInfos.data();
  createInfo.queueCreateInfoCount = (uint32_t)queueCreateInfos.size();
  createInfo.pEnabledFeatures = &deviceFeatures;

  createInfo.enabledExtensionCount = deviceExtensions.size();
  createInfo.ppEnabledExtensionNames = deviceExtensions.data();

  if (enableValidationLayers) {
    createInfo.enabledLayerCount = validationLayers.size();
    createInfo.ppEnabledLayerNames = validationLayers.data();
  } else {
    createInfo.enabledLayerCount = 0;
  }

  if (vkCreateDevice(physicalDevice, &createInfo, nullptr, device.replace()) != VK_SUCCESS) {
    throw std::runtime_error("Failed to create logical device");
  }

  vkGetDeviceQueue(device, indices.graphicsFamily, 0, &graphicsQueue);
  vkGetDeviceQueue(device, indices.presentFamily, 0, &presentQueue);

}


/*
 * Creates the swapChain. The swapchain is an extension that allows the program to present images to the screen. This is done through a swapping procedure; when the next image is ready in memory it will swap it with the current image on the screen. It also can query information about the swapchain.
 */
void VulkanApplication::createSwapChain() {
  SwapChainSupportDetails swapChainSupport =
      querySwapChainSupport(physicalDevice);

  VkSurfaceFormatKHR surfaceFormat =
      chooseSwapSurfaceFormat(swapChainSupport.formats);
  VkPresentModeKHR presentMode =
      chooseSwapPresentMode(swapChainSupport.presentModes);
  VkExtent2D extent = chooseSwapExtent(swapChainSupport.capabilities);

  uint32_t imageCount = swapChainSupport.capabilities.minImageCount + 1;
  if (swapChainSupport.capabilities.maxImageCount > 0 && imageCount >
      swapChainSupport.capabilities.maxImageCount) {
    imageCount = swapChainSupport.capabilities.maxImageCount;
  }

  VkSwapchainCreateInfoKHR createInfo = {};
  createInfo.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
  createInfo.surface = surface;
  createInfo.minImageCount = imageCount;
  createInfo.imageFormat = surfaceFormat.format;
  createInfo.imageColorSpace = surfaceFormat.colorSpace;
  createInfo.imageExtent = extent;
  createInfo.imageArrayLayers = 1;
  createInfo.imageUsage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;

  QueueFamilyIndices indices = findQueueFamilies(physicalDevice);
  uint32_t queueFamilyIndices[] = {(uint32_t)indices.graphicsFamily,
                                   (uint32_t)indices.presentFamily};

  if (indices.graphicsFamily != indices.presentFamily) {
    createInfo.imageSharingMode = VK_SHARING_MODE_CONCURRENT;
    createInfo.queueFamilyIndexCount = 2;
    createInfo.pQueueFamilyIndices = queueFamilyIndices;
  } else {
    createInfo.imageSharingMode = VK_SHARING_MODE_EXCLUSIVE;
    createInfo.queueFamilyIndexCount = 0;
    createInfo.pQueueFamilyIndices = nullptr;
  }

  createInfo.preTransform = swapChainSupport.capabilities.currentTransform;
  createInfo.compositeAlpha = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;
  createInfo.presentMode = presentMode;
  createInfo.clipped = VK_TRUE;

  VkSwapchainKHR oldSwapChain = swapChain;
  createInfo.oldSwapchain = oldSwapChain;

  VkSwapchainKHR newSwapChain;
  if (vkCreateSwapchainKHR(device, &createInfo, nullptr, &newSwapChain)
      != VK_SUCCESS) {
    throw std::runtime_error("Failed to create swap chain");
  }

  swapChain = newSwapChain;

  vkGetSwapchainImagesKHR(device, swapChain, &imageCount, nullptr);
  swapChainImages.resize(imageCount);
  vkGetSwapchainImagesKHR(device, swapChain, &imageCount,
                          swapChainImages.data());

  swapChainImageFormat = surfaceFormat.format;
  swapChainExtent = extent;

}

void VulkanApplication::createImageViews() {
  swapChainImageViews.resize(swapChainImages.size(), VDeleter<VkImageView>
      {device, vkDestroyImageView});

  for (uint32_t i = 0; i < swapChainImages.size(); i++) {
    createImageView(swapChainImages[i], swapChainImageFormat,
                    VK_IMAGE_ASPECT_COLOR_BIT, swapChainImageViews[i]);
  }
}

/*
 * The image view defines how to access an image and what parts of it to access. It has the same size as the number of images supported by the swapchain. It can also be used to manipulate color channels.
 */
void VulkanApplication::createImageView(VkImage image, VkFormat format, VkImageAspectFlags
aspectFlags, VDeleter<VkImageView> &imageView) {
  VkImageViewCreateInfo viewInfo = {};
  viewInfo.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
  viewInfo.image = image;
  viewInfo.viewType = VK_IMAGE_VIEW_TYPE_2D;
  viewInfo.format = format;
  viewInfo.components.r = VK_COMPONENT_SWIZZLE_IDENTITY;
  viewInfo.components.g = VK_COMPONENT_SWIZZLE_IDENTITY;
  viewInfo.components.b = VK_COMPONENT_SWIZZLE_IDENTITY;
  viewInfo.components.a = VK_COMPONENT_SWIZZLE_IDENTITY;
  viewInfo.subresourceRange.aspectMask = aspectFlags;
  viewInfo.subresourceRange.baseMipLevel = 0;
  viewInfo.subresourceRange.levelCount = 1;
  viewInfo.subresourceRange.baseArrayLayer = 0;
  viewInfo.subresourceRange.layerCount = 1;

  if (vkCreateImageView(device, &viewInfo, nullptr, imageView.replace())
      != VK_SUCCESS) {
    throw std::runtime_error("Failed to create texture image view");
  }
}

/*
 * The render pass object is used to tell Vulkan about the color and depth buffers and how to handle their contents. There are more efficent ways to store data based on if they are going to be rendered, copied to another memory location, or to be used to read from for other operations.
 *
 * Render passes consist of subpasses. Each can be used to apply affects on the previous. We define a color subpass and depth subpass that are used to store the color information, and depth information of each pixel.
 */
void VulkanApplication::createRenderPass() {
  //Describes the color rendering of the scene
  VkAttachmentDescription colorAttachment = {};
  colorAttachment.format = swapChainImageFormat;
  colorAttachment.samples = VK_SAMPLE_COUNT_1_BIT;
  colorAttachment.loadOp = VK_ATTACHMENT_LOAD_OP_CLEAR;
  colorAttachment.storeOp = VK_ATTACHMENT_STORE_OP_STORE;
  colorAttachment.stencilLoadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
  colorAttachment.stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
  colorAttachment.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
  colorAttachment.finalLayout = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;

  //Describes the depth rendering of the scene
  VkAttachmentDescription depthAttachment = {};
  depthAttachment.format = findDepthFormat();
  depthAttachment.samples = VK_SAMPLE_COUNT_1_BIT;
  depthAttachment.loadOp = VK_ATTACHMENT_LOAD_OP_CLEAR;
  depthAttachment.storeOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
  depthAttachment.stencilLoadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
  depthAttachment.stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
  depthAttachment.initialLayout =
      VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL;
  depthAttachment.finalLayout = VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL;


  VkAttachmentReference colorAttachmentRef = {};
  colorAttachmentRef.attachment = 0;
  colorAttachmentRef.layout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;

  VkAttachmentReference depthAttachmentRef = {};
  depthAttachmentRef.attachment = 1;
  depthAttachmentRef.layout = VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL;

  VkSubpassDescription subPass = {};
  subPass.pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;
  subPass.colorAttachmentCount = 1;
  subPass.pColorAttachments = &colorAttachmentRef;
  subPass.pDepthStencilAttachment = &depthAttachmentRef;

  VkSubpassDependency dependency = {};
  dependency.srcSubpass = VK_SUBPASS_EXTERNAL;
  dependency.dstSubpass = 0;
  dependency.srcStageMask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
  dependency.srcAccessMask = 0;
  dependency.dstStageMask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
  dependency.dstAccessMask = VK_ACCESS_COLOR_ATTACHMENT_READ_BIT |
      VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;

  std::array<VkAttachmentDescription, 2> attachments = {colorAttachment,
                                                        depthAttachment};
  VkRenderPassCreateInfo renderPassInfo = {};
  renderPassInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO;
  renderPassInfo.attachmentCount = attachments.size();
  renderPassInfo.pAttachments = attachments.data();
  renderPassInfo.subpassCount = 1;
  renderPassInfo.pSubpasses = &subPass;
  renderPassInfo.dependencyCount = 1;
  renderPassInfo.pDependencies = &dependency;

  if (vkCreateRenderPass(device, &renderPassInfo, nullptr, renderPass.replace())
      != VK_SUCCESS) {
    throw std::runtime_error("Failed to create render pass");
  }

}

/*
 * Resource descriptors are ways for shaders to access resources like buffers and matricies. Usage requires the
 * 1. specification of a desciptor layout, which specifies resources,
 * 2. allocation of a descriptor set, the actual buffer, from a descriptor layout,
 * 3. binding of the desciptor set during rendering.
 *
 * We currently have two descriptor sets, one for the transform, and one for the texture data being loaded.
 */

void VulkanApplication::createDescriptorSetLayout() {
  //Binding for the ubo, or uniform buffer object that defines transform
  VkDescriptorSetLayoutBinding uboLayoutBinding = {};
  uboLayoutBinding.binding = 0;
  uboLayoutBinding.descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
  uboLayoutBinding.descriptorCount = 1;
  uboLayoutBinding.stageFlags = VK_SHADER_STAGE_VERTEX_BIT;
  uboLayoutBinding.pImmutableSamplers = nullptr;

  //Binding for the sampler that is used to access colors on the image
  VkDescriptorSetLayoutBinding samplerLayoutBinding = {};
  samplerLayoutBinding.binding = 1;
  samplerLayoutBinding.descriptorType =
      VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
  samplerLayoutBinding.descriptorCount = 1;
  samplerLayoutBinding.stageFlags = VK_SHADER_STAGE_FRAGMENT_BIT;
  samplerLayoutBinding.pImmutableSamplers = nullptr;

  std::array<VkDescriptorSetLayoutBinding, 2> bindings = {uboLayoutBinding,
                                                          samplerLayoutBinding};
  VkDescriptorSetLayoutCreateInfo layoutInfo = {};
  layoutInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;
  layoutInfo.bindingCount = bindings.size();
  layoutInfo.pBindings = bindings.data();

  if (vkCreateDescriptorSetLayout(device, &layoutInfo, nullptr,
                                  descriptorSetLayout.replace()) != VK_SUCCESS) {
    throw std::runtime_error("Failed to create descriptor set layout");
  }
}

/*
 * Loads the vertex and fragment shaders.
 * Also allows for the definition of many features such as color blending, rasterizing, and depth control.
 */
void VulkanApplication::createGraphicsPipeline() {
  auto vertShaderCode = readFile("shaders/vert.spv");
  auto fragShaderCode = readFile("shaders/frag.spv");

  VDeleter<VkShaderModule> vertShaderModule{device, vkDestroyShaderModule};
  VDeleter<VkShaderModule> fragShaderModule{device, vkDestroyShaderModule};

  createShaderModule(vertShaderCode, vertShaderModule);
  createShaderModule(fragShaderCode, fragShaderModule);

  VkPipelineShaderStageCreateInfo vertShaderStageInfo = {};
  vertShaderStageInfo.sType =
      VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
  vertShaderStageInfo.stage = VK_SHADER_STAGE_VERTEX_BIT;
  vertShaderStageInfo.module = vertShaderModule;
  vertShaderStageInfo.pName = "main";

  VkPipelineShaderStageCreateInfo fragShaderStageInfo = {};
  fragShaderStageInfo.sType =
      VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
  fragShaderStageInfo.stage = VK_SHADER_STAGE_FRAGMENT_BIT;
  fragShaderStageInfo.module = fragShaderModule;
  fragShaderStageInfo.pName = "main";

  VkPipelineShaderStageCreateInfo shaderStages[] = {vertShaderStageInfo,
                                                    fragShaderStageInfo};

  auto bindingDescription = Vertex::getBindingDescription();
  auto attributeDescriptions = Vertex::getAttributeDescriptions();

  VkPipelineVertexInputStateCreateInfo vertexInputInfo = {};
  vertexInputInfo.sType =
      VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO;
  vertexInputInfo.vertexBindingDescriptionCount = 1;
  vertexInputInfo.pVertexBindingDescriptions = &bindingDescription;
  vertexInputInfo.vertexAttributeDescriptionCount = attributeDescriptions.size();
  vertexInputInfo.pVertexAttributeDescriptions = attributeDescriptions.data();

  VkPipelineInputAssemblyStateCreateInfo inputAssembly = {};
  inputAssembly.sType =
      VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO;
  inputAssembly.topology = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;
  inputAssembly.primitiveRestartEnable = VK_FALSE;

  VkViewport viewport = {};
  viewport.x = 0.0f;
  viewport.y = 0.0f;
  viewport.width = (float)swapChainExtent.width;
  viewport.height = (float)swapChainExtent.height;
  viewport.minDepth = 0.0f;
  viewport.maxDepth = 1.0f;

  VkRect2D scissor = {};
  scissor.offset = {0, 0};
  scissor.extent = swapChainExtent;

  VkPipelineViewportStateCreateInfo viewportState = {};
  viewportState.sType = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO;
  viewportState.viewportCount = 1;
  viewportState.pViewports = &viewport;
  viewportState.scissorCount = 1;
  viewportState.pScissors = &scissor;

  VkPipelineRasterizationStateCreateInfo rasterizer = {};
  rasterizer.sType = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO;
  rasterizer.depthClampEnable = VK_FALSE;
  rasterizer.rasterizerDiscardEnable = VK_FALSE;
  rasterizer.polygonMode = VK_POLYGON_MODE_FILL;
  rasterizer.lineWidth = 1.0f;
  rasterizer.cullMode = VK_CULL_MODE_BACK_BIT;
  rasterizer.frontFace = VK_FRONT_FACE_COUNTER_CLOCKWISE;
  rasterizer.depthBiasEnable = VK_FALSE;
  rasterizer.depthBiasConstantFactor = 0.0f;
  rasterizer.depthBiasClamp = 0.0f;
  rasterizer.depthBiasSlopeFactor = 0.0f;

  VkPipelineMultisampleStateCreateInfo multisampling = {};
  multisampling.sType = VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO;
  multisampling.rasterizationSamples = VK_SAMPLE_COUNT_1_BIT;
  multisampling.minSampleShading = 1.0f;
  multisampling.pSampleMask = nullptr;
  multisampling.alphaToCoverageEnable = VK_FALSE;
  multisampling.alphaToOneEnable = VK_FALSE;

  VkPipelineDepthStencilStateCreateInfo depthStencil = {};
  depthStencil.sType =
      VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO;
  depthStencil.depthTestEnable = VK_TRUE;
  depthStencil.depthWriteEnable = VK_TRUE;
  depthStencil.depthCompareOp = VK_COMPARE_OP_LESS;
  depthStencil.depthBoundsTestEnable = VK_FALSE;
  depthStencil.minDepthBounds = 0.0f;
  depthStencil.maxDepthBounds = 1.0f;
  depthStencil.stencilTestEnable = VK_FALSE;
  depthStencil.front = {};
  depthStencil.back = {};

  VkPipelineColorBlendAttachmentState colorBlendAttachment = {};
  colorBlendAttachment.colorWriteMask = VK_COLOR_COMPONENT_R_BIT |
      VK_COLOR_COMPONENT_G_BIT | VK_COLOR_COMPONENT_B_BIT |
      VK_COLOR_COMPONENT_A_BIT;
  colorBlendAttachment.blendEnable = VK_FALSE;

  VkPipelineColorBlendStateCreateInfo colorBlending = {};
  colorBlending.sType = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO;
  colorBlending.logicOpEnable = VK_FALSE;
  colorBlending.attachmentCount = 1;
  colorBlending.pAttachments = &colorBlendAttachment;
  colorBlending.blendConstants[0] = 0.0f;
  colorBlending.blendConstants[1] = 0.0f;
  colorBlending.blendConstants[2] = 0.0f;
  colorBlending.blendConstants[3] = 0.0f;

  VkDescriptorSetLayout setLayouts[] = {descriptorSetLayout};
  VkPipelineLayoutCreateInfo pipelineLayoutInfo = {};
  pipelineLayoutInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
  pipelineLayoutInfo.setLayoutCount = 1;
  pipelineLayoutInfo.pSetLayouts = setLayouts;
  pipelineLayoutInfo.pushConstantRangeCount = 0;
  pipelineLayoutInfo.pPushConstantRanges = 0;

  if (vkCreatePipelineLayout(device, &pipelineLayoutInfo, nullptr,
                             pipelineLayout.replace()) != VK_SUCCESS) {
    throw std::runtime_error("Failed to create pipeline layout");
  }

  VkGraphicsPipelineCreateInfo pipelineInfo = {};
  pipelineInfo.sType = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO;
  pipelineInfo.stageCount = 2;
  pipelineInfo.pStages = shaderStages;
  pipelineInfo.pVertexInputState = &vertexInputInfo;
  pipelineInfo.pInputAssemblyState = &inputAssembly;
  pipelineInfo.pViewportState = &viewportState;
  pipelineInfo.pRasterizationState = &rasterizer;
  pipelineInfo.pMultisampleState = &multisampling;
  pipelineInfo.pDepthStencilState = &depthStencil;
  pipelineInfo.pColorBlendState = &colorBlending;
  pipelineInfo.pDynamicState = nullptr;
  pipelineInfo.layout = pipelineLayout;
  pipelineInfo.renderPass = renderPass;
  pipelineInfo.subpass = 0;
  pipelineInfo.basePipelineHandle = VK_NULL_HANDLE;
  pipelineInfo.basePipelineIndex = -1;

  if (vkCreateGraphicsPipelines(device, VK_NULL_HANDLE, 1, &pipelineInfo,
                                nullptr, graphicsPipeline.replace()) != VK_SUCCESS) {
    throw std::runtime_error("Failed to create graphics pipeline");
  }
}

void VulkanApplication::createShaderModule(const std::vector<char> &code, VDeleter<VkShaderModule>
&shaderModule) {
  VkShaderModuleCreateInfo createInfo = {};
  createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
  createInfo.codeSize = code.size();
  createInfo.pCode = (uint32_t*)code.data();

  if (vkCreateShaderModule(device, &createInfo, nullptr,
                           shaderModule.replace()) != VK_SUCCESS) {
    throw std::runtime_error("Failed to create shader module");
  }
}

/*
 * All of the options submitted are wrapped into a framebuffer object. We have multiple framebuffers for the different types of attachments i.e. color or depth, that can be returned.
 */
void VulkanApplication::createFramebuffers() {
  swapChainFramebuffers.resize(swapChainImageViews.size(),
                               VDeleter<VkFramebuffer>{device, vkDestroyFramebuffer});

  for (size_t i = 0; i < swapChainImageViews.size(); i++) {
    std::array<VkImageView, 2> attachments = {
        swapChainImageViews[i],
        depthImageView
    };

    VkFramebufferCreateInfo framebufferInfo = {};
    framebufferInfo.sType = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
    framebufferInfo.renderPass = renderPass;
    framebufferInfo.attachmentCount = attachments.size();
    framebufferInfo.pAttachments = attachments.data();
    framebufferInfo.width = swapChainExtent.width;
    framebufferInfo.height = swapChainExtent.height;
    framebufferInfo.layers = 1;

    if (vkCreateFramebuffer(device, &framebufferInfo, nullptr,
                            swapChainFramebuffers[i].replace()) != VK_SUCCESS) {
      throw std::runtime_error("Failed to create framebuffer");
    }
  }
}

/*
 * Command buffers are commands run on the gpu and used to draw vertices. They are provided by a command pool.
 */
void VulkanApplication::createCommandPool() {
  QueueFamilyIndices queueFamilyIndices = findQueueFamilies(physicalDevice);
  VkCommandPoolCreateInfo poolInfo = {};
  poolInfo.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
  poolInfo.queueFamilyIndex = queueFamilyIndices.graphicsFamily;
  poolInfo.flags = 0;

  if (vkCreateCommandPool(device, &poolInfo, nullptr, commandPool.replace())
      != VK_SUCCESS) {
    throw std::runtime_error("Failed to create command pool");
  }
}

/*
 * A depth resource is an image that tells the depth of a pixel relative to the camera. We create it as Vulkan does not create it automatically
 */
void VulkanApplication::createDepthResources() {
  VkFormat depthFormat = findDepthFormat();
  createImage(swapChainExtent.width, swapChainExtent.height, depthFormat,
              VK_IMAGE_TILING_OPTIMAL, VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT,
              VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT, depthImage, depthImageMemory);
  createImageView(depthImage, depthFormat, VK_IMAGE_ASPECT_DEPTH_BIT,
                  depthImageView);

  transitionImageLayout(depthImage, depthFormat, VK_IMAGE_LAYOUT_UNDEFINED,
                        VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL);
}

VkFormat VulkanApplication::findDepthFormat() {
  return findSupportedFormat({VK_FORMAT_D32_SFLOAT, VK_FORMAT_D32_SFLOAT_S8_UINT,
                              VK_FORMAT_D24_UNORM_S8_UINT}, VK_IMAGE_TILING_OPTIMAL,
                             VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT);
}

VkFormat VulkanApplication::findSupportedFormat(const std::vector<VkFormat> &candidates, VkImageTiling
tiling, VkFormatFeatureFlags features) {
  for (VkFormat format : candidates) {
    VkFormatProperties props;
    vkGetPhysicalDeviceFormatProperties(physicalDevice, format, &props);

    if (tiling == VK_IMAGE_TILING_LINEAR && (props.linearTilingFeatures &
        features) == features) {
      return format;
    } else if (tiling == VK_IMAGE_TILING_OPTIMAL &&
        (props.optimalTilingFeatures & features) == features) {
      return format;
    }
  }

  throw std::runtime_error("Failed to find supported format");
}

bool VulkanApplication::hasStencilComponent(VkFormat format) {
  return format == VK_FORMAT_D32_SFLOAT_S8_UINT || format ==
      VK_FORMAT_D24_UNORM_S8_UINT;
}


void VulkanApplication::createTextureImage() {
  for (auto texture = textures.begin(); texture != textures.end(); ++texture) {
    createSingleTextureImage(&*texture);
  }
}

/*
 * Loads the image we want to draw into GPU memory. In general, the most optimal memory on graphics cards is not accessibly by the CPU. Therefore this creates a staging buffer in CPU accessible memory where the image is loaded into, then copied into more performant meory through a buffer copy command.
 */
void VulkanApplication::createSingleTextureImage(TextureInternal *texture) {
  VDeleter<VkImage> stagingImage{device, vkDestroyImage};
  VDeleter<VkDeviceMemory> stagingImageMemory{device, vkFreeMemory};

  createImage(texture->baseTexture->texWidth, texture->baseTexture->texHeight, VK_FORMAT_R8G8B8A8_UNORM,
              VK_IMAGE_TILING_LINEAR, VK_IMAGE_USAGE_TRANSFER_SRC_BIT,
              VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT,
              stagingImage, stagingImageMemory);

  VkDeviceSize imageSize = texture->baseTexture->texWidth * texture->baseTexture->texHeight * 4;
  void *data;
  vkMapMemory(device, stagingImageMemory, 0, imageSize, 0, &data);
  memcpy(data, texture->baseTexture->pixels, (size_t) imageSize);
  vkUnmapMemory(device, stagingImageMemory);

  //stbi_image_free(texture->baseTexture.pixels);

  createImage(
      texture->baseTexture->texWidth,
      texture->baseTexture->texHeight,
      VK_FORMAT_R8G8B8A8_UNORM,
      VK_IMAGE_TILING_OPTIMAL,
      VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_SAMPLED_BIT,
      VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT,
      texture->textureImage,
      texture->textureImageMemory
  );

  transitionImageLayout(stagingImage, VK_FORMAT_R8G8B8A8_UNORM,
                        VK_IMAGE_LAYOUT_PREINITIALIZED, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL);
  transitionImageLayout(texture->textureImage, VK_FORMAT_R8G8B8A8_UNORM,
                        VK_IMAGE_LAYOUT_PREINITIALIZED, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL);
  copyImage(stagingImage, texture->textureImage, texture->baseTexture->texWidth, texture->baseTexture->texHeight);

  transitionImageLayout(texture->textureImage, VK_FORMAT_R8G8B8A8_UNORM,
                        VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,
                        VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL);

}


void VulkanApplication::createTextureImageView() {

  for (auto texture = textures.begin(); texture != textures.end(); ++texture) {
    createSingleTextureImageView(&*texture);
  }
}

/*
 * Loads the image we want to draw into GPU memory. In general, the most optimal memory on graphics cards is not accessibly by the CPU. Therefore this creates a staging buffer in CPU accessible memory where the image is loaded into, then copied into more performant memory through a buffer copy command.
 */
void VulkanApplication::createSingleTextureImageView(TextureInternal *texture) {
  createImageView(texture->textureImage, VK_FORMAT_R8G8B8A8_UNORM,
                  VK_IMAGE_ASPECT_COLOR_BIT, texture->textureImageView);
}

void VulkanApplication::createTextureSampler() {
  for (auto texture = textures.begin(); texture != textures.end(); ++texture) {
    createSingleTextureSampler(&*texture);
  }
}

/*
 * It is not common to load each pixel when reading textures. They are generally loaded through samplers that apply filtering and transformations to the image. For example, if the final 3D output has more fragments to render than there are pixels, using a sampler with linear interpolation can result in a better quality image than simply taking the nearest pixels.
 */
void VulkanApplication::createSingleTextureSampler(TextureInternal *texture) {
  VkSamplerCreateInfo samplerInfo = {};
  samplerInfo.sType = VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO;
  samplerInfo.magFilter = VK_FILTER_LINEAR;
  samplerInfo.minFilter = VK_FILTER_LINEAR;
  samplerInfo.addressModeU = VK_SAMPLER_ADDRESS_MODE_REPEAT;
  samplerInfo.addressModeV = VK_SAMPLER_ADDRESS_MODE_REPEAT;
  samplerInfo.addressModeW = VK_SAMPLER_ADDRESS_MODE_REPEAT;
  samplerInfo.anisotropyEnable = VK_TRUE;
  samplerInfo.maxAnisotropy = 16;
  samplerInfo.borderColor = VK_BORDER_COLOR_INT_OPAQUE_BLACK;
  samplerInfo.unnormalizedCoordinates = VK_FALSE;
  samplerInfo.compareEnable = VK_FALSE;
  samplerInfo.compareOp = VK_COMPARE_OP_ALWAYS;
  samplerInfo.mipmapMode = VK_SAMPLER_MIPMAP_MODE_LINEAR;
  samplerInfo.mipLodBias = 0.0f;
  samplerInfo.minLod = 0.0f;
  samplerInfo.maxLod = 0.0f;

  if (vkCreateSampler(device, &samplerInfo, nullptr, texture->textureSampler.replace())
      != VK_SUCCESS) {
    throw std::runtime_error("Failed to create texture sampler");
  }
}

void VulkanApplication::createImage(uint32_t width, uint32_t height, VkFormat format, VkImageTiling
tiling, VkImageUsageFlags usage, VkMemoryPropertyFlags properties,
                                  VDeleter<VkImage> &image, VDeleter<VkDeviceMemory> &imageMemory) {

  VkImageCreateInfo imageInfo = {};
  imageInfo.sType = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
  imageInfo.imageType = VK_IMAGE_TYPE_2D;
  imageInfo.extent.width = width;
  imageInfo.extent.height = height;
  imageInfo.extent.depth = 1;
  imageInfo.mipLevels = 1;
  imageInfo.arrayLayers = 1;
  imageInfo.format = format;
  imageInfo.tiling = tiling;
  imageInfo.initialLayout = VK_IMAGE_LAYOUT_PREINITIALIZED;
  imageInfo.usage = usage;
  imageInfo.sharingMode = VK_SHARING_MODE_EXCLUSIVE;
  imageInfo.samples = VK_SAMPLE_COUNT_1_BIT;
  imageInfo.flags = 0;

  if (vkCreateImage(device, &imageInfo, nullptr, image.replace())
      != VK_SUCCESS) {
    throw std::runtime_error("Failed to create image");
  }

  VkMemoryRequirements memRequirements;
  vkGetImageMemoryRequirements(device, image, &memRequirements);

  VkMemoryAllocateInfo allocInfo = {};
  allocInfo.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
  allocInfo.allocationSize = memRequirements.size;
  allocInfo.memoryTypeIndex = findMemoryType(memRequirements.memoryTypeBits,
                                             properties);

  if (vkAllocateMemory(device, &allocInfo, nullptr, imageMemory.replace())
      != VK_SUCCESS) {
    throw std::runtime_error("Failed to allocate image memory");
  }

  vkBindImageMemory(device, image, imageMemory, 0);
}

void VulkanApplication::createBuffer(VkDeviceSize size, VkBufferUsageFlags usage,
                                   VkMemoryPropertyFlags properties, VDeleter<VkBuffer> &buffer,
                                   VDeleter<VkDeviceMemory> &bufferMemory) {

  VkBufferCreateInfo bufferInfo = {};
  bufferInfo.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
  bufferInfo.size = size;
  bufferInfo.usage = usage;
  bufferInfo.sharingMode = VK_SHARING_MODE_EXCLUSIVE;

  if (vkCreateBuffer(device, &bufferInfo, nullptr, buffer.replace())
      != VK_SUCCESS) {
    throw std::runtime_error("Failed to create vertex buffer");
  }

  VkMemoryRequirements memRequirements;
  vkGetBufferMemoryRequirements(device, buffer, &memRequirements);

  VkMemoryAllocateInfo allocInfo = {};
  allocInfo.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
  allocInfo.allocationSize = memRequirements.size;
  allocInfo.memoryTypeIndex = findMemoryType(memRequirements.memoryTypeBits,
                                             properties);

  if (vkAllocateMemory(device, &allocInfo, nullptr, bufferMemory.replace())
      != VK_SUCCESS) {
    throw std::runtime_error("Failed to allocate vertex buffer memory");
  }


  vkBindBufferMemory(device, buffer, bufferMemory, 0);
}

VkCommandBuffer VulkanApplication::beginSingleTimeCommands() {
  VkCommandBufferAllocateInfo allocInfo = {};
  allocInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
  allocInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
  allocInfo.commandPool = commandPool;
  allocInfo.commandBufferCount = 1;

  VkCommandBuffer commandBuffer;
  vkAllocateCommandBuffers(device, &allocInfo, &commandBuffer);

  VkCommandBufferBeginInfo beginInfo = {};
  beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
  beginInfo.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;

  vkBeginCommandBuffer(commandBuffer, &beginInfo);

  return commandBuffer;
}

void VulkanApplication::endSingleTimeCommands(VkCommandBuffer commandBuffer) {
  vkEndCommandBuffer(commandBuffer);

  VkSubmitInfo submitInfo = {};
  submitInfo.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
  submitInfo.commandBufferCount = 1;
  submitInfo.pCommandBuffers = &commandBuffer;

  vkQueueSubmit(graphicsQueue, 1, &submitInfo, VK_NULL_HANDLE);
  vkQueueWaitIdle(graphicsQueue);

  vkFreeCommandBuffers(device, commandPool, 1, &commandBuffer);

}

/*
 * Copies model and texture data from input. Builds MeshInternal and TextureInternal from the input Mesh and Texture objects
 */
void VulkanApplication::loadModels() {

  for (int i = 0; i < inputTextures.size(); i++) {
    TextureInternal textureInternal(device, inputTextures[i]);
    textures.push_back(textureInternal);
  }


  for (int i = 0; i < inputMeshes.size(); i++) {
    MeshInternal meshInternal(device, inputMeshes[i]);
    for (int j = 0; j < textures.size(); j++) {
      if (inputMeshes[i]->texture == textures[j].baseTexture) {
        meshInternal.texture = &textures[j];
        break;
      }
    }
    meshes.push_back(meshInternal);
  }

}



void VulkanApplication::createVertexBuffer() {
  for (auto mesh = meshes.begin(); mesh != meshes.end(); ++mesh) {
    createSingleVertexBuffer(&*mesh);
  }
}

/*
 * Creates a staging buffer and final buffer for vertices, just like createTextureImage does for texture. This undergoes the same process of allocating, mapping, and transferring the vertex data to the GPU.
 * The vertex buffer holds all of the positions of the verticies of each mesh
 */
void VulkanApplication::createSingleVertexBuffer(MeshInternal *mesh) {
  VkDeviceSize bufferSize = sizeof(mesh->vertices[0]) * mesh->vertices.size();
  VDeleter<VkBuffer> stagingBuffer{device, vkDestroyBuffer};
  VDeleter<VkDeviceMemory> stagingBufferMemory{device, vkFreeMemory};

  createBuffer(bufferSize, VK_BUFFER_USAGE_TRANSFER_SRC_BIT,
               VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT,
               stagingBuffer, stagingBufferMemory);


  void *data;
  vkMapMemory(device, stagingBufferMemory, 0, bufferSize, 0, &data);
  memcpy(data, mesh->vertices.data(), (size_t)bufferSize);
  vkUnmapMemory(device, stagingBufferMemory);

  createBuffer(bufferSize, VK_BUFFER_USAGE_TRANSFER_DST_BIT |
                   VK_BUFFER_USAGE_VERTEX_BUFFER_BIT, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT,
               mesh->vertexBuffer, mesh->vertexBufferMemory);

  copyBuffer(stagingBuffer, mesh->vertexBuffer, bufferSize);

}

void VulkanApplication::createIndexBuffer() {
  for (auto mesh = meshes.begin(); mesh != meshes.end(); ++mesh) {
    createSingleIndexBuffer(&*mesh);
  }
}

/*
 * An index buffer allows the reduction of data in the vertex buffer. Since complex models are made up of triangles with shared sides, they will also have shared verticies. Copying all vertices to the vertex buffer results in duplicate vertices. An index buffer can reduce the data usage by identifying the vertices used in triangles, therefore only requiring one of each uniqe vertex in the vertex buffer.
 *
 * Creating the index buffer undergoes the same process as the vertex buffer in the creation of a staging and final buffer.
 */
void VulkanApplication::createSingleIndexBuffer(MeshInternal *mesh) {
  VkDeviceSize bufferSize = sizeof(mesh->indices[0]) * mesh->indices.size();
  VDeleter<VkBuffer> stagingBuffer{device, vkDestroyBuffer};
  VDeleter<VkDeviceMemory> stagingBufferMemory{device, vkFreeMemory};

  createBuffer(bufferSize, VK_BUFFER_USAGE_TRANSFER_SRC_BIT,
               VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT,
               stagingBuffer, stagingBufferMemory);


  void *data;
  vkMapMemory(device, stagingBufferMemory, 0, bufferSize, 0, &data);
  memcpy(data, mesh->indices.data(), (size_t)bufferSize);
  vkUnmapMemory(device, stagingBufferMemory);

  createBuffer(bufferSize, VK_BUFFER_USAGE_TRANSFER_DST_BIT |
                   VK_BUFFER_USAGE_INDEX_BUFFER_BIT, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT,
               mesh->indexBuffer, mesh->indexBufferMemory);

  copyBuffer(stagingBuffer, mesh->indexBuffer, bufferSize);

}

void VulkanApplication::createUniformBuffer() {
  for (auto mesh = meshes.begin(); mesh != meshes.end(); ++mesh) {
    createSingleUniformBuffer(&*mesh);
  }
}

/*
 * Creates a buffer that is accessibly by the shaders. This is where we put the UniformBufferObject that defines the transformation of the respective meshes.
 */
void VulkanApplication::createSingleUniformBuffer(MeshInternal *mesh) {
  VkDeviceSize bufferSize = sizeof(UniformBufferObject);

  createBuffer(bufferSize, VK_BUFFER_USAGE_TRANSFER_SRC_BIT,
               VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT |
                   VK_MEMORY_PROPERTY_HOST_COHERENT_BIT, mesh->uniformStagingBuffer,
               mesh->uniformStagingBufferMemory);
  createBuffer(bufferSize, VK_BUFFER_USAGE_TRANSFER_DST_BIT |
                   VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT,
               mesh->uniformBuffer, mesh->uniformBufferMemory);
}


void VulkanApplication::copyBuffer(VkBuffer srcBuffer, VkBuffer dstBuffer, VkDeviceSize size) {
  VkCommandBuffer commandBuffer = beginSingleTimeCommands();

  VkBufferCopy copyRegion = {};
  copyRegion.size = size;
  vkCmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, 1, &copyRegion);

  endSingleTimeCommands(commandBuffer);
}

void VulkanApplication::transitionImageLayout(VkImage image, VkFormat format, VkImageLayout oldLayout,
                                            VkImageLayout newLayout) {
  VkCommandBuffer commandBuffer = beginSingleTimeCommands();

  VkImageMemoryBarrier barrier = {};
  barrier.sType = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
  barrier.oldLayout = oldLayout;
  barrier.newLayout = newLayout;
  barrier.srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
  barrier.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
  barrier.image = image;

  if (newLayout == VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL) {
    barrier.subresourceRange.aspectMask = VK_IMAGE_ASPECT_DEPTH_BIT;
    if (hasStencilComponent(format)) {
      barrier.subresourceRange.aspectMask |= VK_IMAGE_ASPECT_STENCIL_BIT;
    }
  } else {
    barrier.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
  }

  barrier.subresourceRange.baseMipLevel = 0;
  barrier.subresourceRange.levelCount = 1;
  barrier.subresourceRange.baseArrayLayer = 0;
  barrier.subresourceRange.layerCount = 1;
  barrier.srcAccessMask = 0;
  barrier.dstAccessMask = 0;

  if (oldLayout == VK_IMAGE_LAYOUT_PREINITIALIZED && newLayout ==
      VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL) {
    barrier.srcAccessMask = VK_ACCESS_HOST_WRITE_BIT;
    barrier.dstAccessMask = VK_ACCESS_TRANSFER_READ_BIT;
  } else if (oldLayout == VK_IMAGE_LAYOUT_PREINITIALIZED && newLayout ==
      VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL) {
    barrier.srcAccessMask = VK_ACCESS_HOST_WRITE_BIT;
    barrier.dstAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
  } else if (oldLayout == VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL &&
      newLayout == VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL) {
    barrier.srcAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
    barrier.dstAccessMask = VK_ACCESS_SHADER_READ_BIT;
  } else if (oldLayout == VK_IMAGE_LAYOUT_UNDEFINED && newLayout ==
      VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL) {
    barrier.srcAccessMask = 0;
    barrier.dstAccessMask = VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_READ_BIT |
        VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT;
  } else {
    throw std::invalid_argument("Unsupported layout transition");
  }

  vkCmdPipelineBarrier(commandBuffer, VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                       VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, 0, 0, nullptr, 0, nullptr, 1, &barrier);


  endSingleTimeCommands(commandBuffer);
}

void VulkanApplication::copyImage(VkImage srcImage, VkImage dstImage, uint32_t width,
                                uint32_t height) {
  VkCommandBuffer commandBuffer = beginSingleTimeCommands();

  VkImageSubresourceLayers subResource = {};
  subResource.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
  subResource.baseArrayLayer = 0;
  subResource.mipLevel = 0;
  subResource.layerCount = 1;

  VkImageCopy region = {};
  region.srcSubresource = subResource;
  region.dstSubresource = subResource;
  region.srcOffset = {0, 0, 0};
  region.dstOffset = {0, 0, 0};
  region.extent.width = width;
  region.extent.height = height;
  region.extent.depth = 1;

  vkCmdCopyImage(commandBuffer,
                 srcImage, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
                 dstImage, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,
                 1, &region);



  endSingleTimeCommands(commandBuffer);
}

uint32_t VulkanApplication::findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties) {
  VkPhysicalDeviceMemoryProperties memProperties;
  vkGetPhysicalDeviceMemoryProperties(physicalDevice, &memProperties);

  for (uint32_t i = 0; i < memProperties.memoryTypeCount; i++) {
    if ((typeFilter & (1 << i)) && (memProperties.memoryTypes[i].propertyFlags & properties)
        == properties) {
      return i;
    }
  }
  throw std::runtime_error("Failed to find suitable memory type");
}

/*
 * To create a descriptorSet, a descriptorPool needs to be defined to show the usage of the set.
 */
void VulkanApplication::createDescriptorPool() {
  std::array<VkDescriptorPoolSize, 2> poolSizes = {};
  poolSizes[0].type = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
  //poolSizes[0].descriptorCount = meshes.size() + 1;
  poolSizes[0].descriptorCount = 100;
  poolSizes[1].type = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
  //poolSizes[1].descriptorCount = meshes.size() + 1;
  poolSizes[1].descriptorCount = 100;

  VkDescriptorPoolCreateInfo poolInfo = {};
  poolInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO;
  poolInfo.poolSizeCount = poolSizes.size();
  poolInfo.pPoolSizes = poolSizes.data();
  //poolInfo.maxSets = meshes.size() + 1;
  poolInfo.maxSets = 100;

  if (vkCreateDescriptorPool(device, &poolInfo, nullptr,
                             descriptorPool.replace()) != VK_SUCCESS) {
    throw std::runtime_error("Failed to create descriptor pool");
  }
}

void VulkanApplication::createDescriptorSet() {
  for (auto mesh = meshes.begin(); mesh != meshes.end(); ++mesh) {
    createSingleDescriptorSet(&*mesh);
  }
}

/*
 * A descriptorSet defines bindings between memory and shaders.
 */
void VulkanApplication::createSingleDescriptorSet(MeshInternal *mesh) {
  VkDescriptorSetLayout layouts[] = {descriptorSetLayout};
  VkDescriptorSetAllocateInfo allocInfo = {};
  allocInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO;
  allocInfo.descriptorPool = descriptorPool;
  allocInfo.descriptorSetCount = 1;
  allocInfo.pSetLayouts = layouts;

  if (vkAllocateDescriptorSets(device, &allocInfo, &mesh->descriptorSet) !=
      VK_SUCCESS) {
    throw std::runtime_error("Failed to allocate descriptor set");
  }

  VkDescriptorBufferInfo bufferInfo = {};
  bufferInfo.buffer = mesh->uniformBuffer;
  bufferInfo.offset = 0;
  bufferInfo.range = sizeof(UniformBufferObject);

  VkDescriptorImageInfo imageInfo = {};
  imageInfo.imageLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
  imageInfo.imageView = mesh->texture->textureImageView;
  imageInfo.sampler = mesh->texture->textureSampler;


  std::array<VkWriteDescriptorSet, 2> descriptorWrites = {};

  descriptorWrites[0].sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
  descriptorWrites[0].dstSet = mesh->descriptorSet;
  descriptorWrites[0].dstBinding = 0;
  descriptorWrites[0].dstArrayElement = 0;
  descriptorWrites[0].descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
  descriptorWrites[0].descriptorCount = 1;
  descriptorWrites[0].pBufferInfo = &bufferInfo;

  descriptorWrites[1].sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
  descriptorWrites[1].dstSet = mesh->descriptorSet;
  descriptorWrites[1].dstBinding = 1;
  descriptorWrites[1].dstArrayElement = 0;
  descriptorWrites[1].descriptorType = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
  descriptorWrites[1].descriptorCount = 1;
  descriptorWrites[1].pImageInfo = &imageInfo;

  vkUpdateDescriptorSets(device, descriptorWrites.size(),
                         descriptorWrites.data(), 0, nullptr);
}

/*
 * Command buffers are objects used to record commands which can be submitted to a device queue, our graphics card, for execution.
 */
void VulkanApplication::createCommandBuffers() {
  if (commandBuffers.size() > 0) {
    vkFreeCommandBuffers(device, commandPool, commandBuffers.size(),
                         commandBuffers.data());
  }


  commandBuffers.resize(swapChainFramebuffers.size());

  VkCommandBufferAllocateInfo allocInfo = {};
  allocInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
  allocInfo.commandPool = commandPool;
  allocInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
  allocInfo.commandBufferCount = (uint32_t)commandBuffers.size();

  if (vkAllocateCommandBuffers(device, &allocInfo, commandBuffers.data())
      != VK_SUCCESS) {
    throw std::runtime_error("Failed to allocate command buffers");
  }

  /*
  if (meshes.size() == 2) {
    for (int i = 0; i < meshes.size(); i++) {

      MeshInternal test = meshes[i];
    }
  }
   */

  for (size_t i = 0; i < commandBuffers.size(); i++) {
    VkCommandBufferBeginInfo beginInfo = {};
    beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
    beginInfo.flags = VK_COMMAND_BUFFER_USAGE_SIMULTANEOUS_USE_BIT;
    beginInfo.pInheritanceInfo = nullptr;

    vkBeginCommandBuffer(commandBuffers[i], &beginInfo);

    VkRenderPassBeginInfo renderPassInfo = {};
    renderPassInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
    renderPassInfo.renderPass = renderPass;
    renderPassInfo.framebuffer = swapChainFramebuffers[i];
    renderPassInfo.renderArea.offset = {0, 0};
    renderPassInfo.renderArea.extent = swapChainExtent;

    std::array<VkClearValue, 2> clearValues = {};
    clearValues[0].color = {0.0f, 0.0f, 0.0f, 1.0f};
    clearValues[1].depthStencil = {1.0f, 0};

    renderPassInfo.clearValueCount = clearValues.size();
    renderPassInfo.pClearValues = clearValues.data();

    vkCmdBeginRenderPass(commandBuffers[i], &renderPassInfo,
                         VK_SUBPASS_CONTENTS_INLINE);

    vkCmdBindPipeline(commandBuffers[i], VK_PIPELINE_BIND_POINT_GRAPHICS,
                      graphicsPipeline);

    for (auto mesh = meshes.begin(); mesh != meshes.end(); ++mesh) {
      VkBuffer vertexBuffers[] = {mesh->vertexBuffer};
      VkDeviceSize offsets[] = {0};
      vkCmdBindVertexBuffers(commandBuffers[i], 0, 1, vertexBuffers, offsets);

      vkCmdBindIndexBuffer(commandBuffers[i], mesh->indexBuffer, 0,
                           VK_INDEX_TYPE_UINT32);

      vkCmdBindDescriptorSets(commandBuffers[i], VK_PIPELINE_BIND_POINT_GRAPHICS,
                              pipelineLayout, 0, 1, &mesh->descriptorSet, 0, nullptr);

      vkCmdDrawIndexed(commandBuffers[i], mesh->indices.size(), 1, 0, 0, 1);
      //j++;
    }
    vkCmdEndRenderPass(commandBuffers[i]);

    if (vkEndCommandBuffer(commandBuffers[i]) != VK_SUCCESS) {
      throw std::runtime_error("Failed to record command buffer");
    }
  }
}

/*
 * Semaphores allow for the syncronization of the process of aquiring the image, executing the command buffer, and presenting the image.  One semaphore is used to signal that an image has been aquired and is ready for rendering, and one that rendering is finished and the image can be presented.
 */
void VulkanApplication::createSemaphores() {
  VkSemaphoreCreateInfo semaphoreInfo = {};
  semaphoreInfo.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;

  if (vkCreateSemaphore(device, &semaphoreInfo, nullptr,
                        imageAvailableSemaphore.replace()) != VK_SUCCESS || vkCreateSemaphore(
      device, &semaphoreInfo, nullptr, renderFinishedSemaphore.replace()) !=
      VK_SUCCESS) {
    throw std::runtime_error("Failed to create semaphores");
  }
}

void VulkanApplication::updateUniformBuffer() {
  for (auto mesh = meshes.begin(); mesh != meshes.end(); ++mesh) {
    UniformBufferObject ubo = {};
    ubo.model = mesh->baseMesh->transform;
    //ubo.view = glm::lookAt(glm::vec3(2.0f, 2.0f, 2.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    ubo.view = *cameraTransform;
    ubo.proj = glm::perspective(glm::radians(45.0f), swapChainExtent.width /
        (float) swapChainExtent.height, 0.1f, 100.0f); //Cull near and fall is the last two arguments!!

    ubo.proj[1][1] *= -1;

    void *data;
    vkMapMemory(device, mesh->uniformStagingBufferMemory, 0, sizeof(ubo), 0, &data);
    memcpy(data, &ubo, sizeof(ubo));
    vkUnmapMemory(device, mesh->uniformStagingBufferMemory);

    copyBuffer(mesh->uniformStagingBuffer, mesh->uniformBuffer, sizeof(ubo));
  }
}

void VulkanApplication::drawFrame() {
  uint32_t imageIndex;
  VkResult result = vkAcquireNextImageKHR(device, swapChain,
                                          std::numeric_limits<uint64_t>::max(), imageAvailableSemaphore,
                                          VK_NULL_HANDLE, &imageIndex);

  if (result == VK_ERROR_OUT_OF_DATE_KHR) {
    recreateSwapChain();
    return;
  } else if (result != VK_SUCCESS && result != VK_SUBOPTIMAL_KHR) {
    throw std::runtime_error("Failed to acquire swap chain image");
  }

  VkSubmitInfo submitInfo = {};
  submitInfo.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;

  VkSemaphore waitSemaphores[] = {imageAvailableSemaphore};
  VkPipelineStageFlags waitStages[] =
      {VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT};
  submitInfo.waitSemaphoreCount = 1;
  submitInfo.pWaitSemaphores = waitSemaphores;
  submitInfo.pWaitDstStageMask = waitStages;
  submitInfo.commandBufferCount = 1;
  submitInfo.pCommandBuffers = &commandBuffers[imageIndex];

  VkSemaphore signalSemaphores[] = {renderFinishedSemaphore};
  submitInfo.signalSemaphoreCount = 1;
  submitInfo.pSignalSemaphores = signalSemaphores;

  if (vkQueueSubmit(graphicsQueue, 1, &submitInfo, VK_NULL_HANDLE)
      != VK_SUCCESS) {
    throw std::runtime_error("Failed to submit draw command buffer");
  }

  VkPresentInfoKHR presentInfo = {};
  presentInfo.sType = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR;
  presentInfo.waitSemaphoreCount = 1;
  presentInfo.pWaitSemaphores = signalSemaphores;

  VkSwapchainKHR swapChains[] = {swapChain};
  presentInfo.swapchainCount = 1;
  presentInfo.pSwapchains = swapChains;
  presentInfo.pImageIndices = &imageIndex;
  presentInfo.pResults = nullptr;

  result = vkQueuePresentKHR(presentQueue, &presentInfo);

  if (result == VK_ERROR_OUT_OF_DATE_KHR || result == VK_SUBOPTIMAL_KHR) {
    recreateSwapChain();
  } else if(result != VK_SUCCESS) {
    throw std::runtime_error("Failed to present swap chain image");
  }

}

void VulkanApplication::recreateSwapChain() {
  vkDeviceWaitIdle(device);

  createSwapChain();
  createImageViews();
  createRenderPass();
  createGraphicsPipeline();
  createDepthResources();
  createFramebuffers();
  createCommandBuffers();
}

VkSurfaceFormatKHR VulkanApplication::chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>
                                                            availableFormats) {
  if (availableFormats.size() == 1 && availableFormats[0].format ==
      VK_FORMAT_UNDEFINED) {
    return {VK_FORMAT_B8G8R8A8_UNORM, VK_COLOR_SPACE_SRGB_NONLINEAR_KHR};
  }

  for (const auto &availableFormat : availableFormats) {
    if (availableFormat.format == VK_FORMAT_B8G8R8A8_UNORM &&
        availableFormat.colorSpace == VK_COLOR_SPACE_SRGB_NONLINEAR_KHR) {
      return availableFormat;
    }
  }

  return availableFormats[0];
}

VkPresentModeKHR VulkanApplication::chooseSwapPresentMode(const std::vector<VkPresentModeKHR>
                                                        availablePresentModes) {

  for (const auto &availablePresentMode : availablePresentModes) {
    if (availablePresentMode == VK_PRESENT_MODE_MAILBOX_KHR) {
      return availablePresentMode;
    }
  }

  return VK_PRESENT_MODE_FIFO_KHR;
}

VkExtent2D VulkanApplication::chooseSwapExtent(const VkSurfaceCapabilitiesKHR &capabilities) {
  if (capabilities.currentExtent.width != std::numeric_limits<uint32_t>::max()) {
    return capabilities.currentExtent;
  } else {
    VkExtent2D actualExtent = {(uint32_t)WIDTH, (uint32_t)HEIGHT};

    actualExtent.width = std::max(capabilities.minImageExtent.width,
                                  std::min(capabilities.maxImageExtent.width, actualExtent.width));
    actualExtent.height = std::max(capabilities.minImageExtent.height,
                                   std::min(capabilities.maxImageExtent.height, actualExtent.height));

    return actualExtent;
  }
}

std::vector<char> VulkanApplication::readFile(const std::string &filename) {
  std::ifstream file(filename, std::ios::ate | std::ios::binary);

  if (!file.is_open()) {
    throw std::runtime_error("Failed to open file");
  }
  size_t fileSize = (size_t)file.tellg();
  std::vector<char>buffer(fileSize);

  file.seekg(0);
  file.read(buffer.data(), fileSize);

  file.close();

  return buffer;
}


