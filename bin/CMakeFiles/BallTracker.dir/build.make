# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/cmake-gui

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tgd/Code/nurobotics_ws/lacrosse-bot

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tgd/Code/nurobotics_ws/lacrosse-bot/bin

# Include any dependencies generated for this target.
include CMakeFiles/BallTracker.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/BallTracker.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BallTracker.dir/flags.make

CMakeFiles/BallTracker.dir/src/BallTracker.cpp.o: CMakeFiles/BallTracker.dir/flags.make
CMakeFiles/BallTracker.dir/src/BallTracker.cpp.o: ../src/BallTracker.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/tgd/Code/nurobotics_ws/lacrosse-bot/bin/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/BallTracker.dir/src/BallTracker.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/BallTracker.dir/src/BallTracker.cpp.o -c /home/tgd/Code/nurobotics_ws/lacrosse-bot/src/BallTracker.cpp

CMakeFiles/BallTracker.dir/src/BallTracker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BallTracker.dir/src/BallTracker.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/tgd/Code/nurobotics_ws/lacrosse-bot/src/BallTracker.cpp > CMakeFiles/BallTracker.dir/src/BallTracker.cpp.i

CMakeFiles/BallTracker.dir/src/BallTracker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BallTracker.dir/src/BallTracker.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/tgd/Code/nurobotics_ws/lacrosse-bot/src/BallTracker.cpp -o CMakeFiles/BallTracker.dir/src/BallTracker.cpp.s

CMakeFiles/BallTracker.dir/src/BallTracker.cpp.o.requires:
.PHONY : CMakeFiles/BallTracker.dir/src/BallTracker.cpp.o.requires

CMakeFiles/BallTracker.dir/src/BallTracker.cpp.o.provides: CMakeFiles/BallTracker.dir/src/BallTracker.cpp.o.requires
	$(MAKE) -f CMakeFiles/BallTracker.dir/build.make CMakeFiles/BallTracker.dir/src/BallTracker.cpp.o.provides.build
.PHONY : CMakeFiles/BallTracker.dir/src/BallTracker.cpp.o.provides

CMakeFiles/BallTracker.dir/src/BallTracker.cpp.o.provides.build: CMakeFiles/BallTracker.dir/src/BallTracker.cpp.o

# Object files for target BallTracker
BallTracker_OBJECTS = \
"CMakeFiles/BallTracker.dir/src/BallTracker.cpp.o"

# External object files for target BallTracker
BallTracker_EXTERNAL_OBJECTS =

BallTracker: CMakeFiles/BallTracker.dir/src/BallTracker.cpp.o
BallTracker: CMakeFiles/BallTracker.dir/build.make
BallTracker: CMakeFiles/BallTracker.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable BallTracker"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BallTracker.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BallTracker.dir/build: BallTracker
.PHONY : CMakeFiles/BallTracker.dir/build

CMakeFiles/BallTracker.dir/requires: CMakeFiles/BallTracker.dir/src/BallTracker.cpp.o.requires
.PHONY : CMakeFiles/BallTracker.dir/requires

CMakeFiles/BallTracker.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/BallTracker.dir/cmake_clean.cmake
.PHONY : CMakeFiles/BallTracker.dir/clean

CMakeFiles/BallTracker.dir/depend:
	cd /home/tgd/Code/nurobotics_ws/lacrosse-bot/bin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tgd/Code/nurobotics_ws/lacrosse-bot /home/tgd/Code/nurobotics_ws/lacrosse-bot /home/tgd/Code/nurobotics_ws/lacrosse-bot/bin /home/tgd/Code/nurobotics_ws/lacrosse-bot/bin /home/tgd/Code/nurobotics_ws/lacrosse-bot/bin/CMakeFiles/BallTracker.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BallTracker.dir/depend

