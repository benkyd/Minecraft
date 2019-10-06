#ifndef MINECRAFT_RENDERER_FACE_H_
#define MINECRAFT_RENDERER_FACE_H_

#include "../common.hpp"

class Camera;
class Shader;

enum FaceDirection {
	Top,
	Bottom,
	Front,
	Back,
	Left,
	Right
};

class Face {
public:
	Face(FaceDirection direction, int textureID);
	
	void GetMesh(std::vector<glm::vec3>& verts, std::vector<glm::vec2>& uvs);
	void Render(std::shared_ptr<Camera> camera, std::shared_ptr<Shader> shader);

	int Texture = 0;

	FaceDirection Direction = FaceDirection::Top;

private:

	std::vector<glm::vec3> m_verticies;
	std::vector<glm::vec2> m_uvs;

	GLuint m_vao;
	GLuint m_vbo;

};

#endif
