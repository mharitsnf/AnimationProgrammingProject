#ifndef _H_VERTEXARRAY_
#define _H_VERTEXARRAY_

class VertexArray {
public:
	unsigned int mHandle;
	unsigned int mCount;

public:
    VertexArray();
    ~VertexArray();

    void Bind();
    void Unbind();

    unsigned int Count();
	unsigned int GetHandle();
};

#endif