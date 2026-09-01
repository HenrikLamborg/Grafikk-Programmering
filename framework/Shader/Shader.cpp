#include "Shader.h"

Shader::Shader(
	const std::string& vertexSrc,
	const std::string& fragmentSrc
) 
{
	// Create Vertex shader
	mVertexShader = glCreateShader(GL_VERTEX_SHADER);

	const char* vertexShaderSrc = vertexSrc.c_str();

	glShaderSource(
		mVertexShader,
		1,
		&vertexShaderSrc,
		nullptr
	);

	glCompileShader(mVertexShader);


	// Create Fragment shader
	mFragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	const char* fragmentShaderSrc = fragmentSrc.c_str();

	glShaderSource(
		mFragmentShader,
		1,
		&fragmentShaderSrc,
		nullptr
	);

	glCompileShader(mFragmentShader);


	// Shader program
	mShaderProgram = glCreateProgram();

	glAttachShader(mShaderProgram, mVertexShader);
	glAttachShader(mShaderProgram, mFragmentShader);

	glLinkProgram(mShaderProgram);

	// Delete shaders
	glDeleteShader(mVertexShader);
	glDeleteShader(mFragmentShader);
}

// Deconstructor 
Shader::~Shader() {
	glDeleteProgram(mShaderProgram);
}

void Shader::Bind() const{
	glUseProgram(mShaderProgram);
}

void Shader::Unbind() const{
	glUseProgram(0);
}