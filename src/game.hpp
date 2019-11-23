#ifndef MINECRAFT_GAME_H_
#define MINECRAFT_GAME_H_

#ifdef NDEBUG
#define __DEBUG
#endif

#define __DEBUG
// #define __IMGUI

#include <memory>
#include <string>
#include <map>

#if _WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

class Logger;

class Renderer;
class Camera;

class Player;
class World;
	
class Game {
public:
	Game();

	void Setup(int w, int h);

	void Input(SDL_Event* e);

	void Run();

	bool IsDisplayOpen = false;
	bool IsMouseActive = true;

private:
	SDL_Window* m_window = nullptr;
	SDL_GLContext m_glContext = nullptr;

	std::shared_ptr<Logger> m_logger;

	std::shared_ptr<Renderer> m_renderer;
	std::shared_ptr<World> m_world;

	std::shared_ptr<Player> m_player;
	
};

#endif
