#define GLFW_INCLUDE_NONE
#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include "GLFWApplication.h"
#include "Shader.h"
#include "shaders/square.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "GeometricTools.h"
#include "RenderCommands.h"
#include "IndexBuffer.h"


class MyApplication : public GLFWApplication {
public: 
	MyApplication() : GLFWApplication("GrafikkProgrammering", "1.0")
	{
	}

	unsigned Run() const override 
	{

		// VBO
		auto squareVBO = VertexBuffer(GeometricTools::Square2DIndexed.data(), sizeof(GeometricTools::Square2DIndexed));

		// VBL (Layout)
		VertexBufferLayout layout;
		layout.Push(GL_FLOAT, 2, false); // (x, y)
		layout.Push(GL_FLOAT, 3, false); // (r, g, b)

		// VAO
		auto squareVAO = VertexArray();
		squareVAO.Bind();
		squareVAO.SetLayout(layout);

		// EBO
		auto squareEBO = IndexBuffer(GeometricTools::Square2DIndices.data(), sizeof(GeometricTools::Square2DIndices));

		// shader
		Shader shader
		(
			squareVertexShaderSrc,
			squareFragmentShaderSrc
		);
		
		while (!glfwWindowShouldClose(mWindow)) 
		{
			RenderCommands::ClearColor(0.5f, 0.5f, 0.5f, 1.0f);
			RenderCommands::Clear();

			shader.Bind();
			squareVAO.Bind();
			RenderCommands::DrawIndexed(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
			squareVAO.Unbind();
			shader.Unbind();

			glfwSwapBuffers(mWindow);
			glfwPollEvents();
		}

		return 0;
	}
};

int main() {
	MyApplication app;

	if (app.Init() != 0) {
		return -1;
	}
	return app.Run();
}
