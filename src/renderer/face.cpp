#include "face.hpp"

Face::Face(FaceDirection direction, int textureID) {
	Direction = direction;
	Texture = textureID;

	m_uvs = {
		{ 0.0f, 0.0f },
		{ 1.0f, 0.0f },
		{ 1.0f, 1.0f },
		{ 1.0f, 1.0f },
		{ 0.0f, 1.0f },
		{ 0.0f, 0.0f }
	};

	switch (Direction) {case FaceDirection::Top:
		{

			m_verticies = {
				{ -0.5f, -0.5f, -0.5f },
				{  0.5f, -0.5f, -0.5f },
				{  0.5f,  0.5f, -0.5f },
				{  0.5f,  0.5f, -0.5f },
				{ -0.5f,  0.5f, -0.5f },
				{ -0.5f, -0.5f, -0.5f },
			};

			break;

		}

		case FaceDirection::Bottom:
		{

			m_verticies = {
				{ -0.5f, -0.5f,  0.5f },
				{  0.5f, -0.5f,  0.5f },
				{  0.5f,  0.5f,  0.5f },
				{  0.5f,  0.5f,  0.5f },
				{ -0.5f,  0.5f,  0.5f },
				{ -0.5f, -0.5f,  0.5f },
			};

			break;

		}

		case FaceDirection::Front:
		{

			m_verticies = {
				{ -0.5f,  0.5f,  0.5f },
				{ -0.5f,  0.5f, -0.5f },
				{ -0.5f, -0.5f, -0.5f },
				{ -0.5f, -0.5f, -0.5f },
				{ -0.5f, -0.5f,  0.5f },
				{ -0.5f,  0.5f,  0.5f },
			};

			break;

		}

		case FaceDirection::Back:
		{

			m_verticies = {
				{  0.5f,  0.5f,  0.5f },
				{  0.5f,  0.5f, -0.5f },
				{  0.5f, -0.5f, -0.5f },
				{  0.5f, -0.5f, -0.5f },
				{  0.5f, -0.5f,  0.5f },
				{  0.5f,  0.5f,  0.5f },
			};

			break;

		}

		case FaceDirection::Left:
		{

			m_verticies = {
				{ -0.5f, -0.5f, -0.5f },
				{  0.5f, -0.5f, -0.5f },
				{  0.5f, -0.5f,  0.5f },
				{  0.5f, -0.5f,  0.5f },
				{ -0.5f, -0.5f,  0.5f },
				{ -0.5f, -0.5f, -0.5f },
			};

			break;

		}

		case FaceDirection::Right:
		{

			m_verticies = {
				{ -0.5f,  0.5f, -0.5f },
				{  0.5f,  0.5f, -0.5f },
				{  0.5f,  0.5f,  0.5f },
				{  0.5f,  0.5f,  0.5f },
				{ -0.5f,  0.5f,  0.5f },
				{ -0.5f,  0.5f, -0.5f },
			};

			break;

		}

	};

}

void Face::GetMesh(std::vector<glm::vec3>& verts, std::vector<glm::vec2>& uvs) {

}
