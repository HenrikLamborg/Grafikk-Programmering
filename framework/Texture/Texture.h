#pragma once

#include <glad/gl.h>
#include <string>

class Texture 
{
public: 
	Texture(const std::string& path);
	~Texture();

	void Bind() const;
	void Unbind() const;

private: 
	GLuint mTextureID;
};