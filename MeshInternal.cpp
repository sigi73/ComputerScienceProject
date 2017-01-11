//
// Created by siddharth on 1/10/17.
//

#include "MeshInternal.h"

MeshInternal::MeshInternal(Mesh mesh, VDeleter<VkDevice> device, Texture inputTexture) :
  vertexBuffer{device, vkDestroyBuffer},
  vertexBufferMemory{device, vkFreeMemory},
  indexBuffer{device, vkDestroyBuffer},
  indexBufferMemory{device, vkFreeMemory},
  uniformStagingBuffer{device, vkDestroyBuffer},
  uniformStagingBufferMemory{device, vkFreeMemory},
  uniformBuffer{device, vkDestroyBuffer},
  uniformBufferMemory{device, vkDestroyBuffer}
{
  //vertexBuffer(device, vkDestroyBuffer);
  texture = inputTexture;
}

void MeshInternal::updateUBO() {

}
