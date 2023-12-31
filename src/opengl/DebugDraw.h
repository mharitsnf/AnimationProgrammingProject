#ifndef _H_DEBUGLINE_
#define _H_DEBUGLINE_

#include "Shader.h"
#include "Attribute.h"
#include "VertexArray.h"
#include "../math/vec3.h"
#include "../math/mat4.h"
#include "../animation/Pose.h"
#include "../ik/CCDSolver.h"
#include "../ik/FABRIKSolver.h"
#include <vector>

enum class DebugDrawMode {
	Lines, Loop, Strip, Points
};

class DebugDraw {
protected:
	VertexArray* mVertexArray;
	std::vector<vec3> mPoints;
	Attribute<vec3>* mAttribs;
	Shader* mShader;

private:
	DebugDraw(const DebugDraw&);
	DebugDraw& operator=(const DebugDraw&);

public:
	DebugDraw();
	DebugDraw(unsigned int size);
	~DebugDraw();

	unsigned int Size();
	void Resize(unsigned int newSize);
	vec3& operator[](unsigned int index);
	void Push(const vec3& v);

	void FromPose(Pose& pose);
	void LinesFromIKSolver(CCDSolver& solver);
	void PointsFromIKSolver(CCDSolver& solver);
	void LinesFromIKSolver(FABRIKSolver& solver);
	void PointsFromIKSolver(FABRIKSolver& solver);

	void UpdateOpenGLBuffers();
	void Draw(DebugDrawMode mode, const vec3& color, const mat4& mvp);
};

#endif