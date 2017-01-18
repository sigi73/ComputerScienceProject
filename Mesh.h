//
// Created by siddharth on 1/4/17.
//


#ifndef VULKANENGINE_MESH_H
#define VULKANENGINE_MESH_H

/*
#ifndef VULKAN_COMMON_IMPLEMENTATION
#define VULKAN_COMMON_IMPLEMENTATION
#include "VulkanCommon.h"
#endif

#include "VDeleter.h"
 */

#include <vector>
#include <string>
#include <unordered_map>
#include <glm/glm.hpp>

struct Vertex;

class Mesh {

 public:
  std::vector<Vertex> vertices;
  std::vector<uint32_t> indices;

  glm::mat4 transform;

  int textureIndex;

  /*
  VDeleter<VkBuffer> vertexBuffer;
  VDeleter<VkDeviceMemory> vertexBufferMemory;
  VDeleter<VkBuffer> indexBuffer;
  VDeleter<VkDeviceMemory> indexBufferMemory;

  VDeleter<VkBuffer> uniformStagingBuffer;
  VDeleter<VkDeviceMemory> uniformStagingBufferMemory;
  VDeleter<VkBuffer> uniformBuffer;
  VDeleter<VkDeviceMemory>uniformBufferMemory;

  VkDescriptorSet descriptorSet;
   */

  Mesh(std::string path, int inputTextureIndex);

  void translate(glm::vec3 vector);
};

#endif //VULKANENGINE_MESH_H
