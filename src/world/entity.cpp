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
    
    Position = { 0, 64, 0 };
    EntityCamera->Position = { Position.x, Position.y + EyePosition, Position.z };
    EntityCamera->UpdateView();

}

void Player::MoveSDL(Uint8* state) {
    
    EntityCamera->MoveCamera(state);
    Position = EntityCamera->Position;
    Position.y -= EyePosition;

}

void Player::HandleMouseSDL(SDL_Event e) {

    EntityCamera->HandleMouse(e);
    Direction = EntityCamera->LookDirection;

}

void Player::UpdatePosition(glm::vec3 position) {

    Position = position;
    EntityCamera->UpdatePosition({ Position.x, Position.y + EyePosition, Position.z });

}


void Player::UpdateDirection(glm::vec3 direction) {

    Direction = direction;
    EntityCamera->UpdateLookDirection(direction);

}

void Player::CameraUpdateProjection(int xres, int yres) {

    EntityCamera->UpdateProjection(xres, yres);

}
