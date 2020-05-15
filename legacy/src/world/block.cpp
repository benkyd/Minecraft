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

	RegisterTexture("stone.png");
	RegisterTexture("dirt.png");
	RegisterTexture("grass_side.png");
	RegisterTexture("grass_top.png");
	RegisterTexture("cobblestone.png");
	RegisterTexture("bedrock.png");
	
	// Texture winding order - top, bottom, left, right, front, back
	RegisterBlock(EBlockType::Air, 			{ });
	RegisterBlock(EBlockType::Stone,		{ EFaceTexture::Stone,			EFaceTexture::Stone,		EFaceTexture::Stone,		EFaceTexture::Stone,		EFaceTexture::Stone,		EFaceTexture::Stone });
	RegisterBlock(EBlockType::Dirt,			{ EFaceTexture::Dirt,			EFaceTexture::Dirt,			EFaceTexture::Dirt,			EFaceTexture::Dirt,			EFaceTexture::Dirt,			EFaceTexture::Dirt });
	RegisterBlock(EBlockType::Grass,		{ EFaceTexture::Grass,			EFaceTexture::Dirt,			EFaceTexture::GrassSide,	EFaceTexture::GrassSide,	EFaceTexture::GrassSide,	EFaceTexture::GrassSide });
	RegisterBlock(EBlockType::Cobblestone,	{ EFaceTexture::Cobblestone,	EFaceTexture::Cobblestone,	EFaceTexture::Cobblestone,	EFaceTexture::Cobblestone,	EFaceTexture::Cobblestone,	EFaceTexture::Cobblestone });
	RegisterBlock(EBlockType::Bedrock,		{ EFaceTexture::Bedrock,		EFaceTexture::Bedrock,		EFaceTexture::Bedrock,		EFaceTexture::Bedrock,		EFaceTexture::Bedrock,		EFaceTexture::Bedrock });

}

void CBlockDictionary::RegisterTexture(std::string texture) {

	Textures.push_back(texture);

}

void CBlockDictionary::RegisterBlock(EBlockType::Block block, std::vector<uint16_t> faceTextures) {

	BlockEntries[block] = std::make_shared<CBlockEntry>((uint8_t)block, faceTextures);

}
