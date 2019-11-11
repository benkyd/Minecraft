#include "entity.hpp"

#include "../renderer/camera.hpp"

Entity::Entity(glm::vec3 postion, glm::vec3 direction, std::shared_ptr<Camera> camera)
    : Position(Position)
    , Direction(direction) 
    , EntityCamera(camera)
    {

    if (EntityCamera) {
        EntityCamera->UpdateView();
    }
}

Player::Player(glm::vec3 position, glm::vec3 direction, std::shared_ptr<Camera> camera)
    : Entity(position, direction, camera) {
    
    camera->Position = 

}

Player(glm::vec3 position, glm::vec3 direction = {0.0f, 0.0f, 0.0f});

void Move(Uint8* state);
void HandleMouse(SDL_Event e);

void UpdatePosition(glm::vec3 position);
void UpdateDirection(glm::vec3 direction);

void CameaUpdateProjection(int xres, int yres);	
