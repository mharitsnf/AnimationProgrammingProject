cmake_minimum_required(VERSION 3.25.1)

project(AnimationProject)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME}
    main.cpp
    external/glad/src/glad.c 
    external/glad/include/glad/glad.h
    external/stb_image/stb_image.cpp
    external/stb_image/stb_image.h
    external/cgltf/cgltf.c
    external/cgltf/cgltf.h
    external/cgltf/GLTFLoader.cpp
    external/cgltf/GLTFLoader.h
    src/math/vec3.cpp
    src/math/vec3.h
    src/math/vec2.h
    src/math/vec4.h
    src/math/mat4.cpp
    src/math/mat4.h
    src/math/quat.cpp
    src/math/quat.h
    src/animation/Transform.cpp
    src/animation/Transform.h
    src/opengl/Shader.cpp
    src/opengl/Shader.h
    src/opengl/Attribute.cpp
    src/opengl/Attribute.h
    src/opengl/Uniform.cpp
    src/opengl/Uniform.h
    src/opengl/IndexBuffer.cpp
    src/opengl/IndexBuffer.h
    src/opengl/Draw.cpp
    src/opengl/Draw.h
    src/opengl/VertexArray.cpp
    src/opengl/VertexArray.h
    src/opengl/Texture.cpp
    src/opengl/Texture.h
    src/application/Application.h
    src/application/LearnOpenGLApp.cpp
    src/application/LearnOpenGLApp.h
    src/application/BasicApp.cpp
    src/application/BasicApp.h
    src/animation/Interpolation.h
    src/animation/Frame.h
    src/animation/Track.cpp
    src/animation/Track.h
    src/animation/TransformTrack.cpp
    src/animation/TransformTrack.h
    src/opengl/DebugDraw.cpp
    src/opengl/DebugDraw.h
    src/application/ch8/ChapterEightApp.cpp
    src/application/ch8/ChapterEightApp.h
    src/application/DebugApp.cpp
    src/application/DebugApp.h
    src/animation/Pose.cpp
    src/animation/Pose.h
    src/animation/Clip.cpp
    src/application/ch9/ChapterNinthApp.cpp
    src/application/ch9/ChapterNinthApp.h
    src/application/ch9/OwnNinthApp.cpp
    src/application/ch9/OwnNinthApp.h
    src/animation/Skeleton.cpp
    src/animation/Skeleton.h
    src/animation/Mesh.cpp
    src/animation/Mesh.h
    src/application/ch10/ChapterTenApp.cpp
    src/application/ch10/ChapterTenApp.h
    src/application/ch10/ChapterTenApp2.cpp
    src/application/ch10/ChapterTenApp2.h
    src/application/ch10/OwnChapterTen.cpp
    src/application/ch10/OwnChapterTen.h
    src/animation/RearrangeBones.cpp
    src/animation/RearrangeBones.h
    src/application/ch11/Sample01.cpp
    src/application/ch11/Sample01.h
    src/application/ch11/Sample02.cpp
    src/application/ch11/Sample02.h
    src/application/ch11/Sample03.cpp
    src/application/ch11/Sample03.h
    src/animation/Blending.cpp
    src/animation/Blending.h
    src/animation/CrossFadeTarget.h
    src/animation/CrossFadeController.cpp
    src/animation/CrossFadeController.h
    src/application/ch12/Sample01.cpp
    src/application/ch12/Sample01.h
    src/application/ch12/Sample02.cpp
    src/application/ch12/Sample02.h
    src/application/ch12/Sample03.cpp
    src/application/ch12/Sample03.h
    src/ik/CCDSolver.cpp
    src/ik/CCDSolver.h
    src/ik/FABRIKSolver.cpp
    src/ik/FABRIKSolver.h
    src/application/ch13/Sample01.cpp
    src/application/ch13/Sample01.h
    src/application/ch13/Sample02.cpp
    src/application/ch13/Sample02.h
    src/ik/Intersections.cpp
    src/ik/Intersections.h
    src/ik/IKLeg.cpp
    src/ik/IKLeg.h
    src/application/ch13/Sample03.cpp
    src/application/ch13/Sample03.h
    src/math/DualQuaternion.cpp
    src/math/DualQuaternion.h
    src/application/ch14/Sample01.cpp
    src/application/ch14/Sample01.h
    src/opengl/AnimTexture.cpp
    src/opengl/AnimTexture.h
    src/opengl/AnimBaker.cpp
    src/opengl/AnimBaker.h
    src/animation/Crowd.cpp
    src/animation/Crowd.h
    src/application/ch15/Sample01.cpp
    src/application/ch15/Sample01.h
)


# For using glfw homebrew
#include_directories(/usr/local/include) # Where is the global header files?
#link_directories(/usr/local/lib) # Where is the global lib files (definition of the headers)?

add_subdirectory(external/glfw)

# Where is the .h file?
target_include_directories(${PROJECT_NAME}
    PUBLIC external/glfw/include
) 

# Where is the .a / .cpp file?
target_link_directories(${PROJECT_NAME}
    PRIVATE external/glfw/src
) 

target_link_libraries(${PROJECT_NAME} glfw)