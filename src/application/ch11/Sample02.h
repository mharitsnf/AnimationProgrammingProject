#ifndef _H_CHAPTER11SAMPLE02_
#define _H_CHAPTER11SAMPLE02_

#include "../Application.h"
#include <vector>
#include "../../animation/Pose.h"
#include "../../animation/Clip.h"
#include "../../animation/Skeleton.h"
#include "../../animation/Mesh.h"
#include "../../opengl/Texture.h"
#include "../../opengl/Shader.h"

class Ch11Sample2 : public Application {
protected:
	Texture* mDiffuseTexture;
	Shader* mSkinnedShader;
	std::vector<Mesh> mMeshes;
	std::vector<mat4> mPosePalette;
	Skeleton mSkeleton;
	Pose mCurrentPose;
	std::vector<FastClip> mClips;
	unsigned int mCurrentClip;
	float mPlaybackTime;
public:
	void Initialize();
	void Update(float deltaTime);
	void Render(float inAspectRatio);
	void Shutdown();
};

#endif