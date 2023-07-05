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
    src/application/ChapterEightApp.cpp
    src/application/ChapterEightApp.h
    src/application/CurveApp.cpp
    src/application/CurveApp.h
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