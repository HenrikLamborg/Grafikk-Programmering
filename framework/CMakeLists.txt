add_library(framework
	GLFWApplication/GLFWApplication.cpp
	GLFWApplication/GLFWApplication.h
	Shader/Shader.cpp
	Shader/Shader.h
	Render/VertexBuffer.cpp
	Render/VertexBuffer.h
)

target_include_directories(framework
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}/GLFWApplication
		${CMAKE_CURRENT_SOURCE_DIR}/Shader
		${CMAKE_CURRENT_SOURCE_DIR}/Render
)

target_link_libraries(framework
    PUBLIC
        glfw
        glad
)