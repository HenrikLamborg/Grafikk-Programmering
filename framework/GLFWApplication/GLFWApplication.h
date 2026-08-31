#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <string>

class GLFWApplication
{
public:
	GLFWApplication(
		const std::string& name,
		const std::string& version
	); // Constructor
	virtual ~GLFWApplication(); // Destructor

	virtual unsigned Init(); // Initialize the application

	virtual unsigned Run() const = 0; // Main loop

protected:
	std::string mName; // Application name
	std::string mVersion; // Application version
	GLFWwindow* mWindow; // Pointer to the GLFW window
};