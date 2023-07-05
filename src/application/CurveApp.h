#ifndef _H_CURVEAPP_
#define _H_CURVEAPP_

#include "Application.h"
#include "../opengl/DebugDraw.h"

#define DEG2RAD 0.0174533f

class CurveApp : public Application {
protected:
	DebugDraw* line;
    
public:
	void Initialize();
	void Render(float inAspectRatio);
	void Shutdown();
};

#endif