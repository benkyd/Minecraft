#include "shader.hpp"

Shader::Shader()
	: m_fileReader() {

	m_program = 0;
	m_frag = 0;
	m_vert = 0;

	m_logger = std::make_shared<Logger>();

}


void Shader::Load(std::string path) {

	std::string vertexLocation = path + ".vert";
	Load(vertexLocation, GL_VERTEX_SHADER);
	*m_logger << LOGGER_INFO << "Vertex shader at '" << vertexLocation << "' loaded..." << LOGGER_ENDL;


	std::string fragmentLocation = path + ".frag";
	Load(fragmentLocation, GL_FRAGMENT_SHADER);
	*m_logger << LOGGER_INFO << "Fragment shader at '" << fragmentLocation << "' loaded..." << LOGGER_ENDL;

	Link();

}


void Shader::Load(std::string path, GLenum type) {

	GLuint activeShader = 0;

	if (type == GL_VERTEX_SHADER)
		m_vert = activeShader = glCreateShader(type);

	if (type == GL_FRAGMENT_SHADER)
		m_frag = activeShader = glCreateShader(type);

	std::string loadedShaderSource = m_fileReader.LoadTextFromFile(path);
	const char* shaderSource = loadedShaderSource.c_str();
	int shaderSourceLength = loadedShaderSource.length();

	glShaderSource(activeShader, 1, &shaderSource, &shaderSourceLength);

}

void Shader::Link() {

	if (m_vert == 0 || m_frag == 0) {
		*m_logger << LOGGER_ERROR << "Failed to link programs: Both programs not present" << LOGGER_ENDL;
		return;
	}

	glCompileShader(m_vert);
	if (m_CheckShader(m_vert)) {
		*m_logger << LOGGER_INFO << "Vertex shader '" << m_vert << "' compiled..." << LOGGER_ENDL;
	}

	glCompileShader(m_frag);
	if (m_CheckShader(m_frag)) {
		*m_logger << LOGGER_INFO << "Fragment shader '" << m_frag << "' compiled..." << LOGGER_ENDL; 
	}

	m_program = glCreateProgram();

	glAttachShader(m_program, m_vert);
	glAttachShader(m_program, m_frag);

	glLinkProgram(m_program);

	glDeleteShader(m_vert);
	glDeleteShader(m_frag);

	*m_logger << LOGGER_INFO << "Program '" << m_program << "' loaded..." << LOGGER_ENDL;

}

void Shader::Use() {

	glUseProgram(m_program);

}


bool Shader::m_CheckShader(GLuint uid) {

	GLint status = GL_TRUE;

	glGetShaderiv(uid, GL_COMPILE_STATUS, &status);
	
	if (status == GL_FALSE) {
		char buf[512];
		glGetShaderInfoLog(uid, 512, NULL, buf);
		*m_logger << LOGGER_ERROR << buf << LOGGER_ENDL;
		delete buf;
		return false;
	}

	return true;
}


Shader::~Shader() {

	glDeleteProgram(m_program);
	glDeleteShader(m_vert);
	glDeleteShader(m_frag);

}
