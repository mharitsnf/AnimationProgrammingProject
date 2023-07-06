#define _CRT_SECURE_NO_WARNINGS
#include "ChapterNinthApp.h"
#include <string>
#include "../../external/cgltf/GLTFLoader.h"

void ChapterNinthApp::Initialize() {
	cgltf_data* gltf = LoadGLTFFile("assets/models/Woman.gltf");
	mRestPose = LoadRestPose(gltf);
	mClips = LoadAnimationClips(gltf);
	FreeGLTFFile(gltf);

	mRestPoseVisual = new DebugDraw();
	mRestPoseVisual->FromPose(mRestPose);
	mRestPoseVisual->UpdateOpenGLBuffers();

	mCurrentClip = 0;
	mCurrentPose = mRestPose;

	mCurrentPoseVisual = new DebugDraw();
	mCurrentPoseVisual->FromPose(mCurrentPose);
	mCurrentPoseVisual->UpdateOpenGLBuffers();

	// For the UI
	unsigned int numUIClips = (unsigned int)mClips.size();
	for (unsigned int i = 0; i < numUIClips; ++i) {
		if (mClips[i].GetName() == "Lean_Left") {
			mCurrentClip = i;
			break;
		}
	}
}

void ChapterNinthApp::Update(float deltaTime) {
	mPlaybackTime = mClips[mCurrentClip].Sample(mCurrentPose, mPlaybackTime + deltaTime);
	mCurrentPoseVisual->FromPose(mCurrentPose);
}

void ChapterNinthApp::Render(float inAspectRatio) {
	mat4 projection = perspective(60.0f, inAspectRatio, 0.01f, 1000.0f);
	mat4 view = lookAt(vec3(0, 4, 7), vec3(0, 4, 0), vec3(0, 1, 0));
	mat4 mvp = projection * view; // No model

	mRestPoseVisual->Draw(DebugDrawMode::Lines, vec3(1, 0, 0), mvp);
	mCurrentPoseVisual->UpdateOpenGLBuffers();
	mCurrentPoseVisual->Draw(DebugDrawMode::Lines, vec3(0, 0, 1), mvp);
}

void ChapterNinthApp::Shutdown() {
	delete mRestPoseVisual;
	delete mCurrentPoseVisual;
	mClips.clear();
}