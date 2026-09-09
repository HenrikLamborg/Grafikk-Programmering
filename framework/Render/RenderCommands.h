#pragma once

#include <glad/gl.h>

namespace RenderCommands
{
	void Clear() {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Draw(GLenum mode, GLint first, GLsizei count) {
		glDrawArrays(mode, first, count);
	}

	// Render primitives from array data
	void DrawIndexed(GLenum mode, GLsizei count, GLenum type, const void* indices) {
		glDrawElements(mode, count, type, indices);
	}

	void ClearColor(float r, float g, float b, float a) {
		glClearColor(r, g, b, a);
	}
}