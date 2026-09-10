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
		auto squareVBO = VertexBuffer(GeometricTools::Square2D.data(), sizeof(GeometricTools::Square2D));

		// VAO
		auto squareVAO = VertexArray();
		squareVAO.Bind();
		squareVAO.SetVertexAttribute(
			0,
			2,
			GL_FLOAT,
			false,
			5 * sizeof(float),
			nullptr
		);

		squareVAO.SetVertexAttribute(
			1,
			3,
			GL_FLOAT,
			false,
			5 * sizeof(float),
			reinterpret_cast<const void*>(2 * sizeof(float))
		);

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
			RenderCommands::Draw(GL_TRIANGLES, 0, 6);
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
