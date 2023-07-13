#ifndef _H_CHAPTER15SAMPLE01_
#define _H_CHAPTER15SAMPLE01_

#include "../Application.h"
#include <vector>
#include "../../animation/Pose.h"
#include "../../animation/Clip.h"
#include "../../animation/Skeleton.h"
#include "../../animation/Mesh.h"
#include "../../opengl/Texture.h"
#include "../../opengl/AnimTexture.h"
#include "../../animation/Crowd.h"

class Ch15Sample01 : public Application {
protected:
	Texture* mDiffuseTexture;
	Shader* mCrowdShader;
	std::vector<Mesh> mMeshes;
	Skeleton mSkeleton;
	std::vector<Clip> mClips;
	std::vector<AnimTexture> mTextures;
	std::vector<Crowd> mCrowds;

protected:
	void SetCrowdSize(unsigned int size);
	bool CheckFileExists(const std::string& path);
    
public:
	void Initialize();
	void Update(float deltaTime);
	void Render(float inAspectRatio);
	void Shutdown();
};

#endif