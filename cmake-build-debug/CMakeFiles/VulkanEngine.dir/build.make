# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /home/siddharth/Packages/clion-2016.2.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/siddharth/Packages/clion-2016.2.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/siddharth/ClionProjects/VulkanEngine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/VulkanEngine.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/VulkanEngine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/VulkanEngine.dir/flags.make

CMakeFiles/VulkanEngine.dir/main.cpp.o: CMakeFiles/VulkanEngine.dir/flags.make
CMakeFiles/VulkanEngine.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/VulkanEngine.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/VulkanEngine.dir/main.cpp.o -c /home/siddharth/ClionProjects/VulkanEngine/main.cpp

CMakeFiles/VulkanEngine.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VulkanEngine.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/siddharth/ClionProjects/VulkanEngine/main.cpp > CMakeFiles/VulkanEngine.dir/main.cpp.i

CMakeFiles/VulkanEngine.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VulkanEngine.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/siddharth/ClionProjects/VulkanEngine/main.cpp -o CMakeFiles/VulkanEngine.dir/main.cpp.s

CMakeFiles/VulkanEngine.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/VulkanEngine.dir/main.cpp.o.requires

CMakeFiles/VulkanEngine.dir/main.cpp.o.provides: CMakeFiles/VulkanEngine.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/VulkanEngine.dir/build.make CMakeFiles/VulkanEngine.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/VulkanEngine.dir/main.cpp.o.provides

CMakeFiles/VulkanEngine.dir/main.cpp.o.provides.build: CMakeFiles/VulkanEngine.dir/main.cpp.o


CMakeFiles/VulkanEngine.dir/VDeleter.cpp.o: CMakeFiles/VulkanEngine.dir/flags.make
CMakeFiles/VulkanEngine.dir/VDeleter.cpp.o: ../VDeleter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/VulkanEngine.dir/VDeleter.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/VulkanEngine.dir/VDeleter.cpp.o -c /home/siddharth/ClionProjects/VulkanEngine/VDeleter.cpp

CMakeFiles/VulkanEngine.dir/VDeleter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VulkanEngine.dir/VDeleter.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/siddharth/ClionProjects/VulkanEngine/VDeleter.cpp > CMakeFiles/VulkanEngine.dir/VDeleter.cpp.i

CMakeFiles/VulkanEngine.dir/VDeleter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VulkanEngine.dir/VDeleter.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/siddharth/ClionProjects/VulkanEngine/VDeleter.cpp -o CMakeFiles/VulkanEngine.dir/VDeleter.cpp.s

CMakeFiles/VulkanEngine.dir/VDeleter.cpp.o.requires:

.PHONY : CMakeFiles/VulkanEngine.dir/VDeleter.cpp.o.requires

CMakeFiles/VulkanEngine.dir/VDeleter.cpp.o.provides: CMakeFiles/VulkanEngine.dir/VDeleter.cpp.o.requires
	$(MAKE) -f CMakeFiles/VulkanEngine.dir/build.make CMakeFiles/VulkanEngine.dir/VDeleter.cpp.o.provides.build
.PHONY : CMakeFiles/VulkanEngine.dir/VDeleter.cpp.o.provides

CMakeFiles/VulkanEngine.dir/VDeleter.cpp.o.provides.build: CMakeFiles/VulkanEngine.dir/VDeleter.cpp.o


CMakeFiles/VulkanEngine.dir/Shader.cpp.o: CMakeFiles/VulkanEngine.dir/flags.make
CMakeFiles/VulkanEngine.dir/Shader.cpp.o: ../Shader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/VulkanEngine.dir/Shader.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/VulkanEngine.dir/Shader.cpp.o -c /home/siddharth/ClionProjects/VulkanEngine/Shader.cpp

CMakeFiles/VulkanEngine.dir/Shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VulkanEngine.dir/Shader.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/siddharth/ClionProjects/VulkanEngine/Shader.cpp > CMakeFiles/VulkanEngine.dir/Shader.cpp.i

CMakeFiles/VulkanEngine.dir/Shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VulkanEngine.dir/Shader.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/siddharth/ClionProjects/VulkanEngine/Shader.cpp -o CMakeFiles/VulkanEngine.dir/Shader.cpp.s

CMakeFiles/VulkanEngine.dir/Shader.cpp.o.requires:

.PHONY : CMakeFiles/VulkanEngine.dir/Shader.cpp.o.requires

CMakeFiles/VulkanEngine.dir/Shader.cpp.o.provides: CMakeFiles/VulkanEngine.dir/Shader.cpp.o.requires
	$(MAKE) -f CMakeFiles/VulkanEngine.dir/build.make CMakeFiles/VulkanEngine.dir/Shader.cpp.o.provides.build
.PHONY : CMakeFiles/VulkanEngine.dir/Shader.cpp.o.provides

CMakeFiles/VulkanEngine.dir/Shader.cpp.o.provides.build: CMakeFiles/VulkanEngine.dir/Shader.cpp.o


CMakeFiles/VulkanEngine.dir/Mesh.cpp.o: CMakeFiles/VulkanEngine.dir/flags.make
CMakeFiles/VulkanEngine.dir/Mesh.cpp.o: ../Mesh.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/VulkanEngine.dir/Mesh.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/VulkanEngine.dir/Mesh.cpp.o -c /home/siddharth/ClionProjects/VulkanEngine/Mesh.cpp

CMakeFiles/VulkanEngine.dir/Mesh.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VulkanEngine.dir/Mesh.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/siddharth/ClionProjects/VulkanEngine/Mesh.cpp > CMakeFiles/VulkanEngine.dir/Mesh.cpp.i

CMakeFiles/VulkanEngine.dir/Mesh.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VulkanEngine.dir/Mesh.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/siddharth/ClionProjects/VulkanEngine/Mesh.cpp -o CMakeFiles/VulkanEngine.dir/Mesh.cpp.s

CMakeFiles/VulkanEngine.dir/Mesh.cpp.o.requires:

.PHONY : CMakeFiles/VulkanEngine.dir/Mesh.cpp.o.requires

CMakeFiles/VulkanEngine.dir/Mesh.cpp.o.provides: CMakeFiles/VulkanEngine.dir/Mesh.cpp.o.requires
	$(MAKE) -f CMakeFiles/VulkanEngine.dir/build.make CMakeFiles/VulkanEngine.dir/Mesh.cpp.o.provides.build
.PHONY : CMakeFiles/VulkanEngine.dir/Mesh.cpp.o.provides

CMakeFiles/VulkanEngine.dir/Mesh.cpp.o.provides.build: CMakeFiles/VulkanEngine.dir/Mesh.cpp.o


CMakeFiles/VulkanEngine.dir/VulkanCommon.cpp.o: CMakeFiles/VulkanEngine.dir/flags.make
CMakeFiles/VulkanEngine.dir/VulkanCommon.cpp.o: ../VulkanCommon.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/VulkanEngine.dir/VulkanCommon.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/VulkanEngine.dir/VulkanCommon.cpp.o -c /home/siddharth/ClionProjects/VulkanEngine/VulkanCommon.cpp

CMakeFiles/VulkanEngine.dir/VulkanCommon.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VulkanEngine.dir/VulkanCommon.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/siddharth/ClionProjects/VulkanEngine/VulkanCommon.cpp > CMakeFiles/VulkanEngine.dir/VulkanCommon.cpp.i

CMakeFiles/VulkanEngine.dir/VulkanCommon.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VulkanEngine.dir/VulkanCommon.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/siddharth/ClionProjects/VulkanEngine/VulkanCommon.cpp -o CMakeFiles/VulkanEngine.dir/VulkanCommon.cpp.s

CMakeFiles/VulkanEngine.dir/VulkanCommon.cpp.o.requires:

.PHONY : CMakeFiles/VulkanEngine.dir/VulkanCommon.cpp.o.requires

CMakeFiles/VulkanEngine.dir/VulkanCommon.cpp.o.provides: CMakeFiles/VulkanEngine.dir/VulkanCommon.cpp.o.requires
	$(MAKE) -f CMakeFiles/VulkanEngine.dir/build.make CMakeFiles/VulkanEngine.dir/VulkanCommon.cpp.o.provides.build
.PHONY : CMakeFiles/VulkanEngine.dir/VulkanCommon.cpp.o.provides

CMakeFiles/VulkanEngine.dir/VulkanCommon.cpp.o.provides.build: CMakeFiles/VulkanEngine.dir/VulkanCommon.cpp.o


CMakeFiles/VulkanEngine.dir/VulkanApplication.cpp.o: CMakeFiles/VulkanEngine.dir/flags.make
CMakeFiles/VulkanEngine.dir/VulkanApplication.cpp.o: ../VulkanApplication.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/VulkanEngine.dir/VulkanApplication.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/VulkanEngine.dir/VulkanApplication.cpp.o -c /home/siddharth/ClionProjects/VulkanEngine/VulkanApplication.cpp

CMakeFiles/VulkanEngine.dir/VulkanApplication.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VulkanEngine.dir/VulkanApplication.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/siddharth/ClionProjects/VulkanEngine/VulkanApplication.cpp > CMakeFiles/VulkanEngine.dir/VulkanApplication.cpp.i

CMakeFiles/VulkanEngine.dir/VulkanApplication.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VulkanEngine.dir/VulkanApplication.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/siddharth/ClionProjects/VulkanEngine/VulkanApplication.cpp -o CMakeFiles/VulkanEngine.dir/VulkanApplication.cpp.s

CMakeFiles/VulkanEngine.dir/VulkanApplication.cpp.o.requires:

.PHONY : CMakeFiles/VulkanEngine.dir/VulkanApplication.cpp.o.requires

CMakeFiles/VulkanEngine.dir/VulkanApplication.cpp.o.provides: CMakeFiles/VulkanEngine.dir/VulkanApplication.cpp.o.requires
	$(MAKE) -f CMakeFiles/VulkanEngine.dir/build.make CMakeFiles/VulkanEngine.dir/VulkanApplication.cpp.o.provides.build
.PHONY : CMakeFiles/VulkanEngine.dir/VulkanApplication.cpp.o.provides

CMakeFiles/VulkanEngine.dir/VulkanApplication.cpp.o.provides.build: CMakeFiles/VulkanEngine.dir/VulkanApplication.cpp.o


# Object files for target VulkanEngine
VulkanEngine_OBJECTS = \
"CMakeFiles/VulkanEngine.dir/main.cpp.o" \
"CMakeFiles/VulkanEngine.dir/VDeleter.cpp.o" \
"CMakeFiles/VulkanEngine.dir/Shader.cpp.o" \
"CMakeFiles/VulkanEngine.dir/Mesh.cpp.o" \
"CMakeFiles/VulkanEngine.dir/VulkanCommon.cpp.o" \
"CMakeFiles/VulkanEngine.dir/VulkanApplication.cpp.o"

# External object files for target VulkanEngine
VulkanEngine_EXTERNAL_OBJECTS =

VulkanEngine: CMakeFiles/VulkanEngine.dir/main.cpp.o
VulkanEngine: CMakeFiles/VulkanEngine.dir/VDeleter.cpp.o
VulkanEngine: CMakeFiles/VulkanEngine.dir/Shader.cpp.o
VulkanEngine: CMakeFiles/VulkanEngine.dir/Mesh.cpp.o
VulkanEngine: CMakeFiles/VulkanEngine.dir/VulkanCommon.cpp.o
VulkanEngine: CMakeFiles/VulkanEngine.dir/VulkanApplication.cpp.o
VulkanEngine: CMakeFiles/VulkanEngine.dir/build.make
VulkanEngine: /usr/local/lib/libglfw3.a
VulkanEngine: /usr/lib64/librt.so
VulkanEngine: /usr/lib64/libm.so
VulkanEngine: /usr/lib64/libX11.so
VulkanEngine: /usr/lib64/libXrandr.so
VulkanEngine: /usr/lib64/libXinerama.so
VulkanEngine: /usr/lib64/libXxf86vm.so
VulkanEngine: /usr/lib64/libXcursor.so
VulkanEngine: CMakeFiles/VulkanEngine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable VulkanEngine"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/VulkanEngine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/VulkanEngine.dir/build: VulkanEngine

.PHONY : CMakeFiles/VulkanEngine.dir/build

CMakeFiles/VulkanEngine.dir/requires: CMakeFiles/VulkanEngine.dir/main.cpp.o.requires
CMakeFiles/VulkanEngine.dir/requires: CMakeFiles/VulkanEngine.dir/VDeleter.cpp.o.requires
CMakeFiles/VulkanEngine.dir/requires: CMakeFiles/VulkanEngine.dir/Shader.cpp.o.requires
CMakeFiles/VulkanEngine.dir/requires: CMakeFiles/VulkanEngine.dir/Mesh.cpp.o.requires
CMakeFiles/VulkanEngine.dir/requires: CMakeFiles/VulkanEngine.dir/VulkanCommon.cpp.o.requires
CMakeFiles/VulkanEngine.dir/requires: CMakeFiles/VulkanEngine.dir/VulkanApplication.cpp.o.requires

.PHONY : CMakeFiles/VulkanEngine.dir/requires

CMakeFiles/VulkanEngine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/VulkanEngine.dir/cmake_clean.cmake
.PHONY : CMakeFiles/VulkanEngine.dir/clean

CMakeFiles/VulkanEngine.dir/depend:
	cd /home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/siddharth/ClionProjects/VulkanEngine /home/siddharth/ClionProjects/VulkanEngine /home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug /home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug /home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/CMakeFiles/VulkanEngine.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/VulkanEngine.dir/depend

