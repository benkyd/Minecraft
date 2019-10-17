#ifndef MINECRAFT_WORLD_BLOCK_H_
#define MINECRAFT_WORLD_BLOCK_H_

#include "../common.hpp"

class CBlockEntry {
public:
	uint8_t ID;
	
};

// TODO: Make design of the class data oriented
class CBlockDictionary {
public:

	void Build();

	// The index of the texutres path in this array is equal to
	// that textures ID, to be referenced in the block entry
	std::vector<std::string> Textures;

	// Only supports up to 255 blocs, 0 being air
	// word stores vectors of chunks which are 16x16x256
	// vectors of uint8_t which reference the block dictionary
	std::map<uint8_t, CBlockEntry> BlockEntries;

private:

	void registerTexture();
	void registerBlock();

};


static CBlockDictionary BlockDictionary;

// static std::vector<std::pair<int, std::string>> TextureIdsAndPaths {
// 	{0, "dirt.png"},
// 	{1, "grass_side.png"},
// 	{2, "grass_top.png"}
// };

#endif
