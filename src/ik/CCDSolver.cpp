#include "CCDSolver.h"

CCDSolver::CCDSolver() {
	mNumSteps = 15;
	mThreshold = 0.00001f;
}

unsigned int CCDSolver::Size() {
	return mIKChain.size();
}

void CCDSolver::Resize(unsigned int newSize) {
	mIKChain.resize(newSize);
}

Transform& CCDSolver::operator[](unsigned int index) {
	return mIKChain[index];
}

unsigned int CCDSolver::GetNumSteps() {
	return mNumSteps;
}

void CCDSolver::SetNumSteps(unsigned int numSteps) {
	mNumSteps = numSteps;
}

float CCDSolver::GetThreshold() {
	return mThreshold;
}

void CCDSolver::SetThreshold(float value) {
	mThreshold = value;
}

Transform CCDSolver::GetGlobalTransform(unsigned int index) {
	unsigned int size = (unsigned int)mIKChain.size();
	Transform world = mIKChain[index];
    // loop over its parents, combine their transforms
	for (int i = (int)index - 1; i >= 0; --i) {
		world = combine(mIKChain[i], world);
	}
	return world;
}

bool CCDSolver::Solve(const Transform& target) {
	unsigned int size = Size();
	if (size == 0) { return false; }

	unsigned int last = size - 1;
	float thresholdSq = mThreshold * mThreshold;
	vec3 goal = target.position;

    // loop until the number of steps is exceeded
	for (unsigned int i = 0; i < mNumSteps; ++i) {
		vec3 effector = GetGlobalTransform(last).position; // get the effector (the one touching the target)

        // if the distance between the goal and effector is too small, we consider the IK is solved (finished)
		if (lenSq(goal - effector) < thresholdSq) {
			return true;
		}

        // we start from the joint connected to the effector (mIKChain[size-2])
        // loop from there to the root node (mIKChain[0])
		for (int j = (int)size - 2; j >= 0; --j) {
			effector = GetGlobalTransform(last).position;

            // the current joint transform
			Transform world = GetGlobalTransform(j);
			vec3 position = world.position;
			quat rotation = world.rotation;

            // create vectors from current joint position to effector position and from current joint position to goal position
			vec3 toEffector = effector - position;
			vec3 toGoal = goal - position;
			quat effectorToGoal;

            // if length to goal is greater than a certain threshold, we construct the quaternion
            // that rotates the arm toEffector towards toGoal
			if (lenSq(toGoal) > 0.00001f) {
				effectorToGoal = fromTo(toEffector, toGoal);
			}

            // rotate the current joint using the effectorToGoal quat
            // to convert back to local space, multiply the world rotation with the invere world rotation
            // set the rotation of the current joint by multiplying the unchanged local rotation with the changed one (localRotate)
			quat worldRotated = rotation * effectorToGoal;
			quat localRotate = worldRotated * inverse(rotation);
			mIKChain[j].rotation = localRotate * mIKChain[j].rotation;

            // if the length of the effector is close enough to the goal
            // we return true, meaning we have reached the goal
			effector = GetGlobalTransform(last).position;
			if (lenSq(goal - effector) < thresholdSq) {
				return true;
			}
		}
	}

	return false;
} // End CCDSolver::Solve function