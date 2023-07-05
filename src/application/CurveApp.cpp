#include "CurveApp.h"
#include "../math/vec3.h"
#include "../math/mat4.h"


void CurveApp::Initialize() {
    line = new DebugDraw;

    line->Push(vec3(  0.f,  0.f, 0.0f));
    line->Push(vec3( 10.f, 10.f, 0.0f));
    line->UpdateOpenGLBuffers();
}

void CurveApp::Render(float inAspectRatio) {
    mat4 model;
	mat4 view = lookAt(vec3(0, 0, 5), vec3(0, 0, 0), vec3(0, 1, 0));
	mat4 projection = ortho(0, inAspectRatio * 22.0f, 0, 22, 0.001f, 10);

	mat4 mvp = projection * view * model;

    line->Draw(DebugDrawMode::Lines, vec3(1,1,1), mvp);
}

void CurveApp::Shutdown() {
    delete line;
}