//
// Created by siddharth on 1/24/17.
//

#include <chrono>
#include "Application.h"


void Application::run() {
 Texture houseTexture(HOUSE_TEXTURE_PATH);
 Texture cubeTexture(CUBE_TEXTURE_PATH);

 //textures.push_back(&houseTexture);
 textures.push_back(&cubeTexture);


 Mesh house = Mesh(HOUSE_PATH, &houseTexture);
 cube = Mesh(CUBE_PATH, &cubeTexture);

 //meshes.push_back(&house);
 meshes.push_back(&cube);

 cube.transform = glm::translate(glm::mat4(), glm::vec3(0, 1, .5));

 cameraTransform = glm::lookAt(glm::vec3(2.0f, 2.0f, 2.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f));



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
 if (key == GLFW_KEY_M) {
  if (action == GLFW_PRESS) {
  }
  else if (action == GLFW_RELEASE) {
    bumped = true;
  }
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
 cube.transform = glm::translate(glm::mat4(), glm::vec3(1, 0, 0));
 cube.transform = glm::scale(cube.transform, glm::vec3(0.2f * ((float)sin(time) + 1.5f)));

 if (bumped) {
  bumped = false;
  Texture test(CUBE_TEXTURE_PATH);
  Mesh cube2(CUBE_PATH, &test);
  cube2.transform = glm::translate(glm::mat4(), glm::vec3(0, 1, 0));
  printf("Doing the thing\n");
  app.addMesh(&cube2);
 }
}

void Application::internalInitWindow() {
 glfwSetWindowUserPointer(window, this);
 glfwSetWindowSizeCallback(window, Application::onWindowResized);
 glfwSetKeyCallback(window, Application::key_callback);

}
