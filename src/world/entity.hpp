#ifndef MINECRAFT_WORLD_ENTITY_H_
#define MINECRAFT_WORLD_ENTITY_H_

#include "../common.hpp"

class Camera;

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


    // Mesh (or reference to)

};


class Player : public Entity {
public: 

    Player(glm::vec3 position, glm::vec3 direction,  std::shared_ptr<Camera> camera);

    void Move(Uint8* state);
	void HandleMouseSDL(SDL_Event e);

    void UpdatePosition(glm::vec3 position);
    void UpdateDirection(glm::vec3 direction);

    void CameaUpdateProjection(int xres, int yres);	

};

#endif
