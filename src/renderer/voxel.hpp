#ifndef MINECRAFT_RENDERER_VOXEL_H_
#define MINECRAFT_RENDERER_VOXEL_H_

#include "../common.hpp"

#include "face.hpp"

class Camera;
class Shader;

class Voxel {
public:
	Voxel(int x, int y, int z);

	void Render(std::shared_ptr<Camera> camera, std::shared_ptr<Shader> shader);

private:

	std::vector<Face> m_faces;

	GLuint m_vao = 0;
	GLuint m_vbo = 0;

	glm::mat4 m_model;

	std::vector<glm::vec3> m_vertices;
	std::vector<glm::vec3> m_uvs;
};

#endif
