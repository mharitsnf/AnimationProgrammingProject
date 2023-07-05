#ifndef _H_LEARNOPENGLAPP_
#define _H_LEARNOPENGLAPP_

#include "../math/vec3.h"
#include "../math/vec2.h"


#include "Application.h"
#include "../opengl/Shader.h"
#include "../opengl/Attribute.h"
#include "../opengl/IndexBuffer.h"
#include "../opengl/VertexArray.h"
#include "../opengl/Texture.h"

#define DEG2RAD 0.0174533f

class LearnOpenGLApp : public Application {
protected:
	Shader* mShader;
	Attribute<vec3>* mVertexPositions;
	Attribute<vec2>* mVertexTexCoords;
	IndexBuffer* mIndexBuffer;
    VertexArray* mVertexArray;
	Texture* mDisplayTexture;
	float mRotation;

public:
	void Initialize();
	void Update(float inDeltaTime) { }
	void Render(float inAspectRatio);
	void Shutdown();
};

#endif