#ifndef _H_INDEXBUFFER_
#define _H_INDEXBUFFER_

#include <vector>

// Abstraction of EBO

class IndexBuffer {
public:
	unsigned int mHandle;
	unsigned int mCount;

private:
	IndexBuffer(const IndexBuffer& other);
	IndexBuffer& operator=(const IndexBuffer& other);

public:
	IndexBuffer();
	~IndexBuffer();

	void Set(unsigned int* inputArray, unsigned int arrayLengt);
	void Set(std::vector<unsigned int>& input);
    void Unbind();

	unsigned int Count();
	unsigned int GetHandle();
};


#endif