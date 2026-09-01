#pragma once

#include <string>
#include <glad/gl.h>

class Shader {
public: 	
	Shader(const std::string& vertexSrc, const std::string& fragSrc);
	~Shader();

	void Bind() const;
	void Unbind() const;

private: 
	GLuint mVertexShader;
	GLuint mFragmentShader;
	GLuint mShaderProgram;
};