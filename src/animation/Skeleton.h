#ifndef _H_SKELETON_
#define _H_SKELETON_

#include "Pose.h"
#include "../math/mat4.h"
#include "../math/DualQuaternion.h"
#include <vector>
#include <string>

class Skeleton {
protected:
	Pose mRestPose;
	Pose mBindPose;
	std::vector<mat4> mInvBindPose; // the transform of the joints in bind pose as matrices
	std::vector<std::string> mJointNames;

protected:
	void UpdateInverseBindPose();
    
public:
	Skeleton();
	Skeleton(const Pose& rest, const Pose& bind, const std::vector<std::string>& names);

	void Set(const Pose& rest, const Pose& bind, const std::vector<std::string>& names);

	Pose& GetBindPose();
	Pose& GetRestPose();
	std::vector<mat4>& GetInvBindPose();
	std::vector<std::string>& GetJointNames();
	std::string& GetJointName(unsigned int index);

	void GetInvBindPose(std::vector<DualQuaternion>& outInvBndPose);
};

#endif 