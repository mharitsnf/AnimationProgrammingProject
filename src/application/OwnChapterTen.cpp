#define _CRT_SECURE_NO_WARNINGS
#include "OwnChapterTen.h"
#include "../../external/cgltf/GLTFLoader.h"
#include "../opengl/Uniform.h"

void OwnChapterTen::Initialize() {
	cgltf_data* gltf = LoadGLTFFile("assets/models/Woman.gltf");
	mMeshes = LoadMeshes(gltf);
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
		if (mClips[i].GetName() == "Running") {
			mCurrentClip = i;
			break;
		}
	}

	mStaticShader = new Shader("shaders/static.vert", "shaders/lit.frag");
	mDiffuseTexture = new Texture();
	mDiffuseTexture->Load("assets/textures/Woman.png");
	for (auto mesh : mMeshes) {
		std::cout << mesh.GetPosition().size() << "\n";
		mesh.UpdateOpenGLBuffers();
		mesh.Bind(mStaticShader->GetAttribute("position"), mStaticShader->GetAttribute("normal"), mStaticShader->GetAttribute("texCoord"), -1, -1);
	}
}

void OwnChapterTen::Update(float deltaTime) {
	mPlaybackTime = mClips[mCurrentClip].Sample(mCurrentPose, mPlaybackTime + deltaTime);
	mCurrentPoseVisual->FromPose(mCurrentPose);
}

void OwnChapterTen::Render(float inAspectRatio) {
	mat4 projection = perspective(60.0f, inAspectRatio, 0.01f, 1000.0f);
	mat4 view = lookAt(vec3(0, 4, -7), vec3(0, 4, 0), vec3(0, 1, 0));
	mat4 model;
	mat4 mvp = projection * view; // No model

	mRestPoseVisual->Draw(DebugDrawMode::Lines, vec3(1, 0, 0), mvp);

	mCurrentPoseVisual->UpdateOpenGLBuffers();
	mCurrentPoseVisual->Draw(DebugDrawMode::Lines, vec3(0, 0, 1), mvp);

	mBindPoseVisual->Draw(DebugDrawMode::Lines, vec3(0, 1, 0), mvp);

	// mesh draw
	mStaticShader->Bind();
	Uniform<mat4>::Set(mStaticShader->GetUniform("model"), model);
	Uniform<mat4>::Set(mStaticShader->GetUniform("view"), view);
	Uniform<mat4>::Set(mStaticShader->GetUniform("projection"), projection);
	Uniform<vec3>::Set(mStaticShader->GetUniform("light"), vec3(1, 1, 1));
	mDiffuseTexture->Set(mStaticShader->GetUniform("tex0"), 0);

	for (auto mesh : mMeshes) {
		mesh.Draw();
	}

	mDiffuseTexture->UnSet(0);
	mStaticShader->UnBind();
}

void OwnChapterTen::Shutdown() {
	delete mStaticShader;
	delete mDiffuseTexture;
	mMeshes.clear();

	delete mRestPoseVisual;
	delete mCurrentPoseVisual;
	delete mBindPoseVisual;
	mClips.clear();
}