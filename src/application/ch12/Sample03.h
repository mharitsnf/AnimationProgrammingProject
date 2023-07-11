#ifndef _H_CH12SAMPLE03_
#define _H_CH12SAMPLE03_

#include "../Application.h"
#include "../../animation/Skeleton.h"
#include "../../animation/Pose.h"
#include "../../animation/Clip.h"
#include "../../animation/Mesh.h"
#include "../../opengl/Shader.h"
#include "../../opengl/Texture.h"
#include "../../animation/CrossFadeController.h"
#include "../../animation/CrossFadeTarget.h"

class Ch12Sample03 : public Application {
protected:
	Shader* mShader;
	Texture* mTexture;
	std::vector<Mesh> mMeshes;
	std::vector<Clip> mClips;
	Skeleton mSkeleton;
	std::vector<mat4> mPosePalette;

	unsigned int mClip;
	unsigned int mAdditiveIndex;

	float mPlaybackTime;
	float mAdditiveTime;
	float mAdditiveDirection;

	Pose mCurrentPose;
	Pose mAddPose;
	Pose mAdditiveBase;
public:
	void Initialize();
	void Update(float inDeltaTime);
	void Render(float inAspectRatio);
	void Shutdown();
};

#endif