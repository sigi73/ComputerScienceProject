//
// Created by siddharth on 1/10/17.
//

#pragma once

#ifndef VULKANENGINE_TEXTURE_H
#define VULKANENGINE_TEXTURE_H

#include <string>
#include "VDeleter.h"


typedef unsigned char stbi_uc;

class Texture {
 public:
  Texture();
  Texture(std::string path);

  stbi_uc *pixels;

  int texWidth;
  int texHeight;
  int texChannels;

};

#endif //VULKANENGINE_TEXTURE_H
