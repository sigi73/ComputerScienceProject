//
// Created by siddharth on 1/10/17.
//

#include "Texture.h"
#ifndef INCLUDING_STB_IMAGE
#define INCLUDING_STB_IMAGE
//#ifndef STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
//#endif
#include <stb_image.h>
#include <stdexcept>
#endif

Texture::Texture() {
}

Texture::Texture(std::string path) {
 pixels = stbi_load(path.c_str(), &texWidth, &texHeight, &texChannels, STBI_rgb_alpha);
 if (!pixels) {
  throw std::runtime_error("Failed to load texture image");
 }
}
