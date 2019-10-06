#ifndef MINECRAFT_WORLD_BLOCK_H_
#define MINECRAFT_WORLD_BLOCK_H_

#include "../common.hpp"

struct Block {
	std::string Name;
	int ID;

	std::vector<std::pair<int, std::string>> Textures;

};


std::vector<std::shared_ptr> BlockAtlas();

#endif
