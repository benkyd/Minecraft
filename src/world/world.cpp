#include "world.hpp"

#include "chunk/chunk.hpp"

#include "../renderer/shader.hpp"

#include "../util/fastnoise.hpp"

#include "../config.hpp"
#include "entity.hpp"

World::World() {

}

void World::LoadWorld() {
	
	m_shaders["Basic"] = std::make_shared<Shader>();
	m_shaders["Basic"]->Load(GameConfig.ResourceBase + "shaders/simple");
	m_shaders["Basic"]->Link();

	srand(time(NULL));

    m_noiseGenerator = std::make_shared<FastNoise>();
    m_noiseGenerator->SetSeed(rand());

    m_noiseGenerator->SetNoiseType(FastNoise::Perlin);

    m_noiseGenerator->SetFractalOctaves(8);

	for (int x = -4; x < 50; x++)
	for (int y = -50; y < 4; y++) {

		m_chunkLoaderQueue.push({ x, y });

	}

	// Spawn generator threads
	for (int i = 0; i < 6; i++) {

		m_generatorThreads.push_back(std::thread([&]() {

			m_loadChunks();

		}));

	}

	m_generatorRunning = true;

}

void World::SetTextureMap(GLuint map) {

	m_textureMapID = map;

}

glm::vec2 World::GetChunkCoords(glm::vec3 wordCoords) {

	return { wordCoords.x / CHUNK_WIDTH, wordCoords.z / CHUNK_DEPTH };

}

std::vector<std::shared_ptr<Chunk>> World::GetRenderableChunks() {

	std::vector<std::shared_ptr<Chunk>> chunks;

	for (auto& chunk : m_chunks) {

		 // Should the chunk be rendererd ?
		if (chunk.second->ShouldRender) {

			m_chunkMutex.lock();

			if (chunk.second->MeshReady)
				chunk.second->UploadMesh();

			m_chunkMutex.unlock();

			// If not, add it
			chunks.push_back(chunk.second);

		}

	}

	return chunks;

}

void World::Update(std::shared_ptr<Entity> player) {

}

void World::Render(std::shared_ptr<Entity> player) {

	glBindTexture(GL_TEXTURE_2D_ARRAY, m_textureMapID);

	std::vector<std::shared_ptr<Chunk>> chunks = GetRenderableChunks();

	
	for (int i = 0; i < chunks.size(); i++) {

		chunks[i]->Render(player->EntityCamera, m_shaders["Basic"]);

	}

}

World::~World() {

	m_generatorRunning = false;

	for (int i = 0; i < m_generatorThreads.size(); i++) {

		m_generatorThreads[i].join();

	}

}

void World::m_loadChunks() {

	while (m_generatorRunning) {

		m_chunkMutex.lock();

		glm::vec2 coords = m_chunkLoaderQueue.front();
		m_chunkLoaderQueue.pop();

		m_chunkMutex.unlock();


		std::shared_ptr<Chunk> loadingChunk = std::make_shared<Chunk>(coords.x, coords.y, m_noiseGenerator);
		std::cout << "Loaded chunk " << coords.x << ":" << coords.y << std::endl;


		m_chunkMutex.lock();

		m_chunks[coords] = loadingChunk;
		m_chunks[coords]->ShouldRender = true;

		m_chunkMutex.unlock();


		while (m_chunkLoaderQueue.empty()) {

			if (!m_generatorRunning) break;

			static std::chrono::milliseconds dura(1);
			std::this_thread::sleep_for(dura);
		
		}

	}

}
