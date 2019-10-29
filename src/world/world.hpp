#ifndef MINECRAFT_WORLD_WORLD_H_
#define MINECRAFT_WORLD_WORLD_H_

#include "../common.hpp"

#include <unordered_map>

#include <thread>

class Shader;
class Chunk;

class World {
public:

	World();

	void LoadWorld();

	void SetTextureMap(GLuint map);

	// Takes world coordinates and gets a chunks coordinates
	glm::vec2 GetChunkCoords(glm::vec3);

	std::vector<std::shared_ptr<Chunk>> GetRenderableChunks();

private:

	GLuint m_textureMapID;
	
	
	std::map<std::string, std::shared_ptr<Shader>> m_shaders;
	

	std::vector<std::thread> m_generatorThreads;

	// Chuks

	std::vector<std::shared_ptr<Chunk>> m_renderableChunks;
	std::unordered_map<glm::vec2, std::shared_ptr<Chunk>> m_chunks;

};

#endif
