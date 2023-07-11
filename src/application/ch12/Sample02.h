#ifndef _H_CH12SAMPLE02_
#define _H_CH12SAMPLE02_

#include "../Application.h"
#include "../../animation/Skeleton.h"
#include "../../animation/Pose.h"
#include "../../animation/Clip.h"
#include "../../animation/Mesh.h"
#include "../../opengl/Shader.h"
#include "../../opengl/Texture.h"
#include "../../animation/CrossFadeController.h"
#include "../../animation/CrossFadeTarget.h"

class Ch12Sample02 : public Application {
protected:
	Shader* mShader;
	Texture* mTexture;
	std::vector<Mesh> mMeshes;
	std::vector<Clip> mClips;
	Skeleton mSkeleton;
	std::vector<mat4> mPosePalette;

	CrossFadeController mFadeController;
	unsigned int mCurrentClip;
	float mFadeTimer;
public:
	void Initialize();
	void Update(float inDeltaTime);
	void Render(float inAspectRatio);
	void Shutdown();
};

#endif