#ifndef _H_CH12SAMPLE01_
#define _H_CH12SAMPLE01_

#include "../Application.h"
#include "../../animation/Skeleton.h"
#include "../../animation/Pose.h"
#include "../../animation/Clip.h"
#include "../../animation/Mesh.h"
#include "../../opengl/Shader.h"
#include "../../opengl/Texture.h"

struct AnimationInstance {
	unsigned int mClip;
	float mTime;
	Pose mPose;
};

// Blending between walk and run on a timer
class Ch12Sample01 : public Application {
protected:
	Shader* mShader;
	Texture* mTexture;
	std::vector<Mesh> mMeshes;
	std::vector<Clip> mClips;
	Skeleton mSkeleton;
	Pose mPose;
	std::vector<mat4> mPosePalette;
	std::vector<mat4> mSkinPalette;

	AnimationInstance mA;
	AnimationInstance mB;
	float mBlendTime;
	bool mInvertBlend;
public:
	void Initialize();
	void Update(float inDeltaTime);
	void Render(float inAspectRatio);
	void Shutdown();
};

#endif