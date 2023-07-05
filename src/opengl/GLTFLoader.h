#ifndef _H_GLTFLOADER_
#define _H_GLTFLOADER_

#include "../../external/cgltf/cgltf.h"

cgltf_data* LoadGLTFFile(const char* path);
void FreeGLTFFile(cgltf_data* handle);

#endif