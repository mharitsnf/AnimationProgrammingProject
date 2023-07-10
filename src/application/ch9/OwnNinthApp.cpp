#include "OwnNinthApp.h"
#include "../../animation/Transform.h"
#include "../../animation/TransformTrack.h"
#include "../../animation/Track.h"
#include "../../math/mat4.h"

void OwnNinthApp::Initialize() {
    // Pose setup
    mPose = new Pose(2);

    // First, we make the joints for the pose. For this application, I want to have two joints only.
    // The second joint will be the child of the first joint, and the first joint will be the root.

    Transform jointA;
    jointA.position = vec3(3, 5, 0);
    mPose->SetLocalTransform(0, jointA);
    mPose->SetParent(0, -1);

    Transform jointB;
    jointB.position = vec3(4, 6, 0);
    mPose->SetLocalTransform(1, jointB);
    mPose->SetParent(1, 0);

    // Clip setup
    mClipA = new Clip();

    // Now we make a clip. A clip is composed of multiple tracks (vector<TransformTrack>), and each track corresponds to one joint.
    // In this case, we need two TransformTracks.

    // Track for joint A
    // The get functions returns a track. It also creates one if the track does not exist.
    VectorTrack &posTrackA = mClipA->operator[](0).GetPositionTrack();
    VectorTrack &scaleTrackA =  mClipA->operator[](0).GetScaleTrack();
    QuaternionTrack &rotTrackA = mClipA->operator[](0).GetRotationTrack();

    posTrackA.Resize(2);
    VectorFrame posFrame0 = MakeFrame(0.0f, vec3(3, 5, 0)); // absolute position
    VectorFrame posFrame1 = MakeFrame(1.0f, vec3(3, 5, 0)); // absolute position
    posTrackA[0] = posFrame0;
    posTrackA[1] = posFrame1;
    
    scaleTrackA.Resize(2);
    VectorFrame scaleFrame0 = MakeFrame(0.0f, vec3(1, 1, 1));
    VectorFrame scaleFrame1 = MakeFrame(1.0f, vec3(1, 1, 1));
    scaleTrackA[0] = scaleFrame0;
    scaleTrackA[1] = scaleFrame1;

    rotTrackA.Resize(2);
    QuaternionFrame rotFrame0 = MakeFrame(0.0f, quat(0,0,0,1));
    QuaternionFrame rotFrame1 = MakeFrame(1.0f, quat(0,0,0,1));
    rotTrackA[0] = rotFrame0;
    rotTrackA[1] = rotFrame1;

    // Track for joint B
    VectorTrack &posTrackB = mClipA->operator[](1).GetPositionTrack();
    VectorTrack &scaleTrackB =  mClipA->operator[](1).GetScaleTrack();
    QuaternionTrack &rotTrackB = mClipA->operator[](1).GetRotationTrack();

    posTrackB.Resize(2);
    posFrame0 = MakeFrame(0.0f, vec3(0, 0, 0)); // relative to the parent's position
    posFrame1 = MakeFrame(1.0f, vec3(1, -1, 0)); // relative to the parent's position
    posTrackB[0] = posFrame0;
    posTrackB[1] = posFrame1;
    
    scaleTrackB.Resize(2);
    scaleFrame0 = MakeFrame(0.0f, vec3(1, 1, 1));
    scaleFrame1 = MakeFrame(1.0f, vec3(1, 1, 1));
    scaleTrackB[0] = scaleFrame0;
    scaleTrackB[1] = scaleFrame1;

    rotTrackB.Resize(2);
    rotFrame0 = MakeFrame(0.0f, quat(0, 0, 0, 1));
    rotFrame1 = MakeFrame(1.0f, quat(0, 0, 0, 1));
    rotTrackB[0] = rotFrame0;
    rotTrackB[1] = rotFrame1;

    // We set the tracks' ID according to the joint ID (in the Pose object)
    mClipA->SetIdAtIndex(0, 0);
    mClipA->SetIdAtIndex(1, 1);
    mClipA->RecalculateDuration();

    // Add visuals
    mPoseVisual = new DebugDraw;
    mPoseVisual->FromPose(*mPose);
    mPoseVisual->UpdateOpenGLBuffers();
}

void OwnNinthApp::Update(float inDeltaTime) {
    // We create animation by sampling the keyframes we have defined above.
    // This function will change the joints position directly.
    mPlaybackTime = mClipA->Sample(*mPose, mPlaybackTime + inDeltaTime);
    mPoseVisual->FromPose(*mPose);
}

void OwnNinthApp::Render(float inAspectRatio) {
	mat4 projection = perspective(60.0f, inAspectRatio, 0.01f, 1000.0f);
	mat4 view = lookAt(vec3(0, 4, 7), vec3(0, 4, 0), vec3(0, 1, 0));
	mat4 mvp = projection * view; // No model

	mPoseVisual->UpdateOpenGLBuffers();
	mPoseVisual->Draw(DebugDrawMode::Lines, vec3(1, 1, 1), mvp);
}

void OwnNinthApp::Shutdown() {
    delete mPoseVisual;
}

VectorFrame OwnNinthApp::MakeFrame(float time, const vec3& value, const vec3& in, const vec3& out) {
    VectorFrame result;
	result.mTime = time;
	result.mIn[0] = in.x;
	result.mIn[1] = in.y;
	result.mIn[2] = in.z;
	result.mValue[0] = value.x;
	result.mValue[1] = value.y;
	result.mValue[2] = value.z;
	result.mOut[0] = out.x;
	result.mOut[1] = out.y;
	result.mOut[2] = out.z;
	return result;
}

VectorFrame OwnNinthApp::MakeFrame(float time, const vec3& value) {
    return MakeFrame(time, value, vec3(), vec3());
}

QuaternionFrame OwnNinthApp::MakeFrame(float time, const quat& value, const quat& in, const quat& out) {
    QuaternionFrame result;
	result.mTime = time;
	result.mIn[0] = in.x;
	result.mIn[1] = in.y;
	result.mIn[2] = in.z;
	result.mIn[3] = in.w;
	result.mValue[0] = value.x;
	result.mValue[1] = value.y;
	result.mValue[2] = value.z;
	result.mValue[3] = value.w;
	result.mOut[0] = out.x;
	result.mOut[1] = out.y;
	result.mOut[2] = out.z;
	result.mOut[3] = out.w;
	return result;
}

QuaternionFrame OwnNinthApp::MakeFrame(float time, const quat& value) {
    return MakeFrame(time, value, quat(0,0,0,0), quat(0,0,0,0));
}