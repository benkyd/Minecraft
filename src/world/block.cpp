#include "block.hpp"

#include "../config.hpp"

void CBlockDictionary::Build() {

	// Texture winding order - top, bottom, left, right, front, back
	registerBlock(EBlockType::Air, { });
	registerBlock(EBlockType::Dirt,		{ EFaceTexture::Dirt,		EFaceTexture::Dirt,		FaceTexture::Dirt,			EFaceTexture::Dirt,			EFaceTexture::Dirt,			EFaceTexture::Dirt });
	registerBlock(EBlockType::Grass,	{ EFaceTexture::Grass,		EFaceTexture::Dirt,		EFaceTexture::GrassSide,	EFaceTexture::GrassSide,	EFaceTexture::GrassSide,	EFaceTexture::GrassSide });

}

void CBlockDictionary::registerTexture(std::string texture) {

	Textures.push_back(texture);

}

void CBlockDictionary::registerBlock(EBlockType::Block block, std::vector<uint16_t> faceTextures) {

	CBlockEntry entry = { block, faceTextures };

	BlockEntries[(uint8_t)block] = entry;

}
