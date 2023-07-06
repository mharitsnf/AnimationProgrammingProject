#ifndef _H_OWNNINTHAPP_
#define _H_OWNNINTHAPP_

#include "Application.h"
#include "../opengl/DebugDraw.h"
#include "../animation/Pose.h"
#include "../animation/Clip.h"
#include "../animation/Frame.h"
#include "../math/vec3.h"
#include "../math/quat.h"

class OwnNinthApp : public Application {
protected:
	Pose* mPose;
    Clip* mClipA;
    float mPlaybackTime;
    DebugDraw* mPoseVisual;

protected:
    VectorFrame MakeFrame(float time, const vec3& value);
    VectorFrame MakeFrame(float time, const vec3& value, const vec3& in, const vec3& out);
    QuaternionFrame MakeFrame(float time, const quat& value);
	QuaternionFrame MakeFrame(float time, const quat& value, const quat& in, const quat& out);
    
public:
	void Initialize();
	void Update(float inDeltaTime);
	void Render(float inAspectRatio);
	void Shutdown();
};

#endif