#ifndef MINECRAFT_RENDERER_VOXEL_H_
#define MINECRAFT_RENDERER_VOXEL_H_

#include "../common.hpp"

class Camera;
class Shader;

class Face;

class Voxel {
	Voxel(int x, int y, int z);

	void Render(std::shared_ptr<Camera> camera, std::shared_ptr<Shader> shader);

private:

	GLuint m_vao = 0;
	GLuint m_vbo = 0;

	glm::mat4 m_model;



};

#endif
