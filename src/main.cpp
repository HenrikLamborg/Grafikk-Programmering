#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <iostream>
#include <glad/gl.h>
#include "shaders/triangle.h"

int main() {
	
	if (!glfwInit()) {
		std::cout << "Failed to initialize GLFW" << std::endl;
		return -1;
	}

	GLFWwindow* window = glfwCreateWindow(
		800, 
		600, 
		"GrafikkProgrammering", 
		NULL, 
		NULL
	);

	glfwMakeContextCurrent(window);

	if (!gladLoadGL(glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		glfwTerminate();
		return EXIT_FAILURE;
	}

	// Create and compile the vertex shader
	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	const char* vertexShaderSource = triangleVertexShaderSrc.c_str();

	glShaderSource(
		vertexShader,
		1,
		&vertexShaderSource,
		nullptr
	);
	glCompileShader(vertexShader);

	// Check for shader compilation errors
	int success;
	char infoLog[512];

	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
			<< infoLog << std::endl;
	}


	// Fragment shader
	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	const char* fragmentShaderSource = triangleFragmentShaderSrc.c_str();

	glShaderSource(
		fragmentShader,
		1,
		&fragmentShaderSource,
		nullptr
	);

	glCompileShader(fragmentShader);

	// Check for shader compilation errors
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n"
			<< infoLog << std::endl;
	}

	// Shader program
	unsigned int shaderProgram = glCreateProgram();

	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	// Check for linking errors
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);

	if (!success)
	{
		glGetProgramInfoLog(shaderProgram, 512, nullptr, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n"
			<< infoLog << std::endl;
	}

	// Clean up shaders after linking
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);


	// Triangle example
	float vertices[] = {
		 0.0f,  0.5f,
		-0.5f, -0.5f,
		 0.5f, -0.5f
	};

	unsigned int VBO;
	unsigned int VAO;

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(
		GL_ARRAY_BUFFER, 
		sizeof(vertices), 
		vertices, 
		GL_STATIC_DRAW
	);

	glVertexAttribPointer(
		0,					// attribute location
		2,					// number of values
		GL_FLOAT,			// data type
		GL_FALSE,			// normalize?
		2 * sizeof(float),	// stride
		(void*)0			// offset
	);

	glEnableVertexAttribArray(0);

	while (!glfwWindowShouldClose(window)) 
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// Draw the triangle
		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}