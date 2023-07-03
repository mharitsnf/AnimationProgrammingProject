#ifndef _H_DRAW_
#define _H_DRAW_

#include "IndexBuffer.h"
#include "VertexArray.h"

enum class DrawMode {
	Points,
	LineStrip,
	LineLoop,
	Lines,
	Triangles,
	TriangleStrip,
	TriangleFan
};

void Draw(IndexBuffer& inIndexBuffer, DrawMode mode);
void Draw(IndexBuffer& inIndexBuffer, VertexArray& inVertexArray, DrawMode mode);
void Draw(unsigned int vertexCount, DrawMode mode);

void DrawInstanced(IndexBuffer& inIndexBuffer, DrawMode mode, unsigned int instanceCount);
void DrawInstanced(unsigned int vertexCount, DrawMode mode, unsigned int numInstances);

#endif