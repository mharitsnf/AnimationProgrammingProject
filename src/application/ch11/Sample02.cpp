#pragma warning(disable : 26451)
#define _CRT_SECURE_NO_WARNINGS
#include "Sample02.h"
#include "../../../external/cgltf/GLTFLoader.h"
#include "../../opengl/Uniform.h"
#include "../../../external/glad/include/glad/glad.h"

void Ch11Sample2::Initialize() {
	cgltf_data* gltf = LoadGLTFFile("assets/models/Woman.gltf");
	mMeshes = LoadMeshes(gltf);
	mSkeleton = LoadSkeleton(gltf);
	std::vector<Clip> clips = LoadAnimationClips(gltf);
	mClips.resize(clips.size());
	for (unsigned int i = 0, size = (unsigned int)clips.size(); i < size; ++i) {
		mClips[i] = OptimizeClip(clips[i]);
	}
	FreeGLTFFile(gltf);

	mSkinnedShader = new Shader("shaders/skinned.vert", "shaders/lit.frag");
	mDiffuseTexture = new Texture("assets/textures/Woman.png");

	mCurrentClip = 0;
	mCurrentPose = mSkeleton.GetRestPose();

	unsigned int numUIClips = (unsigned int)mClips.size();
	for (unsigned int i = 0; i < numUIClips; ++i) {
		if (mClips[i].GetName() == "Walking") {
			mCurrentClip = i;
			break;
		}
	}
}

void Ch11Sample2::Update(float deltaTime) {
	mPlaybackTime = mClips[mCurrentClip].Sample(mCurrentPose, mPlaybackTime + deltaTime);
	mCurrentPose.GetMatrixPalette(mPosePalette);
}

void Ch11Sample2::Render(float inAspectRatio) {
	mat4 projection = perspective(60.0f, inAspectRatio, 0.01f, 1000.0f);
	mat4 view = lookAt(vec3(0, 5, 7), vec3(0, 3, 0), vec3(0, 1, 0));

	mSkinnedShader->Bind();
	Uniform<mat4>::Set(mSkinnedShader->GetUniform("model"), mat4());
	Uniform<mat4>::Set(mSkinnedShader->GetUniform("view"), view);
	Uniform<mat4>::Set(mSkinnedShader->GetUniform("projection"), projection);
	Uniform<vec3>::Set(mSkinnedShader->GetUniform("light"), vec3(1, 1, 1));

	Uniform<mat4>::Set(mSkinnedShader->GetUniform("pose"), mPosePalette);
	Uniform<mat4>::Set(mSkinnedShader->GetUniform("invBindPose"), mSkeleton.GetInvBindPose());

	mDiffuseTexture->Set(mSkinnedShader->GetUniform("tex0"), 0);
	for (unsigned int i = 0, size = (unsigned int)mMeshes.size(); i < size; ++i) {
		mMeshes[i].Bind(mSkinnedShader->GetAttribute("position"), mSkinnedShader->GetAttribute("normal"), mSkinnedShader->GetAttribute("texCoord"), mSkinnedShader->GetAttribute("weights"), mSkinnedShader->GetAttribute("joints"));
		mMeshes[i].Draw();
		mMeshes[i].UnBind(mSkinnedShader->GetAttribute("position"), mSkinnedShader->GetAttribute("normal"), mSkinnedShader->GetAttribute("texCoord"), mSkinnedShader->GetAttribute("weights"), mSkinnedShader->GetAttribute("joints"));
	}
	mDiffuseTexture->UnSet(0);
	mSkinnedShader->UnBind();
}

void Ch11Sample2::Shutdown() {
	delete mDiffuseTexture;
	delete mSkinnedShader;
	mClips.clear();
	mMeshes.clear();
}