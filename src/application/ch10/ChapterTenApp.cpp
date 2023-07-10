#define _CRT_SECURE_NO_WARNINGS
#include "ChapterTenApp.h"
#include "../../../external/cgltf/GLTFLoader.h"

void ChapterTenApp::Initialize() {
	cgltf_data* gltf = LoadGLTFFile("assets/models/Woman.gltf");
	mSkeleton = LoadSkeleton(gltf);
	mClips = LoadAnimationClips(gltf);
	FreeGLTFFile(gltf);

	mRestPoseVisual = new DebugDraw();
	mRestPoseVisual->FromPose(mSkeleton.GetRestPose());
	mRestPoseVisual->UpdateOpenGLBuffers();

	mBindPoseVisual = new DebugDraw();
	mBindPoseVisual->FromPose(mSkeleton.GetBindPose());
	mBindPoseVisual->UpdateOpenGLBuffers();

	mCurrentClip = 0;
	mCurrentPose = mSkeleton.GetRestPose();

	mCurrentPoseVisual = new DebugDraw();
	mCurrentPoseVisual->FromPose(mCurrentPose);
	mCurrentPoseVisual->UpdateOpenGLBuffers();

	// For the UI
	unsigned int numUIClips = (unsigned int)mClips.size();
	for (unsigned int i = 0; i < numUIClips; ++i) {
		if (mClips[i].GetName() == "Walking") {
			mCurrentClip = i;
			break;
		}
	}
}

void ChapterTenApp::Update(float deltaTime) {
	mPlaybackTime = mClips[mCurrentClip].Sample(mCurrentPose, mPlaybackTime + deltaTime);
	mCurrentPoseVisual->FromPose(mCurrentPose);
}

void ChapterTenApp::Render(float inAspectRatio) {
	mat4 projection = perspective(60.0f, inAspectRatio, 0.01f, 1000.0f);
	mat4 view = lookAt(vec3(0, 4, -7), vec3(0, 4, 0), vec3(0, 1, 0));
	mat4 mvp = projection * view; // No model

	mRestPoseVisual->Draw(DebugDrawMode::Lines, vec3(1, 0, 0), mvp);

	mCurrentPoseVisual->UpdateOpenGLBuffers();
	mCurrentPoseVisual->Draw(DebugDrawMode::Lines, vec3(0, 0, 1), mvp);

	mBindPoseVisual->Draw(DebugDrawMode::Lines, vec3(0, 1, 0), mvp);
}

void ChapterTenApp::Shutdown() {
	delete mRestPoseVisual;
	delete mCurrentPoseVisual;
	delete mBindPoseVisual;
	mClips.clear();
}