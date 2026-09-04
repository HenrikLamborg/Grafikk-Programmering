#include "VertexBuffer.h"


VertexBuffer::VertexBuffer
(
	const void* vertices,
	GLsizei size
) 
{
	glGenBuffers(1, &mBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, mBufferID);

	// Upload buffer data
	glBufferData(
		GL_ARRAY_BUFFER,
		size,
		vertices,
		GL_STATIC_DRAW
	);
}

VertexBuffer::~VertexBuffer() 
{
	glDeleteBuffers(1, &mBufferID);
}

void VertexBuffer::Bind() const 
{
	glBindBuffer(GL_ARRAY_BUFFER, mBufferID);
}

void VertexBuffer::Unbind() const 
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}