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
CMAKE_COMMAND = /snap/clion/98/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/98/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/vikrambhatt/CLionProjects/SimulatedAnnealing

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vikrambhatt/CLionProjects/SimulatedAnnealing/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SimulatedAnnealing.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SimulatedAnnealing.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SimulatedAnnealing.dir/flags.make

CMakeFiles/SimulatedAnnealing.dir/main.cpp.o: CMakeFiles/SimulatedAnnealing.dir/flags.make
CMakeFiles/SimulatedAnnealing.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vikrambhatt/CLionProjects/SimulatedAnnealing/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SimulatedAnnealing.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SimulatedAnnealing.dir/main.cpp.o -c /home/vikrambhatt/CLionProjects/SimulatedAnnealing/main.cpp

CMakeFiles/SimulatedAnnealing.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SimulatedAnnealing.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vikrambhatt/CLionProjects/SimulatedAnnealing/main.cpp > CMakeFiles/SimulatedAnnealing.dir/main.cpp.i

CMakeFiles/SimulatedAnnealing.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SimulatedAnnealing.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vikrambhatt/CLionProjects/SimulatedAnnealing/main.cpp -o CMakeFiles/SimulatedAnnealing.dir/main.cpp.s

CMakeFiles/SimulatedAnnealing.dir/objective_function.cpp.o: CMakeFiles/SimulatedAnnealing.dir/flags.make
CMakeFiles/SimulatedAnnealing.dir/objective_function.cpp.o: ../objective_function.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vikrambhatt/CLionProjects/SimulatedAnnealing/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SimulatedAnnealing.dir/objective_function.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SimulatedAnnealing.dir/objective_function.cpp.o -c /home/vikrambhatt/CLionProjects/SimulatedAnnealing/objective_function.cpp

CMakeFiles/SimulatedAnnealing.dir/objective_function.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SimulatedAnnealing.dir/objective_function.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vikrambhatt/CLionProjects/SimulatedAnnealing/objective_function.cpp > CMakeFiles/SimulatedAnnealing.dir/objective_function.cpp.i

CMakeFiles/SimulatedAnnealing.dir/objective_function.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SimulatedAnnealing.dir/objective_function.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vikrambhatt/CLionProjects/SimulatedAnnealing/objective_function.cpp -o CMakeFiles/SimulatedAnnealing.dir/objective_function.cpp.s

# Object files for target SimulatedAnnealing
SimulatedAnnealing_OBJECTS = \
"CMakeFiles/SimulatedAnnealing.dir/main.cpp.o" \
"CMakeFiles/SimulatedAnnealing.dir/objective_function.cpp.o"

# External object files for target SimulatedAnnealing
SimulatedAnnealing_EXTERNAL_OBJECTS =

SimulatedAnnealing: CMakeFiles/SimulatedAnnealing.dir/main.cpp.o
SimulatedAnnealing: CMakeFiles/SimulatedAnnealing.dir/objective_function.cpp.o
SimulatedAnnealing: CMakeFiles/SimulatedAnnealing.dir/build.make
SimulatedAnnealing: CMakeFiles/SimulatedAnnealing.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vikrambhatt/CLionProjects/SimulatedAnnealing/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable SimulatedAnnealing"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SimulatedAnnealing.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SimulatedAnnealing.dir/build: SimulatedAnnealing

.PHONY : CMakeFiles/SimulatedAnnealing.dir/build

CMakeFiles/SimulatedAnnealing.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SimulatedAnnealing.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SimulatedAnnealing.dir/clean

CMakeFiles/SimulatedAnnealing.dir/depend:
	cd /home/vikrambhatt/CLionProjects/SimulatedAnnealing/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vikrambhatt/CLionProjects/SimulatedAnnealing /home/vikrambhatt/CLionProjects/SimulatedAnnealing /home/vikrambhatt/CLionProjects/SimulatedAnnealing/cmake-build-debug /home/vikrambhatt/CLionProjects/SimulatedAnnealing/cmake-build-debug /home/vikrambhatt/CLionProjects/SimulatedAnnealing/cmake-build-debug/CMakeFiles/SimulatedAnnealing.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SimulatedAnnealing.dir/depend

