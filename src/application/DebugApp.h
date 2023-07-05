#ifndef _H_DEBUGAPP_
#define _H_DEBUGAPP_

#include "Application.h"
#include "../opengl/DebugDraw.h"

#define DEG2RAD 0.0174533f

class DebugApp : public Application {
protected:
	DebugDraw* refLine;
	DebugDraw* newLine;
    
public:
	void Initialize();
	void Render(float inAspectRatio);
	void Shutdown();
};

#endif