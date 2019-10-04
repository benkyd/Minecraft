#include "camera.hpp"

void Camera::UpdateView() {
	// roll can be removed from here. because is not actually used in FPS camera
	glm::mat4 matRoll = glm::mat4(1.0f);//identity matrix; 
	glm::mat4 matPitch = glm::mat4(1.0f);//identity matrix
	glm::mat4 matYaw = glm::mat4(1.0f);//identity matrix

	// roll, pitch and yaw are used to store our angles in our class
	matRoll = glm::rotate(matRoll, roll, glm::vec3(0.0f, 0.0f, 1.0f));
	matPitch = glm::rotate(matPitch, pitch, glm::vec3(1.0f, 0.0f, 0.0f));
	matYaw = glm::rotate(matYaw, yaw, glm::vec3(0.0f, 1.0f, 0.0f));

	// order matters
	glm::mat4 rotate = matRoll * matPitch * matYaw;

	glm::mat4 translate = glm::mat4(1.0f);
	translate = glm::translate(translate, -eyeVector);

	viewMatrix = rotate * translate;
}

glm::mat4 Camera::GetViewMatrix() {
	return viewMatrix;
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

void Camera::MoveCamera() {
	float dx = 0;
	float dz = 0;

	const Uint8* state = SDL_GetKeyboardState(NULL);

	if (state[SDL_SCANCODE_W])
		dz += 2;
	if (state[SDL_SCANCODE_S])
		dz += -2;
	if (state[SDL_SCANCODE_A])
		dx += -2;
	if (state[SDL_SCANCODE_D])
		dx += 2;
	// if (state[SDL_SCANCODE_Z])

	// if (state[SDL_SCANCODE_LSHIFT])


	// get current view matrix
	glm::mat4 mat = GetViewMatrix();
	// row major
	glm::vec3 forward(mat[0][2], mat[1][2], mat[2][2]);
	glm::vec3 strafe(mat[0][0], mat[1][0], mat[2][0]);

	// forward vector must be negative to look forward. 
	// read :http://in2gpu.com/2015/05/17/view-matrix/
	eyeVector += (-dz * forward + dx * strafe) * CameraSpeed;

	// update the view matrix
	UpdateView();
}

void Camera::MouseMoved(glm::vec2 mouseDelta) {
	// note that yaw and pitch must be converted to radians.
	// this is done in UpdateView() by glm::rotate
	yaw += MouseSensitivity * mouseDelta.x;
	pitch += MouseSensitivity * mouseDelta.y;

	UpdateView();
}

