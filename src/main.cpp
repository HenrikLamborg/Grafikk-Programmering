#define GLFW_INCLUDE_NONE
#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include "GLFWApplication.h"
#include "Shader.h"
#include "shaders/triangle.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "GeometricTools.h"


class MyApplication : public GLFWApplication {
public: 
	MyApplication() : GLFWApplication("GrafikkProgrammering", "1.0")
	{
	}

	unsigned Run() const override 
	{

		// VBO
		auto triangleVBO = VertexBuffer(GeometricTools::Triangle2D.data(), sizeof(GeometricTools::Triangle2D));

		// VAO
		auto triangleVAO = VertexArray();
		triangleVAO.Bind();
		triangleVAO.SetVertexAttribute(
			0,
			2,
			GL_FLOAT,
			false,
			2 * sizeof(float),
			nullptr
		);

		// shader
		Shader shader
		(
			triangleVertexShaderSrc,
			triangleFragmentShaderSrc
		);
		
		while (!glfwWindowShouldClose(mWindow)) 
		{
			glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			shader.Bind();
			triangleVAO.Bind();
			glDrawArrays(GL_TRIANGLES, 0, 3);
			triangleVAO.Unbind();
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
