#pragma once
#include "glad/gl.h"
#include <vector>

struct VertexBufferAttributes {
	VertexBufferAttributes(GLenum type, GLuint count, GLboolean normalized)
		: Type(type), Count(count), Normalized(normalized) {
	}

	GLenum Type;
	GLuint Count;
	GLboolean Normalized;
};

class VertexBufferLayout {
public:
	VertexBufferLayout();
	
	void Push(GLenum type, GLuint count, GLboolean normalized);

	const std::vector<VertexBufferAttributes>& GetAttributes() const;

	GLsizei GetStride() const;



private: 
	std::vector<VertexBufferAttributes> mAttributes;
	GLsizei mStride;
};