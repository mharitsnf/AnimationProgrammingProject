cmake_minimum_required(VERSION 3.25.1)

project(AnimationProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME}
    main.cpp
    external/glad/src/glad.c 
    external/glad/include/glad/glad.h
    src/math/vec3.cpp
    src/math/vec3.h
    src/math/vec2.h
    src/math/vec4.h
    src/math/mat4.cpp
    src/math/mat4.h
    src/math/quat.cpp
    src/math/quat.h
    src/transform/Transform.cpp
    src/transform/Transform.h
    src/opengl/Shader.cpp
    src/opengl/Shader.h
    src/opengl/Attribute.h
    src/opengl/Uniform.h
    src/opengl/IndexBuffer.cpp
    src/opengl/IndexBuffer.h
    src/opengl/Draw.cpp
    src/opengl/Draw.h
)

# For using glfw homebrew
#include_directories(/usr/local/include) # Where is the global header files?
#link_directories(/usr/local/lib) # Where is the global lib files (definition of the headers)?

add_subdirectory(external/glfw)

# Where is the .h file?
target_include_directories(${PROJECT_NAME}
    PUBLIC external/glfw/include
) 

# Where is the .a file?
target_link_directories(${PROJECT_NAME}
    PRIVATE external/glfw/src
) 

target_link_libraries(${PROJECT_NAME} glfw)