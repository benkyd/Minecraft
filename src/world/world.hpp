#ifndef MINECRAFT_WORLD_WORLD_H_
#define MINECRAFT_WORLD_WORLD_H_

#include "../common.hpp"

#include <unordered_map>

#include <thread>

class Shader;
class Chunk;

class World {
public:


private:

	GLuint m_textureMapID;
	
	
	std::map<std::string, std::shared_ptr<Shader>> m_shaders;
	

	std::vector<std::thread> m_generatorThreads;

	std::unordered_map<glm::vec2, std::shared_ptr<Chunk>> m_chunks;

};

#endif
