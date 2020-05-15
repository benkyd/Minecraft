#ifndef MINECRAFT_RENDERER_SHADER_H_
#define MINECRAFT_RENDERER_SHADER_H_

#include <logger.h>

#include "../util/filereader.hpp"
#include "../common.hpp"

class Shader {
public:
	Shader();

	void Load(std::string path);
	void Load(std::string path, GLenum type);

	GLuint Program;
	void Link();

	void Use();

	~Shader();
private:
	std::shared_ptr<Logger> m_logger;

	bool m_CheckShader(GLuint uid);

	FileReader m_fileReader;

	GLuint m_vert;
	GLuint m_frag;
};

#endif
