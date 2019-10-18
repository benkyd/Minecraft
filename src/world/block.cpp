#include "block.hpp"

#include "../config.hpp"

#include <iostream>

std::shared_ptr<CBlockDictionary> CBlockDictionary::Instance;

std::shared_ptr<CBlockDictionary> CBlockDictionary::GetInstance() {

	if (!CBlockDictionary::Instance) {

		CBlockDictionary::Instance = std::make_shared<CBlockDictionary>();

	}

	return CBlockDictionary::Instance;

}


void CBlockDictionary::Build() {

	RegisterTexture("dirt.png");
	RegisterTexture("grass_side.png");
	RegisterTexture("grass_top.png");
	
	// Texture winding order - top, bottom, left, right, front, back
	RegisterBlock(EBlockType::Air, 		{ });
	RegisterBlock(EBlockType::Dirt,		{ EFaceTexture::Dirt,		EFaceTexture::Dirt,		EFaceTexture::Dirt,			EFaceTexture::Dirt,			EFaceTexture::Dirt,			EFaceTexture::Dirt });
	RegisterBlock(EBlockType::Grass,	{ EFaceTexture::Grass,		EFaceTexture::Dirt,		EFaceTexture::GrassSide,	EFaceTexture::GrassSide,	EFaceTexture::GrassSide,	EFaceTexture::GrassSide });

}

void CBlockDictionary::RegisterTexture(std::string texture) {

	Textures.push_back(texture);

}

void CBlockDictionary::RegisterBlock(EBlockType::Block block, std::vector<uint16_t> faceTextures) {

	BlockEntries[block] = std::make_shared<CBlockEntry>((uint8_t)block, faceTextures);

}
