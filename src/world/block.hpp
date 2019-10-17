#ifndef MINECRAFT_WORLD_BLOCK_H_
#define MINECRAFT_WORLD_BLOCK_H_

#include "../common.hpp"


namespace EBlockType {

	enum Block : uint8_t {

		Air = 0,
		Dirt,
		Grass

	};

}

namespace EFaceTexture {

	enum Texture : uint16_t {

		Air = 0,
		Dirt,
		GrassSide,
		Grass

	};

}

class CBlockEntry {
public:
	uint8_t ID;
	// Texture winding order - top, bottom, left, right, front, back
	std::vector<uint16_t> FaceTextures;
	
};

// TODO: Make design of the class data oriented
// ie, import all the data used in the build from
// files and that
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

	// Expects textures to be inserted in order, 0-...
	void registerTexture(std::string texture);
	
	void registerBlock(EBlockType::Block block, std::vector<uint16_t> faceTextures);

};


static CBlockDictionary BlockDictionary;

// static std::vector<std::pair<int, std::string>> TextureIdsAndPaths {
// 	{0, "dirt.png"},
// 	{1, "grass_side.png"},
// 	{2, "grass_top.png"}
// };

#endif
