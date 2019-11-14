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
class Entity;

class World {
public:

	// Default constructor
	World();


	// Preps the render threads and loads all of the shaders
	void LoadWorld();

	void SetTextureMap(GLuint map);

	// Takes world coordinates and gets a chunks coordinates
	glm::vec3 GetChunkCoords(glm::vec3 wordCoords);

	// Takes world coordinates and gets the chunk those coorinates
	// fall in
	glm::vec2 GetChunk(glm::vec3 worldCoords);

	std::vector<std::shared_ptr<Chunk>> GetRenderableChunks();

	void Update(std::shared_ptr<Entity> player);
	void Render(std::shared_ptr<Entity> player);

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

	std::mutex m_chunkUpdaterMutex;
	std::queue<glm::vec2> m_chunkUpdatesQueue;

	std::mutex m_chunkLoderMutex;
	std::queue<glm::vec2> m_chunkLoaderQueue;

	// Generator
	std::shared_ptr<FastNoise> m_noiseGenerator;


	void m_loadChunks();

};

#endif
