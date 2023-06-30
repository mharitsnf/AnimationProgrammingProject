#ifndef _H_MAT4_
#define _H_MAT4_

#include "vec3.h"
#include "vec4.h"

#include <iostream>
#include <vector>

#define MAT4_EPSILON 0.000001f

class mat4 {
public:
    std::vector<float> v;

public:
	inline mat4() { 
        v = { 1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1 };

    }
    inline mat4(std::vector<float> fv) : v(fv) { }
    inline mat4(float _00, float _01, float _02, float _03,
                float _10, float _11, float _12, float _13,
		        float _20, float _21, float _22, float _23,
		        float _30, float _31, float _32, float _33)
    {
        v = { _00, _01, _02, _03, _10, _11, _12, _13, _20, _21, _22, _23, _30, _31, _32, _33};

    }

    inline vec4 right() const { return vec4(v[0], v[4], v[8], v[12]); }
    inline vec4 up() const { return vec4(v[1], v[5], v[9], v[13]); }
    inline vec4 forward() const { return vec4(v[2], v[6], v[10], v[14]); }
    inline vec4 position() const { return vec4(v[3], v[7], v[11], v[15]); }


}; // end mat4 class


bool operator==(const mat4& a, const mat4& b);
bool operator!=(const mat4& a, const mat4& b);
mat4 operator*(const mat4& m, float f);
mat4 operator+(const mat4& a, const mat4& b);
mat4 operator*(const mat4& a, const mat4& b);
vec4 operator*(const mat4& m, const vec4& v);
vec3 transformVector(const mat4& m, const vec3& v);
vec3 transformPoint(const mat4& m, const vec3& v);
vec3 transformPoint(const mat4& m, const vec3& v, float& w);
void transpose(mat4& m);
mat4 transposed(const mat4& m);
float determinant(const mat4& m);
mat4 adjugate(const mat4& m);
mat4 inverse(const mat4& m);
void invert(mat4& m);
mat4 frustum(float l, float r, float b, float t, float n, float f);
mat4 perspective(float fov, float aspect, float znear, float zfar);
mat4 ortho(float l, float r, float b, float t, float n, float f);
mat4 lookAt(const vec3& position, const vec3& target, const vec3& up);

#endif