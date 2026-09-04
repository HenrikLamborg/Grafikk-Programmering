#include "VertexArray.h"

VertexArray::VertexArray()
{
	glGenVertexArrays(1, &mArrayID);
}

VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &mArrayID);
}

void VertexArray::Bind() const
{
	glBindVertexArray(mArrayID);
}

void VertexArray::Unbind() const
{
	glBindVertexArray(0);
}

void VertexArray::SetVertexAttribute
(
	GLuint index,
	GLint size,
	GLenum type,
	GLboolean normalized,
	GLsizei stride,
	const void* pointer
) const{
	glVertexAttribPointer
	(
		index,
		size,
		type,
		normalized,
		stride,
		pointer
	);

	glEnableVertexAttribArray(index);
}