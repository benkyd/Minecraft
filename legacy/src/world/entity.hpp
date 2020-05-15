#ifndef MINECRAFT_WORLD_ENTITY_H_
#define MINECRAFT_WORLD_ENTITY_H_

#include "../common.hpp"

class Camera;

class Collider;

class Entity {
public:

    Entity(glm::vec3 position, glm::vec3 direction = { 0.0f, 0.0f, 0.0f }, std::shared_ptr<Camera> camera = std::make_shared<Camera>());

    // World position, 1.7 units below the 
    // camera position.
    glm::vec3 Position;
    // Look direction of the camera
    glm::vec3 Direction;
    // Velocity in direction
    // of movement
    glm::vec3 Velocity;

    // Can be null
    std::shared_ptr<Camera> EntityCamera;

    // Collider
    // std::unique_ptr<Collider> EntityCollider;

    // Mesh (or reference to)

};

class Player : public Entity {
public: 

    Player(glm::vec3 position, glm::vec3 direction,  std::shared_ptr<Camera> camera);

    float EyePosition = 1.7f;

    void MoveSDL(Uint8* state);
	void HandleMouseSDL(SDL_Event e);

    void UpdatePosition(glm::vec3 position);
    void UpdateDirection(glm::vec3 direction);

    void CameraUpdateProjection(int xres, int yres);	

};

#endif
