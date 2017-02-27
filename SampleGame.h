//
// Created by siddharth on 2/24/17.
//

#ifndef VULKANENGINE_SAMPLEGAME_H
#define VULKANENGINE_SAMPLEGAME_H

#ifndef GLFW_IMPLEMENTATION
#define GLFW_IMPLEMENTATION
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#endif

#include "VulkanApplication.h"

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/hash.hpp>
#include <map>

class SampleGame {
 public:
  static void loop(float deltaTime, void *app);
  static void onWindowResized(GLFWwindow *window, int width, int height);
  static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
  static void initWindow(void *app);

  void run();

 private:
  void internalLoop(float deltaTime);
  void internalKeyCallback(int key, int scancode, int action, int mods);
  void internalInitWindow();

  void updateCameraTransform();
  float horzCameraRotation = 0.5f;
  float vertCameraRotation = 1.0f;

  glm::mat4 cameraTransform;

  GLFWwindow *window;

  const std::string FLOOR_PATH = "models/floor.obj";
  const std::string BALL_PATH = "models/ball.obj";

  const std::string FLOOR_TEXTURE_PATH = "textures/FloorTexture.png";
  const std::string BALL_TEXTURE_PATH = "textures/BallTexture.png";

  std::vector<Mesh*> meshes;
  std::vector<Texture*> textures;


  VulkanApplication app{800, 600, &cameraTransform, &window, this, SampleGame::loop, SampleGame::initWindow};

  std::vector<Mesh*> floors;
  Mesh ball;
  glm::vec3 ballLocation{0.0f, 0.0f, 5.0f};
  float ballRotation = 0.0f;
  float ballSpeed = 1.0f;
  float ballRotationSpeed = 1.0f;
  float ballMaxY = 4.0f;

  //glm::vec3 bufferInitialLocation{-100.0f, 0.0f, 0.0f};
  //glm::vec3 bufferOffset{0.0f, 100.0f, 0.0f};
  glm::vec3 bufferInitialLocation{0.0f, 0.0f, 0.0f};
  glm::vec3 bufferOffset{0.0f, 1.0f, 0.0f};

  std::map<Mesh*, glm::vec3> bufferLocations;

  bool leftPressed = false;
  bool rightPressed = false;
};

#endif //VULKANENGINE_SAMPLEGAME_H
