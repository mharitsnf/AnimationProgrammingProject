#include "Sample01.h"
#include "../../../external/cgltf/GLTFLoader.h"
#include "../../animation/Blending.h"
#include "../../opengl/Uniform.h"

void Ch12Sample01::Initialize() {
	cgltf_data* gltf = LoadGLTFFile("assets/models/Woman.gltf");
	mSkeleton = LoadSkeleton(gltf);
	mClips = LoadAnimationClips(gltf);
	mMeshes = LoadMeshes(gltf);
	FreeGLTFFile(gltf);

    // get the rest pose, bind matrix, and inverse bind matrix
	mPose = mSkeleton.GetRestPose();
	mPose.GetMatrixPalette(mPosePalette);
	mSkinPalette = mSkeleton.GetInvBindPose();

    // use GPU skinning
	mShader = new Shader("shaders/skinned.vert", "shaders/lit.frag");
	mTexture = new Texture("assets/textures/Woman.png");

	mA.mPose = mPose;
	mB.mPose = mPose;

	mBlendTime = 0.0f;
	mInvertBlend = false;

	mA.mClip = 0;
	mB.mClip = 1;
	for (unsigned int i = 0, size = (unsigned int)mClips.size(); i < size; ++i) {
		if (mClips[i].GetName() == "Walking") {
			mA.mClip = i;
			mA.mTime = mClips[i].GetStartTime();
		}
		else if (mClips[i].GetName() == "Running") {
			mB.mClip = i;
			mB.mTime = mClips[i].GetStartTime();
		}
	}
}

void Ch12Sample01::Shutdown() {
	mClips.clear();
	mMeshes.clear();
	delete mShader;
	delete mTexture;
}

void Ch12Sample01::Update(float dt) {
	mA.mTime = mClips[mA.mClip].Sample(mA.mPose, mA.mTime + dt);
	mB.mTime = mClips[mB.mClip].Sample(mB.mPose, mB.mTime + dt);

	float bt = mBlendTime;
    // do some clamping
	if (bt < 0.0f) { bt = 0.0f; }
	if (bt > 1.0f) { bt = 1.0f; }
    
    // blend time will be from 1 to 0 if inverted
	if (mInvertBlend) { bt = 1.0f - bt; }

    // call blend, and update the matrix palette
	Blend(mPose, mA.mPose, mB.mPose, bt, -1);
	mPose.GetMatrixPalette(mPosePalette);


	mBlendTime += dt;
	if (mBlendTime >= 2.0f) {
		mBlendTime = 0.0f;
		mInvertBlend = !mInvertBlend;
		mPose = mSkeleton.GetRestPose();
	}
}

void Ch12Sample01::Render(float aspect) {
	mat4 model;
	mat4 view = lookAt(vec3(0, 3, 5), vec3(0, 3, 0), vec3(0, 1, 0));
	mat4 projection = perspective(60.0f, aspect, 0.01f, 1000.0f);

	mShader->Bind();
	Uniform<mat4>::Set(mShader->GetUniform("model"), model);
	Uniform<mat4>::Set(mShader->GetUniform("view"), view);
	Uniform<mat4>::Set(mShader->GetUniform("projection"), projection);
	Uniform<mat4>::Set(mShader->GetUniform("pose"), mPosePalette);
	Uniform<mat4>::Set(mShader->GetUniform("invBindPose"), mSkinPalette);
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