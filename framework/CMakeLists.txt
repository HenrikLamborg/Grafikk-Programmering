add_library(framework
	GLFWApplication/GLFWApplication.cpp
	GLFWApplication/GLFWApplication.h
	Shader/Shader.cpp
	Shader/Shader.h
)

target_include_directories(framework
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}/GLFWApplication
		${CMAKE_CURRENT_SOURCE_DIR}/Shader
)

target_link_libraries(framework
    PUBLIC
        glfw
        glad
)