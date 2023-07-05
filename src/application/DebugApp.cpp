#include "DebugApp.h"
#include "../math/vec3.h"
#include "../math/mat4.h"


void DebugApp::Initialize() {
    refLine = new DebugDraw;
    for (unsigned int i = 0; i < 10; ++i) {
		float yPosition = (i * 2.0f) + ((float)i * 0.2f) + 0.1f;
		float height = 1.8f;

		float left = 1.0f;
		float right = 14.0;

		refLine->Push(vec3(left, yPosition, 0));
		refLine->Push(vec3(left, yPosition + height, 0));

		refLine->Push(vec3(left, yPosition, 0));
		refLine->Push(vec3(right, yPosition, 0));
	}
	refLine->UpdateOpenGLBuffers();

    newLine = new DebugDraw;
    newLine->Push(vec3(1.f, 1.f, 0.f));
    newLine->Push(vec3(10.f, 10.f, 0.f));
    newLine->UpdateOpenGLBuffers();
}

void DebugApp::Render(float inAspectRatio) {
    mat4 model;
	mat4 view = lookAt(vec3(0, 0, 5), vec3(0, 0, 0), vec3(0, 1, 0));
	mat4 projection = ortho(0, inAspectRatio * 22.0f, 0, 22, 0.001f, 10);

	mat4 mvp = projection * view * model;

    refLine->Draw(DebugDrawMode::Lines, vec3(1, 1, 1), mvp);
    newLine->Draw(DebugDrawMode::Lines, vec3(1, 1, 1), mvp);
}

void DebugApp::Shutdown() {
    delete refLine;
    delete newLine;
}