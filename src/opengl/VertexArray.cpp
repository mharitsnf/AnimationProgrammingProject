#include "VertexArray.h"
#include "../../external/glad/include/glad/glad.h"


VertexArray::VertexArray() {
    glGenVertexArrays(1, &mHandle);
    mCount = 0;
}

VertexArray::~VertexArray() {
    glDeleteVertexArrays(1, &mHandle);
}

unsigned int VertexArray::Count() {
	return mCount;
}

unsigned int VertexArray::GetHandle() {
	return mHandle;
}

void VertexArray::Bind() {
	glBindVertexArray(mHandle);
}

void VertexArray::Unbind() {
	glBindVertexArray(0);
}