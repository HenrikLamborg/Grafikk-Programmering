#pragma once

#include <glad/gl.h>

class VertexBuffer
{
public: 
	VertexBuffer(const void* vertices, GLsizei size);
	~VertexBuffer();

	void Bind() const;
	void Unbind() const;

private:
	GLuint mBufferID;
};