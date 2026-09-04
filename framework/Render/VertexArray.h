#pragma once

#include <glad/gl.h>

class VertexArray
{
public:
	VertexArray();
	~VertexArray();

	void Bind() const;
	void Unbind() const;

	void SetVertexAttribute
	(
		GLuint index,
		GLint size,
		GLenum type,
		GLboolean normalized,
		GLsizei stride,
		const void* pointer
	) const;
private:
	GLuint mArrayID;
};