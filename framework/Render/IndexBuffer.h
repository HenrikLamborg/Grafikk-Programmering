#pragma once

#include <glad/gl.h>

class IndexBuffer
{
public:
	IndexBuffer
	(
		const void* data,
		GLsizei size
	);

	~IndexBuffer();

	void Bind() const;
	void Unbind() const;
private:
	GLuint mIndexBufferID;
};