#include "Texture.h"
#include "../../external/stb_image/stb_image.h"
#include "../../external/glad/include/glad/glad.h"

#include <iostream>

Texture::Texture() {
	mWidth = 0;
	mHeight = 0;
	mChannels = 0;
	glGenTextures(1, &mHandle);
}

Texture::Texture(const char* path) {
	glGenTextures(1, &mHandle);
	Load(path);
}

Texture::~Texture() {
	glDeleteTextures(1, &mHandle);
}


void Texture::Load(const char* path) {
	glBindTexture(GL_TEXTURE_2D, mHandle);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int width, height, channels;
    stbi_set_flip_vertically_on_load(true);
	unsigned char* data = stbi_load(path, &width, &height, &channels, 4);

    if (data) {
	    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	    glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        std::cout << "Failed to load image.\n";
    }

	stbi_image_free(data);
	glBindTexture(GL_TEXTURE_2D, 0);

	mWidth = width;
	mHeight = height;
	mChannels = channels;
}

void Texture::Set(unsigned int uniformIndex, unsigned int textureIndex) {
	glActiveTexture(GL_TEXTURE0 + textureIndex);
	glBindTexture(GL_TEXTURE_2D, mHandle);
	glUniform1i(uniformIndex, textureIndex);
}

void Texture::UnSet(unsigned int textureIndex) {
	glActiveTexture(GL_TEXTURE0 + textureIndex);
	glBindTexture(GL_TEXTURE_2D, 0);
	glActiveTexture(GL_TEXTURE0);
}

unsigned int Texture::GetHandle() {
	return mHandle;
}