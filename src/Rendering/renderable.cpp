#include "renderable.hpp"

#include <algorithm>

Renderable::Renderable()
{

}

void Renderable::Init()
{
	
}

void Renderable::AddMesh( Mesh* mesh )
{
	if (mesh == nullptr) return;
	mMeshs.push_back( mesh );
}

void Renderable::RemoveMesh( Mesh* mesh )
{
	// Renderable does not include mesh
	if (std::find( mMeshs.begin(), mMeshs.end(), mesh ) == mMeshs.end())
		return;

	std::remove( mMeshs.begin(), mMeshs.end(), mesh );

}

void Renderable::SetActiveMesh( Mesh* mesh )
{
	// Renderable does not include mesh
	if (std::find( mMeshs.begin(), mMeshs.end(), mesh ) == mMeshs.end())
		return;

	mActiveMesh = mesh;
}

Mesh* Renderable::GetActiveMesh()
{
	return mActiveMesh;
}

void Renderable::UpdateBuffer()
{

}

void Renderable::Load()
{

}

void Renderable::Unload()
{

}

Renderable::~Renderable()
{
	Unload();
}



