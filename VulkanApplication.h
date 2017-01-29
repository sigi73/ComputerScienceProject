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

  void addMesh(Mesh *newMesh);
  void deleteMesh(Mesh *toDelete);

  static void onWindowResized(GLFWwindow *window, int width, int height, VulkanApplication *app);
  //static void cursor_pos_callback(GLFWwindow *window, double xpos, double ypos);
  //static void mouse_button_callback(GLFWwindow *window, int button, int action, int mods);

 private:

  void *app;
  int WIDTH;
  int HEIGHT;

  void (*userLoop)(float, void *app);
  void (*windowSetup)(void *app);

  const std::vector<const char*> validationLayers = {
      "VK_LAYER_LUNARG_standard_validation"
  };


  const std::vector<const char*> deviceExtensions = {
      VK_KHR_SWAPCHAIN_EXTENSION_NAME
  };


#define DEBUGGING_STATEMENTS
#ifdef DEBUGGING_STATEMENTS     //Used to set defines for printing
  //diagnostic information
#define ENUMERATE_EXTENSIONS
  const bool enableValidationLayers = true;
#else
  const bool enableValidationLayers = false;
#endif //DEBUGGING_STATEMENTS

  GLFWwindow *window;
  GLFWwindow **userWindow;
  GLFWcursor *standardCursor;

  VDeleter<VkInstance> instance{vkDestroyInstance};
  VDeleter<VkDebugReportCallbackEXT> callback{instance, DestroyDebugReportCallbackEXT};
  VDeleter<VkSurfaceKHR> surface{instance, vkDestroySurfaceKHR};

  VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
  VDeleter<VkDevice> device{vkDestroyDevice};


  std::vector<Mesh*> inputMeshes;
  std::vector<MeshInternal> meshes;

  std::vector<Texture*> inputTextures;
  std::vector<TextureInternal> textures;


  glm::mat4 *cameraTransform;

  VkQueue graphicsQueue;
  VkQueue presentQueue;

  VDeleter<VkSwapchainKHR> swapChain{device, vkDestroySwapchainKHR};
  std::vector<VkImage> swapChainImages;
  VkFormat swapChainImageFormat;
  VkExtent2D swapChainExtent;

  std::vector<VDeleter<VkImageView>> swapChainImageViews;

  VDeleter<VkRenderPass> renderPass{device, vkDestroyRenderPass};

  VDeleter<VkDescriptorSetLayout> descriptorSetLayout{device,
                                                      vkDestroyDescriptorSetLayout};
  VDeleter<VkPipelineLayout> pipelineLayout{device, vkDestroyPipelineLayout};

  VDeleter<VkPipeline> graphicsPipeline{device, vkDestroyPipeline};

  std::vector<VDeleter<VkFramebuffer>> swapChainFramebuffers;
  VDeleter<VkCommandPool> commandPool{device, vkDestroyCommandPool};

  std::vector<VkCommandBuffer> commandBuffers;

  VDeleter<VkSemaphore> imageAvailableSemaphore{device, vkDestroySemaphore};
  VDeleter<VkSemaphore> renderFinishedSemaphore{device, vkDestroySemaphore};

  //VDeleter<VkImage> textureImage{device, vkDestroyImage};
  //VDeleter<VkDeviceMemory> textureImageMemory{device, vkFreeMemory};

  /*
  std::vector<Vertex> vertices;
  std::vector<uint32_t> indices;

  VDeleter<VkBuffer> vertexBuffer{device, vkDestroyBuffer};
  VDeleter<VkDeviceMemory> vertexBufferMemory{device, vkFreeMemory};
  VDeleter<VkBuffer> indexBuffer{device, vkDestroyBuffer};
  VDeleter<VkDeviceMemory> indexBufferMemory{device, vkFreeMemory};

  VDeleter<VkBuffer> uniformStagingBuffer{device, vkDestroyBuffer};
  VDeleter<VkDeviceMemory> uniformStagingBufferMemory{device, vkFreeMemory};
  VDeleter<VkBuffer> uniformBuffer{device, vkDestroyBuffer};
  VDeleter<VkDeviceMemory>uniformBufferMemory{device, vkFreeMemory};
  */

  VDeleter<VkDescriptorPool> descriptorPool{device, vkDestroyDescriptorPool};
  //VkDescriptorSet descriptorSet;

  //VDeleter<VkImageView> textureImageView{device, vkDestroyImageView};

  //VDeleter<VkSampler> textureSampler{device, vkDestroySampler};

  VDeleter<VkImage> depthImage{device, vkDestroyImage};
  VDeleter<VkDeviceMemory> depthImageMemory{device, vkFreeMemory};
  VDeleter<VkImageView> depthImageView{device, vkDestroyImageView};

  //bool leftDown = false;
  //double startX = 0.0d;
  //double startY = 0.0d;

  //float modelRotation = 0.0f;

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

  //void addMesh(Mesh *mesh); //@TODO: To do this, need to create Uniform Buffer, descriptorSet, vertexBuffer, indexBuffer, and record commandBuffer.
  //void deleteMesh(Mesh *mesh); //@TODO: To do this, need to delete the MeshInternal object and record commandBuffer.

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
