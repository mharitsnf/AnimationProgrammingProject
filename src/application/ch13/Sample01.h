#ifndef _H_CH13SAMPLE01_
#define _H_CH13SAMPLE01_

#include "../Application.h"
#include "../../opengl/DebugDraw.h"
#include <vector>
#include "../../animation/TransformTrack.h"
#include "../../ik/CCDSolver.h"

class Ch13Sample01 : public Application {
protected:
	Transform mTarget;
	CCDSolver mSolver;
	DebugDraw* mSolverLines;
	DebugDraw* mSolverPoints;
	DebugDraw* mTargetVisual[3];
	TransformTrack mTargetPath;
	float mPlayTime;
	float mCamPitch;
	float mCamYaw;
	float mCamDist;
protected:
	void SetFrame(VectorTrack& track, int index, float time, const vec3& value);
public:
	void Initialize();
	void Update(float deltaTime);
	void Render(float inAspectRatio);
	void Shutdown();
};

#endif