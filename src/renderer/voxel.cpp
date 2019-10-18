#include "voxel.hpp"

#include <iostream>
#include <memory>

#include "shader.hpp"
#include "camera.hpp"

#include "face.hpp"

#include "../world/block.hpp"

Voxel::Voxel(glm::vec3 coordsInChunk, uint8_t block) {

	// Texture winding order - top, bottom, left, right, front, back

	Block = block;
	m_coordsInChunk = coordsInChunk;

}

void Voxel::AddFace(EFaceType::Face face) {

	std::vector<glm::vec3> verts; 
	std::vector<glm::vec2> uvs; 

	switch (face) {

		case EFaceType::Top:
		{

			verts = CubeTopFace;
			uvs = CubeTopFaceUVs;

			break;
		}

		case EFaceType::Bottom:
		{

			verts = CubeBottomFace;
			uvs = CubeBottomFaceUVs;

			break;
		}

		case EFaceType::Left:
		{

			verts = CubeLeftFace;
			uvs = CubeLeftFaceUVs;

			break;
		}

		case EFaceType::Right:
		{

			verts = CubeRightFace;
			uvs = CubeRightFaceUVs;

			break;
		}

		case EFaceType::Front:
		{

			verts = CubeFrontFace;
			uvs = CubeFrontFaceUVs;

			break;
		}

		case EFaceType::Back:
		{

			verts = CubeBackFace;
			uvs = CubeBackFaceUVs;

			break;
		}

	}

	
	verts = m_translateIntoChunk(verts, m_coordsInChunk);
	m_vertices.insert(m_vertices.end(), verts.begin(), verts.end());


	std::shared_ptr<CBlockEntry> block = CBlockDictionary::GetInstance()->BlockEntries[Block];

	uint16_t tex = block->FaceTextures[(uint16_t)face];

	std::vector<glm::vec3> uvws;

	for (auto& uv : uvs) {

		uvws.push_back({ uv.x, uv.y, (float)tex });

	}

	m_uvs.insert(m_uvs.end(), uvws.begin(), uvws.end());

}

void Voxel::GetMesh(std::vector<glm::vec3>& verts, std::vector<glm::vec3>& uvs) {

	verts = m_vertices;
	uvs = m_uvs;

}

std::vector<glm::vec3> Voxel::m_translateIntoChunk(std::vector<glm::vec3> verts, glm::vec3 trans) {
	
	for (int i = 0; i < verts.size(); i++) {

		verts[i].x += trans.x;
		verts[i].y += trans.y;
		verts[i].z += trans.z;

	}

	return verts;

}
