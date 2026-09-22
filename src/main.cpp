#define GLFW_INCLUDE_NONE
#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include "GLFWApplication.h"
#include "Shader.h"
#include "shaders/cube.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "GeometricTools.h"
#include "RenderCommands.h"
#include "IndexBuffer.h"
#include "Camera.h"

class MyApplication : public GLFWApplication {
public:
	MyApplication() : GLFWApplication("GrafikkProgrammering", "1.0")
	{
	}

	unsigned Run() const override
	{

		// VBO
		auto cubeVBO = VertexBuffer(GeometricTools::Cube3D.data(), sizeof(GeometricTools::Cube3D));

		// VBL (Layout)
		VertexBufferLayout layout;
		layout.Push(GL_FLOAT, 3, false); // (x, y, z)
		layout.Push(GL_FLOAT, 3, false); // (r, g, b)

		// VAO
		auto cubeVAO = VertexArray();
		cubeVAO.Bind();
		cubeVAO.SetLayout(layout);

		// EBO
		auto cubeEBO = IndexBuffer(GeometricTools::Cube3DIndices.data(), sizeof(GeometricTools::Cube3DIndices));

		// shader
		Shader shader
		(
			cubeVertexShaderSrc,
			cubeFragmentShaderSrc
		);

		// Camera settings
		Camera camera;
		Mat4 view = camera.GetViewMatrix();

		Mat4 projection = Mat4::Perspective(
			45.0f,				// FOV in degrees
			800.0f / 600.0f,	// Aspect ratio (width / height)
			0.1f,				// Near clipping plane
			100.0f				// Far clipping plane
		);


		glEnable(GL_DEPTH_TEST);

		while (!glfwWindowShouldClose(mWindow))
		{
			RenderCommands::ClearColor(0.5f, 0.5f, 0.5f, 1.0f);
			RenderCommands::Clear();

			shader.Bind();
			shader.SetUniformMat4("view", view);
			shader.SetUniformMat4("projection", projection);
			cubeVAO.Bind();
			RenderCommands::DrawIndexed(GL_TRIANGLES, 36, GL_UNSIGNED_INT, nullptr);
			cubeVAO.Unbind();
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
