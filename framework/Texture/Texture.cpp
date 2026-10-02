#include "Texture.h"
#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>


Texture::Texture(const std::string& path)
{
    glGenTextures(1, &mTextureID);

    int width;
    int height;
    int channels;

    unsigned char* data = stbi_load(
        path.c_str(),
        &width,
        &height,
        &channels,
        0
    );

    if (!data) {
        std::cout << "Failed to load texture: " << path << std::endl;
        std::cout << "Reason: " << stbi_failure_reason() << std::endl;
        return;
    }

    glBindTexture(GL_TEXTURE_2D, mTextureID);

    GLenum format;
    if (channels == 4) {
        format = GL_RGBA;
    }
    else {
        format = GL_RGB;
    }

    glTexImage2D(
        GL_TEXTURE_2D,
        0,
        format,
        width,
        height,
        0,
        format,
        GL_UNSIGNED_BYTE,
        data
    );

    glGenerateMipmap(GL_TEXTURE_2D);

    glTexParameteri(
        GL_TEXTURE_2D,
        GL_TEXTURE_MIN_FILTER,
        GL_LINEAR_MIPMAP_LINEAR
    );

    glTexParameteri(
        GL_TEXTURE_2D, 
        GL_TEXTURE_MAG_FILTER, 
        GL_LINEAR
    );

    glTexParameteri(
        GL_TEXTURE_2D,
        GL_TEXTURE_WRAP_S,
        GL_REPEAT
    );

    glTexParameteri(
        GL_TEXTURE_2D,
        GL_TEXTURE_WRAP_T,
        GL_REPEAT
    );

    stbi_image_free(data);
}

Texture::~Texture()
{
    glDeleteTextures(1, &mTextureID);
}

void Texture::Bind() const
{
    glBindTexture(GL_TEXTURE_2D, mTextureID);
}

void Texture::Unbind() const
{
    glBindTexture(GL_TEXTURE_2D, 0);
}