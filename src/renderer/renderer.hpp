#ifndef MINECRAFT_RENDERER_RENDERER_H_
#define MINECRAFT_RENDERER_RENDERER_H_

#include "../common.hpp"

#include "../world/world.hpp"
#include "camera.hpp"

// Does GL render passes then returns to the game loop
class Renderer {
public:
	Renderer();

	void Render(std::shared_ptr<World> world, std::shared_ptr<Camera> camera);

};

#endif
