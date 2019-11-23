#include "renderer.hpp"

#include "../world/chunk/chunk.hpp"
#include "../world/world.hpp"
#include "shader.hpp"

Renderer::Renderer() {

}

// Perform the render passes
void Renderer::Render(std::shared_ptr<World> world, std::shared_ptr<Entity> entity) {

	world->Render(entity);

}
