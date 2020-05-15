#ifndef MINECRAFT_RENDERER_TEXTURE_H_
#define MINECRAFT_RENDERER_TEXTURE_H_

#include "../common.hpp"

class Texture {
public:
    GLuint LoadTextures(std::vector<std::string> textures);
};

#endif
