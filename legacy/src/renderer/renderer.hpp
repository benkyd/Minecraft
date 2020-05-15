#ifndef MINECRAFT_RENDERER_RENDERER_H_
#define MINECRAFT_RENDERER_RENDERER_H_

#include "../common.hpp"

class Camera;
class World;

// Does GL render passes then returns to the game loop
class Renderer {
public:
	Renderer();

	void Render(std::shared_ptr<World> world, std::shared_ptr<Camera> camera);

};

#endif
