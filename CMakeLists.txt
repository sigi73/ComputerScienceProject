cmake_minimum_required(VERSION 3.6)
project(VulkanEngine)

set(VULKAN_SDK_PATH "Packages/VulkanSDK/1.0.30.0/x86_64")
set(STB_INCLUDE_PATH "Packages/stb")
set(TINYOBJ_INCLUDE_PATH "Packages/tinyobjloader")
set(GLM_INCLUDE_PATH "Packages/glm")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

file(COPY models DESTINATION .)
file(COPY shaders DESTINATION .)
file(COPY textures DESTINATION .)

include_directories(${VULKAN_SDK_PATH}/include)
include_directories(${STB_INCLUDE_PATH})
include_directories(${TINYOBJ_INCLUDE_PATH})
include_directories(${GLM_INCLUDE_PATH})
#include_directories("Packages/glfw/include")

link_directories("${VULKAN_SDK}/lib")
link_directories("${VULKAN_SDK}/explicit_layer.d")

#find_package(glfw3 3.2 REQUIRED)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(Packages/glfw)


set(SOURCE_FILES main.cpp VDeleter.cpp VDeleter.h VulkanCommon.h Mesh.cpp Mesh.h VulkanCommon.cpp VulkanApplication.cpp VulkanApplication.h MeshInternal.cpp MeshInternal.h Texture.cpp Texture.h TextureInternal.cpp TextureInternal.h Application.cpp Application.h)
add_executable(VulkanEngine ${SOURCE_FILES})
target_link_libraries(VulkanEngine glfw)
target_link_libraries(VulkanEngine vulkan)
