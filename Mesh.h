//
// Created by siddharth on 1/4/17.
//


#ifndef VULKANENGINE_MESH_H
#define VULKANENGINE_MESH_H


#include "VDeleter.h"


#include <vector>
#include <string>
#include <unordered_map>
#include <glm/glm.hpp>
#include "Texture.h"

struct Vertex;

class Mesh {

 public:
  std::vector<Vertex> vertices;
  std::vector<uint32_t> indices;

  glm::mat4 transform;

  //int textureIndex;
  Texture *texture;



  Mesh(std::string path, int inputTextureIndex);
  Mesh(std::string path, Texture *inputTexture);
  Mesh();

  void translate(glm::vec3 vector);
};

#endif //VULKANENGINE_MESH_H
