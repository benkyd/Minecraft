#include "voxel.hpp"

#include "shader.hpp"
#include "camera.hpp"

#include "face.hpp"

Voxel::Voxel(int x, int y, int z) {

	m_model = glm::translate(glm::mat4(1.0f), { (float)x, (float)y, (float)z });

	Face top((FaceDirection)0, 2);
	std::vector<glm::vec3> topVert;
	std::vector<glm::vec3> topUVs;
	top.GetMesh(topVert, topUVs);
	m_vertices.insert(m_vertices.end(), topVert.begin(), topVert.end());
	m_uvs.insert(m_uvs.end(), topUVs.begin(), topUVs.end());

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

void Voxel::Render(std::shared_ptr<Camera> camera, std::shared_ptr<Shader> shader) {

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
