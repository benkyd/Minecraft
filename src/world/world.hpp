#ifndef MINECRAFT_WORLD_WORLD_H_
#define MINECRAFT_WORLD_WORLD_H_

#include "../common.hpp"

class Shader;
class Voxel;

class World {
public:

	std::map<std::string, std::shared_ptr<Shader>> Shaders;
	std::vector<std::shared_ptr<Voxel>> Voxels;

	GLuint TextureID;

};

#endif
