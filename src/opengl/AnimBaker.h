#ifndef _H_ANIMBAKER_
#define _H_ANIMBAKER_

#include "../animation/Skeleton.h"
#include "../animation/Clip.h"
#include "AnimTexture.h"

void BakeAnimationToTexture(Skeleton& skel, Clip& clip, AnimTexture& tex);

#endif