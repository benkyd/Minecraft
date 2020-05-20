#include "display.hpp"

Display::Display( int w, int h, std::string title )
	: mLogger() 
{
	
	mLogger << LOGGER_INFO << "Initializing display" << LOGGER_ENDL;
	SDL_Init( SDL_INIT_VIDEO|SDL_INIT_AUDIO );

	SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 8 );
	SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 8 );
	SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 8 );
	SDL_GL_SetAttribute( SDL_GL_ALPHA_SIZE, 8 );
	SDL_GL_SetAttribute( SDL_GL_BUFFER_SIZE, 32 );
	SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );

	SDL_GL_SetAttribute( SDL_GL_MULTISAMPLEBUFFERS, 1 );
	SDL_GL_SetAttribute( SDL_GL_MULTISAMPLESAMPLES, 4 );

	SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 4 );
	SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 5 );

	// Create GL window
	mLogger << LOGGER_INFO << "Creating window" << LOGGER_ENDL;
	mWindow = SDL_CreateWindow( title.c_str(),
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, w, h,
		SDL_WINDOW_OPENGL|SDL_WINDOW_RESIZABLE );

	// Create GL context
	mLogger << LOGGER_INFO << "Creating OpenGL context" << LOGGER_ENDL;
	mGlContext = SDL_GL_CreateContext( mWindow );

	SDL_SetRelativeMouseMode( SDL_TRUE );

	// Set VSYNC swap interval
	SDL_GL_SetSwapInterval( 1 );

	mLogger << LOGGER_INFO << "Display set up" << LOGGER_ENDL;

	// Load OpenGL
	gladLoadGLLoader( SDL_GL_GetProcAddress );
	glEnable( GL_MULTISAMPLE );
	// glEnable(GL_CULL_FACE);
	glCullFace( GL_BACK );
	glEnable( GL_DEPTH_TEST );
	// glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	mLogger << LOGGER_INFO << "Loaded OpenGL" << LOGGER_ENDL;
	mLogger << LOGGER_ENDL;

	IsWindowOpen = true;

}

void Display::Input( SDL_Event* e )
{

	Uint8* state = (Uint8*) SDL_GetKeyboardState( NULL );

	while ( SDL_PollEvent( e ) )
	{
		switch ( e->type )
		{

		case SDL_KEYDOWN:
		{
			if ( e->key.keysym.sym == SDLK_ESCAPE )
			{
				IsMouseActive = !IsMouseActive;

				if ( IsMouseActive )
					SDL_SetRelativeMouseMode( SDL_TRUE );
				else
					SDL_SetRelativeMouseMode( SDL_FALSE );
			}

			break;
		}

		case SDL_WINDOWEVENT:
		{
			if ( e->window.event == SDL_WINDOWEVENT_RESIZED )
			{
				mW = e->window.data1; mH = e->window.data2;
				// CameraUpdateProjection( mW, mH );
				glViewport( 0, 0, mW, mH );
			}

			break;
		}

		case SDL_QUIT:
		{
			IsWindowOpen = false;
			break;
		}

		}

		// if ( IsMouseActive ) HandleMouseSDL( *e );
	}

	// m_player->MoveSDL( state );

}

void Display::PrepareFrame()
{
	static const float clear[] = { 186.0f / 255.0f, 214.0f / 255.0f, 254.0f / 255.0f };

	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glClearBufferfv( GL_COLOR, 0, clear );
}

void Display::NextFrame()
{
	SDL_GL_SwapWindow( mWindow );
}

