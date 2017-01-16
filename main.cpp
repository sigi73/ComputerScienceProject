

#include "VulkanApplication.h"

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/hash.hpp>


const std::string HOUSE_TEXTURE_PATH = "textures/chalet.jpg";
const std::string HOUSE_PATH = "models/chalet.obj";

const std::string CUBE_TEXTURE_PATH = "textures/cube.jpg";
const std::string CUBE_PATH = "models/cube.obj";

int main() {

  std::vector<Mesh> meshes;
  std::vector<Texture> textures;

  Texture houseTexture(HOUSE_TEXTURE_PATH);
  textures.push_back(houseTexture);

  Texture cubeTexture(CUBE_TEXTURE_PATH);
  textures.push_back(cubeTexture);

  Mesh mesh(HOUSE_PATH, 0);
  meshes.push_back(mesh);

  Mesh mesh2(CUBE_PATH, 1);
  mesh2.translate(glm::vec3(0, 1, .5));
  meshes.push_back(mesh2);


  VulkanApplication app(800, 600, meshes, textures);

  try {
    app.run();
  } catch (const std::runtime_error &e) {
    std::cerr << e.what() << std::endl;
    //return EXIT_FAILURE;
  }
}