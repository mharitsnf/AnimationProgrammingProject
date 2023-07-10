#ifndef _H_CHAPTER11SAMPLE01_
#define _H_CHAPTER11SAMPLE01_

#include "../Application.h"
#include <vector>
#include "../../animation/Pose.h"
#include "../../animation/Clip.h"
#include "../../animation/Skeleton.h"
#include "../../opengl/Texture.h"
#include "../../animation/Mesh.h"
#include "../../opengl/Shader.h"

struct AnimationInstance {
	Pose mAnimatedPose;
	std::vector <mat4> mPosePalette;
	unsigned int mClip;
	float mPlayback;
	Transform mModel;

	inline AnimationInstance() : mClip(0), mPlayback(0.0f) { }
};

class Ch11Sample1 : public Application {
protected:
	Texture* mDiffuseTexture;
	Shader* mStaticShader;
	Shader* mSkinnedShader;
	Skeleton mSkeleton;
	std::vector<Clip> mClips;

	std::vector<Mesh> mCPUMeshes;
	std::vector<Mesh> mGPUMeshes;
	AnimationInstance mCPUInstance;
	AnimationInstance mGPUInstance;
public:
	void Initialize();
	void Update(float deltaTime);
	void Render(float inAspectRatio);
	void Shutdown();
};

#endif