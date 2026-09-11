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


class MyApplication : public GLFWApplication {
public: 
	MyApplication() : GLFWApplication("GrafikkProgrammering", "1.0")
	{
	}

	unsigned Run() const override 
	{

		// VBO
		auto squareVBO = VertexBuffer(GeometricTools::Square2D.data(), sizeof(GeometricTools::Square2D));

		// VBL (Layout)
		VertexBufferLayout layout;
		layout.Push(GL_FLOAT, 2, false); // (x, y)
		layout.Push(GL_FLOAT, 3, false); // (r, g, b)

		// VAO
		auto squareVAO = VertexArray();
		squareVAO.Bind();
		squareVAO.SetLayout(layout);

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
