#include "chunk.hpp"

#include "shader.hpp"
#include "camera.hpp"

#include "voxel.hpp"

Chunk::Chunk() {

	for (int x = 0; x < CHUNK_WIDTH; x++)
	for (int y = 0; y < CHUNK_HEIGHT; y++)
	for (int z = 0; z < CHUNK_HEIGHT; z++) {
	
		Voxels.push_back(std::make_shared<Voxel>(x, y, z));

	}

	std::cout << Voxels.size() << " voxels" << std::endl;

	m_mesh();

}

Chunk::Chunk(std::vector<std::shared_ptr<Voxel>> voxels) {

	Voxels = voxels;
	m_mesh();

}


void Chunk::Render(std::shared_ptr<Camera> camera, std::shared_ptr<Shader> shader) {

	shader->Use();
	glBindVertexArray(m_vao);

	GLint uniTrans = glGetUniformLocation(shader->Program, "model");
	glUniformMatrix4fv(uniTrans, 1, GL_FALSE, glm::value_ptr(m_model));

	GLint uniView = glGetUniformLocation(shader->Program, "view");
	glUniformMatrix4fv(uniView, 1, GL_FALSE, glm::value_ptr(camera->GetViewMatrix()));

	GLint uniProj = glGetUniformLocation(shader->Program, "proj");
	glUniformMatrix4fv(uniProj, 1, GL_FALSE, glm::value_ptr(camera->GetProjectionMatrix()));

	glDrawArrays(GL_TRIANGLES, 0, m_vertices.size());

}

void Chunk::Update() {

	m_mesh();

}

void Chunk::m_mesh() {

	for (auto& voxel : Voxels) {

		std::vector<glm::vec3>tempVerts;
		std::vector<glm::vec3>tempUVs;

		voxel->GetMesh(tempVerts, tempUVs);
		
		for (auto& vert : tempVerts)
			m_vertices.push_back(vert);

		for (auto& uv : tempUVs)
			m_uvs.push_back(uv);

	}

	glGenVertexArrays(1, &m_vao);
	glBindVertexArray(m_vao);

	glGenBuffers(1, &m_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);

	std::vector<glm::vec3> data;
	data.insert(data.end(), m_vertices.begin(), m_vertices.end());
	data.insert(data.end(), m_uvs.begin(), m_uvs.end());

	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(glm::vec3), &data[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (const void*)0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (const void*)(m_vertices.size() * sizeof(glm::vec3)));

	glBindVertexArray(0);

}
