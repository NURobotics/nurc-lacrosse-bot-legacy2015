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
include CMakeFiles/Trackers.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Trackers.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Trackers.dir/flags.make

CMakeFiles/Trackers.dir/src/Tracker.cpp.o: CMakeFiles/Trackers.dir/flags.make
CMakeFiles/Trackers.dir/src/Tracker.cpp.o: ../src/Tracker.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/tgd/Code/nurobotics_ws/lacrosse-bot/bin/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Trackers.dir/src/Tracker.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Trackers.dir/src/Tracker.cpp.o -c /home/tgd/Code/nurobotics_ws/lacrosse-bot/src/Tracker.cpp

CMakeFiles/Trackers.dir/src/Tracker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Trackers.dir/src/Tracker.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/tgd/Code/nurobotics_ws/lacrosse-bot/src/Tracker.cpp > CMakeFiles/Trackers.dir/src/Tracker.cpp.i

CMakeFiles/Trackers.dir/src/Tracker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Trackers.dir/src/Tracker.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/tgd/Code/nurobotics_ws/lacrosse-bot/src/Tracker.cpp -o CMakeFiles/Trackers.dir/src/Tracker.cpp.s

CMakeFiles/Trackers.dir/src/Tracker.cpp.o.requires:
.PHONY : CMakeFiles/Trackers.dir/src/Tracker.cpp.o.requires

CMakeFiles/Trackers.dir/src/Tracker.cpp.o.provides: CMakeFiles/Trackers.dir/src/Tracker.cpp.o.requires
	$(MAKE) -f CMakeFiles/Trackers.dir/build.make CMakeFiles/Trackers.dir/src/Tracker.cpp.o.provides.build
.PHONY : CMakeFiles/Trackers.dir/src/Tracker.cpp.o.provides

CMakeFiles/Trackers.dir/src/Tracker.cpp.o.provides.build: CMakeFiles/Trackers.dir/src/Tracker.cpp.o

CMakeFiles/Trackers.dir/src/Ball2DTracker.cpp.o: CMakeFiles/Trackers.dir/flags.make
CMakeFiles/Trackers.dir/src/Ball2DTracker.cpp.o: ../src/Ball2DTracker.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/tgd/Code/nurobotics_ws/lacrosse-bot/bin/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Trackers.dir/src/Ball2DTracker.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Trackers.dir/src/Ball2DTracker.cpp.o -c /home/tgd/Code/nurobotics_ws/lacrosse-bot/src/Ball2DTracker.cpp

CMakeFiles/Trackers.dir/src/Ball2DTracker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Trackers.dir/src/Ball2DTracker.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/tgd/Code/nurobotics_ws/lacrosse-bot/src/Ball2DTracker.cpp > CMakeFiles/Trackers.dir/src/Ball2DTracker.cpp.i

CMakeFiles/Trackers.dir/src/Ball2DTracker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Trackers.dir/src/Ball2DTracker.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/tgd/Code/nurobotics_ws/lacrosse-bot/src/Ball2DTracker.cpp -o CMakeFiles/Trackers.dir/src/Ball2DTracker.cpp.s

CMakeFiles/Trackers.dir/src/Ball2DTracker.cpp.o.requires:
.PHONY : CMakeFiles/Trackers.dir/src/Ball2DTracker.cpp.o.requires

CMakeFiles/Trackers.dir/src/Ball2DTracker.cpp.o.provides: CMakeFiles/Trackers.dir/src/Ball2DTracker.cpp.o.requires
	$(MAKE) -f CMakeFiles/Trackers.dir/build.make CMakeFiles/Trackers.dir/src/Ball2DTracker.cpp.o.provides.build
.PHONY : CMakeFiles/Trackers.dir/src/Ball2DTracker.cpp.o.provides

CMakeFiles/Trackers.dir/src/Ball2DTracker.cpp.o.provides.build: CMakeFiles/Trackers.dir/src/Ball2DTracker.cpp.o

# Object files for target Trackers
Trackers_OBJECTS = \
"CMakeFiles/Trackers.dir/src/Tracker.cpp.o" \
"CMakeFiles/Trackers.dir/src/Ball2DTracker.cpp.o"

# External object files for target Trackers
Trackers_EXTERNAL_OBJECTS =

../lib/libTrackers.a: CMakeFiles/Trackers.dir/src/Tracker.cpp.o
../lib/libTrackers.a: CMakeFiles/Trackers.dir/src/Ball2DTracker.cpp.o
../lib/libTrackers.a: CMakeFiles/Trackers.dir/build.make
../lib/libTrackers.a: CMakeFiles/Trackers.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library ../lib/libTrackers.a"
	$(CMAKE_COMMAND) -P CMakeFiles/Trackers.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Trackers.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Trackers.dir/build: ../lib/libTrackers.a
.PHONY : CMakeFiles/Trackers.dir/build

CMakeFiles/Trackers.dir/requires: CMakeFiles/Trackers.dir/src/Tracker.cpp.o.requires
CMakeFiles/Trackers.dir/requires: CMakeFiles/Trackers.dir/src/Ball2DTracker.cpp.o.requires
.PHONY : CMakeFiles/Trackers.dir/requires

CMakeFiles/Trackers.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Trackers.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Trackers.dir/clean

CMakeFiles/Trackers.dir/depend:
	cd /home/tgd/Code/nurobotics_ws/lacrosse-bot/bin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tgd/Code/nurobotics_ws/lacrosse-bot /home/tgd/Code/nurobotics_ws/lacrosse-bot /home/tgd/Code/nurobotics_ws/lacrosse-bot/bin /home/tgd/Code/nurobotics_ws/lacrosse-bot/bin /home/tgd/Code/nurobotics_ws/lacrosse-bot/bin/CMakeFiles/Trackers.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Trackers.dir/depend

