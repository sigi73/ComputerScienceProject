# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/siddharth/ClionProjects/VulkanEngine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug

# Include any dependencies generated for this target.
include Packages/glfw/src/CMakeFiles/glfw.dir/depend.make

# Include the progress variables for this target.
include Packages/glfw/src/CMakeFiles/glfw.dir/progress.make

# Include the compile flags for this target's objects.
include Packages/glfw/src/CMakeFiles/glfw.dir/flags.make

Packages/glfw/src/CMakeFiles/glfw.dir/context.c.o: Packages/glfw/src/CMakeFiles/glfw.dir/flags.make
Packages/glfw/src/CMakeFiles/glfw.dir/context.c.o: ../Packages/glfw/src/context.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object Packages/glfw/src/CMakeFiles/glfw.dir/context.c.o"
	cd /home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/Packages/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glfw.dir/context.c.o   -c /home/siddharth/ClionProjects/VulkanEngine/Packages/glfw/src/context.c

Packages/glfw/src/CMakeFiles/glfw.dir/context.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/context.c.i"
	cd /home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/Packages/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/siddharth/ClionProjects/VulkanEngine/Packages/glfw/src/context.c > CMakeFiles/glfw.dir/context.c.i

Packages/glfw/src/CMakeFiles/glfw.dir/context.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/context.c.s"
	cd /home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/Packages/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/siddharth/ClionProjects/VulkanEngine/Packages/glfw/src/context.c -o CMakeFiles/glfw.dir/context.c.s

Packages/glfw/src/CMakeFiles/glfw.dir/context.c.o.requires:

.PHONY : Packages/glfw/src/CMakeFiles/glfw.dir/context.c.o.requires

Packages/glfw/src/CMakeFiles/glfw.dir/context.c.o.provides: Packages/glfw/src/CMakeFiles/glfw.dir/context.c.o.requires
	$(MAKE) -f Packages/glfw/src/CMakeFiles/glfw.dir/build.make Packages/glfw/src/CMakeFiles/glfw.dir/context.c.o.provides.build
.PHONY : Packages/glfw/src/CMakeFiles/glfw.dir/context.c.o.provides

Packages/glfw/src/CMakeFiles/glfw.dir/context.c.o.provides.build: Packages/glfw/src/CMakeFiles/glfw.dir/context.c.o


Packages/glfw/src/CMakeFiles/glfw.dir/init.c.o: Packages/glfw/src/CMakeFiles/glfw.dir/flags.make
Packages/glfw/src/CMakeFiles/glfw.dir/init.c.o: ../Packages/glfw/src/init.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object Packages/glfw/src/CMakeFiles/glfw.dir/init.c.o"
	cd /home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/Packages/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glfw.dir/init.c.o   -c /home/siddharth/ClionProjects/VulkanEngine/Packages/glfw/src/init.c

Packages/glfw/src/CMakeFiles/glfw.dir/init.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/init.c.i"
	cd /home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/Packages/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/siddharth/ClionProjects/VulkanEngine/Packages/glfw/src/init.c > CMakeFiles/glfw.dir/init.c.i

Packages/glfw/src/CMakeFiles/glfw.dir/init.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/init.c.s"
	cd /home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/Packages/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/siddharth/ClionProjects/VulkanEngine/Packages/glfw/src/init.c -o CMakeFiles/glfw.dir/init.c.s

Packages/glfw/src/CMakeFiles/glfw.dir/init.c.o.requires:

.PHONY : Packages/glfw/src/CMakeFiles/glfw.dir/init.c.o.requires

Packages/glfw/src/CMakeFiles/glfw.dir/init.c.o.provides: Packages/glfw/src/CMakeFiles/glfw.dir/init.c.o.requires
	$(MAKE) -f Packages/glfw/src/CMakeFiles/glfw.dir/build.make Packages/glfw/src/CMakeFiles/glfw.dir/init.c.o.provides.build
.PHONY : Packages/glfw/src/CMakeFiles/glfw.dir/init.c.o.provides

Packages/glfw/src/CMakeFiles/glfw.dir/init.c.o.provides.build: Packages/glfw/src/CMakeFiles/glfw.dir/init.c.o


Packages/glfw/src/CMakeFiles/glfw.dir/input.c.o: Packages/glfw/src/CMakeFiles/glfw.dir/flags.make
Packages/glfw/src/CMakeFiles/glfw.dir/input.c.o: ../Packages/glfw/src/input.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object Packages/glfw/src/CMakeFiles/glfw.dir/input.c.o"
	cd /home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/Packages/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glfw.dir/input.c.o   -c /home/siddharth/ClionProjects/VulkanEngine/Packages/glfw/src/input.c

Packages/glfw/src/CMakeFiles/glfw.dir/input.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/input.c.i"
	cd /home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/Packages/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/siddharth/ClionProjects/VulkanEngine/Packages/glfw/src/input.c > CMakeFiles/glfw.dir/input.c.i

Packages/glfw/src/CMakeFiles/glfw.dir/input.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/input.c.s"
	cd /home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/Packages/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/siddharth/ClionProjects/VulkanEngine/Packages/glfw/src/input.c -o CMakeFiles/glfw.dir/input.c.s

Packages/glfw/src/CMakeFiles/glfw.dir/input.c.o.requires:

.PHONY : Packages/glfw/src/CMakeFiles/glfw.dir/input.c.o.requires

Packages/glfw/src/CMakeFiles/glfw.dir/input.c.o.provides: Packages/glfw/src/CMakeFiles/glfw.dir/input.c.o.requires
	$(MAKE) -f Packages/glfw/src/CMakeFiles/glfw.dir/build.make Packages/glfw/src/CMakeFiles/glfw.dir/input.c.o.provides.build
.PHONY : Packages/glfw/src/CMakeFiles/glfw.dir/input.c.o.provides

Packages/glfw/src/CMakeFiles/glfw.dir/input.c.o.provides.build: Packages/glfw/src/CMakeFiles/glfw.dir/input.c.o


Packages/glfw/src/CMakeFiles/glfw.dir/monitor.c.o: Packages/glfw/src/CMakeFiles/glfw.dir/flags.make
Packages/glfw/src/CMakeFiles/glfw.dir/monitor.c.o: ../Packages/glfw/src/monitor.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object Packages/glfw/src/CMakeFiles/glfw.dir/monitor.c.o"
	cd /home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/Packages/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glfw.dir/monitor.c.o   -c /home/siddharth/ClionProjects/VulkanEngine/Packages/glfw/src/monitor.c

Packages/glfw/src/CMakeFiles/glfw.dir/monitor.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/monitor.c.i"
	cd /home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/Packages/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/siddharth/ClionProjects/VulkanEngine/Packages/glfw/src/monitor.c > CMakeFiles/glfw.dir/monitor.c.i

Packages/glfw/src/CMakeFiles/glfw.dir/monitor.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/monitor.c.s"
	cd /home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/Packages/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/siddharth/ClionProjects/VulkanEngine/Packages/glfw/src/monitor.c -o CMakeFiles/glfw.dir/monitor.c.s

Packages/glfw/src/CMakeFiles/glfw.dir/monitor.c.o.requires:

.PHONY : Packages/glfw/src/CMakeFiles/glfw.dir/monitor.c.o.requires

Packages/glfw/src/CMakeFiles/glfw.dir/monitor.c.o.provides: Packages/glfw/src/CMakeFiles/glfw.dir/monitor.c.o.requires
	$(MAKE) -f Packages/glfw/src/CMakeFiles/glfw.dir/build.make Packages/glfw/src/CMakeFiles/glfw.dir/monitor.c.o.provides.build
.PHONY : Packages/glfw/src/CMakeFiles/glfw.dir/monitor.c.o.provides

Packages/glfw/src/CMakeFiles/glfw.dir/monitor.c.o.provides.build: Packages/glfw/src/CMakeFiles/glfw.dir/monitor.c.o


Packages/glfw/src/CMakeFiles/glfw.dir/vulkan.c.o: Packages/glfw/src/CMakeFiles/glfw.dir/flags.make
Packages/glfw/src/CMakeFiles/glfw.dir/vulkan.c.o: ../Packages/glfw/src/vulkan.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object Packages/glfw/src/CMakeFiles/glfw.dir/vulkan.c.o"
	cd /home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/Packages/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glfw.dir/vulkan.c.o   -c /home/siddharth/ClionProjects/VulkanEngine/Packages/glfw/src/vulkan.c

Packages/glfw/src/CMakeFiles/glfw.dir/vulkan.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/vulkan.c.i"
	cd /home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/Packages/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/siddharth/ClionProjects/VulkanEngine/Packages/glfw/src/vulkan.c > CMakeFiles/glfw.dir/vulkan.c.i

Packages/glfw/src/CMakeFiles/glfw.dir/vulkan.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/vulkan.c.s"
	cd /home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/Packages/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/siddharth/ClionProjects/VulkanEngine/Packages/glfw/src/vulkan.c -o CMakeFiles/glfw.dir/vulkan.c.s

Packages/glfw/src/CMakeFiles/glfw.dir/vulkan.c.o.requires:

.PHONY : Packages/glfw/src/CMakeFiles/glfw.dir/vulkan.c.o.requires

Packages/glfw/src/CMakeFiles/glfw.dir/vulkan.c.o.provides: Packages/glfw/src/CMakeFiles/glfw.dir/vulkan.c.o.requires
	$(MAKE) -f Packages/glfw/src/CMakeFiles/glfw.dir/build.make Packages/glfw/src/CMakeFiles/glfw.dir/vulkan.c.o.provides.build
.PHONY : Packages/glfw/src/CMakeFiles/glfw.dir/vulkan.c.o.provides

Packages/glfw/src/CMakeFiles/glfw.dir/vulkan.c.o.provides.build: Packages/glfw/src/CMakeFiles/glfw.dir/vulkan.c.o


Packages/glfw/src/CMakeFiles/glfw.dir/window.c.o: Packages/glfw/src/CMakeFiles/glfw.dir/flags.make
Packages/glfw/src/CMakeFiles/glfw.dir/window.c.o: ../Packages/glfw/src/window.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object Packages/glfw/src/CMakeFiles/glfw.dir/window.c.o"
	cd /home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/Packages/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glfw.dir/window.c.o   -c /home/siddharth/ClionProjects/VulkanEngine/Packages/glfw/src/window.c

Packages/glfw/src/CMakeFiles/glfw.dir/window.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/window.c.i"
	cd /home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/Packages/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/siddharth/ClionProjects/VulkanEngine/Packages/glfw/src/window.c > CMakeFiles/glfw.dir/window.c.i

Packages/glfw/src/CMakeFiles/glfw.dir/window.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/window.c.s"
	cd /home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/Packages/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/siddharth/ClionProjects/VulkanEngine/Packages/glfw/src/window.c -o CMakeFiles/glfw.dir/window.c.s

Packages/glfw/src/CMakeFiles/glfw.dir/window.c.o.requires:

.PHONY : Packages/glfw/src/CMakeFiles/glfw.dir/window.c.o.requires

Packages/glfw/src/CMakeFiles/glfw.dir/window.c.o.provides: Packages/glfw/src/CMakeFiles/glfw.dir/window.c.o.requires
	$(MAKE) -f Packages/glfw/src/CMakeFiles/glfw.dir/build.make Packages/glfw/src/CMakeFiles/glfw.dir/window.c.o.provides.build
.PHONY : Packages/glfw/src/CMakeFiles/glfw.dir/window.c.o.provides

Packages/glfw/src/CMakeFiles/glfw.dir/window.c.o.provides.build: Packages/glfw/src/CMakeFiles/glfw.dir/window.c.o


Packages/glfw/src/CMakeFiles/glfw.dir/x11_init.c.o: Packages/glfw/src/CMakeFiles/glfw.dir/flags.make
Packages/glfw/src/CMakeFiles/glfw.dir/x11_init.c.o: ../Packages/glfw/src/x11_init.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object Packages/glfw/src/CMakeFiles/glfw.dir/x11_init.c.o"
	cd /home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/Packages/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glfw.dir/x11_init.c.o   -c /home/siddharth/ClionProjects/VulkanEngine/Packages/glfw/src/x11_init.c

Packages/glfw/src/CMakeFiles/glfw.dir/x11_init.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/x11_init.c.i"
	cd /home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/Packages/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/siddharth/ClionProjects/VulkanEngine/Packages/glfw/src/x11_init.c > CMakeFiles/glfw.dir/x11_init.c.i

Packages/glfw/src/CMakeFiles/glfw.dir/x11_init.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/x11_init.c.s"
	cd /home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/Packages/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/siddharth/ClionProjects/VulkanEngine/Packages/glfw/src/x11_init.c -o CMakeFiles/glfw.dir/x11_init.c.s

Packages/glfw/src/CMakeFiles/glfw.dir/x11_init.c.o.requires:

.PHONY : Packages/glfw/src/CMakeFiles/glfw.dir/x11_init.c.o.requires

Packages/glfw/src/CMakeFiles/glfw.dir/x11_init.c.o.provides: Packages/glfw/src/CMakeFiles/glfw.dir/x11_init.c.o.requires
	$(MAKE) -f Packages/glfw/src/CMakeFiles/glfw.dir/build.make Packages/glfw/src/CMakeFiles/glfw.dir/x11_init.c.o.provides.build
.PHONY : Packages/glfw/src/CMakeFiles/glfw.dir/x11_init.c.o.provides

Packages/glfw/src/CMakeFiles/glfw.dir/x11_init.c.o.provides.build: Packages/glfw/src/CMakeFiles/glfw.dir/x11_init.c.o


Packages/glfw/src/CMakeFiles/glfw.dir/x11_monitor.c.o: Packages/glfw/src/CMakeFiles/glfw.dir/flags.make
Packages/glfw/src/CMakeFiles/glfw.dir/x11_monitor.c.o: ../Packages/glfw/src/x11_monitor.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object Packages/glfw/src/CMakeFiles/glfw.dir/x11_monitor.c.o"
	cd /home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/Packages/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glfw.dir/x11_monitor.c.o   -c /home/siddharth/ClionProjects/VulkanEngine/Packages/glfw/src/x11_monitor.c

Packages/glfw/src/CMakeFiles/glfw.dir/x11_monitor.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/x11_monitor.c.i"
	cd /home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/Packages/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/siddharth/ClionProjects/VulkanEngine/Packages/glfw/src/x11_monitor.c > CMakeFiles/glfw.dir/x11_monitor.c.i

Packages/glfw/src/CMakeFiles/glfw.dir/x11_monitor.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/x11_monitor.c.s"
	cd /home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/Packages/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/siddharth/ClionProjects/VulkanEngine/Packages/glfw/src/x11_monitor.c -o CMakeFiles/glfw.dir/x11_monitor.c.s

Packages/glfw/src/CMakeFiles/glfw.dir/x11_monitor.c.o.requires:

.PHONY : Packages/glfw/src/CMakeFiles/glfw.dir/x11_monitor.c.o.requires

Packages/glfw/src/CMakeFiles/glfw.dir/x11_monitor.c.o.provides: Packages/glfw/src/CMakeFiles/glfw.dir/x11_monitor.c.o.requires
	$(MAKE) -f Packages/glfw/src/CMakeFiles/glfw.dir/build.make Packages/glfw/src/CMakeFiles/glfw.dir/x11_monitor.c.o.provides.build
.PHONY : Packages/glfw/src/CMakeFiles/glfw.dir/x11_monitor.c.o.provides

Packages/glfw/src/CMakeFiles/glfw.dir/x11_monitor.c.o.provides.build: Packages/glfw/src/CMakeFiles/glfw.dir/x11_monitor.c.o


Packages/glfw/src/CMakeFiles/glfw.dir/x11_window.c.o: Packages/glfw/src/CMakeFiles/glfw.dir/flags.make
Packages/glfw/src/CMakeFiles/glfw.dir/x11_window.c.o: ../Packages/glfw/src/x11_window.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object Packages/glfw/src/CMakeFiles/glfw.dir/x11_window.c.o"
	cd /home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/Packages/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glfw.dir/x11_window.c.o   -c /home/siddharth/ClionProjects/VulkanEngine/Packages/glfw/src/x11_window.c

Packages/glfw/src/CMakeFiles/glfw.dir/x11_window.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/x11_window.c.i"
	cd /home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/Packages/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/siddharth/ClionProjects/VulkanEngine/Packages/glfw/src/x11_window.c > CMakeFiles/glfw.dir/x11_window.c.i

Packages/glfw/src/CMakeFiles/glfw.dir/x11_window.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/x11_window.c.s"
	cd /home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/Packages/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/siddharth/ClionProjects/VulkanEngine/Packages/glfw/src/x11_window.c -o CMakeFiles/glfw.dir/x11_window.c.s

Packages/glfw/src/CMakeFiles/glfw.dir/x11_window.c.o.requires:

.PHONY : Packages/glfw/src/CMakeFiles/glfw.dir/x11_window.c.o.requires

Packages/glfw/src/CMakeFiles/glfw.dir/x11_window.c.o.provides: Packages/glfw/src/CMakeFiles/glfw.dir/x11_window.c.o.requires
	$(MAKE) -f Packages/glfw/src/CMakeFiles/glfw.dir/build.make Packages/glfw/src/CMakeFiles/glfw.dir/x11_window.c.o.provides.build
.PHONY : Packages/glfw/src/CMakeFiles/glfw.dir/x11_window.c.o.provides

Packages/glfw/src/CMakeFiles/glfw.dir/x11_window.c.o.provides.build: Packages/glfw/src/CMakeFiles/glfw.dir/x11_window.c.o


Packages/glfw/src/CMakeFiles/glfw.dir/xkb_unicode.c.o: Packages/glfw/src/CMakeFiles/glfw.dir/flags.make
Packages/glfw/src/CMakeFiles/glfw.dir/xkb_unicode.c.o: ../Packages/glfw/src/xkb_unicode.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object Packages/glfw/src/CMakeFiles/glfw.dir/xkb_unicode.c.o"
	cd /home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/Packages/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glfw.dir/xkb_unicode.c.o   -c /home/siddharth/ClionProjects/VulkanEngine/Packages/glfw/src/xkb_unicode.c

Packages/glfw/src/CMakeFiles/glfw.dir/xkb_unicode.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/xkb_unicode.c.i"
	cd /home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/Packages/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/siddharth/ClionProjects/VulkanEngine/Packages/glfw/src/xkb_unicode.c > CMakeFiles/glfw.dir/xkb_unicode.c.i

Packages/glfw/src/CMakeFiles/glfw.dir/xkb_unicode.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/xkb_unicode.c.s"
	cd /home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/Packages/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/siddharth/ClionProjects/VulkanEngine/Packages/glfw/src/xkb_unicode.c -o CMakeFiles/glfw.dir/xkb_unicode.c.s

Packages/glfw/src/CMakeFiles/glfw.dir/xkb_unicode.c.o.requires:

.PHONY : Packages/glfw/src/CMakeFiles/glfw.dir/xkb_unicode.c.o.requires

Packages/glfw/src/CMakeFiles/glfw.dir/xkb_unicode.c.o.provides: Packages/glfw/src/CMakeFiles/glfw.dir/xkb_unicode.c.o.requires
	$(MAKE) -f Packages/glfw/src/CMakeFiles/glfw.dir/build.make Packages/glfw/src/CMakeFiles/glfw.dir/xkb_unicode.c.o.provides.build
.PHONY : Packages/glfw/src/CMakeFiles/glfw.dir/xkb_unicode.c.o.provides

Packages/glfw/src/CMakeFiles/glfw.dir/xkb_unicode.c.o.provides.build: Packages/glfw/src/CMakeFiles/glfw.dir/xkb_unicode.c.o


Packages/glfw/src/CMakeFiles/glfw.dir/linux_joystick.c.o: Packages/glfw/src/CMakeFiles/glfw.dir/flags.make
Packages/glfw/src/CMakeFiles/glfw.dir/linux_joystick.c.o: ../Packages/glfw/src/linux_joystick.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object Packages/glfw/src/CMakeFiles/glfw.dir/linux_joystick.c.o"
	cd /home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/Packages/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glfw.dir/linux_joystick.c.o   -c /home/siddharth/ClionProjects/VulkanEngine/Packages/glfw/src/linux_joystick.c

Packages/glfw/src/CMakeFiles/glfw.dir/linux_joystick.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/linux_joystick.c.i"
	cd /home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/Packages/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/siddharth/ClionProjects/VulkanEngine/Packages/glfw/src/linux_joystick.c > CMakeFiles/glfw.dir/linux_joystick.c.i

Packages/glfw/src/CMakeFiles/glfw.dir/linux_joystick.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/linux_joystick.c.s"
	cd /home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/Packages/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/siddharth/ClionProjects/VulkanEngine/Packages/glfw/src/linux_joystick.c -o CMakeFiles/glfw.dir/linux_joystick.c.s

Packages/glfw/src/CMakeFiles/glfw.dir/linux_joystick.c.o.requires:

.PHONY : Packages/glfw/src/CMakeFiles/glfw.dir/linux_joystick.c.o.requires

Packages/glfw/src/CMakeFiles/glfw.dir/linux_joystick.c.o.provides: Packages/glfw/src/CMakeFiles/glfw.dir/linux_joystick.c.o.requires
	$(MAKE) -f Packages/glfw/src/CMakeFiles/glfw.dir/build.make Packages/glfw/src/CMakeFiles/glfw.dir/linux_joystick.c.o.provides.build
.PHONY : Packages/glfw/src/CMakeFiles/glfw.dir/linux_joystick.c.o.provides

Packages/glfw/src/CMakeFiles/glfw.dir/linux_joystick.c.o.provides.build: Packages/glfw/src/CMakeFiles/glfw.dir/linux_joystick.c.o


Packages/glfw/src/CMakeFiles/glfw.dir/posix_time.c.o: Packages/glfw/src/CMakeFiles/glfw.dir/flags.make
Packages/glfw/src/CMakeFiles/glfw.dir/posix_time.c.o: ../Packages/glfw/src/posix_time.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object Packages/glfw/src/CMakeFiles/glfw.dir/posix_time.c.o"
	cd /home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/Packages/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glfw.dir/posix_time.c.o   -c /home/siddharth/ClionProjects/VulkanEngine/Packages/glfw/src/posix_time.c

Packages/glfw/src/CMakeFiles/glfw.dir/posix_time.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/posix_time.c.i"
	cd /home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/Packages/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/siddharth/ClionProjects/VulkanEngine/Packages/glfw/src/posix_time.c > CMakeFiles/glfw.dir/posix_time.c.i

Packages/glfw/src/CMakeFiles/glfw.dir/posix_time.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/posix_time.c.s"
	cd /home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/Packages/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/siddharth/ClionProjects/VulkanEngine/Packages/glfw/src/posix_time.c -o CMakeFiles/glfw.dir/posix_time.c.s

Packages/glfw/src/CMakeFiles/glfw.dir/posix_time.c.o.requires:

.PHONY : Packages/glfw/src/CMakeFiles/glfw.dir/posix_time.c.o.requires

Packages/glfw/src/CMakeFiles/glfw.dir/posix_time.c.o.provides: Packages/glfw/src/CMakeFiles/glfw.dir/posix_time.c.o.requires
	$(MAKE) -f Packages/glfw/src/CMakeFiles/glfw.dir/build.make Packages/glfw/src/CMakeFiles/glfw.dir/posix_time.c.o.provides.build
.PHONY : Packages/glfw/src/CMakeFiles/glfw.dir/posix_time.c.o.provides

Packages/glfw/src/CMakeFiles/glfw.dir/posix_time.c.o.provides.build: Packages/glfw/src/CMakeFiles/glfw.dir/posix_time.c.o


Packages/glfw/src/CMakeFiles/glfw.dir/posix_tls.c.o: Packages/glfw/src/CMakeFiles/glfw.dir/flags.make
Packages/glfw/src/CMakeFiles/glfw.dir/posix_tls.c.o: ../Packages/glfw/src/posix_tls.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building C object Packages/glfw/src/CMakeFiles/glfw.dir/posix_tls.c.o"
	cd /home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/Packages/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glfw.dir/posix_tls.c.o   -c /home/siddharth/ClionProjects/VulkanEngine/Packages/glfw/src/posix_tls.c

Packages/glfw/src/CMakeFiles/glfw.dir/posix_tls.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/posix_tls.c.i"
	cd /home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/Packages/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/siddharth/ClionProjects/VulkanEngine/Packages/glfw/src/posix_tls.c > CMakeFiles/glfw.dir/posix_tls.c.i

Packages/glfw/src/CMakeFiles/glfw.dir/posix_tls.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/posix_tls.c.s"
	cd /home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/Packages/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/siddharth/ClionProjects/VulkanEngine/Packages/glfw/src/posix_tls.c -o CMakeFiles/glfw.dir/posix_tls.c.s

Packages/glfw/src/CMakeFiles/glfw.dir/posix_tls.c.o.requires:

.PHONY : Packages/glfw/src/CMakeFiles/glfw.dir/posix_tls.c.o.requires

Packages/glfw/src/CMakeFiles/glfw.dir/posix_tls.c.o.provides: Packages/glfw/src/CMakeFiles/glfw.dir/posix_tls.c.o.requires
	$(MAKE) -f Packages/glfw/src/CMakeFiles/glfw.dir/build.make Packages/glfw/src/CMakeFiles/glfw.dir/posix_tls.c.o.provides.build
.PHONY : Packages/glfw/src/CMakeFiles/glfw.dir/posix_tls.c.o.provides

Packages/glfw/src/CMakeFiles/glfw.dir/posix_tls.c.o.provides.build: Packages/glfw/src/CMakeFiles/glfw.dir/posix_tls.c.o


Packages/glfw/src/CMakeFiles/glfw.dir/glx_context.c.o: Packages/glfw/src/CMakeFiles/glfw.dir/flags.make
Packages/glfw/src/CMakeFiles/glfw.dir/glx_context.c.o: ../Packages/glfw/src/glx_context.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building C object Packages/glfw/src/CMakeFiles/glfw.dir/glx_context.c.o"
	cd /home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/Packages/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glfw.dir/glx_context.c.o   -c /home/siddharth/ClionProjects/VulkanEngine/Packages/glfw/src/glx_context.c

Packages/glfw/src/CMakeFiles/glfw.dir/glx_context.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/glx_context.c.i"
	cd /home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/Packages/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/siddharth/ClionProjects/VulkanEngine/Packages/glfw/src/glx_context.c > CMakeFiles/glfw.dir/glx_context.c.i

Packages/glfw/src/CMakeFiles/glfw.dir/glx_context.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/glx_context.c.s"
	cd /home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/Packages/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/siddharth/ClionProjects/VulkanEngine/Packages/glfw/src/glx_context.c -o CMakeFiles/glfw.dir/glx_context.c.s

Packages/glfw/src/CMakeFiles/glfw.dir/glx_context.c.o.requires:

.PHONY : Packages/glfw/src/CMakeFiles/glfw.dir/glx_context.c.o.requires

Packages/glfw/src/CMakeFiles/glfw.dir/glx_context.c.o.provides: Packages/glfw/src/CMakeFiles/glfw.dir/glx_context.c.o.requires
	$(MAKE) -f Packages/glfw/src/CMakeFiles/glfw.dir/build.make Packages/glfw/src/CMakeFiles/glfw.dir/glx_context.c.o.provides.build
.PHONY : Packages/glfw/src/CMakeFiles/glfw.dir/glx_context.c.o.provides

Packages/glfw/src/CMakeFiles/glfw.dir/glx_context.c.o.provides.build: Packages/glfw/src/CMakeFiles/glfw.dir/glx_context.c.o


Packages/glfw/src/CMakeFiles/glfw.dir/egl_context.c.o: Packages/glfw/src/CMakeFiles/glfw.dir/flags.make
Packages/glfw/src/CMakeFiles/glfw.dir/egl_context.c.o: ../Packages/glfw/src/egl_context.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building C object Packages/glfw/src/CMakeFiles/glfw.dir/egl_context.c.o"
	cd /home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/Packages/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glfw.dir/egl_context.c.o   -c /home/siddharth/ClionProjects/VulkanEngine/Packages/glfw/src/egl_context.c

Packages/glfw/src/CMakeFiles/glfw.dir/egl_context.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/egl_context.c.i"
	cd /home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/Packages/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/siddharth/ClionProjects/VulkanEngine/Packages/glfw/src/egl_context.c > CMakeFiles/glfw.dir/egl_context.c.i

Packages/glfw/src/CMakeFiles/glfw.dir/egl_context.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/egl_context.c.s"
	cd /home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/Packages/glfw/src && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/siddharth/ClionProjects/VulkanEngine/Packages/glfw/src/egl_context.c -o CMakeFiles/glfw.dir/egl_context.c.s

Packages/glfw/src/CMakeFiles/glfw.dir/egl_context.c.o.requires:

.PHONY : Packages/glfw/src/CMakeFiles/glfw.dir/egl_context.c.o.requires

Packages/glfw/src/CMakeFiles/glfw.dir/egl_context.c.o.provides: Packages/glfw/src/CMakeFiles/glfw.dir/egl_context.c.o.requires
	$(MAKE) -f Packages/glfw/src/CMakeFiles/glfw.dir/build.make Packages/glfw/src/CMakeFiles/glfw.dir/egl_context.c.o.provides.build
.PHONY : Packages/glfw/src/CMakeFiles/glfw.dir/egl_context.c.o.provides

Packages/glfw/src/CMakeFiles/glfw.dir/egl_context.c.o.provides.build: Packages/glfw/src/CMakeFiles/glfw.dir/egl_context.c.o


# Object files for target glfw
glfw_OBJECTS = \
"CMakeFiles/glfw.dir/context.c.o" \
"CMakeFiles/glfw.dir/init.c.o" \
"CMakeFiles/glfw.dir/input.c.o" \
"CMakeFiles/glfw.dir/monitor.c.o" \
"CMakeFiles/glfw.dir/vulkan.c.o" \
"CMakeFiles/glfw.dir/window.c.o" \
"CMakeFiles/glfw.dir/x11_init.c.o" \
"CMakeFiles/glfw.dir/x11_monitor.c.o" \
"CMakeFiles/glfw.dir/x11_window.c.o" \
"CMakeFiles/glfw.dir/xkb_unicode.c.o" \
"CMakeFiles/glfw.dir/linux_joystick.c.o" \
"CMakeFiles/glfw.dir/posix_time.c.o" \
"CMakeFiles/glfw.dir/posix_tls.c.o" \
"CMakeFiles/glfw.dir/glx_context.c.o" \
"CMakeFiles/glfw.dir/egl_context.c.o"

# External object files for target glfw
glfw_EXTERNAL_OBJECTS =

Packages/glfw/src/libglfw3.a: Packages/glfw/src/CMakeFiles/glfw.dir/context.c.o
Packages/glfw/src/libglfw3.a: Packages/glfw/src/CMakeFiles/glfw.dir/init.c.o
Packages/glfw/src/libglfw3.a: Packages/glfw/src/CMakeFiles/glfw.dir/input.c.o
Packages/glfw/src/libglfw3.a: Packages/glfw/src/CMakeFiles/glfw.dir/monitor.c.o
Packages/glfw/src/libglfw3.a: Packages/glfw/src/CMakeFiles/glfw.dir/vulkan.c.o
Packages/glfw/src/libglfw3.a: Packages/glfw/src/CMakeFiles/glfw.dir/window.c.o
Packages/glfw/src/libglfw3.a: Packages/glfw/src/CMakeFiles/glfw.dir/x11_init.c.o
Packages/glfw/src/libglfw3.a: Packages/glfw/src/CMakeFiles/glfw.dir/x11_monitor.c.o
Packages/glfw/src/libglfw3.a: Packages/glfw/src/CMakeFiles/glfw.dir/x11_window.c.o
Packages/glfw/src/libglfw3.a: Packages/glfw/src/CMakeFiles/glfw.dir/xkb_unicode.c.o
Packages/glfw/src/libglfw3.a: Packages/glfw/src/CMakeFiles/glfw.dir/linux_joystick.c.o
Packages/glfw/src/libglfw3.a: Packages/glfw/src/CMakeFiles/glfw.dir/posix_time.c.o
Packages/glfw/src/libglfw3.a: Packages/glfw/src/CMakeFiles/glfw.dir/posix_tls.c.o
Packages/glfw/src/libglfw3.a: Packages/glfw/src/CMakeFiles/glfw.dir/glx_context.c.o
Packages/glfw/src/libglfw3.a: Packages/glfw/src/CMakeFiles/glfw.dir/egl_context.c.o
Packages/glfw/src/libglfw3.a: Packages/glfw/src/CMakeFiles/glfw.dir/build.make
Packages/glfw/src/libglfw3.a: Packages/glfw/src/CMakeFiles/glfw.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Linking C static library libglfw3.a"
	cd /home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/Packages/glfw/src && $(CMAKE_COMMAND) -P CMakeFiles/glfw.dir/cmake_clean_target.cmake
	cd /home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/Packages/glfw/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/glfw.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Packages/glfw/src/CMakeFiles/glfw.dir/build: Packages/glfw/src/libglfw3.a

.PHONY : Packages/glfw/src/CMakeFiles/glfw.dir/build

Packages/glfw/src/CMakeFiles/glfw.dir/requires: Packages/glfw/src/CMakeFiles/glfw.dir/context.c.o.requires
Packages/glfw/src/CMakeFiles/glfw.dir/requires: Packages/glfw/src/CMakeFiles/glfw.dir/init.c.o.requires
Packages/glfw/src/CMakeFiles/glfw.dir/requires: Packages/glfw/src/CMakeFiles/glfw.dir/input.c.o.requires
Packages/glfw/src/CMakeFiles/glfw.dir/requires: Packages/glfw/src/CMakeFiles/glfw.dir/monitor.c.o.requires
Packages/glfw/src/CMakeFiles/glfw.dir/requires: Packages/glfw/src/CMakeFiles/glfw.dir/vulkan.c.o.requires
Packages/glfw/src/CMakeFiles/glfw.dir/requires: Packages/glfw/src/CMakeFiles/glfw.dir/window.c.o.requires
Packages/glfw/src/CMakeFiles/glfw.dir/requires: Packages/glfw/src/CMakeFiles/glfw.dir/x11_init.c.o.requires
Packages/glfw/src/CMakeFiles/glfw.dir/requires: Packages/glfw/src/CMakeFiles/glfw.dir/x11_monitor.c.o.requires
Packages/glfw/src/CMakeFiles/glfw.dir/requires: Packages/glfw/src/CMakeFiles/glfw.dir/x11_window.c.o.requires
Packages/glfw/src/CMakeFiles/glfw.dir/requires: Packages/glfw/src/CMakeFiles/glfw.dir/xkb_unicode.c.o.requires
Packages/glfw/src/CMakeFiles/glfw.dir/requires: Packages/glfw/src/CMakeFiles/glfw.dir/linux_joystick.c.o.requires
Packages/glfw/src/CMakeFiles/glfw.dir/requires: Packages/glfw/src/CMakeFiles/glfw.dir/posix_time.c.o.requires
Packages/glfw/src/CMakeFiles/glfw.dir/requires: Packages/glfw/src/CMakeFiles/glfw.dir/posix_tls.c.o.requires
Packages/glfw/src/CMakeFiles/glfw.dir/requires: Packages/glfw/src/CMakeFiles/glfw.dir/glx_context.c.o.requires
Packages/glfw/src/CMakeFiles/glfw.dir/requires: Packages/glfw/src/CMakeFiles/glfw.dir/egl_context.c.o.requires

.PHONY : Packages/glfw/src/CMakeFiles/glfw.dir/requires

Packages/glfw/src/CMakeFiles/glfw.dir/clean:
	cd /home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/Packages/glfw/src && $(CMAKE_COMMAND) -P CMakeFiles/glfw.dir/cmake_clean.cmake
.PHONY : Packages/glfw/src/CMakeFiles/glfw.dir/clean

Packages/glfw/src/CMakeFiles/glfw.dir/depend:
	cd /home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/siddharth/ClionProjects/VulkanEngine /home/siddharth/ClionProjects/VulkanEngine/Packages/glfw/src /home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug /home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/Packages/glfw/src /home/siddharth/ClionProjects/VulkanEngine/cmake-build-debug/Packages/glfw/src/CMakeFiles/glfw.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Packages/glfw/src/CMakeFiles/glfw.dir/depend

