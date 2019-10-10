#include "camera.hpp"

Camera::Camera(int w, int h) {

	projMatrix = glm::perspective(glm::radians(45.0f), (float)w / float(h), 0.1f, 1000.0f);

	roll = 0.0f;
	pitch = 0.0f;
	yaw = 0.0f;

	eyeVector = {};
	viewMatrix = {};
}

void Camera::UpdateView() {
	// roll can be removed
	glm::mat4 matRoll = glm::mat4(1.0f); //identity matrix; 
	glm::mat4 matPitch = glm::mat4(1.0f);//identity matrix
	glm::mat4 matYaw = glm::mat4(1.0f);  //identity matrix

	// roll, pitch and yaw
	matRoll = glm::rotate(matRoll, roll, glm::vec3(0.0f, 0.0f, 1.0f));
	matPitch = glm::rotate(matPitch, pitch, glm::vec3(1.0f, 0.0f, 0.0f));
	matYaw = glm::rotate(matYaw, yaw, glm::vec3(0.0f, 1.0f, 0.0f));

	glm::mat4 rotate = matRoll * matPitch * matYaw;

	glm::mat4 translate = glm::mat4(1.0f);
	translate = glm::translate(translate, -eyeVector);

	viewMatrix = rotate * translate;
}

glm::mat4 Camera::GetViewMatrix() {
	return viewMatrix;
}

glm::mat4 Camera::GetProjectionMatrix() {
	return projMatrix;
}

glm::vec3 Camera::GetPos() {
	return eyeVector;
}

void Camera::HandleMouse(SDL_Event e) {
	if (e.type != SDL_MOUSEMOTION)
		return;


	float mouseDX = e.motion.xrel;
	float mouseDY = e.motion.yrel;

	glm::vec2 mouseDelta{ mouseDX, mouseDY };

	MouseMoved(mouseDelta);
}

void Camera::MoveCamera(Uint8* state) {
	float dx = 0;
	float dz = 0;
	float dy = 0;

	// Rotate by camera direction
	glm::mat2 rotate {
		cos(yaw), -sin(yaw),
		sin(yaw), cos(yaw)
	};

	glm::vec2 f(0.0, 1.0);
	f = f * rotate;

	if (state[SDL_SCANCODE_W]) {
		dz -= f.y;
		dx -= f.x;
	}
	if (state[SDL_SCANCODE_S]) {
		dz += f.y;
		dx += f.x;
	}
	if (state[SDL_SCANCODE_A]) {
		dz += f.x;
		dx += -f.y;
	}
	if (state[SDL_SCANCODE_D]) {
		dz -= f.x;
		dx -= -f.y;
	}
	if (state[SDL_SCANCODE_SPACE]) {
		dy += 1;
	}
	if (state[SDL_SCANCODE_LSHIFT]) {
		dy -= 1;
	}

	// get current view matrix
	glm::mat4 mat = GetViewMatrix();
	glm::vec3 forward(mat[0][2], mat[1][2], mat[2][2]);
	glm::vec3 strafe(mat[0][0], mat[1][0], mat[2][0]);

	// forward vector must be negative to look forward. 
	// read :http://in2gpu.com/2015/05/17/view-matrix/
	eyeVector.x += dx * CameraSpeed;
	eyeVector.z += dz * CameraSpeed;
	eyeVector.y += dy * CameraSpeed;
	// update the view matrix
	UpdateView();
}

void Camera::MouseMoved(glm::vec2 mouseDelta) {
	// note that yaw and pitch must be converted to radians.
	// this is done in UpdateView() by glm::rotate
	yaw += MouseSensitivity * (mouseDelta.x/100);
	pitch += MouseSensitivity * (mouseDelta.y/100);
	pitch = glm::clamp<float>(pitch, -M_PI/2, M_PI/2);

	UpdateView();
}

