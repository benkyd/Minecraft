#ifndef MINECRAFT_RENDERER_CHUNK_H_
#define MINECRAFT_RENDERER_CHUNK_H_

#include "../common.hpp"

#define CHUNK_HEIGHT 10
#define CHUNK_WIDTH  10
#define CHUNK_DEPTH  10

class Camera;
class Shader;

class Voxel;

class Chunk {
public:

	Chunk();
	Chunk(std::vector<std::shared_ptr<Voxel>> voxels);

	void Render(std::shared_ptr<Camera> camera, std::shared_ptr<Shader> shader);

	void Update();

	// Indexed sequentially [x + WIDTH * (y + HEIGHT * z)] = voxel
	std::vector<std::shared_ptr<Voxel>> Voxels;

private:

	void m_mesh();

	GLuint m_vao = 0;
	GLuint m_vbo = 0;

	// Must be translated by a multiple of 16 in the x or z, nothing in y
	glm::mat4 m_model;

	std::vector<glm::vec3> m_vertices;
	std::vector<glm::vec3> m_uvs;


};

#endif
