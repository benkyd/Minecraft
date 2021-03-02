#ifndef MINECRAFT_RENDERER_VOXELMESH_H_
#define MINECRAFT_RENDERER_VOXELMESH_H_

#include "mesh.hpp"

class VoxelMesh : public Mesh
{
public:

	VoxelMesh();



	int Width;
	int Height;
	int Depth;

	// Size is w*h*d
	std::vector<uint8_t> Voxels;

};

#endif
