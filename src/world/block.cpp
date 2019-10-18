#include "block.hpp"

#include "../config.hpp"

#include <iostream>

void CBlockDictionary::Build() {

	RegisterTexture("dirt.png");
	RegisterTexture("grass_side.png");
	RegisterTexture("grass_top.png");
	
	// Texture winding order - top, bottom, left, right, front, back
	RegisterBlock(EBlockType::Air, 		{ });
	RegisterBlock(EBlockType::Dirt,		{ EFaceTexture::Dirt,		EFaceTexture::Dirt,		EFaceTexture::Dirt,			EFaceTexture::Dirt,			EFaceTexture::Dirt,			EFaceTexture::Dirt });
	RegisterBlock(EBlockType::Grass,	{ EFaceTexture::Grass,		EFaceTexture::Dirt,		EFaceTexture::GrassSide,	EFaceTexture::GrassSide,	EFaceTexture::GrassSide,	EFaceTexture::GrassSide });

	std::cout << "Block Entries Size " << BlockEntries.size() << std::endl;

}

void CBlockDictionary::RegisterTexture(std::string texture) {

	Textures.push_back(texture);

}

void CBlockDictionary::RegisterBlock(uint8_t block, std::vector<uint16_t> faceTextures) {

	std::cout << "Block Entries Size " << BlockEntries.size() << std::endl;
	BlockEntries[block] = std::make_shared<CBlockEntry>((uint8_t)block, faceTextures);

}
