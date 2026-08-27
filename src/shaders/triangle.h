#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <string>

static const std::string triangleVertexShaderSrc = R"(
#version 330 core

layout(location = 0) in vec2 aPos;

void main()
{
    gl_Position = vec4(aPos, 0.0, 1.0);
}
)";

static const std::string triangleFragmentShaderSrc = R"(
#version 330 core

out vec4 FragColor;

void main()
{
    FragColor = vec4(1.0, 0.0, 0.0, 1.0);
}
)";

#endif