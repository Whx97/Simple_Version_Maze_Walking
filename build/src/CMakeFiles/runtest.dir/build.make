# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/wuhongxi/TEST/second_work

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wuhongxi/TEST/second_work/build

# Include any dependencies generated for this target.
include src/CMakeFiles/runtest.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/runtest.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/runtest.dir/flags.make

src/CMakeFiles/runtest.dir/__/test/runtest.cpp.o: src/CMakeFiles/runtest.dir/flags.make
src/CMakeFiles/runtest.dir/__/test/runtest.cpp.o: ../test/runtest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wuhongxi/TEST/second_work/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/runtest.dir/__/test/runtest.cpp.o"
	cd /home/wuhongxi/TEST/second_work/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/runtest.dir/__/test/runtest.cpp.o -c /home/wuhongxi/TEST/second_work/test/runtest.cpp

src/CMakeFiles/runtest.dir/__/test/runtest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runtest.dir/__/test/runtest.cpp.i"
	cd /home/wuhongxi/TEST/second_work/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wuhongxi/TEST/second_work/test/runtest.cpp > CMakeFiles/runtest.dir/__/test/runtest.cpp.i

src/CMakeFiles/runtest.dir/__/test/runtest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runtest.dir/__/test/runtest.cpp.s"
	cd /home/wuhongxi/TEST/second_work/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wuhongxi/TEST/second_work/test/runtest.cpp -o CMakeFiles/runtest.dir/__/test/runtest.cpp.s

# Object files for target runtest
runtest_OBJECTS = \
"CMakeFiles/runtest.dir/__/test/runtest.cpp.o"

# External object files for target runtest
runtest_EXTERNAL_OBJECTS =

../bin/runtest: src/CMakeFiles/runtest.dir/__/test/runtest.cpp.o
../bin/runtest: src/CMakeFiles/runtest.dir/build.make
../bin/runtest: src/libtest2.a
../bin/runtest: src/CMakeFiles/runtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wuhongxi/TEST/second_work/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../bin/runtest"
	cd /home/wuhongxi/TEST/second_work/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/runtest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/runtest.dir/build: ../bin/runtest

.PHONY : src/CMakeFiles/runtest.dir/build

src/CMakeFiles/runtest.dir/clean:
	cd /home/wuhongxi/TEST/second_work/build/src && $(CMAKE_COMMAND) -P CMakeFiles/runtest.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/runtest.dir/clean

src/CMakeFiles/runtest.dir/depend:
	cd /home/wuhongxi/TEST/second_work/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wuhongxi/TEST/second_work /home/wuhongxi/TEST/second_work/src /home/wuhongxi/TEST/second_work/build /home/wuhongxi/TEST/second_work/build/src /home/wuhongxi/TEST/second_work/build/src/CMakeFiles/runtest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/runtest.dir/depend
