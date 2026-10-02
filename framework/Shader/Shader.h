#pragma once

#include <string>
#include <glad/gl.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader {
public: 	
	Shader(const std::string& vertexSrc, const std::string& fragSrc);
	~Shader();

	void Bind() const;
	void Unbind() const;
	void SetUniformMat4(const std::string& name, const glm::mat4& matrix);
	void SetUniform1i(const std::string& name, int value);

private: 
	GLuint mVertexShader;
	GLuint mFragmentShader;
	GLuint mShaderProgram;
};