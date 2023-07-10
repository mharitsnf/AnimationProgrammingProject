#include "RearrangeBones.h"
#include <list>

BoneMap RearrangeSkeleton(Skeleton& skeleton) {
    using std::vector;

	Pose& restPose = skeleton.GetRestPose();
	Pose& bindPose = skeleton.GetBindPose();
	unsigned int size = restPose.Size();
	if (size == 0) { return BoneMap(); }

	vector<vector<int>> hierarchy(size);
	std::list<int> process; // containing root nodes (no parents)
	for (unsigned int i = 0; i < size; ++i) {
		int parent = restPose.GetParent(i);
		if (parent >= 0) {
            // the current joint (i) has a parent
            // add the current joint (i) to the vector hierarchy[parent]
			hierarchy[parent].push_back((int)i);
		}
		else {
			process.push_back((int)i); // add parent into process
		}
	}

	BoneMap mapForward;
	BoneMap mapBackward;
	int index = 0;
	while (process.size() > 0) {
        // get first element, and pop it from the vector
		int current = *process.begin();
		process.pop_front();

        // a reference to the children of the parent (according to the hierarchy position)
		std::vector<int>& children = hierarchy[current];

        // loop through all the children, and process them directly
		unsigned int numChildren = (unsigned int)children.size();
		for (unsigned int i = 0; i < numChildren; ++i) {
			process.push_back(children[i]);
		}

        // set the mapping
		mapForward[index] = current;
		mapBackward[current] = index;
		index += 1;
	}
	mapForward[-1] = -1;
	mapBackward[-1] = -1;

	Pose newRestPose(size);
	Pose newBindPose(size);
	std::vector<std::string> newNames(size);
	for (unsigned int i = 0; i < size; ++i) {
		int thisBone = mapForward[i];
		newRestPose.SetLocalTransform(i, restPose.GetLocalTransform(thisBone));
		newBindPose.SetLocalTransform(i, bindPose.GetLocalTransform(thisBone));
		newNames[i] = skeleton.GetJointName(thisBone);

		int parent = mapBackward[bindPose.GetParent(thisBone)];
		newRestPose.SetParent(i, parent);
		newBindPose.SetParent(i, parent);
	}

	skeleton.Set(newRestPose, newBindPose, newNames);
	return mapBackward;
} // End of RearrangeSkeleton function

void RearrangeClip(Clip& clip, BoneMap& boneMap) {
	unsigned int size = clip.Size();

	for (unsigned int i = 0; i < size; ++i) {
		int joint = (int)clip.GetIdAtIndex(i);
		unsigned int newJoint = (unsigned int)boneMap[joint];
		clip.SetIdAtIndex(i, newJoint);
	}
}

void RearrangeFastclip(FastClip& clip, BoneMap& boneMap) {
	unsigned int size = clip.Size();

	for (unsigned int i = 0; i < size; ++i) {
		int joint = (int)clip.GetIdAtIndex(i);
		unsigned int newJoint = (unsigned int)boneMap[joint];
		clip.SetIdAtIndex(i, newJoint);
	}
}

void RearrangeMesh(Mesh& mesh, BoneMap& boneMap) {
	std::vector<ivec4>& influences = mesh.GetInfluences();
	unsigned int size = (unsigned int)influences.size();

	for (unsigned int i = 0; i < size; ++i) {
		influences[i].x = boneMap[influences[i].x];
		influences[i].y = boneMap[influences[i].y];
		influences[i].z = boneMap[influences[i].z];
		influences[i].w = boneMap[influences[i].w];
	}

	mesh.UpdateOpenGLBuffers();
}