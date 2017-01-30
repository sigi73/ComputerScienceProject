//
// Created by siddharth on 1/24/17.
//

#include <chrono>
#include "Application.h"


void Application::run() {

 Texture groundTexture(GROUND_TEXTURE_PATH);
 Texture waterTexture(WATER_TEXTURE_PATH);
 Texture treeTexture(TREE_TEXTURE_PATH);
 Texture duckTexture(DUCK_TEXTURE_PATH);

 Mesh ground(GROUND_PATH, &groundTexture);
 Mesh water(WATER_PATH, &waterTexture);
 Mesh tree(TREE_PATH, &treeTexture);
 Mesh tree2(TREE_PATH, &treeTexture);
 duck = Mesh(DUCK_PATH, &duckTexture);

  ground.transform = glm::scale(glm::mat4(), glm::vec3(.2, .2, .2));
  water.transform = glm::scale(glm::mat4(), glm::vec3(.2, .2, .2));
  tree.transform = glm::scale(glm::mat4(), glm::vec3(.2, .2, .2));
  tree2.transform = glm::scale(glm::mat4(), glm::vec3(.2, .2, .2));
  duck.transform = glm::scale(glm::mat4(), glm::vec3(.2, .2, .2));


 textures.push_back(&groundTexture);
 textures.push_back(&waterTexture);
 textures.push_back(&treeTexture);
 textures.push_back(&duckTexture);
 meshes.push_back(&ground);
 meshes.push_back(&water);

 meshes.push_back(&tree);
 meshes.push_back(&duck);



 updateCameraTransform();


 try {
  app.run(meshes, textures);
  app.startMainLoop();
 } catch (const std::runtime_error &e) {
  std::cerr << e.what() << std::endl;
 }
}

void Application::onWindowResized(GLFWwindow *window, int width, int height) {
 Application *mainApp = reinterpret_cast<Application*>(glfwGetWindowUserPointer(window));
 //VulkanApplication::onWindowResized(window, width, height, &mainApp->app);
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
  cameraRotation -= ROTATION_SPEED * deltaTime;
  updateCameraTransform();
 } else if (rightPressed) {
  cameraRotation += ROTATION_SPEED * deltaTime;
  updateCameraTransform();
 }

 duck.transform = glm::scale(glm::mat4(), glm::vec3(.2));
 duck.transform = glm::translate(duck.transform, glm::vec3(0.6f * (float)sin(time), 0.0f, 0.0f));

}


void Application::updateCameraTransform() {
 cameraTransform = glm::lookAt(glm::vec3(cos(cameraRotation), sin(cameraRotation), 1.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f));
}
void Application::internalInitWindow() {
 glfwSetWindowUserPointer(window, this);
 glfwSetWindowSizeCallback(window, Application::onWindowResized);
 glfwSetKeyCallback(window, Application::key_callback);

}
