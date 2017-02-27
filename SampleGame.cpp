//
// Created by siddharth on 2/24/17.
//

#include <chrono>
#include "SampleGame.h"

void SampleGame::run() {
  Texture floorTexture(FLOOR_TEXTURE_PATH);
  Texture ballTexture(BALL_TEXTURE_PATH);

  Mesh floor1 = Mesh(FLOOR_PATH, &floorTexture);
  Mesh floor2 = Mesh(FLOOR_PATH, &floorTexture);
  ball = Mesh(BALL_PATH, &ballTexture);

  ball.transform = glm::mat4();
  textures.push_back(&ballTexture);
  textures.push_back(&floorTexture);
  meshes.push_back(&ball);
  meshes.push_back(&floor1);
  //meshes.push_back(&floor2);

  floors.push_back(&floor1);
  floors.push_back(&floor2);

  ball.transform = glm::translate(glm::mat4(), ballLocation);
  //cameraTransform = glm::lookAt(glm::vec3(-1.0f, 0.0f, 50.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f));
  updateCameraTransform();

  int index = 0;
  for (Mesh* floor : floors) {
    bufferLocations[floor] = glm::vec3(bufferInitialLocation.x + bufferOffset.x * index, bufferInitialLocation.y + bufferOffset.y * index, bufferInitialLocation.z + bufferOffset.z * index);
    floor->transform = glm::translate(glm::mat4(), bufferLocations[floor]);
    index++;
  }

  try {
    app.run(meshes, textures);
    app.startMainLoop();
  } catch (const std::runtime_error &e) {
    std::cerr << e.what() << std::endl;
  }

}

void SampleGame::onWindowResized(GLFWwindow *window, int width, int height) {
  SampleGame *game = reinterpret_cast<SampleGame*>(glfwGetWindowUserPointer(window));
  VulkanApplication::onWindowResized(window, width, height, &game->app);
}

void SampleGame::key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
  SampleGame *game = reinterpret_cast<SampleGame*>(glfwGetWindowUserPointer(window));
  game->internalKeyCallback(key, scancode, action, mods);
}

void SampleGame::loop(float deltaTime, void *app) {
  SampleGame *game = reinterpret_cast<SampleGame*>(app);
  game->internalLoop(deltaTime);
}

void SampleGame::initWindow(void *app) {
  SampleGame *game = reinterpret_cast<SampleGame*>(app);
  game->internalInitWindow();
}

void SampleGame::internalKeyCallback(int key, int scancode, int action, int mods) {
  if (key == GLFW_KEY_LEFT || key == GLFW_KEY_A) {
    if (action == GLFW_PRESS)
      leftPressed = true;
    else if (action == GLFW_RELEASE)
      leftPressed = false;
  }

  if (key == GLFW_KEY_RIGHT || key == GLFW_KEY_D) {
    if (action == GLFW_PRESS)
      rightPressed = true;
    else if (action == GLFW_RELEASE)
      rightPressed = false;
  }
}

void SampleGame::internalLoop(float deltaTime) {
  static auto startTime = std::chrono::high_resolution_clock::now();

  auto currentTime = std::chrono::high_resolution_clock::now();
  float time = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - startTime).count() / 1000.0f;

  ballLocation.x += deltaTime * ballSpeed;
  if (rightPressed) {
    ballLocation.y -= deltaTime * ballSpeed;
    if (ballLocation.y < -ballMaxY)
      ballLocation.y = -ballMaxY;
  }
  else if (leftPressed) {
    ballLocation.y += deltaTime * ballSpeed;
    if (ballLocation.y > ballMaxY)
      ballLocation.y = ballMaxY;
  }

  ballRotation += ballRotationSpeed * deltaTime;
  if (ballRotation > 360) ballRotation -= 360.0f;
  ball.transform = glm::translate(glm::mat4(), ballLocation);
  ball.transform = glm::rotate(ball.transform, ballRotation, glm::vec3(0.0f, 1.0f, 0.0f));

  updateCameraTransform();
}

void SampleGame::updateCameraTransform() {
  cameraTransform = glm::lookAt(ballLocation + glm::vec3(-1.0f, 0.0f, 50.0f), ballLocation, glm::vec3(0.0f, 0.0f, 1.0f));
}

void SampleGame::internalInitWindow() {
  glfwSetWindowUserPointer(window, this);
  glfwSetWindowSizeCallback(window, SampleGame::onWindowResized);
  glfwSetKeyCallback(window, SampleGame::key_callback);
}
