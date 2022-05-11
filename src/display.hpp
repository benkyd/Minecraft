#ifndef MINECRAFT_DISPLAY_H_
#define MINECRAFT_DISPLAY_H_

#include <string>

#include <logger.h>

#if _WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include <glad/glad.h>
#include <KHR/khrplatform.h>

class Display
{
public:

	Display( int w, int h, std::string title );

	void Input( SDL_Event* e );

	void PrepareFrame();
	void NextFrame();

	bool IsWindowOpen = false;
	bool IsMouseActive = true;

private:

	Logger mLogger;

	SDL_Window* mWindow = nullptr;
	SDL_GLContext mGlContext = nullptr;

	int mW, mH;

};

#endif
