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

<<<<<<< HEAD
Player::Player(glm::vec3 position, glm::vec3 direction) {

}

void Player::Move(Uint8* state) {
	
}

void Player::HandleMouseSDL(SDL_Event e) {

}

    void UpdatePosition(glm::vec3 position);
    void UpdateDirection(glm::vec3 direction);

    void CameaUpdateProjection(int xres, int yres);	
=======
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
>>>>>>> 0b6a3b520cd2e51e4d8cf7716ec4ddcf51297e2e
