#define GLFW_INCLUDE_NONE
#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include "GLFWApplication.h"


class MyApplication : public GLFWApplication {
public: 
	MyApplication() : GLFWApplication("GrafikkProgrammering", "1.0")
	{
	}

	unsigned Run() const override {
		while (!glfwWindowShouldClose(mWindow)) {
			glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

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
