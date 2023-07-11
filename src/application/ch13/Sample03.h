#ifndef _H_CH13SAMPLE03_
#define _H_CH13SAMPLE03_

#include "../Application.h"
#include "../../opengl/DebugDraw.h"
#include <vector>
#include "../../animation/Pose.h"
#include "../../animation/Clip.h"
#include "../../animation/Skeleton.h"
#include "../../animation/Mesh.h"
#include "../../opengl/Texture.h"
#include "../../ik/Intersections.h"
#include "../../ik/IKLeg.h"

class Ch13Sample03 : public Application {
protected:
	Texture* mCourseTexture;
	std::vector<Mesh> mIKCourse;
	std::vector<Triangle> mTriangles;

	VectorTrack mMotionTrack;
	float mWalkingTime;

	Transform mModel;
	std::vector<Mesh> mMeshes;
	Pose mCurrentPose;
	std::vector<mat4> mPosePalette;
	float mSinkIntoGround;

	IKLeg* mLeftLeg;
	IKLeg* mRightLeg;
	float mToeLength;
	float mLastModelY;

	Texture* mDiffuseTexture;
	Shader* mStaticShader;
	Shader* mSkinnedShader;
	Skeleton mSkeleton;
	std::vector<Clip> mClips;
	unsigned int mCurrentClip;
	float mPlaybackTime;
	DebugDraw* mCurrentPoseVisual;

	bool mShowIKPose;
	bool mShowCurrentPose;
	float mTimeMod;
	bool mDepthTest;
	bool mShowMesh;
	bool mShowEnvironment;
public:
	void Initialize();
	void Update(float deltaTime);
	void Render(float inAspectRatio);
	void Shutdown();
};

#endif