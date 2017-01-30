//
// Created by siddharth on 1/24/17.
//

#ifndef VULKANENGINE_APPLICATION_H
#define VULKANENGINE_APPLICATION_H

#ifndef GLFW_IMPLEMENTATION
#define GLFW_IMPLEMENTATION
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#endif

#include "VulkanApplication.h"

//#include "Mesh.h"
//#include "Texture.h"

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/hash.hpp>

class Application {

 public:
  static void loop(float deltaTime, void* app);
  static void onWindowResized(GLFWwindow *window, int width, int height);
  static void cursor_pos_callback(GLFWwindow *window, double xpos, double ypos);
  static void mouse_button_callback(GLFWwindow *window, double xpos, double ypos);
  static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
  static void initWindow(void *app);

  void run();


 private:
  void internalLoop(float deltaTime);
  void internalKeyCallback(int key, int scancode, int action, int mods);
  void internalInitWindow();
  void updateCameraTransform();

  GLFWwindow *window;
  glm::mat4 cameraTransform;

  std::vector<Mesh*> meshes;
  std::vector<Texture*> textures;


  const std::string GROUND_PATH = "models/ground.obj";
  const std::string WATER_PATH = "models/water.obj";
  const std::string TREE_PATH = "models/tree.obj";
  const std::string DUCK_PATH = "models/duck.obj";

  const std::string GROUND_TEXTURE_PATH = "textures/GroundTexture.png";
  const std::string WATER_TEXTURE_PATH = "textures/WaterTexture.png";
  const std::string TREE_TEXTURE_PATH = "textures/TreeTexture.png";
  const std::string DUCK_TEXTURE_PATH = "textures/DuckTexture.png";

  float ROTATION_SPEED = 1.0f;

  VulkanApplication app{800, 600, &cameraTransform, &window, this, Application::loop, Application::initWindow};

  Mesh duck;

  float cameraRotation = 0.0f;

  bool leftPressed = false;
  bool rightPressed = false;

};

#endif //VULKANENGINE_APPLICATION_H
