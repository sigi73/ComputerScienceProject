//
// Created by siddharth on 1/4/17.
//


#ifndef VULKANENGINE_MESH_H
#define VULKANENGINE_MESH_H

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

  Texture texture;

  Mesh();
  Mesh(std::string path);

  void translate(glm::vec3 vector);
};

#endif //VULKANENGINE_MESH_H
