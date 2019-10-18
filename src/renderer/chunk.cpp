#include "chunk.hpp"

#include "shader.hpp"
#include "camera.hpp"

#include "voxel.hpp"

#include "../world/block.hpp"

Chunk::Chunk(int x, int z) {

	m_model = glm::translate(glm::mat4(1.0f), { x * CHUNK_WIDTH, 0, z * CHUNK_DEPTH });
	
	// [x + WIDTH * (y + HEIGHT * z)]
	for (int x = 0; x < CHUNK_WIDTH; x++)
	for (int y = 0; y < CHUNK_HEIGHT; y++)
	for (int z = 0; z < CHUNK_DEPTH; z++) {

		// Grass on the top layer
		if (y == CHUNK_HEIGHT - 1) {

			Voxels.push_back((uint8_t)EBlockType::Grass);
		
		} else {
			
			Voxels.push_back((uint8_t)EBlockType::Dirt);

		}

	}

	std::cout << Voxels.size() << " voxels" << std::endl;

	m_mesh();

}

Chunk::Chunk(int x, int z, std::vector<uint8_t> voxels) {

	m_model = glm::translate(glm::mat4(1.0f), { x * CHUNK_WIDTH, 0, z * CHUNK_DEPTH });
	
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

uint8_t Chunk::BlockAt(int x, int y, int z) {

	return Voxels[x + CHUNK_WIDTH * (y + CHUNK_HEIGHT * z)];

}

void Chunk::m_mesh() {

	for (int x = 0; x < CHUNK_WIDTH; x++)
	for (int y = 0; y < CHUNK_HEIGHT; y++)
	for (int z = 0; z < CHUNK_DEPTH; z++) {

		std::vector<glm::vec3> tempVerts;
		std::vector<glm::vec3> tempUVs;

		std::cout << x << " " << y << " " << z << std::endl;

		uint8_t block = BlockAt(x, y, z);

		std::cout << "Block ID " << (int)block << std::endl;

		Voxel tmp({x, y, z}, BlockAt(x, y, z));

		tmp.AddFace(EFaceType::Top);
		tmp.AddFace(EFaceType::Bottom);
		tmp.AddFace(EFaceType::Left);
		tmp.AddFace(EFaceType::Right);
		tmp.AddFace(EFaceType::Front);
		tmp.AddFace(EFaceType::Back);

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
