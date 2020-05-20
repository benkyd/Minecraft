#ifndef MINECRAFT_RENDERING_SHADER_H_
#define MINECRAFT_RENDERING_SHADER_H_

#include <logger.h>

#include <glad/glad.h>

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
	std::shared_ptr<Logger> mLogger;

	bool mCheckShader(GLuint uid);

	GLuint mVert;
	GLuint mFrag;
};

#endif
