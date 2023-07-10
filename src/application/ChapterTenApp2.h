#ifndef _H_CHAPTERTENAPP2_
#define _H_CHAPTERTENAPP2_

#include "Application.h"
#include <vector>
#include "../animation/Pose.h"
#include "../animation/Clip.h"
#include "../animation/Skeleton.h"
#include "../animation/Mesh.h"
#include "../opengl/Texture.h"
#include "../opengl/Shader.h"

#include "../opengl/DebugDraw.h"

struct AnimationInstance {
	Pose mAnimatedPose;
	std::vector <mat4> mPosePalette;
	unsigned int mClip;
	float mPlayback;
	Transform mModel;

	inline AnimationInstance() : mClip(0), mPlayback(0.0f) { }
};

class ChapterTenApp2 : public Application {
protected:
	Texture* mDiffuseTexture;
	Shader* mStaticShader;
	Shader* mSkinnedShader;
	std::vector<Mesh> mCPUMeshes;
	std::vector<Mesh> mGPUMeshes;
	Skeleton mSkeleton;
	std::vector<Clip> mClips;

	AnimationInstance mGPUAnimInfo;
	AnimationInstance mCPUAnimInfo;

public:
	void Initialize();
	void Update(float deltaTime);
	void Render(float inAspectRatio);
	void Shutdown();
};

#endif