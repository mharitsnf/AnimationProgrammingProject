# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.25.1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.25.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/mharitsnf/Documents/C++/AnimationProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/mharitsnf/Documents/C++/AnimationProject/out/build

# Include any dependencies generated for this target.
include CMakeFiles/AnimationProject.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/AnimationProject.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/AnimationProject.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AnimationProject.dir/flags.make

CMakeFiles/AnimationProject.dir/main.cpp.o: CMakeFiles/AnimationProject.dir/flags.make
CMakeFiles/AnimationProject.dir/main.cpp.o: /Users/mharitsnf/Documents/C++/AnimationProject/main.cpp
CMakeFiles/AnimationProject.dir/main.cpp.o: CMakeFiles/AnimationProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mharitsnf/Documents/C++/AnimationProject/out/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/AnimationProject.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AnimationProject.dir/main.cpp.o -MF CMakeFiles/AnimationProject.dir/main.cpp.o.d -o CMakeFiles/AnimationProject.dir/main.cpp.o -c /Users/mharitsnf/Documents/C++/AnimationProject/main.cpp

CMakeFiles/AnimationProject.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AnimationProject.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mharitsnf/Documents/C++/AnimationProject/main.cpp > CMakeFiles/AnimationProject.dir/main.cpp.i

CMakeFiles/AnimationProject.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AnimationProject.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mharitsnf/Documents/C++/AnimationProject/main.cpp -o CMakeFiles/AnimationProject.dir/main.cpp.s

CMakeFiles/AnimationProject.dir/external/glad/src/glad.c.o: CMakeFiles/AnimationProject.dir/flags.make
CMakeFiles/AnimationProject.dir/external/glad/src/glad.c.o: /Users/mharitsnf/Documents/C++/AnimationProject/external/glad/src/glad.c
CMakeFiles/AnimationProject.dir/external/glad/src/glad.c.o: CMakeFiles/AnimationProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mharitsnf/Documents/C++/AnimationProject/out/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/AnimationProject.dir/external/glad/src/glad.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/AnimationProject.dir/external/glad/src/glad.c.o -MF CMakeFiles/AnimationProject.dir/external/glad/src/glad.c.o.d -o CMakeFiles/AnimationProject.dir/external/glad/src/glad.c.o -c /Users/mharitsnf/Documents/C++/AnimationProject/external/glad/src/glad.c

CMakeFiles/AnimationProject.dir/external/glad/src/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/AnimationProject.dir/external/glad/src/glad.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/mharitsnf/Documents/C++/AnimationProject/external/glad/src/glad.c > CMakeFiles/AnimationProject.dir/external/glad/src/glad.c.i

CMakeFiles/AnimationProject.dir/external/glad/src/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/AnimationProject.dir/external/glad/src/glad.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/mharitsnf/Documents/C++/AnimationProject/external/glad/src/glad.c -o CMakeFiles/AnimationProject.dir/external/glad/src/glad.c.s

CMakeFiles/AnimationProject.dir/src/math/vec3.cpp.o: CMakeFiles/AnimationProject.dir/flags.make
CMakeFiles/AnimationProject.dir/src/math/vec3.cpp.o: /Users/mharitsnf/Documents/C++/AnimationProject/src/math/vec3.cpp
CMakeFiles/AnimationProject.dir/src/math/vec3.cpp.o: CMakeFiles/AnimationProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mharitsnf/Documents/C++/AnimationProject/out/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/AnimationProject.dir/src/math/vec3.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AnimationProject.dir/src/math/vec3.cpp.o -MF CMakeFiles/AnimationProject.dir/src/math/vec3.cpp.o.d -o CMakeFiles/AnimationProject.dir/src/math/vec3.cpp.o -c /Users/mharitsnf/Documents/C++/AnimationProject/src/math/vec3.cpp

CMakeFiles/AnimationProject.dir/src/math/vec3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AnimationProject.dir/src/math/vec3.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mharitsnf/Documents/C++/AnimationProject/src/math/vec3.cpp > CMakeFiles/AnimationProject.dir/src/math/vec3.cpp.i

CMakeFiles/AnimationProject.dir/src/math/vec3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AnimationProject.dir/src/math/vec3.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mharitsnf/Documents/C++/AnimationProject/src/math/vec3.cpp -o CMakeFiles/AnimationProject.dir/src/math/vec3.cpp.s

CMakeFiles/AnimationProject.dir/src/math/mat4.cpp.o: CMakeFiles/AnimationProject.dir/flags.make
CMakeFiles/AnimationProject.dir/src/math/mat4.cpp.o: /Users/mharitsnf/Documents/C++/AnimationProject/src/math/mat4.cpp
CMakeFiles/AnimationProject.dir/src/math/mat4.cpp.o: CMakeFiles/AnimationProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mharitsnf/Documents/C++/AnimationProject/out/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/AnimationProject.dir/src/math/mat4.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AnimationProject.dir/src/math/mat4.cpp.o -MF CMakeFiles/AnimationProject.dir/src/math/mat4.cpp.o.d -o CMakeFiles/AnimationProject.dir/src/math/mat4.cpp.o -c /Users/mharitsnf/Documents/C++/AnimationProject/src/math/mat4.cpp

CMakeFiles/AnimationProject.dir/src/math/mat4.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AnimationProject.dir/src/math/mat4.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mharitsnf/Documents/C++/AnimationProject/src/math/mat4.cpp > CMakeFiles/AnimationProject.dir/src/math/mat4.cpp.i

CMakeFiles/AnimationProject.dir/src/math/mat4.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AnimationProject.dir/src/math/mat4.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mharitsnf/Documents/C++/AnimationProject/src/math/mat4.cpp -o CMakeFiles/AnimationProject.dir/src/math/mat4.cpp.s

CMakeFiles/AnimationProject.dir/src/math/quat.cpp.o: CMakeFiles/AnimationProject.dir/flags.make
CMakeFiles/AnimationProject.dir/src/math/quat.cpp.o: /Users/mharitsnf/Documents/C++/AnimationProject/src/math/quat.cpp
CMakeFiles/AnimationProject.dir/src/math/quat.cpp.o: CMakeFiles/AnimationProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mharitsnf/Documents/C++/AnimationProject/out/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/AnimationProject.dir/src/math/quat.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AnimationProject.dir/src/math/quat.cpp.o -MF CMakeFiles/AnimationProject.dir/src/math/quat.cpp.o.d -o CMakeFiles/AnimationProject.dir/src/math/quat.cpp.o -c /Users/mharitsnf/Documents/C++/AnimationProject/src/math/quat.cpp

CMakeFiles/AnimationProject.dir/src/math/quat.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AnimationProject.dir/src/math/quat.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mharitsnf/Documents/C++/AnimationProject/src/math/quat.cpp > CMakeFiles/AnimationProject.dir/src/math/quat.cpp.i

CMakeFiles/AnimationProject.dir/src/math/quat.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AnimationProject.dir/src/math/quat.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mharitsnf/Documents/C++/AnimationProject/src/math/quat.cpp -o CMakeFiles/AnimationProject.dir/src/math/quat.cpp.s

CMakeFiles/AnimationProject.dir/src/transform/Transform.cpp.o: CMakeFiles/AnimationProject.dir/flags.make
CMakeFiles/AnimationProject.dir/src/transform/Transform.cpp.o: /Users/mharitsnf/Documents/C++/AnimationProject/src/transform/Transform.cpp
CMakeFiles/AnimationProject.dir/src/transform/Transform.cpp.o: CMakeFiles/AnimationProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mharitsnf/Documents/C++/AnimationProject/out/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/AnimationProject.dir/src/transform/Transform.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AnimationProject.dir/src/transform/Transform.cpp.o -MF CMakeFiles/AnimationProject.dir/src/transform/Transform.cpp.o.d -o CMakeFiles/AnimationProject.dir/src/transform/Transform.cpp.o -c /Users/mharitsnf/Documents/C++/AnimationProject/src/transform/Transform.cpp

CMakeFiles/AnimationProject.dir/src/transform/Transform.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AnimationProject.dir/src/transform/Transform.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mharitsnf/Documents/C++/AnimationProject/src/transform/Transform.cpp > CMakeFiles/AnimationProject.dir/src/transform/Transform.cpp.i

CMakeFiles/AnimationProject.dir/src/transform/Transform.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AnimationProject.dir/src/transform/Transform.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mharitsnf/Documents/C++/AnimationProject/src/transform/Transform.cpp -o CMakeFiles/AnimationProject.dir/src/transform/Transform.cpp.s

CMakeFiles/AnimationProject.dir/src/opengl/Shader.cpp.o: CMakeFiles/AnimationProject.dir/flags.make
CMakeFiles/AnimationProject.dir/src/opengl/Shader.cpp.o: /Users/mharitsnf/Documents/C++/AnimationProject/src/opengl/Shader.cpp
CMakeFiles/AnimationProject.dir/src/opengl/Shader.cpp.o: CMakeFiles/AnimationProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mharitsnf/Documents/C++/AnimationProject/out/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/AnimationProject.dir/src/opengl/Shader.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AnimationProject.dir/src/opengl/Shader.cpp.o -MF CMakeFiles/AnimationProject.dir/src/opengl/Shader.cpp.o.d -o CMakeFiles/AnimationProject.dir/src/opengl/Shader.cpp.o -c /Users/mharitsnf/Documents/C++/AnimationProject/src/opengl/Shader.cpp

CMakeFiles/AnimationProject.dir/src/opengl/Shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AnimationProject.dir/src/opengl/Shader.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mharitsnf/Documents/C++/AnimationProject/src/opengl/Shader.cpp > CMakeFiles/AnimationProject.dir/src/opengl/Shader.cpp.i

CMakeFiles/AnimationProject.dir/src/opengl/Shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AnimationProject.dir/src/opengl/Shader.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mharitsnf/Documents/C++/AnimationProject/src/opengl/Shader.cpp -o CMakeFiles/AnimationProject.dir/src/opengl/Shader.cpp.s

CMakeFiles/AnimationProject.dir/src/opengl/IndexBuffer.cpp.o: CMakeFiles/AnimationProject.dir/flags.make
CMakeFiles/AnimationProject.dir/src/opengl/IndexBuffer.cpp.o: /Users/mharitsnf/Documents/C++/AnimationProject/src/opengl/IndexBuffer.cpp
CMakeFiles/AnimationProject.dir/src/opengl/IndexBuffer.cpp.o: CMakeFiles/AnimationProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mharitsnf/Documents/C++/AnimationProject/out/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/AnimationProject.dir/src/opengl/IndexBuffer.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/AnimationProject.dir/src/opengl/IndexBuffer.cpp.o -MF CMakeFiles/AnimationProject.dir/src/opengl/IndexBuffer.cpp.o.d -o CMakeFiles/AnimationProject.dir/src/opengl/IndexBuffer.cpp.o -c /Users/mharitsnf/Documents/C++/AnimationProject/src/opengl/IndexBuffer.cpp

CMakeFiles/AnimationProject.dir/src/opengl/IndexBuffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AnimationProject.dir/src/opengl/IndexBuffer.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mharitsnf/Documents/C++/AnimationProject/src/opengl/IndexBuffer.cpp > CMakeFiles/AnimationProject.dir/src/opengl/IndexBuffer.cpp.i

CMakeFiles/AnimationProject.dir/src/opengl/IndexBuffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AnimationProject.dir/src/opengl/IndexBuffer.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mharitsnf/Documents/C++/AnimationProject/src/opengl/IndexBuffer.cpp -o CMakeFiles/AnimationProject.dir/src/opengl/IndexBuffer.cpp.s

# Object files for target AnimationProject
AnimationProject_OBJECTS = \
"CMakeFiles/AnimationProject.dir/main.cpp.o" \
"CMakeFiles/AnimationProject.dir/external/glad/src/glad.c.o" \
"CMakeFiles/AnimationProject.dir/src/math/vec3.cpp.o" \
"CMakeFiles/AnimationProject.dir/src/math/mat4.cpp.o" \
"CMakeFiles/AnimationProject.dir/src/math/quat.cpp.o" \
"CMakeFiles/AnimationProject.dir/src/transform/Transform.cpp.o" \
"CMakeFiles/AnimationProject.dir/src/opengl/Shader.cpp.o" \
"CMakeFiles/AnimationProject.dir/src/opengl/IndexBuffer.cpp.o"

# External object files for target AnimationProject
AnimationProject_EXTERNAL_OBJECTS =

AnimationProject: CMakeFiles/AnimationProject.dir/main.cpp.o
AnimationProject: CMakeFiles/AnimationProject.dir/external/glad/src/glad.c.o
AnimationProject: CMakeFiles/AnimationProject.dir/src/math/vec3.cpp.o
AnimationProject: CMakeFiles/AnimationProject.dir/src/math/mat4.cpp.o
AnimationProject: CMakeFiles/AnimationProject.dir/src/math/quat.cpp.o
AnimationProject: CMakeFiles/AnimationProject.dir/src/transform/Transform.cpp.o
AnimationProject: CMakeFiles/AnimationProject.dir/src/opengl/Shader.cpp.o
AnimationProject: CMakeFiles/AnimationProject.dir/src/opengl/IndexBuffer.cpp.o
AnimationProject: CMakeFiles/AnimationProject.dir/build.make
AnimationProject: external/glfw/src/libglfw3.a
AnimationProject: CMakeFiles/AnimationProject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/mharitsnf/Documents/C++/AnimationProject/out/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable AnimationProject"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AnimationProject.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AnimationProject.dir/build: AnimationProject
.PHONY : CMakeFiles/AnimationProject.dir/build

CMakeFiles/AnimationProject.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/AnimationProject.dir/cmake_clean.cmake
.PHONY : CMakeFiles/AnimationProject.dir/clean

CMakeFiles/AnimationProject.dir/depend:
	cd /Users/mharitsnf/Documents/C++/AnimationProject/out/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mharitsnf/Documents/C++/AnimationProject /Users/mharitsnf/Documents/C++/AnimationProject /Users/mharitsnf/Documents/C++/AnimationProject/out/build /Users/mharitsnf/Documents/C++/AnimationProject/out/build /Users/mharitsnf/Documents/C++/AnimationProject/out/build/CMakeFiles/AnimationProject.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/AnimationProject.dir/depend

