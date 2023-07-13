#ifndef _H_DUALQUATERNION_
#define _H_DUALQUATERNION_

#include "quat.h"
#include "../animation/Transform.h"

struct DualQuaternion {
	union {
		struct {
			quat real; // holds rotation data
			quat dual; // holds position data
		};
		float v[8];
	};
	inline DualQuaternion() : real(0, 0, 0, 1), dual(0, 0, 0, 0) { } //identity
	inline DualQuaternion(const quat& r, const quat& d) :
		real(r), dual(d) { }
};

DualQuaternion operator+(const DualQuaternion& l, const DualQuaternion& r);
DualQuaternion operator*(const DualQuaternion& dq, float f);
// Multiplication order is left to right
// Left to right is the OPPOSITE of matrices and quaternions
DualQuaternion operator*(const DualQuaternion& l, const DualQuaternion& r);
bool operator==(const DualQuaternion& l, const DualQuaternion& r);
bool operator!=(const DualQuaternion& l, const DualQuaternion& r);

float dot(const DualQuaternion& l, const DualQuaternion& r);
DualQuaternion conjugate(const DualQuaternion& dq);
DualQuaternion normalized(const DualQuaternion& dq);
void normalize(DualQuaternion& dq);

DualQuaternion transformToDualQuat(const Transform& t);
Transform dualQuatToTransform(const DualQuaternion& dq);

vec3 transformVector(const DualQuaternion& dq, const vec3& v);
vec3 transformPoint(const DualQuaternion& dq, const vec3& v);

#endif