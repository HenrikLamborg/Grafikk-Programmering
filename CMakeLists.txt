cmake_minimum_required(VERSION 3.20)

project(GrafikkProgrammering)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(OpenGL REQUIRED)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

add_subdirectory(external/glfw)

add_library(glad
    external/glad/src/gl.c
)

target_include_directories(glad
    PUBLIC
        external/glad/include
)
add_subdirectory(framework)

add_executable(GrafikkProgrammering 
	src/main.cpp
)

target_link_libraries(GrafikkProgrammering
    PRIVATE
        framework
)