#include "IndexBuffer.h"


IndexBuffer::IndexBuffer(const void* data, GLsizei size)
{
	glGenBuffers(1, &mIndexBufferID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIndexBufferID);
	glBufferData(
		GL_ELEMENT_ARRAY_BUFFER,
		size,
		data,
		GL_STATIC_DRAW
	);
}

IndexBuffer::~IndexBuffer() 
{
	glDeleteBuffers(1, &mIndexBufferID);
}

void IndexBuffer::Bind() const {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIndexBufferID);
}

void IndexBuffer::Unbind() const {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}