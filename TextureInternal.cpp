//
// Created by siddharth on 1/14/17.
//

#include "TextureInternal.h"

TextureInternal::TextureInternal(VDeleter<VkDevice> &device, Texture &inTexture) :
  textureImage{device, vkDestroyImage},
  textureImageMemory{device, vkFreeMemory},
  textureImageView{device, vkDestroyImageView},
  textureSampler{device, vkDestroySampler},
  baseTexture()
{
  baseTexture = inTexture;
}
