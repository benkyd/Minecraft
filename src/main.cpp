#include <iostream>
#include <sstream>

#define LOGGER_DEFINITION
#include <logger.h>

#if _WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include "display.hpp"
#include "settings.hpp"

#include "Rendering/rendermaster.hpp"
#include "Rendering/texture.hpp"
#include "Rendering/camera.hpp"
#include "Rendering/mesh.hpp"


#define __DEBUG

static const int VERSION_MAJOR = 0;
static const int VERSION_MINOR = 0;
static const int VERSION_PATCH = 1;

void version()
{
	std::stringstream version;

	const auto& container = []( std::string s ) { std::string r = ""; for ( auto& c : s ) { r += "-"; } return r; };

	version << "Minecraft ";
	version << VERSION_MAJOR << "." << VERSION_MINOR << "." << VERSION_PATCH;

	std::cout << container( version.str() ) << std::endl;
	std::cout << version.str() << std::endl;
	std::cout << container( version.str() ) << std::endl;
}

void Loop( Display* display )
{
	SDL_Event e;




	while ( display->IsWindowOpen )
	{
		display->PrepareFrame();

		// make framerate agnostic
		display->Input( &e );

		// rendering here





		display->NextFrame();
	}

	// cleanup

}

int main( int argc, char** argv )
{
	version();

	Logger mLogger;
	
#ifdef __DEBUG
	mLogger << LOGGER_DEBUG << "Debug mode enabled" << LOGGER_ENDL;
#endif

	// settup display

	std::stringstream version;
	version << "Minecraft ";
	version << VERSION_MAJOR << "." << VERSION_MINOR << "." << VERSION_PATCH;

	Display display { WindowWidth, WindowHeight, version.str() };

	Loop( &display );

	return 0;
}
