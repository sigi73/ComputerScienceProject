//
// Created by siddharth on 1/10/17.
//

#ifndef VULKANENGINE_MESHINTERNAL_H
#define VULKANENGINE_MESHINTERNAL_H



#ifndef VULKAN_COMMON_IMPLEMENTATION
#define VULKAN_COMMON_IMPLEMENTATION
#include "VulkanCommon.h"
#endif

#include "Mesh.h"
#include "VDeleter.h"
#include "Texture.h"


class MeshInternal {

  std::vector<Vertex> vertices;
  std::vector<uint32_t> indices;

  VDeleter<VkBuffer> vertexBuffer;
  VDeleter<VkDeviceMemory> vertexBufferMemory;
  VDeleter<VkBuffer> indexBuffer;
  VDeleter<VkDeviceMemory> indexBufferMemory;

  VDeleter<VkBuffer> uniformStagingBuffer;
  VDeleter<VkDeviceMemory> uniformStagingBufferMemory;
  VDeleter<VkBuffer> uniformBuffer;
  VDeleter<VkDeviceMemory>uniformBufferMemory;

  Texture texture;

  MeshInternal(Mesh mesh, VDeleter<VkDevice> device, Texture inputTexture);

  void updateUBO();
};

#endif //VULKANENGINE_MESHINTERNAL_H
