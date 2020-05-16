#include "shader.hpp"

#include "../utilities.hpp"

Shader::Shader()
{

	Program = 0;
	mFrag = 0;
	mVert = 0;

	mLogger = std::make_shared<Logger>();

}


void Shader::Load( std::string path )
{

	std::string vertexLocation = path + ".vert";
	Load( vertexLocation, GL_VERTEX_SHADER );
	*mLogger << LOGGER_INFO << "Vertex shader at '" << vertexLocation << "' loaded..." << LOGGER_ENDL;


	std::string fragmentLocation = path + ".frag";
	Load( fragmentLocation, GL_FRAGMENT_SHADER );
	*mLogger << LOGGER_INFO << "Fragment shader at '" << fragmentLocation << "' loaded..." << LOGGER_ENDL;

}


void Shader::Load( std::string path, GLenum type )
{

	GLuint activeShader = 0;

	if ( type == GL_VERTEX_SHADER )
		mVert = activeShader = glCreateShader( type );

	if ( type == GL_FRAGMENT_SHADER )
		mFrag = activeShader = glCreateShader( type );

	std::string loadedShaderSource = LoadTextFromFile( path );
	const char* shaderSource = loadedShaderSource.c_str();
	int shaderSourceLength = loadedShaderSource.length();

	glShaderSource( activeShader, 1, &shaderSource, &shaderSourceLength );

}

void Shader::Link()
{

	if ( mVert == 0 || mFrag == 0 )
	{
		*mLogger << LOGGER_ERROR << "Failed to link programs: Both programs not present" << LOGGER_ENDL;
		return;
	}

	glCompileShader( mVert );
	if ( mCheckShader( mVert ) )
	{
		*mLogger << LOGGER_INFO << "Vertex shader '" << mVert << "' compiled..." << LOGGER_ENDL;
	}

	glCompileShader( mFrag );
	if ( mCheckShader( mFrag ) )
	{
		*mLogger << LOGGER_INFO << "Fragment shader '" << mFrag << "' compiled..." << LOGGER_ENDL;
	}

	Program = glCreateProgram();

	glAttachShader( Program, mVert );
	glAttachShader( Program, mFrag );

	glLinkProgram( Program );

	glDeleteShader( mVert );
	glDeleteShader( mFrag );

	*mLogger << LOGGER_INFO << "Program '" << Program << "' loaded..." << LOGGER_ENDL;

}

void Shader::Use()
{

	glUseProgram( Program );

}


bool Shader::mCheckShader( GLuint uid )
{

	GLint status = GL_TRUE;

	glGetShaderiv( uid, GL_COMPILE_STATUS, &status );

	if ( status == GL_FALSE )
	{
		char buf[512];
		glGetShaderInfoLog( uid, 512, NULL, buf );
		*mLogger << LOGGER_ERROR << buf << LOGGER_ENDL;
		delete buf;
		return false;
	}

	return true;
}


Shader::~Shader()
{

	glDeleteProgram( Program );
	glDeleteShader( mVert );
	glDeleteShader( mFrag );

}
