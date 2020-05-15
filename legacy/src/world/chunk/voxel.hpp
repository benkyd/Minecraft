#ifndef MINECRAFT_RENDERER_VOXEL_H_
#define MINECRAFT_RENDERER_VOXEL_H_

#include "../../common.hpp"

#include "face.hpp"

class Camera;
class Shader;

class Voxel {
public:
	Voxel(glm::vec3 coordsInChunk, uint8_t block);

	void AddFace(EFaceType::Face face);
	void GetMesh(std::vector<glm::vec3>& verts, std::vector<glm::vec3>& uvs);

	void Clear();

	uint8_t Block;

private:

	glm::vec3 m_coordsInChunk;

	std::vector<glm::vec3> m_translateIntoChunk(std::vector<glm::vec3> verts, glm::vec3 trans);

	std::vector<glm::vec3> m_vertices;
	std::vector<glm::vec3> m_uvs;

};

#endif
