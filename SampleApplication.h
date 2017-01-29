//
// Created by siddharth on 1/18/17.
//

#ifndef VULKANENGINE_SAMPLEAPPLICATION_H
#define VULKANENGINE_SAMPLEAPPLICATION_H

#include <string>
#include <GLFW/glfw3.h>
#include "Mesh.h"
#include "VulkanApplication.h"

class SampleApplication {
 public:
  std::string HOUSE_TEXTURE_PATH = "textures/chalet.jpg";
  std::string HOUSE_PATH = "models/chalet.obj";

  std::string CUBE_TEXTURE_PATH = "textures/cube.jpg";
  std::string CUBE_PATH = "models/cube.obj";

  SampleApplication();

  Mesh mesh;
  Mesh mesh2;

  GLFWwindow *window;

  VulkanApplication app;

  glm::mat4 cameraTransform;

  void init();
  void loop(float deltaTime);
  static void cursorPosCallback(GLFWwindow *window, double xpos, double ypos);
  static void mouseButtonCallback(GLFWwindow *window, int button, int action, int mods);
};

#endif //VULKANENGINE_SAMPLEAPPLICATION_H
