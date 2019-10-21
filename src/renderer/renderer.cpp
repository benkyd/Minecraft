#include "renderer.hpp"

#include "../world/chunk/chunk.hpp"
#include "../world/world.hpp"
#include "shader.hpp"

Renderer::Renderer() {

}

// Perform the render passes
void Renderer::Render(std::shared_ptr<World> world, std::shared_ptr<Camera> camera) {

	glBindTexture(GL_TEXTURE_2D_ARRAY, world->TextureID);
	
	for (int i = 0; i < world->Chunks.size(); i++) {

		world->Chunks[i]->Render(camera, world->Shaders["Basic"]);
	
	}

}
