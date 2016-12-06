cmake_minimum_required(VERSION 3.6)
project(VulkanEngine)

set(VULKAN_SDK_PATH "Packages/VulkanSDK/1.0.30.0/x86_64")
set(STB_INCLUDE_PATH "Packages/stb")
set(TINYOBJ_INCLUDE_PATH "Packages/tinyobjloader")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

include_directories(${VULKAN_SDK_PATH}/include)
include_directories(${STB_INCLUDE_PATH})
include_directories(${TINYOBJ_INCLUDE_PATH})
include_directories("Packages/glfw/include")

link_directories("${VULKAN_SDK}/lib")
link_directories("${VULKAN_SDK}/explicit_layer.d")

find_package(glfw3 3.2 REQUIRED)

set(SOURCE_FILES main.cpp VDeleter.cpp VDeleter.h VulkanCommon.h)
add_executable(VulkanEngine ${SOURCE_FILES})
target_link_libraries(VulkanEngine glfw)
target_link_libraries(VulkanEngine vulkan)