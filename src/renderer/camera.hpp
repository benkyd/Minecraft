#ifndef MINECRAFT_RENDERER_CAMERA_H_
#define MINECRAFT_RENDERER_CAMERA_H_

#include "../common.hpp"

class Camera {
public:
	Camera();
	Camera(int w, int h);

	void UpdateView();

	glm::mat4 GetViewMatrix();
	glm::mat4 GetProjectionMatrix();

	void UpdateProjection(int width, int height);

	void HandleMouse(SDL_Event e);
	void MoveCamera(Uint8* state);
	void MouseMoved(glm::vec2 mouseDelta);

	float MouseSensitivity = 0.1f;
	float CameraSpeed = 2.0f;

	void UpdatePosition(glm::vec3 position);
	void UpdateEulerLookDirection(float roll, float pitch, float yaw);
	void UpdateLookDirection(glm::vec3 lookDirection);

	glm::vec3 Position = {};
	float Roll, Pitch, Yaw;
	glm::vec3 LookDirection = {};

private:

	glm::mat4 viewMatrix = {};
	glm::mat4 projMatrix = {};

};

#endif
