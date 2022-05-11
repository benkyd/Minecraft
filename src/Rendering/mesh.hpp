#ifndef MINECRAFT_RENDERING_MESH_H_
#define MINECRAFT_RENDERING_MESH_H_

#include "../common.hpp"

class Vertex
{
public:
	glm::vec3 Position;
	glm::vec3 SurfaceNormal;

};

class Mesh
{
public:

	Mesh();
	
private:

	GLuint mVAO;
	GLuint mVBO;

};

#endif
