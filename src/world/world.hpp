#ifndef MINECRAFT_WORLD_WORLD_H_
#define MINECRAFT_WORLD_WORLD_H_

#include "../common.hpp"

#include "../renderer/camera.hpp"

#include "chunk/chunk.hpp"

#include <unordered_map>
#include <thread>
#include <mutex>
#include <queue>

class FastNoise;

class Shader;

class World {
public:

	// Default constructor
	World();


	// Preps the render threads and loads all of the shaders
	void LoadWorld();

	void SetTextureMap(GLuint map);

	// Takes world coordinates and gets a chunks coordinates
	glm::vec2 GetChunkCoords(glm::vec3 wordCoords);

	std::vector<std::shared_ptr<Chunk>> GetRenderableChunks();


	void Render(std::shared_ptr<Camera> camera);

	~World();

private:

	// GL stuff

	// Main texture map id
	GLuint m_textureMapID;
	
	// Shaders indexed by name
	std::map<std::string, std::shared_ptr<Shader>> m_shaders;
	
	
	// Threads used for chunk generation
	std::vector<std::thread> m_generatorThreads;
	bool m_generatorRunning = false;
	

	// Chuks
	// Indexed by chunk coorinates
	std::unordered_map<glm::vec2, std::shared_ptr<Chunk>> m_chunks;

	std::queue<glm::vec2> m_chunkUpdatesQueue;
	std::queue<glm::vec2> m_chunkLoaderQueue;

	std::mutex m_chunkMutex;

	// Generator
	std::shared_ptr<FastNoise> m_noiseGenerator;


	void m_loadChunks();

};

#endif
