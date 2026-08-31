#include "GLFWApplication.h"
#include <iostream>

GLFWApplication::GLFWApplication(
	const std::string& name,
	const std::string& version
) : mName(name), mVersion(version), mWindow(nullptr)
{
}

GLFWApplication::~GLFWApplication() {
	if (mWindow) {
		glfwDestroyWindow(mWindow);
		glfwTerminate();
	}
}

unsigned GLFWApplication::Init() {
	if (!glfwInit()) {
		std::cout << "Failed to initialize GLFW" << std::endl;
		return -1;
	}

	// Check with AI to explain this better.
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

	// Create window
	mWindow = glfwCreateWindow(
		800,
		600,
		mName.c_str(),
		nullptr,
		nullptr
	);

	if (!mWindow) {
		std::cout << "Failed to create GLFW Window";
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(mWindow);


	// Load glad
	if (!gladLoadGL(glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		glfwTerminate();
		return -1;
	}

	std::cout << "Initialized " << mName << " Version: " << mVersion << std::endl;
	return 0;
}
