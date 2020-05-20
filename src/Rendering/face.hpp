#ifndef MINECRAFT_RENDERING_FACE_H_
#define MINECRAFT_RENDERING_FACE_H_

#include "../../common.hpp"

namespace EFaceType {

	enum Face : uint8_t {
		Top,
		Bottom,
		Left,
		Right,
		Front,
		Back,
	};

}

static std::vector<glm::vec3> CubeTopFace = {
	{ -0.5f,  0.5f, -0.5f },
	{  0.5f,  0.5f, -0.5f },
	{  0.5f,  0.5f,  0.5f },
	{  0.5f,  0.5f,  0.5f },
	{ -0.5f,  0.5f,  0.5f },
	{ -0.5f,  0.5f, -0.5f }
};

static std::vector<glm::vec2> CubeTopFaceUVs = {
	{ 0.0f, 0.0f },
	{ 1.0f, 0.0f },
	{ 1.0f, 1.0f },
	{ 1.0f, 1.0f },
	{ 0.0f, 1.0f },
	{ 0.0f, 0.0f }
};

static std::vector<glm::vec3> CubeBottomFace = {
	{ -0.5f, -0.5f, -0.5f },
	{  0.5f, -0.5f, -0.5f },
	{  0.5f, -0.5f,  0.5f },
	{  0.5f, -0.5f,  0.5f },
	{ -0.5f, -0.5f,  0.5f },
	{ -0.5f, -0.5f, -0.5f }
};

static std::vector<glm::vec2> CubeBottomFaceUVs = {
	{ 0.0f, 0.0f },
	{ 1.0f, 0.0f },
	{ 1.0f, 1.0f },
	{ 1.0f, 1.0f },
	{ 0.0f, 1.0f },
	{ 0.0f, 0.0f }
};

static std::vector<glm::vec3> CubeLeftFace = {
	{ -0.5f,  0.5f,  0.5f },
	{ -0.5f,  0.5f, -0.5f },
	{ -0.5f, -0.5f, -0.5f },
	{ -0.5f, -0.5f, -0.5f },
	{ -0.5f, -0.5f,  0.5f },
	{ -0.5f,  0.5f,  0.5f }
};

static std::vector<glm::vec2> CubeLeftFaceUVs = {
	{ 0.0f, 0.0f },
	{ 1.0f, 0.0f },
	{ 1.0f, 1.0f },
	{ 1.0f, 1.0f },
	{ 0.0f, 1.0f },
	{ 0.0f, 0.0f }
};

static std::vector<glm::vec3> CubeRightFace = {
	{  0.5f,  0.5f,  0.5f },
	{  0.5f,  0.5f, -0.5f },
	{  0.5f, -0.5f, -0.5f },
	{  0.5f, -0.5f, -0.5f },
	{  0.5f, -0.5f,  0.5f },
	{  0.5f,  0.5f,  0.5f },
};

static std::vector<glm::vec2> CubeRightFaceUVs = {
	{ 0.0f, 0.0f },
	{ 1.0f, 0.0f },
	{ 1.0f, 1.0f },
	{ 1.0f, 1.0f },
	{ 0.0f, 1.0f },
	{ 0.0f, 0.0f }
};

static std::vector<glm::vec3> CubeFrontFace = {
	{ -0.5f, -0.5f,  0.5f },
	{  0.5f, -0.5f,  0.5f },
	{  0.5f,  0.5f,  0.5f },
	{  0.5f,  0.5f,  0.5f },
	{ -0.5f,  0.5f,  0.5f },
	{ -0.5f, -0.5f,  0.5f }
};

static std::vector<glm::vec2> CubeFrontFaceUVs = {
	{ 1.0f, 1.0f },
	{ 0.0f, 1.0f },
	{ 0.0f, 0.0f },
	{ 0.0f, 0.0f },
	{ 1.0f, 0.0f },
	{ 1.0f, 1.0f }
};

static std::vector<glm::vec3> CubeBackFace = {
	{ -0.5f, -0.5f, -0.5f },
	{  0.5f, -0.5f, -0.5f },
	{  0.5f,  0.5f, -0.5f },
	{  0.5f,  0.5f, -0.5f },
	{ -0.5f,  0.5f, -0.5f },
	{ -0.5f, -0.5f, -0.5f }
};

static std::vector<glm::vec2> CubeBackFaceUVs = {
	{ 1.0f, 1.0f },
	{ 0.0f, 1.0f },
	{ 0.0f, 0.0f },
	{ 0.0f, 0.0f },
	{ 1.0f, 0.0f },
	{ 1.0f, 1.0f }
};

#endif
