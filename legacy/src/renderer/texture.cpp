#include "texture.hpp"

#include <logger.h>

#include "../config.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "../util/stb_image.hpp"

GLuint Texture::LoadTextures(std::vector<std::string> textures) {

    Logger logger;

    std::string basePath = GameConfig.ResourceBase + "textures/";

    int x = 16;
    int y = 16;

	GLsizei layers = textures.size();
	GLubyte* texels = (GLubyte*)malloc(x * y * 4 * layers * sizeof(GLubyte));

    for (int i = 0; i < layers; i++) {

        std::string path = basePath + textures[i];

        int xR = 0;
        int yR = 0;
        int cR = 0;

        unsigned char* texture = stbi_load(path.c_str(), &xR, &yR, &cR, STBI_rgb_alpha);

		memcpy(texels + (i * x * y * 4), texture, x * y * 4);

		stbi_image_free(texture);
        logger << LOGGER_INFO << "Texture at '" << path << "' Loaded..." << LOGGER_ENDL;
        
    }

	GLuint textureArray = 0;

	glGenTextures(1, &textureArray);
	glBindTexture(GL_TEXTURE_2D_ARRAY, textureArray);

	glTexImage3D(GL_TEXTURE_2D_ARRAY, 0, GL_RGBA8, x, y, layers, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);

	glTexSubImage3D(GL_TEXTURE_2D_ARRAY, 0, 0, 0, 0, x, y, layers, GL_RGBA, GL_UNSIGNED_BYTE, texels);

	glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	glBindTexture(GL_TEXTURE_2D_ARRAY, 0);

	free(texels);

	return textureArray;

}
