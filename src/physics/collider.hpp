#ifndef MINECRAFT_PHYSICS_COLLIDER_H_
#define MINECRAFT_PHYSICS_COLLIDER_H_

#include "../common.hpp"

class ColliderBox {
public:
    glm::vec3 Min;
    glm::vec3 Max;
};

class EntityCollider {
public:

    EntityCollider();

    // Surrounding blocks indexed XYZ
    // Returns point of collision 
    glm::vec3 TerrainCollide(std::vector<uint8_t> surroundingBlocks);     

    ColliderBox Bounds;

private:

    bool m_aabb(ColliderBox a, ColliderBox b);
    
    float m_xDepth(ColliderBox a, ColliderBox b);
    float m_yDepth(ColliderBox a, ColliderBox b);
    float m_zDepth(ColliderBox a, ColliderBox b);

};


#endif
