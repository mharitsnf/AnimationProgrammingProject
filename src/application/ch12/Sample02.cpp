#include "Sample02.h"
#include "../../../external/cgltf/GLTFLoader.h"
#include "../../animation/Blending.h"
#include "../../opengl/Uniform.h"

void Ch12Sample02::Initialize() {
	cgltf_data* gltf = LoadGLTFFile("assets/models/Woman.gltf");
	mSkeleton = LoadSkeleton(gltf);
	mClips = LoadAnimationClips(gltf);
	mMeshes = LoadMeshes(gltf);
	FreeGLTFFile(gltf);

	mShader = new Shader("shaders/skinned.vert", "shaders/lit.frag");
	mTexture = new Texture("assets/textures/Woman.png");

	mFadeController.SetSkeleton(mSkeleton);
	mFadeController.Play(&mClips[0]);
	mFadeController.Update(0.0f);
	mFadeController.GetCurrentPose().GetMatrixPalette(mPosePalette);

	mFadeTimer = 3.0f;
	mCurrentClip = 0;
}

void Ch12Sample02::Shutdown() {
	mClips.clear();
	mMeshes.clear();
	delete mShader;
	delete mTexture;
}

void Ch12Sample02::Update(float dt) {
	mFadeController.Update(dt);

	mFadeTimer -= dt;
	if (mFadeTimer < 0.0f) {
		mFadeTimer = 3.0f;

		unsigned int clip = mCurrentClip;
		while (clip == mCurrentClip) {
			clip = rand() % mClips.size();
		}
		mCurrentClip = clip;

		mFadeController.FadeTo(&mClips[clip], 0.5f);
	}

    // update bind matrix palette
	mFadeController.GetCurrentPose().GetMatrixPalette(mPosePalette);
}

void Ch12Sample02::Render(float aspect) {
	mat4 model;
	mat4 view = lookAt(vec3(0, 3, 7), vec3(0, 3, 0), vec3(0, 1, 0));
	mat4 projection = perspective(60.0f, aspect, 0.01f, 1000.0f);

	mShader->Bind();
	Uniform<mat4>::Set(mShader->GetUniform("model"), model);
	Uniform<mat4>::Set(mShader->GetUniform("view"), view);
	Uniform<mat4>::Set(mShader->GetUniform("projection"), projection);
	Uniform<mat4>::Set(mShader->GetUniform("pose"), mPosePalette);
	Uniform<mat4>::Set(mShader->GetUniform("invBindPose"), mSkeleton.GetInvBindPose());
	Uniform<vec3>::Set(mShader->GetUniform("light"), vec3(1, 1, 1));
	mTexture->Set(mShader->GetUniform("tex0"), 0);
	for (unsigned int i = 0, size = (unsigned int)mMeshes.size(); i < size; ++i) {
		mMeshes[i].Bind(mShader->GetAttribute("position"), mShader->GetAttribute("normal"), mShader->GetAttribute("texCoord"), mShader->GetAttribute("weights"), mShader->GetAttribute("joints"));
		mMeshes[i].Draw();
		mMeshes[i].UnBind(mShader->GetAttribute("position"), mShader->GetAttribute("normal"), mShader->GetAttribute("texCoord"), mShader->GetAttribute("weights"), mShader->GetAttribute("joints"));
	}
	mTexture->UnSet(0);

	mShader->UnBind();
}