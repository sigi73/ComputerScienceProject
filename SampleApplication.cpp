//
// Created by siddharth on 1/18/17.
//

#include <chrono>
#include "SampleApplication.h"


SampleApplication::SampleApplication() :
  mesh(HOUSE_PATH, 0),
  mesh2(CUBE_PATH, 1),
  app()
{

}

void SampleApplication::init() {
  std::vector<Mesh*> meshes;
  std::vector<Texture*> textures;

  Texture houseTexture(HOUSE_TEXTURE_PATH);
  textures.push_back(&houseTexture);

  Texture cubeTexture(CUBE_TEXTURE_PATH);
  textures.push_back(&cubeTexture);

  meshes.push_back(&mesh);

  //mesh2.translate(glm::vec3(0, 1, .5));
  mesh2.transform = glm::translate(glm::mat4(), glm::vec3(0, 1, .5));
  mesh2.transform = glm::scale(mesh2.transform, glm::vec3(0.2, 0.2, 0.2));
  meshes.push_back(&mesh2);


  cameraTransform = glm::lookAt(glm::vec3(2.0f, 2.0f, 2.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f));
  app = VulkanApplication(800, 600, meshes, textures, &cameraTransform, &window, SampleApplication::loop);


  try {
    app.run();
    glfwSetCursorPosCallback(window, SampleApplication::cursorPosCallback);
    glfwSetMouseButtonCallback(window, SampleApplication::mouseButtonCallback);
    glfwSetWindowSizeCallback(window, VulkanApplication::onWindowResized);
    app.startMainLoop();
  } catch (const std::runtime_error &e) {
    std::cerr << e.what() << std::endl;
  }
}

void SampleApplication::loop(float deltaTime) {
  static auto startTime = std::chrono::high_resolution_clock::now();

  auto currentTime = std::chrono::high_resolution_clock::now();
  float time = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - startTime).count() / 1000.0f;
  //mesh2.transform = glm::scale(mesh2.transform, glm::vec3((float)sin(time)));
  mesh2.transform = glm::translate(glm::mat4(), glm::vec3(1, 0, 0));
  mesh2.transform = glm::scale(mesh2.transform, glm::vec3(0.2f * ((float)sin(time) + 1.5f)));
  //std::cout<<"1:"<<glm::to_string(mesh2.transform)<<std::endl;

}

void SampleApplication::cursorPosCallback(GLFWwindow *window, double xpos, double ypos) {

}

void SampleApplication::mouseButtonCallback(GLFWwindow *window, int button, int action, int mods) {

}