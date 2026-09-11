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

void VertexArray::SetLayout(const VertexBufferLayout& layout) {
	const auto& attributes = layout.GetAttributes();
	size_t offset = 0;

	for (int i = 0; i < attributes.size(); i++) {
		GLuint index = i;
		GLint size = attributes[i].Count;
		GLenum type = attributes[i].Type;
		GLboolean normalized = attributes[i].Normalized;
		GLsizei stride = layout.GetStride();
		const void* pointer = reinterpret_cast<const void*>(offset);


		SetVertexAttribute(
			index,
			size,
			type,
			normalized,
			stride,
			pointer
		);


		if (type == GL_FLOAT) {
			offset += size * sizeof(float);
		}
		else if (type == GL_INT) {
			offset += size * sizeof(int);
		}
	}

}