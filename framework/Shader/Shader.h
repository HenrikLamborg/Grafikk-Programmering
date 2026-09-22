#pragma once

#include <string>
#include <glad/gl.h>
#include "Mat4.h"

class Shader {
public: 	
	Shader(const std::string& vertexSrc, const std::string& fragSrc);
	~Shader();

	void Bind() const;
	void Unbind() const;
	void SetUniformMat4(const std::string& name, const Mat4& matrix);

private: 
	GLuint mVertexShader;
	GLuint mFragmentShader;
	GLuint mShaderProgram;
};