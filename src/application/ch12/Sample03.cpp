#include "Sample03.h"
#include "../../../external/cgltf/GLTFLoader.h"
#include "../../animation/Blending.h"
#include "../../opengl/Uniform.h"

void Ch12Sample03::Initialize() {
	cgltf_data* gltf = LoadGLTFFile("assets/models/Woman.gltf");
	mSkeleton = LoadSkeleton(gltf);
	mClips = LoadAnimationClips(gltf);
	mMeshes = LoadMeshes(gltf);
	FreeGLTFFile(gltf);

	mShader = new Shader("shaders/skinned.vert", "shaders/lit.frag");
	mTexture = new Texture("assets/textures/Woman.png");

	mAdditiveTime = 0.0f;
	mAdditiveDirection = 1.0f;

	mClip = 0;
	mAdditiveIndex = 0;
	for (unsigned int i = 0, size = (unsigned int)mClips.size(); i < size; ++i) {
		if (mClips[i].GetName() == "Lean_Left") {
			mAdditiveIndex = i;
		}
		if (mClips[i].GetName() == "Walking") {
			mClip = i;
		}
	}

    // sample using the first frame of the lean left (the additive layer)
	mAdditiveBase = MakeAdditivePose(mSkeleton, mClips[mAdditiveIndex]);
	mClips[mAdditiveIndex].SetLooping(false);

	mCurrentPose = mSkeleton.GetRestPose(); 
	mAddPose = mSkeleton.GetRestPose();
	mPlaybackTime = 0.0f;
}

void Ch12Sample03::Shutdown() {
	mClips.clear();
	mMeshes.clear();
	delete mShader;
	delete mTexture;
}

void Ch12Sample03::Update(float dt) {
	mAdditiveTime += dt * mAdditiveDirection;

	if (mAdditiveTime < 0.0f) {
		mAdditiveTime = 0.0f;
		mAdditiveDirection *= -1.0f;
	}

	if (mAdditiveTime > 1.0f) {
		mAdditiveTime = 1.0f;
		mAdditiveDirection *= -1.0f;
	}

    // sample both poses. the current pose should be sampled normally
    // the additive pose is sampled according to the additive time above
    // it is scaled using the duration of the clip.
	mPlaybackTime = mClips[mClip].Sample(mCurrentPose, mPlaybackTime + dt);
	float time = mClips[mAdditiveIndex].GetStartTime() + (mClips[mAdditiveIndex].GetDuration() * mAdditiveTime);
	mClips[mAdditiveIndex].Sample(mAddPose, time);

    // finally, add the add pose to the current pose using the additive base
	Add(mCurrentPose, mCurrentPose, mAddPose, mAdditiveBase, -1);

	mCurrentPose.GetMatrixPalette(mPosePalette);
}

void Ch12Sample03::Render(float aspect) {
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