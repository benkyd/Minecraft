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

Player::Player {
    
}

