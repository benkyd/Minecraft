#ifndef MINECRAFT_RENDERING_TEXTURE_H_
#define MINECRAFT_RENDERING_TEXTURE_H_

#include <vector>
#include <string>

#include <glad/glad.h>

class Texture {
public:
    GLuint LoadTextures(std::vector<std::string> textures);
};

#endif
