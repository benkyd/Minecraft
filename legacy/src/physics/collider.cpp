#include "collider.hpp"

EntityCollider::EntityCollider() {

}

glm::vec3 EntityCollider::TerrainCollide(std::vector<uint8_t> terrain) {



}

bool EntityCollider::m_aabb(ColliderBox a, ColliderBox b) {

    return {
        (a.Min.x <= b.Min.x + b.Max.x && a.Min.x + a.Max.x >= b.Min.x) && 
        (a.Min.y <= b.Min.y + b.Max.y && a.Min.y + a.Max.y >= b.Min.y) && 
        (a.Min.z <= b.Min.z + b.Max.z && a.Min.z + a.Max.z >= b.Min.z) 
    };

}

float EntityCollider::m_xDepth(ColliderBox a, ColliderBox b) {

}


float EntityCollider::m_yDepth(ColliderBox a, ColliderBox b) {
 
}


float EntityCollider::m_zDepth(ColliderBox a, ColliderBox b) {
    
}
