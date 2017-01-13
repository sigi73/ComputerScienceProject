

#include "VulkanApplication.h"


const std::string HOUSE_PATH = "models/chalet.obj";

int main() {

  Texture houseTexture;

  std::vector<Mesh> meshes;
  Mesh mesh(HOUSE_PATH, houseTexture);
  meshes.push_back(mesh);

  Mesh mesh2(HOUSE_PATH);
  //mesh2.translate(glm::vec3(100, 100, 100));
  mesh2.translate(glm::vec3(0, 1, .5));
  meshes.push_back(mesh2);



  VulkanApplication app(800, 600, meshes);

  try {
    app.run();
  } catch (const std::runtime_error &e) {
    std::cerr << e.what() << std::endl;
    //return EXIT_FAILURE;
  }
}