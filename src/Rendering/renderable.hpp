#ifndef MINECRAFT_RENDERING_RENDERABLE_H_
#define MINECRAFT_RENDERING_RENDERABLE_H_

#include "../common.hpp"

class Mesh;

// Basically a model but thats effort
// perhaps sub-class?
class Renderable
{
public:
	Renderable();

	void Init();

	// DOES NOT OWN MESH
	void AddMesh( Mesh* );
	void RemoveMesh( Mesh* );
	void SetActiveMesh( Mesh* );
	Mesh* GetActiveMesh();

	void UpdateBuffer();

	// GPU Load methods
	void Load();
	void Unload();

	~Renderable();

private:

	std::vector<glm::vec3> mBuff;

	std::vector<Mesh*> mMeshs;
	Mesh* mActiveMesh;

	// Meshes have uniform uniforms
	GLuint mUBO;

	glm::mat4 mModelMatrix;

};

#endif
