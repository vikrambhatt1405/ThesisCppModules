# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /opt/clion-2019.2.5/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2019.2.5/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/vikrambhatt/CLionProjects/ParMetis

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vikrambhatt/CLionProjects/ParMetis

# Utility rule file for test2_run.

# Include the progress variables for this target.
include CMakeFiles/test2_run.dir/progress.make

CMakeFiles/test2_run:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/vikrambhatt/CLionProjects/ParMetis/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "run generated test2 in /home/vikrambhatt/CLionProjects/ParMetis"
	test2

test2_run: CMakeFiles/test2_run
test2_run: CMakeFiles/test2_run.dir/build.make

.PHONY : test2_run

# Rule to build all files generated by this target.
CMakeFiles/test2_run.dir/build: test2_run

.PHONY : CMakeFiles/test2_run.dir/build

CMakeFiles/test2_run.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test2_run.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test2_run.dir/clean

CMakeFiles/test2_run.dir/depend:
	cd /home/vikrambhatt/CLionProjects/ParMetis && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vikrambhatt/CLionProjects/ParMetis /home/vikrambhatt/CLionProjects/ParMetis /home/vikrambhatt/CLionProjects/ParMetis /home/vikrambhatt/CLionProjects/ParMetis /home/vikrambhatt/CLionProjects/ParMetis/CMakeFiles/test2_run.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test2_run.dir/depend

