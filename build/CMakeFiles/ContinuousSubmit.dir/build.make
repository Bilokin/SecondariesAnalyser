# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
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
CMAKE_COMMAND = /sps/hep/ilc/bilokin/ilcsoft/v01-17-04/CMake/2.8.5/bin/cmake

# The command to remove a file.
RM = /sps/hep/ilc/bilokin/ilcsoft/v01-17-04/CMake/2.8.5/bin/cmake -E remove -f

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /sps/hep/ilc/bilokin/ilcsoft/v01-17-04/CMake/2.8.5/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /sps/hep/ilc/bilokin/Processors/Analysis/SecondariesAnalyser

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /sps/hep/ilc/bilokin/Processors/Analysis/SecondariesAnalyser/build

# Utility rule file for ContinuousSubmit.

CMakeFiles/ContinuousSubmit:
	/sps/hep/ilc/bilokin/ilcsoft/v01-17-04/CMake/2.8.5/bin/ctest -D ContinuousSubmit

ContinuousSubmit: CMakeFiles/ContinuousSubmit
ContinuousSubmit: CMakeFiles/ContinuousSubmit.dir/build.make
.PHONY : ContinuousSubmit

# Rule to build all files generated by this target.
CMakeFiles/ContinuousSubmit.dir/build: ContinuousSubmit
.PHONY : CMakeFiles/ContinuousSubmit.dir/build

CMakeFiles/ContinuousSubmit.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ContinuousSubmit.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ContinuousSubmit.dir/clean

CMakeFiles/ContinuousSubmit.dir/depend:
	cd /sps/hep/ilc/bilokin/Processors/Analysis/SecondariesAnalyser/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /sps/hep/ilc/bilokin/Processors/Analysis/SecondariesAnalyser /sps/hep/ilc/bilokin/Processors/Analysis/SecondariesAnalyser /sps/hep/ilc/bilokin/Processors/Analysis/SecondariesAnalyser/build /sps/hep/ilc/bilokin/Processors/Analysis/SecondariesAnalyser/build /sps/hep/ilc/bilokin/Processors/Analysis/SecondariesAnalyser/build/CMakeFiles/ContinuousSubmit.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ContinuousSubmit.dir/depend

