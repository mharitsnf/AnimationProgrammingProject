#ifndef _H_OWNCHAPTERTEN_
#define _H_OWNCHAPTERTEN_

#include "Application.h"
#include "../opengl/DebugDraw.h"
#include "../opengl/Shader.h"
#include "../opengl/Texture.h"
#include "../animation/Pose.h"
#include "../animation/Clip.h"
#include "../animation/Skeleton.h"
#include "../animation/Mesh.h"
#include <vector>


class OwnChapterTen : public Application {
protected:
	Skeleton mSkeleton;
	Pose mCurrentPose;
	std::vector<Clip> mClips;
	unsigned int mCurrentClip;
	float mPlaybackTime;
	DebugDraw* mBindPoseVisual;
	DebugDraw* mRestPoseVisual;
	DebugDraw* mCurrentPoseVisual;

	Shader* mStaticShader;
	std::vector<Mesh> mMeshes;
	Texture* mDiffuseTexture;
    
public:
	void Initialize();
	void Update(float deltaTime);
	void Render(float inAspectRatio);
	void Shutdown();
};

#endif