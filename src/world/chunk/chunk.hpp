#ifndef MINECRAFT_RENDERER_CHUNK_H_
#define MINECRAFT_RENDERER_CHUNK_H_

#include "../../common.hpp"

#define CHUNK_HEIGHT 128
#define CHUNK_WIDTH  16
#define CHUNK_DEPTH  16

class Camera;
class Shader;

class Voxel;

class Chunk {
public:

	Chunk();
	Chunk(int x, int z);
	Chunk(int x, int z, std::vector<uint8_t> voxels);

	void Load();

	bool MeshReady = false;
	void UploadMesh();


	void Render(std::shared_ptr<Camera> camera, std::shared_ptr<Shader> shader);

	void Update(std::vector<uint8_t> voxels);

	//bool Loaded = false;
	//bool Render = false;

	uint8_t BlockAt(int x, int y, int z);

	// Indexed sequentially [x + WIDTH * (y + HEIGHT * z)] = voxelID
	// the voxel id is used to index the block dictionary to get properties
	// to generate a mesh and send it to the GPU
	std::vector<uint8_t> Voxels;

	// To only be changed by the class its self 
	bool Loaded = false;
	// To only be changed by render components
	bool ShouldRender = false;

	~Chunk();

private:

	void m_mesh();

	GLuint m_vao = 0;
	GLuint m_vbo = 0;

	// Must be translated by a multiple of 16 in the x or z, nothing in y
	glm::mat4 m_model;

	std::vector<glm::vec3> m_vertices;
	int m_numVerts = 0;

	std::vector<glm::vec3> m_uvs;


};

#endif
