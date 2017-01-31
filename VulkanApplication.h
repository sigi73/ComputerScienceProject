//
// Created by siddharth on 1/10/17.
//

#ifndef VULKANENGINE_VULKANAPPLICATION_H
#define VULKANENGINE_VULKANAPPLICATION_H

#include <vector>
#include <iostream>

#ifndef VULKAN_COMMON_IMPLEMENTATION
#define VULKAN_COMMON_IMPLEMENTATION
#include "VulkanCommon.h"
#endif

#include "VDeleter.h"
#include "MeshInternal.h"
#include "TextureInternal.h"

class VulkanApplication {
 public:
  VulkanApplication();
  VulkanApplication(int window_width, int window_height, glm::mat4 *cameraTransformPointer, GLFWwindow **inUserWindow, void* inApp, void (*loop)(float, void* app), void (*window)(void *app));
  void run(std::vector<Mesh*> inMeshes, std::vector<Texture*> inTextures);
  void startMainLoop();

  static void onWindowResized(GLFWwindow *window, int width, int height, VulkanApplication *app);

 private:

  void *app;
  int WIDTH;
  int HEIGHT;

  /*
   * Stores a reference to an external loop function that is called every frame
   */
  void (*userLoop)(float, void *app);

  /*
   * Stores a reference to a window setup function that allows the user to setup the window
   */
  void (*windowSetup)(void *app);

  /*
   * Validation layers are used for debugging, and when enabled provide verbose output
   */
  const std::vector<const char*> validationLayers = {
      "VK_LAYER_LUNARG_standard_validation"
  };

  /*
   * Extensions are added on top of Vulkan to provide functionality as needed. The swapchain is the system that swaps the images between the screen and a hidden framebuffer. This is used to tell Vulkan what extensions we want to use
   */
  const std::vector<const char*> deviceExtensions = {
      VK_KHR_SWAPCHAIN_EXTENSION_NAME
  };


  /*
   * Used to enable the validation layers and print debug info
   */
//#define DEBUGGING_STATEMENTS
#ifdef DEBUGGING_STATEMENTS
  //diagnostic information
#define ENUMERATE_EXTENSIONS
  const bool enableValidationLayers = true;
#else
  const bool enableValidationLayers = false;
#endif //DEBUGGING_STATEMENTS

  GLFWwindow *window;
  GLFWwindow **userWindow;
  GLFWcursor *standardCursor;

  //Instance of Vulkan. Stores per application state
  VDeleter<VkInstance> instance{vkDestroyInstance};
  //Callback for providing debug information
  VDeleter<VkDebugReportCallbackEXT> callback{instance, DestroyDebugReportCallbackEXT};
  //The surface that the image is presented to
  VDeleter<VkSurfaceKHR> surface{instance, vkDestroySurfaceKHR};

  //Vulkan seperates physical and logical device. These are the two objects for these.
  VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
  VDeleter<VkDevice> device{vkDestroyDevice};


  //Mesh contains only user data. MeshInternal contains Vulkan memory objects
  std::vector<Mesh*> inputMeshes;
  std::vector<MeshInternal> meshes;

  //Texture contains only user data. TextureInternal contains Vulkan memory objects
  std::vector<Texture*> inputTextures;
  std::vector<TextureInternal> textures;

  glm::mat4 *cameraTransform;

  //Graphic processing units have different queues that can be assigned to different tasks. Here one is used to create the image and one is used to present it.
  VkQueue graphicsQueue;
  VkQueue presentQueue;

  /*
   * The swapchain is the system that swaps the images between the screen and a hidden framebuffer. These objects are swapchain itself, as well as the images that are swapped to the screen, and structures describing information about the swapchain.
   */
  VDeleter<VkSwapchainKHR> swapChain{device, vkDestroySwapchainKHR};
  std::vector<VkImage> swapChainImages;
  VkFormat swapChainImageFormat;
  VkExtent2D swapChainExtent;
  std::vector<VDeleter<VkImageView>> swapChainImageViews;

  //A VkRenderPass describes how the vertices submitted to it are rendered.
  VDeleter<VkRenderPass> renderPass{device, vkDestroyRenderPass};

  //Used to describe what types of data will be passed to the shaders. In this case a ubo, or Uniform Buffer Object, which is used to send the position, and a sampler, which is used to access the texture drawn on the meshes.
  VDeleter<VkDescriptorSetLayout> descriptorSetLayout{device,
                                                      vkDestroyDescriptorSetLayout};
  //Access to the above features is done through a pipeline. This object describes how that pipeline is set up.
  VDeleter<VkPipelineLayout> pipelineLayout{device, vkDestroyPipelineLayout};

  //Actual instance of the pipeline
  VDeleter<VkPipeline> graphicsPipeline{device, vkDestroyPipeline};

  //All of the framebuffers that hold the image before presenting it to the swapchain
  std::vector<VDeleter<VkFramebuffer>> swapChainFramebuffers;

  //The commandPool is used to allocate command buffers. Command buffers describe commands that the GPU will run, and are enumerated here before being created.
  VDeleter<VkCommandPool> commandPool{device, vkDestroyCommandPool};
  std::vector<VkCommandBuffer> commandBuffers;

  //Used to notify when the image is available and the render is finished
  VDeleter<VkSemaphore> imageAvailableSemaphore{device, vkDestroySemaphore};
  VDeleter<VkSemaphore> renderFinishedSemaphore{device, vkDestroySemaphore};

  //Maintains a pool of descriptors based on the information in the descriptor set layout above. Allocates a descriptor, used to describe properties of an object, whenever necessary. In this case we are storing information regarding the object position and texture.
  VDeleter<VkDescriptorPool> descriptorPool{device, vkDestroyDescriptorPool};

  //Used to hold information about the distance of each pixel from the camera. Used to determine depth and layering of objects relative to the camera.
  VDeleter<VkImage> depthImage{device, vkDestroyImage};
  VDeleter<VkDeviceMemory> depthImageMemory{device, vkFreeMemory};
  VDeleter<VkImageView> depthImageView{device, vkDestroyImageView};


  /*
   * All descriptions of class functions can be found in VulkanApplication.cpp
   */

  void initWindow();

  void initVulkan();
#ifdef ENUMERATE_EXTENSIONS
  void enumerateExtensions();
#endif
  void createInstance();
  void setupDebugCallback();
  void createSurface();

  void pickPhysicalDevice();
  bool isDeviceSuitable(VkPhysicalDevice device);
  QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
  bool checkDeviceExtensionSupport(VkPhysicalDevice device);
  SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);

  void createLogicalDevice();


  void loadModels();

  void createSwapChain();
  VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR> availableFormats);
  VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR> availablePresentModes);
  VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR &capabilities);

  void createImageViews();
  void createImageView(VkImage image, VkFormat format, VkImageAspectFlags aspectFlags, VDeleter<VkImageView> &imageView);

  void createRenderPass();
  void createDescriptorSetLayout();

  void createGraphicsPipeline();
  static std::vector<char> readFile(const std::string &filename);
  void createShaderModule(const std::vector<char> &code, VDeleter<VkShaderModule> &shaderModule);

  void createCommandPool();

  void createDepthResources();
  VkFormat findDepthFormat();
  VkFormat findSupportedFormat(const std::vector<VkFormat> &candidates, VkImageTiling tiling, VkFormatFeatureFlags features);
  void createImage(uint32_t width, uint32_t height, VkFormat format, VkImageTiling tiling, VkImageUsageFlags usage,
                   VkMemoryPropertyFlags properties, VDeleter<VkImage> &image, VDeleter<VkDeviceMemory> &imageMemory);
  uint32_t findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties);
  void transitionImageLayout(VkImage image, VkFormat format, VkImageLayout oldLayout, VkImageLayout newLayout);
  bool hasStencilComponent(VkFormat format);

  void createFramebuffers();

  void createTextureImage();
  void createSingleTextureImage(TextureInternal *texture);

  void copyImage(VkImage srcImage, VkImage dstImage, uint32_t width, uint32_t height);

  void createTextureImageView();
  void createSingleTextureImageView(TextureInternal *texture);

  void createTextureSampler();
  void createSingleTextureSampler(TextureInternal *texture);

  void createVertexBuffer();
  void createSingleVertexBuffer(MeshInternal *mesh);

  void createBuffer(VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties, VDeleter<VkBuffer> &buffer,
                    VDeleter<VkDeviceMemory> &bufferMemory);
  void copyBuffer(VkBuffer srcBuffer, VkBuffer dstBuffer, VkDeviceSize size);


  void createIndexBuffer();
  void createSingleIndexBuffer(MeshInternal *mesh);

  void createUniformBuffer();
  void createSingleUniformBuffer(MeshInternal *mesh);


  void createDescriptorPool();

  void createDescriptorSet();
  void createSingleDescriptorSet(MeshInternal *mesh);


  void createCommandBuffers();
  VkCommandBuffer beginSingleTimeCommands();
  void endSingleTimeCommands(VkCommandBuffer commandBuffer);

  void createSemaphores();

  void mainLoop();
  long lastTime;

  void updateUniformBuffer();
  void drawFrame();
  void recreateSwapChain();


  std::vector<const char*> getRequiredExtensions();
  bool checkValidationLayerSupport();

  static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback (
      VkDebugReportFlagsEXT flags,
      VkDebugReportObjectTypeEXT objType,
      uint64_t obj,
      size_t location,
      int32_t code,
      const char* layerPrefix,
      const char* msg,
      void* userData) {
    std::cerr << "validationlayer: " << msg << std::endl;

    return VK_FALSE;
  }
};

#endif //VULKANENGINE_VULKANAPPLICATION_H
