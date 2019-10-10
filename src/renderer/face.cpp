#include "face.hpp"

#include "shader.hpp"
#include "camera.hpp"

Face::Face(FaceDirection direction, int textureID) {
	
	Direction = direction;
	Texture = textureID;

	m_uvs = {
		{ 0.0f, 0.0f },
		{ 1.0f, 0.0f },
		{ 1.0f, 1.0f },
		{ 1.0f, 1.0f },
		{ 0.0f, 1.0f },
		{ 0.0f, 0.0f }
	};

	if (Direction == FaceDirection::Top) {

		m_verticies = {
			{ -0.5f,  0.5f, -0.5f },
			{  0.5f,  0.5f, -0.5f },
			{  0.5f,  0.5f,  0.5f },
			{  0.5f,  0.5f,  0.5f },
			{ -0.5f,  0.5f,  0.5f },
			{ -0.5f,  0.5f, -0.5f },
		};

	} else if (Direction == FaceDirection::Bottom) {
	
		m_verticies = {
			{ -0.5f, -0.5f, -0.5f },
			{  0.5f, -0.5f, -0.5f },
			{  0.5f, -0.5f,  0.5f },
			{  0.5f, -0.5f,  0.5f },
			{ -0.5f, -0.5f,  0.5f },
			{ -0.5f, -0.5f, -0.5f },
		};
	
	} else if (Direction == FaceDirection::Front) {
	
		m_verticies = {
			{ -0.5f, -0.5f,  0.5f },
			{  0.5f, -0.5f,  0.5f },
			{  0.5f,  0.5f,  0.5f },
			{  0.5f,  0.5f,  0.5f },
			{ -0.5f,  0.5f,  0.5f },
			{ -0.5f, -0.5f,  0.5f },
		};

		m_uvs = {
			{ 1.0f, 1.0f },
			{ 0.0f, 1.0f },
			{ 0.0f, 0.0f },
			{ 0.0f, 0.0f },
			{ 1.0f, 0.0f },
			{ 1.0f, 1.0f },
		};
	
	} else if (Direction == FaceDirection::Back) {
	
		m_verticies = {
			{ -0.5f, -0.5f, -0.5f },
			{  0.5f, -0.5f, -0.5f },
			{  0.5f,  0.5f, -0.5f },
			{  0.5f,  0.5f, -0.5f },
			{ -0.5f,  0.5f, -0.5f },
			{ -0.5f, -0.5f, -0.5f },
		};

		m_uvs = {
			{ 1.0f, 1.0f },
			{ 0.0f, 1.0f },
			{ 0.0f, 0.0f },
			{ 0.0f, 0.0f },
			{ 1.0f, 0.0f },
			{ 1.0f, 1.0f },
		};
	
	} else if (Direction == FaceDirection::Left) {
	
		m_verticies = {
			{ -0.5f,  0.5f,  0.5f },
			{ -0.5f,  0.5f, -0.5f },
			{ -0.5f, -0.5f, -0.5f },
			{ -0.5f, -0.5f, -0.5f },
			{ -0.5f, -0.5f,  0.5f },
			{ -0.5f,  0.5f,  0.5f },
		};
	
	} else if (Direction == FaceDirection::Right) {
	
		m_verticies = {
			{  0.5f,  0.5f,  0.5f },
			{  0.5f,  0.5f, -0.5f },
			{  0.5f, -0.5f, -0.5f },
			{  0.5f, -0.5f, -0.5f },
			{  0.5f, -0.5f,  0.5f },
			{  0.5f,  0.5f,  0.5f },
		};
	
	}

	glGenVertexArrays(1, &m_vao);
	glBindVertexArray(m_vao);

	glGenBuffers(1, &m_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);

	std::vector<glm::vec3> uvs;
	
	for (auto& uv : m_uvs) {
	
		uvs.push_back({ uv.x, uv.y, textureID });
	
	}

	std::vector<glm::vec3> data;
	data.insert(data.end(), m_verticies.begin(), m_verticies.end());
	data.insert(data.end(), uvs.begin(), uvs.end());

	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(glm::vec3), &data[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (const void*)0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (const void*)(m_verticies.size() * sizeof(glm::vec3)));

	glBindVertexArray(0);

}

void Face::GetMesh(std::vector<glm::vec3>& verts, std::vector<glm::vec3>& uvs) {

	verts = m_verticies;

	std::vector<glm::vec3> UVs;

	for (auto& uv : m_uvs) {

		UVs.push_back({ uv.x, uv.y, (float)Texture });

	}

	uvs = UVs;

}
