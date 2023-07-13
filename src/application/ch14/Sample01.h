#ifndef _H_CH14SAMPLE01_
#define _H_CH14SAMPLE01_

#include "../Application.h"
#include <vector>
#include "../../animation/Pose.h"
#include "../../animation/Clip.h"
#include "../../animation/Skeleton.h"
#include "../../animation/Mesh.h"
#include "../../opengl/Texture.h"
#include "../../opengl/Shader.h"
#include <vector>

class Ch14Sample01 : public Application {
protected:
	Texture* mDiffuseTexture;
	Shader* mLBSShader;
	Shader* mDQShader;
	std::vector<Mesh> mMeshes;
	Skeleton mSkeleton;
	Pose mCurrentPose;

	std::vector<DualQuaternion> mDqPosePalette;
	std::vector<DualQuaternion> mDqInvBindPalette;
	std::vector<mat4> mLbPosePalette;
	std::vector<mat4> mLbInvBindPalette;

	std::vector<Clip> mClips;
	unsigned int mCurrentClip;
	float mPlaybackTime;
public:
	void Initialize();
	void Update(float deltaTime);
	void Render(float inAspectRatio);
	void Shutdown();
};

#endif