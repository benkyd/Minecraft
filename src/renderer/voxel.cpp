#include "voxel.hpp"

#include "shader.hpp"
#include "camera.hpp"

#include "face.hpp"

Voxel::Voxel(int x, int y, int z) {

	m_model = glm::translate(glm::mat4(1.0f), { (float)x, (float)y, (float)z });



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

	glDrawArrays(GL_TRIANGLES, 0, m_verticies.size());

}
