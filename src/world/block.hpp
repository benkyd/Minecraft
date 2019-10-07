#ifndef MINECRAFT_WORLD_BLOCK_H_
#define MINECRAFT_WORLD_BLOCK_H_

#include "../common.hpp"

struct Block {
	std::string Name;
	int id;

public:
	Block();
};

static std::vector<std::pair<int, std::string>> TextureIdsAndPaths {
	{0, "dirt.png"},
	{1, "grass_side.png"},
	{2, "grass_top.png"}
};



#endif
