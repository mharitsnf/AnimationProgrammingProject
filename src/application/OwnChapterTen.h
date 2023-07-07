#ifndef _H_OWNCHAPTERTEN_
#define _H_OWNCHAPTERTEN_

#include "Application.h"
#include "../opengl/DebugDraw.h"
#include <vector>
#include "../animation/Pose.h"
#include "../animation/Clip.h"
#include "../animation/Skeleton.h"

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
    
public:
	void Initialize();
	void Update(float deltaTime);
	void Render(float inAspectRatio);
	void Shutdown();
};

#endif