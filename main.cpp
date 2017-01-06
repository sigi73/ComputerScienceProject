

#include "VulkanApplication.h"
#include "Mesh.h"


const std::string HOUSE_PATH = "models/chalet.obj";

int main() {

  std::vector<Mesh> meshes;
  Mesh mesh(HOUSE_PATH);
  meshes.push_back(mesh);

  Mesh mesh2(HOUSE_PATH);
  //mesh2.translate(glm::vec3(100, 100, 100));
  mesh2.translate(glm::vec3(0, 0, .5));
  meshes.push_back(mesh2);

  for (int i = 0; i < mesh.vertices.size(); i++) {
    glm::vec3 point = mesh.vertices[i].pos;
    glm::vec3 point2 = mesh2.vertices[i].pos;
    printf("1: %f, %f, %f ", point.x, point.y, point.z);
    printf("2: %f, %f, %f\n", point2.x, point2.y, point2.z);
  }

  VulkanApplication app(800, 600, meshes);

  try {
    app.run();
  } catch (const std::runtime_error &e) {
    std::cerr << e.what() << std::endl;
    //return EXIT_FAILURE;
  }
}