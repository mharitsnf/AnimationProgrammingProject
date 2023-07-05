#include "DebugApp.h"
#include "../math/vec3.h"
#include "../math/mat4.h"
#include "../animation/Frame.h"
#include "../animation/Track.h"
#include <iostream>


void DebugApp::Initialize() {
    mTestLine = new DebugDraw;

	ScalarTrack track;
	track.SetInterpolation(Interpolation::Constant);
	track.Resize(5);

	ScalarFrame frame0;
	frame0.mTime = 0.0f;
	frame0.mValue[0] = 1.f;
	frame0.mIn[0] = 0.f;
	frame0.mOut[0] = 0.f;

	ScalarFrame frame1;
	frame1.mTime = 0.2f;
	frame1.mValue[0] = 0.f;
	frame1.mIn[0] = 0.f;
	frame1.mOut[0] = 0.f;

	ScalarFrame frame2;
	frame2.mTime = 0.6f;
	frame2.mValue[0] = 1.f;
	frame2.mIn[0] = 0.f;
	frame2.mOut[0] = 0.f;

	ScalarFrame frame3;
	frame3.mTime = 0.8f;
	frame3.mValue[0] = 0.f;
	frame3.mIn[0] = 0.f;
	frame3.mOut[0] = 0.f;

	ScalarFrame frame4;
	frame4.mTime = 1.f;
	frame4.mValue[0] = 1.f;
	frame4.mIn[0] = 0.f;
	frame4.mOut[0] = 0.f;

	track[0] = frame0;
	track[1] = frame1;
	track[2] = frame2;
	track[3] = frame3;
	track[4] = frame4;

	// scaling the x axis
	float left = 1.f;
	float right = 16.f;
	float xRange = right - left;

	// scaling the y axis
	float bottom = 5.f;
	float top = 10.f;
	float yRange = top - bottom;

	int sampleSize = 50;
	for (int i = 1; i < sampleSize; ++i) {
		float thisINorm = (float)(i - 1) / (float)(sampleSize-1);
		float nextINorm = (float)(i) / (float)(sampleSize-1);

		float x0 = left + thisINorm * xRange;
		float x1 = left + nextINorm * xRange;

		float y0 = track.Sample(thisINorm, false);
		float y1 = track.Sample(nextINorm, false);

		y0 = bottom + y0 * yRange;
		y1 = bottom + y1 * yRange;
		
		mTestLine->Push(vec3(x0, y0, 0.f));
		mTestLine->Push(vec3(x1, y1, 0.f));
	}

	mTestLine->UpdateOpenGLBuffers();
}

void DebugApp::Render(float inAspectRatio) {
    mat4 model;
	mat4 view = lookAt(vec3(0, 0, 5), vec3(0, 0, 0), vec3(0, 1, 0));
	mat4 projection = ortho(0, inAspectRatio * 22.0f, 0, 22, 0.001f, 10);

	mat4 mvp = projection * view * model;

    mTestLine->Draw(DebugDrawMode::Lines, vec3(0, 1, 0), mvp);
}

void DebugApp::Shutdown() {
    delete mTestLine;
}