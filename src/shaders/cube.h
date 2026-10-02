#pragma once

#include <string>

static const std::string cubeVertexShaderSrc = R"(
#version 330 core

layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aColor;
layout(location = 2) in vec2 aTexCoord;

out vec3 vColor;
out vec2 vTexCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    vColor = aColor;
    vTexCoord = aTexCoord;

    gl_Position = projection * view * model * vec4(aPos, 1.0);
}
)";

static const std::string cubeFragmentShaderSrc = R"(
#version 330 core

in vec3 vColor;
in vec2 vTexCoord;

out vec4 FragColor;

uniform sampler2D textureSampler;

void main()
{
    FragColor = texture(textureSampler, vTexCoord);
}
)";