//
// Created by siddharth on 1/10/17.
//

#include "MeshInternal.h"

MeshInternal::MeshInternal(VDeleter<VkDevice> &device, Mesh &mesh) :
  vertexBuffer{device, vkDestroyBuffer},
  vertexBufferMemory{device, vkFreeMemory},
  indexBuffer{device, vkDestroyBuffer},
  indexBufferMemory{device, vkFreeMemory},
  uniformStagingBuffer{device, vkDestroyBuffer},
  uniformStagingBufferMemory{device, vkFreeMemory},
  uniformBuffer{device, vkDestroyBuffer},
  uniformBufferMemory{device, vkFreeMemory}

{
  vertices.insert(vertices.end(), mesh.vertices.begin(), mesh.vertices.end());
  indices.insert(indices.end(), mesh.indices.begin(), mesh.indices.end());
  textureIndex = mesh.textureIndex;
}

void MeshInternal::updateUBO() {

}
