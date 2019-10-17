#include "voxel.hpp"

#include "shader.hpp"
#include "camera.hpp"

#include "face.hpp"


Voxel::Voxel(int x, int y, int z) {

	// Texture winding order - top, bottom, left, right, front, back

	//Faces.push_back(Face((FaceDirection)0, 2));
	//Faces.push_back(Face((FaceDirection)1, 0));
	//Faces.push_back(Face((FaceDirection)2, 1));
	//Faces.push_back(Face((FaceDirection)3, 1));
	//Faces.push_back(Face((FaceDirection)4, 1));
	//Faces.push_back(Face((FaceDirection)5, 1));

	//for (auto& face : Faces) {

	//	std::vector<glm::vec3> Vert;
	//	std::vector<glm::vec3> UVs;

	//	face.GetMesh(Vert, UVs);
	//	
	//	m_vertices.insert(m_vertices.end(), Vert.begin(), Vert.end());
	//	m_uvs.insert(m_uvs.end(), UVs.begin(), UVs.end());

	//}

	for (int i = 0; i < m_vertices.size(); i++) {

		m_vertices[i].x += x;
		m_vertices[i].y += y;
		m_vertices[i].z += z;

	}


}

void Voxel::GetMesh(std::vector<glm::vec3>& verts, std::vector<glm::vec3>& uvs) {

	verts = m_vertices;
	uvs = m_uvs;

}
