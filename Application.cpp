//
// Created by siddharth on 1/24/17.
//

#include <chrono>
#include "Application.h"


void Application::run() {

  /*
   * Initialize textures and meshes from their paths
   */
  Texture groundTexture(GROUND_TEXTURE_PATH);
  Texture waterTexture(WATER_TEXTURE_PATH);
  Texture treeTexture(TREE_TEXTURE_PATH);
  Texture duckTexture(DUCK_TEXTURE_PATH);
  Texture cloudTexture(CLOUD_TEXTURE_PATH);

  ground = Mesh(GROUND_PATH, &groundTexture);
  water = Mesh(WATER_PATH, &waterTexture);
  tree = Mesh(TREE_PATH, &treeTexture);
  tree2 = Mesh(TREE_PATH, &treeTexture);
  duck = Mesh(DUCK_PATH, &duckTexture);
  cloud = Mesh(CLOUD_PATH, &cloudTexture);


  /*
   * Sets the initial scales and locations for the meshes. Meshes are scaled down as input size was too large
   */

  ground.transform = glm::scale(glm::mat4(), glm::vec3(.2));

  water.transform = glm::scale(glm::mat4(), glm::vec3(.2));

  tree.transform = glm::scale(glm::mat4(), glm::vec3(.2));
  tree.transform = glm::translate(tree.transform, glm::vec3(2.0, -1.9, .8));

  tree2.transform = glm::scale(glm::mat4(), glm::vec3(.2));
  tree2.transform = glm::translate(tree2.transform, glm::vec3(-2.0, 1.9, .6));


  textures.push_back(&groundTexture);
  textures.push_back(&waterTexture);
  textures.push_back(&treeTexture);
  textures.push_back(&duckTexture);
  textures.push_back(&cloudTexture);

  meshes.push_back(&ground);
  meshes.push_back(&water);
  meshes.push_back(&tree);
  meshes.push_back(&tree2);
  meshes.push_back(&duck);
  meshes.push_back(&cloud);

  updateCameraTransform();

  try {
    /*
     * Run the app and start the display loop
     */
    app.run(meshes, textures);
    app.startMainLoop();
  } catch (const std::runtime_error &e) {
    std::cerr << e.what() << std::endl;
  }
}

void Application::onWindowResized(GLFWwindow *window, int width, int height) {
 Application *mainApp = reinterpret_cast<Application*>(glfwGetWindowUserPointer(window));
 VulkanApplication::onWindowResized(window, width, height, &mainApp->app);
}


void Application::key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
 Application *mainApp = reinterpret_cast<Application*>(glfwGetWindowUserPointer(window));
  mainApp->internalKeyCallback(key, scancode, action, mods);
}


void Application::internalKeyCallback(int key, int scancode, int action, int mods) {
 if (key == GLFW_KEY_LEFT) {
  if (action == GLFW_PRESS)
    leftPressed = true;
  else if (action == GLFW_RELEASE)
   leftPressed = false;
 }

 if (key == GLFW_KEY_RIGHT) {
  if (action == GLFW_PRESS)
   rightPressed = true;
  else if (action == GLFW_RELEASE)
   rightPressed = false;
 }

  if (key == GLFW_KEY_UP) {
    if (action == GLFW_PRESS)
      upPressed = true;
    else if (action == GLFW_RELEASE)
      upPressed = false;
  }

  if (key == GLFW_KEY_DOWN) {
    if (action == GLFW_PRESS)
      downPressed = true;
    else if (action == GLFW_RELEASE)
      downPressed = false;
  }

}

void Application::loop(float deltaTime, void *app) {
 Application *application = reinterpret_cast<Application*>(app);
 application->internalLoop(deltaTime);
};

void Application::initWindow(void *app) {
 Application *application = reinterpret_cast<Application*>(app);
 application->internalInitWindow();
}

void Application::internalLoop(float deltaTime) {
  static auto startTime = std::chrono::high_resolution_clock::now();

  auto currentTime = std::chrono::high_resolution_clock::now();
  float time = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - startTime).count() / 1000.0f;


  if (leftPressed) {
   horzCameraRotation -= ROTATION_SPEED * deltaTime;
   updateCameraTransform();
  } else if (rightPressed) {
   horzCameraRotation += ROTATION_SPEED * deltaTime;
   updateCameraTransform();
  }
  if (upPressed) {
    vertCameraRotation += ROTATION_SPEED * deltaTime;
    updateCameraTransform();
  } else if (downPressed) {
    vertCameraRotation -= ROTATION_SPEED * deltaTime;
    updateCameraTransform();
  }


  /*
   * Set the rotation of the duck as a function of time
   */
  duck.transform = glm::scale(glm::mat4(), glm::vec3(.2));
  duck.transform = glm::translate(duck.transform, duckRotationCenter);
  duck.transform = glm::rotate(duck.transform, 0.6f * (float)sin(0.9f * time), glm::vec3(0, 0, 1));

  /*
   * Set the location of the cloud as a function of time
   */
  cloud.transform = glm::scale(glm::mat4(), glm::vec3(.1));
  cloud.transform = glm::translate(cloud.transform, glm::vec3(3.0f * (float)sin(time), 1.2f, 6.0f));
}


void Application::updateCameraTransform() {
  /*
   * Set the location of the camera as a function of horzCameraRotation and vertCameraRotation.
   * Note: glm::lookAt has arguments (vec3 Position, vec3 lookAt, vec3 up)
   * Therefore the camera is always looking at the origin with the Z vector facing up.
   */
 cameraTransform = glm::lookAt(cameraRadius * glm::vec3(cos(horzCameraRotation), cameraRadius * sin(horzCameraRotation), cameraRadius * sin(vertCameraRotation)), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f));
}

void Application::internalInitWindow() {
 glfwSetWindowUserPointer(window, this);
 glfwSetWindowSizeCallback(window, Application::onWindowResized);
 glfwSetKeyCallback(window, Application::key_callback);

}
