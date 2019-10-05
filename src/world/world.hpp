#ifndef MINECRAFT_WORLD_WORLD_H_
#define MINECRAFT_WORLD_WORLD_H_

#include "../common.hpp"

class Face;

class World {
public:

	std::vector<std::shared_ptr<Face>> Faces;

};

#endif
