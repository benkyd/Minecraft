#ifndef MINECRAFT_COMMON_H_
#define MINECRAFT_COMMON_H_

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <imgui/imgui.h>
#include <imgui/imgui_impl_sdl.h>
#include <imgui/imgui_impl_opengl3.h>

#include <glad/glad.h>
#include <KHR/khrplatform.h>

#include <string>
#include <vector>
#include <memory>

#if _WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#endif
