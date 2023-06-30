cmake_minimum_required(VERSION 3.25.1)

project(AnimationProject)

add_executable(${PROJECT_NAME}
    main.cpp
    external/glad/src/glad.c 
    external/glad/include/glad/glad.h
    src/vec3.cpp
    src/vec3.h
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