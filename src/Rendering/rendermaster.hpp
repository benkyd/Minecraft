#ifndef MINECRAFT_RENDERING_RENDERMASTER_H_
#define MINECRAFT_RENDERING_RENDERMASTER_H_

/**
 * Renderer Structure
 * 
 * Mesh -> Renderable
 * Mesh -> VoxelMesh
 * Renderable -> Model
 * Renderable -> World (static(?))
 * Renderable -> Entity (dynamic)
 * Renderable -> Particle (dynamic)
 * 
 * Kinda just winging it ngl
*/

class WorldRenderer
{

};


class MeshRenderer
{

};


class RenderMaster
{
public:
	RenderMaster();


	WorldRenderer mWorldRenderer;
	MeshRenderer mMeshRenderer;


};

#endif
