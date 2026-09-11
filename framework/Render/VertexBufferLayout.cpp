#include "VertexBufferLayout.h"
#include <iostream>

VertexBufferLayout::VertexBufferLayout()
	: mStride(0)
{
}

void VertexBufferLayout::Push(GLenum type, GLuint count, GLboolean normalized) {
	
	VertexBufferAttributes newAttributes(type, count, normalized);

	switch (type) {
	case GL_FLOAT: 
		mStride += count * sizeof(float);
		break;
	case GL_INT:
		mStride += count * sizeof(int);
		break;

	default:
		std::cout << "Not supported type\n";
		return;
	}
	mAttributes.push_back(newAttributes);
}

const std::vector<VertexBufferAttributes>& VertexBufferLayout::GetAttributes() const{
	return mAttributes;
}

GLsizei VertexBufferLayout::GetStride() const {
	return mStride;
}