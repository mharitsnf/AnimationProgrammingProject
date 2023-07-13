#define _CRT_SECURE_NO_WARNINGS
#include "Sample01.h"
#include "../../../external/cgltf/GLTFLoader.h"
#include "../../opengl/Uniform.h"
#include "../../../external/glad/include/glad/glad.h"
#include <iostream>

void Ch14Sample01::Initialize() {
	cgltf_data* gltf = LoadGLTFFile("assets/models/dq.gltf");
	mMeshes = LoadMeshes(gltf);
	mSkeleton = LoadSkeleton(gltf);
	mClips = LoadAnimationClips(gltf);
	FreeGLTFFile(gltf);

	mLBSShader = new Shader("shaders/skinned.vert", "shaders/lit.frag");
	mDQShader = new Shader("shaders/dualquaternion.vert", "shaders/lit.frag");
	mDiffuseTexture = new Texture("assets/textures/dq.png");

	mCurrentPose = mSkeleton.GetRestPose();

	mCurrentPose.GetDualQuaternionPalette(mDqPosePalette);
	mSkeleton.GetInvBindPose(mDqInvBindPalette);

	mCurrentPose.GetMatrixPalette(mLbPosePalette);
	mLbInvBindPalette = mSkeleton.GetInvBindPose();

	mCurrentClip = 0;
	mPlaybackTime = 0.0f;
}

void Ch14Sample01::Update(float deltaTime) {
	mPlaybackTime = mClips[mCurrentClip].Sample(mCurrentPose, mPlaybackTime + deltaTime);
	mCurrentPose.GetDualQuaternionPalette(mDqPosePalette);
	mCurrentPose.GetMatrixPalette(mLbPosePalette);
}

void Ch14Sample01::Render(float inAspectRatio) {
	mat4 projection = perspective(60.0f, inAspectRatio, 0.01f, 1000.0f);
	mat4 view = lookAt(vec3(0, 3, 14), vec3(0, 0, 0), vec3(0, 1, 0));

	// Dual Quaternion
	Transform model(vec3(2, 2, 0), quat(), vec3(1, 1, 1));
	mDQShader->Bind();
	Uniform<mat4>::Set(mDQShader->GetUniform("model"), transformToMat4(model));
	Uniform<mat4>::Set(mDQShader->GetUniform("view"), view);
	Uniform<mat4>::Set(mDQShader->GetUniform("projection"), projection);
	Uniform<vec3>::Set(mDQShader->GetUniform("light"), vec3(1, 1, 1));
	Uniform<DualQuaternion>::Set(mDQShader->GetUniform("pose"), mDqPosePalette);
	Uniform<DualQuaternion>::Set(mDQShader->GetUniform("invBindPose"), mDqInvBindPalette);

	mDiffuseTexture->Set(mDQShader->GetUniform("tex0"), 0);
	for (unsigned int i = 0, size = (unsigned int)mMeshes.size(); i < size; ++i) {
		mMeshes[i].Bind(mDQShader->GetAttribute("position"), mDQShader->GetAttribute("normal"), mDQShader->GetAttribute("texCoord"), mDQShader->GetAttribute("weights"), mDQShader->GetAttribute("joints"));
		mMeshes[i].Draw();
		mMeshes[i].UnBind(mDQShader->GetAttribute("position"), mDQShader->GetAttribute("normal"), mDQShader->GetAttribute("texCoord"), mDQShader->GetAttribute("weights"), mDQShader->GetAttribute("joints"));
	}
	mDiffuseTexture->UnSet(0);
	mDQShader->UnBind();

	// Linear Blend
	mLBSShader->Bind();
	model.position.x = -2;
	model.position.y = -2;
	Uniform<mat4>::Set(mDQShader->GetUniform("model"), transformToMat4(model));
	Uniform<mat4>::Set(mLBSShader->GetUniform("view"), view);
	Uniform<mat4>::Set(mLBSShader->GetUniform("projection"), projection);
	Uniform<vec3>::Set(mLBSShader->GetUniform("light"), vec3(1, 1, 1));
	Uniform<mat4>::Set(mLBSShader->GetUniform("pose"), mLbPosePalette);
	Uniform<mat4>::Set(mLBSShader->GetUniform("invBindPose"), mLbInvBindPalette);

	mDiffuseTexture->Set(mLBSShader->GetUniform("tex0"), 0);
	for (unsigned int i = 0, size = (unsigned int)mMeshes.size(); i < size; ++i) {
		mMeshes[i].Bind(mLBSShader->GetAttribute("position"), mLBSShader->GetAttribute("normal"), mLBSShader->GetAttribute("texCoord"), mLBSShader->GetAttribute("weights"), mLBSShader->GetAttribute("joints"));
		mMeshes[i].Draw();
		mMeshes[i].UnBind(mLBSShader->GetAttribute("position"), mLBSShader->GetAttribute("normal"), mLBSShader->GetAttribute("texCoord"), mLBSShader->GetAttribute("weights"), mLBSShader->GetAttribute("joints"));
	}
	mDiffuseTexture->UnSet(0);
	mLBSShader->UnBind();
}

void Ch14Sample01::Shutdown() {
	delete mDiffuseTexture;
	delete mLBSShader;
	delete mDQShader;
	mMeshes.clear();
	mClips.clear();
}