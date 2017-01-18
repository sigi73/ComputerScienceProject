

#include "VulkanApplication.h"

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/hash.hpp>
#include <glm/ext.hpp>
#include <chrono>

const std::string HOUSE_TEXTURE_PATH = "textures/chalet.jpg";
const std::string HOUSE_PATH = "models/chalet.obj";

const std::string CUBE_TEXTURE_PATH = "textures/cube.jpg";
const std::string CUBE_PATH = "models/cube.obj";

Mesh mesh(HOUSE_PATH, 0);
Mesh mesh2(CUBE_PATH, 1);
glm::mat4 cameraTransform;
GLFWwindow *window;


void loop(float deltaTime) {
  static auto startTime = std::chrono::high_resolution_clock::now();

  auto currentTime = std::chrono::high_resolution_clock::now();
  float time = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - startTime).count() / 1000.0f;
  //mesh2.transform = glm::scale(mesh2.transform, glm::vec3((float)sin(time)));
  mesh2.transform = glm::translate(glm::mat4(), glm::vec3(1, 0, 0));
  mesh2.transform = glm::scale(mesh2.transform, glm::vec3(0.2f * ((float)sin(time) + 1.5f)));
  //std::cout<<"1:"<<glm::to_string(mesh2.transform)<<std::endl;

  glm::mat4 temp = glm::lookAt(glm::vec3(2.0f, 2.0f, 2.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f));
  cameraTransform = glm::translate(temp, glm::vec3(0, 0, 0.2f * ((float)sin(1.3f * time) + 1.5f)));

  //printf("%f\n", (float)sin(time));
  //printf("%f, %f\n", time, deltaTime);
}



void cursor_pos_callback(GLFWwindow *window, double xpos, double ypos) {

}


void mouse_button_callback(GLFWwindow *window, int button, int action, int mods) {

}

int main() {
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
  VulkanApplication app(800, 600, meshes, textures, &cameraTransform, window, loop);

  //glfwSetCursorPosCallback(window, cursor_pos_callback);
  //glfwSetMouseButtonCallback(window, mouse_button_callback);

  try {
    app.run();
  } catch (const std::runtime_error &e) {
    std::cerr << e.what() << std::endl;
    //return EXIT_FAILURE;
  }
}


