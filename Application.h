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
  /*
   * Static functions used as callbacks for events
   */
  static void loop(float deltaTime, void* app);
  static void onWindowResized(GLFWwindow *window, int width, int height);
  static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
  static void initWindow(void *app);

  void run();


 private:
  /*
   * Non static methods for the callbacks. onWindowResized doesn't need one as class variables are not accessed in that method
   */
  void internalLoop(float deltaTime);
  void internalKeyCallback(int key, int scancode, int action, int mods);
  void internalInitWindow();

  /*
   * Updates the transform of the camera based on the values of horzCameraRotation, vertCameraRotation, and cameraRadius.
   */
  void updateCameraTransform();
  float horzCameraRotation = 0.5f;
  float vertCameraRotation = 1.0f;

  float cameraRadius = 1.2f;
  float ROTATION_SPEED = 1.0f;

  glm::mat4 cameraTransform;

  /*
   * Reference to the window for grabbing input
   */
  GLFWwindow *window;

  /*
   * Paths to the mesh files
   */
  const std::string GROUND_PATH = "models/ground.obj";
  const std::string WATER_PATH = "models/water.obj";
  const std::string TREE_PATH = "models/tree.obj";
  const std::string DUCK_PATH = "models/duck.obj";
  const std::string CLOUD_PATH = "models/cloud.obj";

  /*
   * Paths to the texture files
   */
  const std::string GROUND_TEXTURE_PATH = "textures/GroundTexture.png";
  const std::string WATER_TEXTURE_PATH = "textures/WaterTexture.png";
  const std::string TREE_TEXTURE_PATH = "textures/TreeTexture.png";
  const std::string DUCK_TEXTURE_PATH = "textures/DuckTexture.png";
  const std::string CLOUD_TEXTURE_PATH = "textures/CloudTexture.png";

  std::vector<Mesh*> meshes;
  std::vector<Texture*> textures;



  /*
   * Instance of VulkanApplication used for this app
   */
  VulkanApplication app{800, 600, &cameraTransform, &window, this, Application::loop, Application::initWindow};

  /*
   * Meshes used in this demo
   */
  Mesh ground;
  Mesh water;
  Mesh tree;
  Mesh tree2;
  Mesh duck;
  Mesh cloud;
  glm::vec3 duckRotationCenter{0.4, -1.5, 0.6};


  /*
   * Used to hold input state for moving the camera
   */
  bool leftPressed = false;
  bool rightPressed = false;
  bool upPressed = false;
  bool downPressed = false;

};

#endif //VULKANENGINE_APPLICATION_H
