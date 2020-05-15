#ifndef MINECRAFT_COMMON_H_
#define MINECRAFT_COMMON_H_

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/hash.hpp>
#include <glm/glm.hpp>

#include <glad/glad.h>
#include <KHR/khrplatform.h>

#include <string>
#include <vector>
#include <memory>
#include <map>

#if _WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#endif
