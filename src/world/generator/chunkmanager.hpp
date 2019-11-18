#ifndef MINECRAFT_WORLD_GENERATOR_CUNKMANAGER_H_
#define MINECRAFT_WORLD_GENERATOR_CUNKMANAGER_H_

#include "../../common.hpp"


class Frustrum;

class ChunkManager {
public:

    // Instatntiated 
    ChunkManager();

    void Update();

    void Play();
    void Pause();

    void LoadChunksAroundWorldPoint(glm::vec3 worldPoint);



    void CullFrustrumFromRenderQueue();

};

#endif
