#ifndef MINECRAFT_RENDERER_VOXEL_H_
#define MINECRAFT_RENDERER_VOXEL_H_

#include "../common.hpp"

#include "face.hpp"

class Camera;
class Shader;

class Voxel {
public:
	Voxel(int x, int y, int z);

	void GetMesh(std::vector<glm::vec3>& verts, std::vector<glm::vec3>& uvs);

private:

	std::vector<glm::vec3> m_vertices;
	std::vector<glm::vec3> m_uvs;

};

#endif
