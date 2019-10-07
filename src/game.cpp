#include "game.hpp"

#define LOGGER_DEFINITION
#include <logger.h>

#include "renderer/renderer.hpp"
#include "renderer/texture.hpp"
#include "renderer/shader.hpp"
#include "renderer/camera.hpp"
#include "renderer/face.hpp"

#include "world/world.hpp"
#include "world/block.hpp"

#include "common.hpp"
#include "config.hpp"


Game::Game() {

}

void Game::Setup(int w, int h) {

	m_logger = std::make_shared<Logger>();

	*m_logger << "----------------" << LOGGER_ENDL;
	*m_logger << "Minecraft 1.14.2" << LOGGER_ENDL;
	*m_logger << "----------------" << LOGGER_ENDL;
	*m_logger << LOGGER_ENDL;

#ifdef __DEBUG
	*m_logger << LOGGER_DEBUG << "Debug mode enabled" << LOGGER_ENDL;
#endif

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

	SDL_WarpMouseInWindow(m_window, w / 2, h / 2);
	SDL_SetRelativeMouseMode(SDL_TRUE);

	// Set VSYNC swap interval
	SDL_GL_SetSwapInterval(1);

	*m_logger << LOGGER_INFO << "Display set up" << LOGGER_ENDL;

	// Load OpenGL
	gladLoadGLLoader(SDL_GL_GetProcAddress);
	glEnable(GL_MULTISAMPLE);
	glEnable(GL_DEPTH_TEST);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

#ifdef __IMGUI
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGui::StyleColorsDark();
	// ImGui_ImplSDL2_InitForOpenGL(m_window, m_glContext);

	ImGuiIO& io = ImGui::GetIO();

	ImVec2 vec;
	vec.x = (float)w;
	vec.y = (float)h;
	io.DisplaySize = vec;

	vec.x = w > 0 ? ((float)w / w) : 0;
	vec.y = h > 0 ? ((float)h / h) : 0;
	io.DisplayFramebufferScale = vec;
	io.Fonts->AddFontDefault();

	unsigned char* pixels;
	int width, height, bytes_per_pixels;
	io.Fonts->GetTexDataAsRGBA32(&pixels, &width, &height, &bytes_per_pixels);

	ImGui_ImplOpenGL3_Init("#version 450");
#endif

	
	*m_logger << LOGGER_INFO << "Loaded OpenGL" << LOGGER_ENDL;
	*m_logger << LOGGER_ENDL;
	IsDisplayOpen = true;

	m_cameras["Default"] = std::make_shared<Camera>();
	m_activeCamera = m_cameras["Default"];

}

void Game::Input(SDL_Event* e) {

	while (SDL_PollEvent(e)) {
		m_activeCamera->HandleMouse(*e);
		if (e->type == SDL_QUIT)
			IsDisplayOpen = false;
	}

	m_activeCamera->MoveCamera();

}

void Game::Run() {
	
	SDL_Event e;

	const float clear[] = { 0.1f, 0.45f, 0.9f, 1.0f };
	
	m_renderer = std::make_unique<Renderer>();
	m_world = std::make_unique<World>();

	m_world->Faces.push_back(std::make_shared<Face>(FaceDirection::Top, 2, 1));
	m_world->Faces.push_back(std::make_shared<Face>(FaceDirection::Bottom, 0, 2));
	m_world->Faces.push_back(std::make_shared<Face>(FaceDirection::Right, 1, 3));
	m_world->Faces.push_back(std::make_shared<Face>(FaceDirection::Left, 1, 4));
	m_world->Faces.push_back(std::make_shared<Face>(FaceDirection::Front, 1, 5));
	m_world->Faces.push_back(std::make_shared<Face>(FaceDirection::Back, 1, 6));

	m_world->Shaders["Basic"] = std::make_shared<Shader>();
	m_world->Shaders["Basic"]->Load(GameConfig.ResourceBase + "shaders/simple");
	m_world->Shaders["Basic"]->Link();

	Texture texture;
	m_world->TextureID = texture.LoadTextures(TextureIdsAndPaths);

	while (IsDisplayOpen) {

		Input(&e);
		
#ifdef __IMGUI
		ImGui::NewFrame();

		ImGui::Begin("bruh");
		ImGui::Text("Hello, world %d", 123);
		if (ImGui::Button("Save")) {}
		ImGui::End();
#endif
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearBufferfv(GL_COLOR, 0, clear);

		m_renderer->Render(m_world , m_activeCamera);

#ifdef __IMGUI
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
#endif
		SDL_GL_SwapWindow(m_window);

	}

}
