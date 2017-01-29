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

  GLFWwindow *window;
  glm::mat4 cameraTransform;
  glm::vec3 cameraPos{0.0f, 0.0f, 0.0f};
  glm::vec3 cameraDirection{0.0f, 0.0f, 0.0f};
  glm::vec2 cameraAngles{0.0f, 0.0f};

  bool moveForward = false;
  bool moveBackward = false;
  bool moveLeft = false;
  bool moveRight = false;
  bool moveUp = false;
  bool moveDown = false;

  std::vector<Mesh*> meshes;
  std::vector<Texture*> textures;

  const std::string HOUSE_TEXTURE_PATH = "textures/chalet.jpg";
  const std::string HOUSE_PATH = "models/chalet.obj";

  const std::string CUBE_TEXTURE_PATH = "textures/cube.jpg";
  const std::string CUBE_PATH = "models/cube.obj";

  //VulkanApplication app{800, 600, &meshes, &textures, &cameraTransform, &window, Application::loop};
  VulkanApplication app{800, 600, &cameraTransform, &window, this, Application::loop, Application::initWindow};


  //Meshes
  Mesh cube;


  bool bumped = false;
};

#endif //VULKANENGINE_APPLICATION_H
