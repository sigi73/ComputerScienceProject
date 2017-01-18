//
// Created by siddharth on 1/14/17.
//

#ifndef VULKANENGINE_TEXTUREINTERNAL_H
#define VULKANENGINE_TEXTUREINTERNAL_H

#ifndef VULKAN_COMMON_IMPLEMENTATION
#define VULKAN_COMMON_IMPLEMENTATION
#include "VulkanCommon.h"
#endif

#include "VDeleter.h"
#include "Texture.h"

class TextureInternal {
 public:
  VDeleter<VkImage> textureImage;
  VDeleter<VkDeviceMemory> textureImageMemory;
  VDeleter<VkImageView> textureImageView;
  VDeleter<VkSampler> textureSampler;

  Texture *baseTexture;

  TextureInternal(VDeleter<VkDevice> &device, Texture *inTexture);
};

#endif //VULKANENGINE_TEXTUREINTERNAL_H
