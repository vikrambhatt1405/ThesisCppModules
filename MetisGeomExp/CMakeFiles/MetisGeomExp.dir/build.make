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
CMAKE_COMMAND = /snap/clion/99/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/99/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/vikrambhatt/CLionProjects/MetisGeomExp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vikrambhatt/CLionProjects/MetisGeomExp

# Include any dependencies generated for this target.
include CMakeFiles/MetisGeomExp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MetisGeomExp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MetisGeomExp.dir/flags.make

CMakeFiles/MetisGeomExp.dir/adjtocsr.cpp.o: CMakeFiles/MetisGeomExp.dir/flags.make
CMakeFiles/MetisGeomExp.dir/adjtocsr.cpp.o: adjtocsr.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vikrambhatt/CLionProjects/MetisGeomExp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MetisGeomExp.dir/adjtocsr.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MetisGeomExp.dir/adjtocsr.cpp.o -c /home/vikrambhatt/CLionProjects/MetisGeomExp/adjtocsr.cpp

CMakeFiles/MetisGeomExp.dir/adjtocsr.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MetisGeomExp.dir/adjtocsr.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vikrambhatt/CLionProjects/MetisGeomExp/adjtocsr.cpp > CMakeFiles/MetisGeomExp.dir/adjtocsr.cpp.i

CMakeFiles/MetisGeomExp.dir/adjtocsr.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MetisGeomExp.dir/adjtocsr.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vikrambhatt/CLionProjects/MetisGeomExp/adjtocsr.cpp -o CMakeFiles/MetisGeomExp.dir/adjtocsr.cpp.s

CMakeFiles/MetisGeomExp.dir/main.cpp.o: CMakeFiles/MetisGeomExp.dir/flags.make
CMakeFiles/MetisGeomExp.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vikrambhatt/CLionProjects/MetisGeomExp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/MetisGeomExp.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MetisGeomExp.dir/main.cpp.o -c /home/vikrambhatt/CLionProjects/MetisGeomExp/main.cpp

CMakeFiles/MetisGeomExp.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MetisGeomExp.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vikrambhatt/CLionProjects/MetisGeomExp/main.cpp > CMakeFiles/MetisGeomExp.dir/main.cpp.i

CMakeFiles/MetisGeomExp.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MetisGeomExp.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vikrambhatt/CLionProjects/MetisGeomExp/main.cpp -o CMakeFiles/MetisGeomExp.dir/main.cpp.s

# Object files for target MetisGeomExp
MetisGeomExp_OBJECTS = \
"CMakeFiles/MetisGeomExp.dir/adjtocsr.cpp.o" \
"CMakeFiles/MetisGeomExp.dir/main.cpp.o"

# External object files for target MetisGeomExp
MetisGeomExp_EXTERNAL_OBJECTS =

MetisGeomExp: CMakeFiles/MetisGeomExp.dir/adjtocsr.cpp.o
MetisGeomExp: CMakeFiles/MetisGeomExp.dir/main.cpp.o
MetisGeomExp: CMakeFiles/MetisGeomExp.dir/build.make
MetisGeomExp: /usr/local/lib/libmpi.so
MetisGeomExp: CMakeFiles/MetisGeomExp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vikrambhatt/CLionProjects/MetisGeomExp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable MetisGeomExp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MetisGeomExp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MetisGeomExp.dir/build: MetisGeomExp

.PHONY : CMakeFiles/MetisGeomExp.dir/build

CMakeFiles/MetisGeomExp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MetisGeomExp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MetisGeomExp.dir/clean

CMakeFiles/MetisGeomExp.dir/depend:
	cd /home/vikrambhatt/CLionProjects/MetisGeomExp && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vikrambhatt/CLionProjects/MetisGeomExp /home/vikrambhatt/CLionProjects/MetisGeomExp /home/vikrambhatt/CLionProjects/MetisGeomExp /home/vikrambhatt/CLionProjects/MetisGeomExp /home/vikrambhatt/CLionProjects/MetisGeomExp/CMakeFiles/MetisGeomExp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MetisGeomExp.dir/depend

