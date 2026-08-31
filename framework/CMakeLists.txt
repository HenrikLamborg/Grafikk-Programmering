add_library(framework
	GLFWApplication/GLFWApplication.cpp
	GLFWApplication/GLFWApplication.h
)

target_include_directories(framework
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}/GLFWApplication
)

target_link_libraries(framework
    PUBLIC
        glfw
        glad
)