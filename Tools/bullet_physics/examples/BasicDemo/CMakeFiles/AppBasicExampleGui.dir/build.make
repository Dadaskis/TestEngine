# CMAKE generated file: DO NOT EDIT!
# Generated by "MSYS Makefiles" Generator, CMake Version 3.12

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /D/Games/cmake-3.12.0-rc1-win32-x86/bin/cmake.exe

# The command to remove a file.
RM = /D/Games/cmake-3.12.0-rc1-win32-x86/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/D/C++ Libs/bullet3-2.87"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/D/C++ Libs/bullet3-2.87"

# Include any dependencies generated for this target.
include examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/depend.make

# Include the progress variables for this target.
include examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/progress.make

# Include the compile flags for this target's objects.
include examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/flags.make

examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/BasicExample.obj: examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/flags.make
examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/BasicExample.obj: examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/includes_CXX.rsp
examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/BasicExample.obj: examples/BasicDemo/BasicExample.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/D/C++ Libs/bullet3-2.87/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/BasicExample.obj"
	cd "/D/C++ Libs/bullet3-2.87/examples/BasicDemo" && /C/msys32/mingw32/bin/g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AppBasicExampleGui.dir/BasicExample.obj -c "/D/C++ Libs/bullet3-2.87/examples/BasicDemo/BasicExample.cpp"

examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/BasicExample.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AppBasicExampleGui.dir/BasicExample.i"
	cd "/D/C++ Libs/bullet3-2.87/examples/BasicDemo" && /C/msys32/mingw32/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/D/C++ Libs/bullet3-2.87/examples/BasicDemo/BasicExample.cpp" > CMakeFiles/AppBasicExampleGui.dir/BasicExample.i

examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/BasicExample.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AppBasicExampleGui.dir/BasicExample.s"
	cd "/D/C++ Libs/bullet3-2.87/examples/BasicDemo" && /C/msys32/mingw32/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/D/C++ Libs/bullet3-2.87/examples/BasicDemo/BasicExample.cpp" -o CMakeFiles/AppBasicExampleGui.dir/BasicExample.s

examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/__/__/build3/bullet.obj: examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/flags.make
examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/__/__/build3/bullet.obj: build3/bullet.rc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/D/C++ Libs/bullet3-2.87/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building RC object examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/__/__/build3/bullet.obj"
	cd "/D/C++ Libs/bullet3-2.87/examples/BasicDemo" && /C/msys32/mingw32/bin/windres.exe -O coff $(RC_DEFINES) $(RC_INCLUDES) $(RC_FLAGS) "/D/C++ Libs/bullet3-2.87/build3/bullet.rc" CMakeFiles/AppBasicExampleGui.dir/__/__/build3/bullet.obj

examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/__/StandaloneMain/main_opengl_single_example.obj: examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/flags.make
examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/__/StandaloneMain/main_opengl_single_example.obj: examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/includes_CXX.rsp
examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/__/StandaloneMain/main_opengl_single_example.obj: examples/StandaloneMain/main_opengl_single_example.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/D/C++ Libs/bullet3-2.87/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/__/StandaloneMain/main_opengl_single_example.obj"
	cd "/D/C++ Libs/bullet3-2.87/examples/BasicDemo" && /C/msys32/mingw32/bin/g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AppBasicExampleGui.dir/__/StandaloneMain/main_opengl_single_example.obj -c "/D/C++ Libs/bullet3-2.87/examples/StandaloneMain/main_opengl_single_example.cpp"

examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/__/StandaloneMain/main_opengl_single_example.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AppBasicExampleGui.dir/__/StandaloneMain/main_opengl_single_example.i"
	cd "/D/C++ Libs/bullet3-2.87/examples/BasicDemo" && /C/msys32/mingw32/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/D/C++ Libs/bullet3-2.87/examples/StandaloneMain/main_opengl_single_example.cpp" > CMakeFiles/AppBasicExampleGui.dir/__/StandaloneMain/main_opengl_single_example.i

examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/__/StandaloneMain/main_opengl_single_example.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AppBasicExampleGui.dir/__/StandaloneMain/main_opengl_single_example.s"
	cd "/D/C++ Libs/bullet3-2.87/examples/BasicDemo" && /C/msys32/mingw32/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/D/C++ Libs/bullet3-2.87/examples/StandaloneMain/main_opengl_single_example.cpp" -o CMakeFiles/AppBasicExampleGui.dir/__/StandaloneMain/main_opengl_single_example.s

examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/__/ExampleBrowser/OpenGLGuiHelper.obj: examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/flags.make
examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/__/ExampleBrowser/OpenGLGuiHelper.obj: examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/includes_CXX.rsp
examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/__/ExampleBrowser/OpenGLGuiHelper.obj: examples/ExampleBrowser/OpenGLGuiHelper.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/D/C++ Libs/bullet3-2.87/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/__/ExampleBrowser/OpenGLGuiHelper.obj"
	cd "/D/C++ Libs/bullet3-2.87/examples/BasicDemo" && /C/msys32/mingw32/bin/g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AppBasicExampleGui.dir/__/ExampleBrowser/OpenGLGuiHelper.obj -c "/D/C++ Libs/bullet3-2.87/examples/ExampleBrowser/OpenGLGuiHelper.cpp"

examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/__/ExampleBrowser/OpenGLGuiHelper.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AppBasicExampleGui.dir/__/ExampleBrowser/OpenGLGuiHelper.i"
	cd "/D/C++ Libs/bullet3-2.87/examples/BasicDemo" && /C/msys32/mingw32/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/D/C++ Libs/bullet3-2.87/examples/ExampleBrowser/OpenGLGuiHelper.cpp" > CMakeFiles/AppBasicExampleGui.dir/__/ExampleBrowser/OpenGLGuiHelper.i

examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/__/ExampleBrowser/OpenGLGuiHelper.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AppBasicExampleGui.dir/__/ExampleBrowser/OpenGLGuiHelper.s"
	cd "/D/C++ Libs/bullet3-2.87/examples/BasicDemo" && /C/msys32/mingw32/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/D/C++ Libs/bullet3-2.87/examples/ExampleBrowser/OpenGLGuiHelper.cpp" -o CMakeFiles/AppBasicExampleGui.dir/__/ExampleBrowser/OpenGLGuiHelper.s

examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/__/ExampleBrowser/GL_ShapeDrawer.obj: examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/flags.make
examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/__/ExampleBrowser/GL_ShapeDrawer.obj: examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/includes_CXX.rsp
examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/__/ExampleBrowser/GL_ShapeDrawer.obj: examples/ExampleBrowser/GL_ShapeDrawer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/D/C++ Libs/bullet3-2.87/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/__/ExampleBrowser/GL_ShapeDrawer.obj"
	cd "/D/C++ Libs/bullet3-2.87/examples/BasicDemo" && /C/msys32/mingw32/bin/g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AppBasicExampleGui.dir/__/ExampleBrowser/GL_ShapeDrawer.obj -c "/D/C++ Libs/bullet3-2.87/examples/ExampleBrowser/GL_ShapeDrawer.cpp"

examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/__/ExampleBrowser/GL_ShapeDrawer.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AppBasicExampleGui.dir/__/ExampleBrowser/GL_ShapeDrawer.i"
	cd "/D/C++ Libs/bullet3-2.87/examples/BasicDemo" && /C/msys32/mingw32/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/D/C++ Libs/bullet3-2.87/examples/ExampleBrowser/GL_ShapeDrawer.cpp" > CMakeFiles/AppBasicExampleGui.dir/__/ExampleBrowser/GL_ShapeDrawer.i

examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/__/ExampleBrowser/GL_ShapeDrawer.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AppBasicExampleGui.dir/__/ExampleBrowser/GL_ShapeDrawer.s"
	cd "/D/C++ Libs/bullet3-2.87/examples/BasicDemo" && /C/msys32/mingw32/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/D/C++ Libs/bullet3-2.87/examples/ExampleBrowser/GL_ShapeDrawer.cpp" -o CMakeFiles/AppBasicExampleGui.dir/__/ExampleBrowser/GL_ShapeDrawer.s

examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/__/ExampleBrowser/CollisionShape2TriangleMesh.obj: examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/flags.make
examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/__/ExampleBrowser/CollisionShape2TriangleMesh.obj: examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/includes_CXX.rsp
examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/__/ExampleBrowser/CollisionShape2TriangleMesh.obj: examples/ExampleBrowser/CollisionShape2TriangleMesh.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/D/C++ Libs/bullet3-2.87/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/__/ExampleBrowser/CollisionShape2TriangleMesh.obj"
	cd "/D/C++ Libs/bullet3-2.87/examples/BasicDemo" && /C/msys32/mingw32/bin/g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AppBasicExampleGui.dir/__/ExampleBrowser/CollisionShape2TriangleMesh.obj -c "/D/C++ Libs/bullet3-2.87/examples/ExampleBrowser/CollisionShape2TriangleMesh.cpp"

examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/__/ExampleBrowser/CollisionShape2TriangleMesh.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AppBasicExampleGui.dir/__/ExampleBrowser/CollisionShape2TriangleMesh.i"
	cd "/D/C++ Libs/bullet3-2.87/examples/BasicDemo" && /C/msys32/mingw32/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/D/C++ Libs/bullet3-2.87/examples/ExampleBrowser/CollisionShape2TriangleMesh.cpp" > CMakeFiles/AppBasicExampleGui.dir/__/ExampleBrowser/CollisionShape2TriangleMesh.i

examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/__/ExampleBrowser/CollisionShape2TriangleMesh.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AppBasicExampleGui.dir/__/ExampleBrowser/CollisionShape2TriangleMesh.s"
	cd "/D/C++ Libs/bullet3-2.87/examples/BasicDemo" && /C/msys32/mingw32/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/D/C++ Libs/bullet3-2.87/examples/ExampleBrowser/CollisionShape2TriangleMesh.cpp" -o CMakeFiles/AppBasicExampleGui.dir/__/ExampleBrowser/CollisionShape2TriangleMesh.s

examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/__/Utils/b3Clock.obj: examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/flags.make
examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/__/Utils/b3Clock.obj: examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/includes_CXX.rsp
examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/__/Utils/b3Clock.obj: examples/Utils/b3Clock.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/D/C++ Libs/bullet3-2.87/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/__/Utils/b3Clock.obj"
	cd "/D/C++ Libs/bullet3-2.87/examples/BasicDemo" && /C/msys32/mingw32/bin/g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AppBasicExampleGui.dir/__/Utils/b3Clock.obj -c "/D/C++ Libs/bullet3-2.87/examples/Utils/b3Clock.cpp"

examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/__/Utils/b3Clock.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AppBasicExampleGui.dir/__/Utils/b3Clock.i"
	cd "/D/C++ Libs/bullet3-2.87/examples/BasicDemo" && /C/msys32/mingw32/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/D/C++ Libs/bullet3-2.87/examples/Utils/b3Clock.cpp" > CMakeFiles/AppBasicExampleGui.dir/__/Utils/b3Clock.i

examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/__/Utils/b3Clock.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AppBasicExampleGui.dir/__/Utils/b3Clock.s"
	cd "/D/C++ Libs/bullet3-2.87/examples/BasicDemo" && /C/msys32/mingw32/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/D/C++ Libs/bullet3-2.87/examples/Utils/b3Clock.cpp" -o CMakeFiles/AppBasicExampleGui.dir/__/Utils/b3Clock.s

# Object files for target AppBasicExampleGui
AppBasicExampleGui_OBJECTS = \
"CMakeFiles/AppBasicExampleGui.dir/BasicExample.obj" \
"CMakeFiles/AppBasicExampleGui.dir/__/__/build3/bullet.obj" \
"CMakeFiles/AppBasicExampleGui.dir/__/StandaloneMain/main_opengl_single_example.obj" \
"CMakeFiles/AppBasicExampleGui.dir/__/ExampleBrowser/OpenGLGuiHelper.obj" \
"CMakeFiles/AppBasicExampleGui.dir/__/ExampleBrowser/GL_ShapeDrawer.obj" \
"CMakeFiles/AppBasicExampleGui.dir/__/ExampleBrowser/CollisionShape2TriangleMesh.obj" \
"CMakeFiles/AppBasicExampleGui.dir/__/Utils/b3Clock.obj"

# External object files for target AppBasicExampleGui
AppBasicExampleGui_EXTERNAL_OBJECTS =

examples/BasicDemo/AppBasicExampleGui.exe: examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/BasicExample.obj
examples/BasicDemo/AppBasicExampleGui.exe: examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/__/__/build3/bullet.obj
examples/BasicDemo/AppBasicExampleGui.exe: examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/__/StandaloneMain/main_opengl_single_example.obj
examples/BasicDemo/AppBasicExampleGui.exe: examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/__/ExampleBrowser/OpenGLGuiHelper.obj
examples/BasicDemo/AppBasicExampleGui.exe: examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/__/ExampleBrowser/GL_ShapeDrawer.obj
examples/BasicDemo/AppBasicExampleGui.exe: examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/__/ExampleBrowser/CollisionShape2TriangleMesh.obj
examples/BasicDemo/AppBasicExampleGui.exe: examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/__/Utils/b3Clock.obj
examples/BasicDemo/AppBasicExampleGui.exe: examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/build.make
examples/BasicDemo/AppBasicExampleGui.exe: lib/libBulletDynamics.dll.a
examples/BasicDemo/AppBasicExampleGui.exe: lib/libBulletCollision.dll.a
examples/BasicDemo/AppBasicExampleGui.exe: lib/libLinearMath.dll.a
examples/BasicDemo/AppBasicExampleGui.exe: lib/libOpenGLWindow.dll.a
examples/BasicDemo/AppBasicExampleGui.exe: lib/libBullet3Common.dll.a
examples/BasicDemo/AppBasicExampleGui.exe: examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/linklibs.rsp
examples/BasicDemo/AppBasicExampleGui.exe: examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/D/C++ Libs/bullet3-2.87/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable AppBasicExampleGui.exe"
	cd "/D/C++ Libs/bullet3-2.87/examples/BasicDemo" && /D/Games/cmake-3.12.0-rc1-win32-x86/bin/cmake.exe -E remove -f CMakeFiles/AppBasicExampleGui.dir/objects.a
	cd "/D/C++ Libs/bullet3-2.87/examples/BasicDemo" && /C/msys32/mingw32/bin/ar.exe cr CMakeFiles/AppBasicExampleGui.dir/objects.a @CMakeFiles/AppBasicExampleGui.dir/objects1.rsp
	cd "/D/C++ Libs/bullet3-2.87/examples/BasicDemo" && /C/msys32/mingw32/bin/g++.exe  -std=c++11 -O3 -DNDEBUG   -Wl,--whole-archive CMakeFiles/AppBasicExampleGui.dir/objects.a -Wl,--no-whole-archive  -o AppBasicExampleGui.exe -Wl,--out-implib,libAppBasicExampleGui.dll.a -Wl,--major-image-version,0,--minor-image-version,0 @CMakeFiles/AppBasicExampleGui.dir/linklibs.rsp

# Rule to build all files generated by this target.
examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/build: examples/BasicDemo/AppBasicExampleGui.exe

.PHONY : examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/build

examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/clean:
	cd "/D/C++ Libs/bullet3-2.87/examples/BasicDemo" && $(CMAKE_COMMAND) -P CMakeFiles/AppBasicExampleGui.dir/cmake_clean.cmake
.PHONY : examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/clean

examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MSYS Makefiles" "/D/C++ Libs/bullet3-2.87" "/D/C++ Libs/bullet3-2.87/examples/BasicDemo" "/D/C++ Libs/bullet3-2.87" "/D/C++ Libs/bullet3-2.87/examples/BasicDemo" "/D/C++ Libs/bullet3-2.87/examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : examples/BasicDemo/CMakeFiles/AppBasicExampleGui.dir/depend

