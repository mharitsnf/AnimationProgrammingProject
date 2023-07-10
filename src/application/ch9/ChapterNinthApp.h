#ifndef _H_CHAPTERNINTHAPP_
#define _H_CHAPTERNINTHAPP_

#include "../Application.h"
#include "../../opengl/DebugDraw.h"
#include <vector>
#include "../../animation/Pose.h"
#include "../../animation/Clip.h"

class ChapterNinthApp : public Application {
protected:
	Pose mRestPose;
	Pose mCurrentPose;
	std::vector<Clip> mClips;
	unsigned int mCurrentClip;
	float mPlaybackTime;
	DebugDraw* mRestPoseVisual;
	DebugDraw* mCurrentPoseVisual;
	
public:
	void Initialize();
	void Update(float deltaTime);
	void Render(float inAspectRatio);
	void Shutdown();
};

#endif