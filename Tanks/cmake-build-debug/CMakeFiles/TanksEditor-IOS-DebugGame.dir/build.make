# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/rafalmanka/Development/unreal/Tanks/Tanks

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/rafalmanka/Development/unreal/Tanks/Tanks/cmake-build-debug

# Utility rule file for TanksEditor-IOS-DebugGame.

# Include the progress variables for this target.
include CMakeFiles/TanksEditor-IOS-DebugGame.dir/progress.make

CMakeFiles/TanksEditor-IOS-DebugGame:
	cd "/Users/Shared/Epic Games/UE_4.21" && bash "/Users/Shared/Epic Games/UE_4.21/Engine/Build/BatchFiles/Mac/Build.sh" TanksEditor IOS DebugGame -project=/Users/rafalmanka/Development/unreal/Tanks/Tanks/Tanks.uproject -game -progress

TanksEditor-IOS-DebugGame: CMakeFiles/TanksEditor-IOS-DebugGame
TanksEditor-IOS-DebugGame: CMakeFiles/TanksEditor-IOS-DebugGame.dir/build.make

.PHONY : TanksEditor-IOS-DebugGame

# Rule to build all files generated by this target.
CMakeFiles/TanksEditor-IOS-DebugGame.dir/build: TanksEditor-IOS-DebugGame

.PHONY : CMakeFiles/TanksEditor-IOS-DebugGame.dir/build

CMakeFiles/TanksEditor-IOS-DebugGame.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TanksEditor-IOS-DebugGame.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TanksEditor-IOS-DebugGame.dir/clean

CMakeFiles/TanksEditor-IOS-DebugGame.dir/depend:
	cd /Users/rafalmanka/Development/unreal/Tanks/Tanks/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/rafalmanka/Development/unreal/Tanks/Tanks /Users/rafalmanka/Development/unreal/Tanks/Tanks /Users/rafalmanka/Development/unreal/Tanks/Tanks/cmake-build-debug /Users/rafalmanka/Development/unreal/Tanks/Tanks/cmake-build-debug /Users/rafalmanka/Development/unreal/Tanks/Tanks/cmake-build-debug/CMakeFiles/TanksEditor-IOS-DebugGame.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TanksEditor-IOS-DebugGame.dir/depend
