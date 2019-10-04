#ifndef MINECRAFT_GAME_H_
#define MINECRAFT_GAME_H_

#include <memory>
#include <vector>

#if _WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

class Logger;
class Camera;


class Game {
public:
	Game();

	void Setup(int w, int h);

	void Input(SDL_Event* e);

	void Run();

	bool IsDisplayOpen = false;

private:
	SDL_Window* m_window = nullptr;
	SDL_GLContext m_glContext = nullptr;

	std::shared_ptr<Logger> m_logger;


	std::vector<std::shared_ptr<Camera>> m_cameras;
	std::shared_ptr<Camera> m_activeCamera;

};

#endif
