#include "voxel.hpp"

#include "shader.hpp"
#include "camera.hpp"

#include "face.hpp"


Voxel::Voxel(int x, int y, int z) {
	
	m_model = glm::translate(glm::mat4(1.0f), { (float)x, (float)y, (float)z });



	//glm::mat4 Matrix = {
	//	{1, 3, 0, 0},
	//	{0, 1, 0, 0},
	// 	{0, 0, 1, 0},
	//	{0, 0, 0, 1},
	//};

	//m_model = Matrix * m_model;

	// Texture winding order - top, bottom, left, right, front, back
	
	Faces.push_back(Face((FaceDirection)0, 2));
	Faces.push_back(Face((FaceDirection)1, 0));
	Faces.push_back(Face((FaceDirection)2, 1));
	Faces.push_back(Face((FaceDirection)3, 1));
	Faces.push_back(Face((FaceDirection)4, 1));
	Faces.push_back(Face((FaceDirection)5, 1));

	for (auto& face : Faces) {

		std::vector<glm::vec3> Vert;
		std::vector<glm::vec3> UVs;
		face.GetMesh(Vert, UVs);
		m_vertices.insert(m_vertices.end(), Vert.begin(), Vert.end());
		m_uvs.insert(m_uvs.end(), UVs.begin(), UVs.end());

	}
/*
	for (auto& vert : m_vertices) {

		glm::vec4 tmp = { vert, 1 };

		glm::vec4 res = tmp * m_model;

		vert = { res.x, res.y, res.z };

	}*/


}

void Voxel::GetMesh(std::vector<glm::vec3>& verts, std::vector<glm::vec3>& uvs) {

	verts = m_vertices;
	uvs = m_uvs;

}
