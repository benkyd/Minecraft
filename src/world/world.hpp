#ifndef MINECRAFT_WORLD_WORLD_H_
#define MINECRAFT_WORLD_WORLD_H_

#include "../common.hpp"

class Shader;
class Face;

class World {
public:

	std::map<std::string, std::shared_ptr<Shader>> Shaders;
	std::vector<std::shared_ptr<Face>> Faces;

	GLuint TextureID;

};

#endif
