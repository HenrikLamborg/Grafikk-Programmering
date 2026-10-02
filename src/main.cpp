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
#include <glm/glm.hpp>
#include "Texture.h"

// Function declarations
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xOffset, double yOffset);

class MyApplication : public GLFWApplication {
public:
	MyApplication() : GLFWApplication("GrafikkProgrammering", "1.0")
	{
	}

	unsigned Run() const override
	{

		// VBO
		auto cubeVBO = VertexBuffer(GeometricTools::Cube3DV2.data(), sizeof(GeometricTools::Cube3DV2));

		// VBL (Layout)
		VertexBufferLayout layout;
		layout.Push(GL_FLOAT, 3, false); // (x, y, z)
		layout.Push(GL_FLOAT, 3, false); // (r, g, b)
		layout.Push(GL_FLOAT, 2, false); // texture coordinates

		// VAO
		auto cubeVAO = VertexArray();
		cubeVAO.Bind();
		cubeVAO.SetLayout(layout);

		// EBO
		auto cubeEBO = IndexBuffer(GeometricTools::Cube3DV2Indices.data(), sizeof(GeometricTools::Cube3DV2Indices));

		// shader
		Shader shader
		(
			cubeVertexShaderSrc,
			cubeFragmentShaderSrc
		);


		// Texture
		Texture  texture("assets/wall.jpg");
		

		// Camera settings
		Camera camera;

		glfwSetWindowUserPointer(mWindow, &camera);
		glfwSetCursorPosCallback(mWindow, mouse_callback);
		glfwSetScrollCallback(mWindow, scroll_callback);
		glfwSetInputMode(mWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);


		glEnable(GL_DEPTH_TEST);

		float lastTime = 0.0f;

		while (!glfwWindowShouldClose(mWindow))
		{
			RenderCommands::ClearColor(0.5f, 0.5f, 0.5f, 1.0f);
			RenderCommands::Clear();

			// Time management
			float currentTime = static_cast<float>(glfwGetTime());
			float deltaTime = currentTime - lastTime;
			lastTime = currentTime;

			// Input handling
			float cameraSpeed = 2.0f;
			if (glfwGetKey(mWindow, GLFW_KEY_W) == GLFW_PRESS)
			{
				camera.MoveForward(cameraSpeed * deltaTime);
			}

			if (glfwGetKey(mWindow, GLFW_KEY_S) == GLFW_PRESS)
			{
				camera.MoveForward(-cameraSpeed * deltaTime);
			}

			if (glfwGetKey(mWindow, GLFW_KEY_D) == GLFW_PRESS)
			{
				camera.MoveRight(cameraSpeed * deltaTime);
			}

			if (glfwGetKey(mWindow, GLFW_KEY_A) == GLFW_PRESS)
			{
				camera.MoveLeft(cameraSpeed * deltaTime);
			}

			if (glfwGetKey(mWindow, GLFW_KEY_SPACE) == GLFW_PRESS)
				camera.MoveUp(cameraSpeed * deltaTime);

			if (glfwGetKey(mWindow, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
				camera.MoveDown(cameraSpeed * deltaTime);

			if (glfwGetKey(mWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
				glfwSetWindowShouldClose(mWindow, true);


			// Camera
			glm::mat4 view = camera.GetViewMatrix();
			glm::mat4 model = glm::mat4(1.0f);
			glm::mat4 projection = glm::perspective(
				glm::radians(camera.GetZoom()),
				800.0f / 600.0f,
				0.1f,
				100.0f
			);
			

			shader.Bind();

			glActiveTexture(GL_TEXTURE0);
			texture.Bind();

			shader.SetUniform1i("textureSampler", 0);
			shader.SetUniformMat4("view", view);
			shader.SetUniformMat4("projection", projection);
			shader.SetUniformMat4("model", model);
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

/// <summary>
/// GLFW mouse movement callback that computes cursor offsets, updates stored last cursor position on first use, and forwards the movement to a Camera obtained from the window user pointer.
/// </summary>
/// <param name="window">Pointer to the GLFW window; used to retrieve the Camera object via glfwGetWindowUserPointer.</param>
/// <param name="xpos">Current cursor x position in screen coordinates.</param>
/// <param name="ypos">Current cursor y position in screen coordinates.</param>
void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	static bool firstMouse = true;
	static float lastX = 400.0f;
	static float lastY = 300.0f;

	if (firstMouse)
	{
		lastX = static_cast<float>(xpos);
		lastY = static_cast<float>(ypos);
		firstMouse = false;
	}

	float xOffset = static_cast<float>(xpos) - lastX;
	float yOffset = lastY - static_cast<float>(ypos);


	lastX = static_cast<float>(xpos);
	lastY = static_cast<float>(ypos);

	Camera* camera = static_cast<Camera*>(glfwGetWindowUserPointer(window));
	camera->ProcessMouseMovement(xOffset, yOffset);
}

/// <summary>
/// Scroll callback that forwards vertical scroll input to a Camera instance stored in the GLFW window user pointer.
/// </summary>
/// <param name="window">Pointer to the GLFW window whose user pointer is expected to hold a Camera instance.</param>
/// <param name="xOffset">Horizontal scroll offset (unused by this callback).</param>
/// <param name="yOffset">Vertical scroll offset forwarded to Camera::ProcessMouseScroll as a float.</param>
void scroll_callback(GLFWwindow* window, double xOffset, double yOffset)
{
	Camera* camera = static_cast<Camera*>(glfwGetWindowUserPointer(window));
	camera->ProcessMouseScroll(static_cast<float>(yOffset));
}

int main() {
	MyApplication app;

	if (app.Init() != 0) {
		return -1;
	}
	return app.Run();
}
