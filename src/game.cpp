#include "game.hpp"

#define LOGGER_DEFINITION
#include <logger.h>

#include "common.hpp"


Game::Game() {

}

void Game::Setup(int w, int h) {
	m_logger = std::make_shared<Logger>();

	*m_logger << "----------------" << LOGGER_ENDL;
	*m_logger << "Minecraft 1.14.2" << LOGGER_ENDL;
	*m_logger << "----------------" << LOGGER_ENDL;
	*m_logger << LOGGER_ENDL;


	*m_logger << LOGGER_INFO << "Initializing display" << LOGGER_ENDL;
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);

	// Create GL window
	*m_logger << LOGGER_INFO << "Creating window" << LOGGER_ENDL;
	m_window = SDL_CreateWindow("Minecraft 1.14.2",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, w, h,
		SDL_WINDOW_OPENGL);

	// Create GL context
	*m_logger << LOGGER_INFO << "Creating OpenGL context" << LOGGER_ENDL;
	m_glContext = SDL_GL_CreateContext(m_window);

	// SDL_WarpMouseInWindow(window, w / 2, h / 2);
	// SDL_SetRelativeMouseMode(SDL_TRUE);

	// Set VSYNC swap interval
	SDL_GL_SetSwapInterval(0);

	*m_logger << LOGGER_INFO << "Display set up" << LOGGER_ENDL;

	// Load OpenGL
	gladLoadGLLoader(SDL_GL_GetProcAddress);
	glEnable(GL_MULTISAMPLE);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	
	*m_logger << LOGGER_INFO << "Loaded OpenGL" << LOGGER_ENDL;
	*m_logger << LOGGER_ENDL;
	IsDisplayOpen = true;
}

void Game::Input(SDL_Event* e) {
	while (SDL_PollEvent(e))
		if (e->type == SDL_QUIT)
			IsDisplayOpen = false;
}

void Game::Run() {
	
	SDL_Event e;

	while (IsDisplayOpen) {

		Input(&e);

		SDL_GL_SwapWindow(m_window);

		glClear(GL_DEPTH_BUFFER_BIT);
		const float clear[] = { 0.1f, 0.45f, 0.9f, 1.0f };
		glClearBufferfv(GL_COLOR, 0, clear);

	}

}
