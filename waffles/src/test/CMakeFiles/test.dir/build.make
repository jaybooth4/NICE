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

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jason.b/Desktop/Github/NICE/waffles/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jason.b/Desktop/Github/NICE/waffles/src

# Include any dependencies generated for this target.
include test/CMakeFiles/test.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/test.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/test.dir/flags.make

test/CMakeFiles/test.dir/main.cpp.o: test/CMakeFiles/test.dir/flags.make
test/CMakeFiles/test.dir/main.cpp.o: test/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jason.b/Desktop/Github/NICE/waffles/src/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object test/CMakeFiles/test.dir/main.cpp.o"
	cd /home/jason.b/Desktop/Github/NICE/waffles/src/test && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/test.dir/main.cpp.o -c /home/jason.b/Desktop/Github/NICE/waffles/src/test/main.cpp

test/CMakeFiles/test.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/main.cpp.i"
	cd /home/jason.b/Desktop/Github/NICE/waffles/src/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/jason.b/Desktop/Github/NICE/waffles/src/test/main.cpp > CMakeFiles/test.dir/main.cpp.i

test/CMakeFiles/test.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/main.cpp.s"
	cd /home/jason.b/Desktop/Github/NICE/waffles/src/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/jason.b/Desktop/Github/NICE/waffles/src/test/main.cpp -o CMakeFiles/test.dir/main.cpp.s

test/CMakeFiles/test.dir/main.cpp.o.requires:
.PHONY : test/CMakeFiles/test.dir/main.cpp.o.requires

test/CMakeFiles/test.dir/main.cpp.o.provides: test/CMakeFiles/test.dir/main.cpp.o.requires
	$(MAKE) -f test/CMakeFiles/test.dir/build.make test/CMakeFiles/test.dir/main.cpp.o.provides.build
.PHONY : test/CMakeFiles/test.dir/main.cpp.o.provides

test/CMakeFiles/test.dir/main.cpp.o.provides.build: test/CMakeFiles/test.dir/main.cpp.o

# Object files for target test
test_OBJECTS = \
"CMakeFiles/test.dir/main.cpp.o"

# External object files for target test
test_EXTERNAL_OBJECTS =

/home/jason.b/Desktop/Github/NICE/waffles/bin/test: test/CMakeFiles/test.dir/main.cpp.o
/home/jason.b/Desktop/Github/NICE/waffles/bin/test: test/CMakeFiles/test.dir/build.make
/home/jason.b/Desktop/Github/NICE/waffles/bin/test: /home/jason.b/Desktop/Github/NICE/waffles/lib/libGClasses.a
/home/jason.b/Desktop/Github/NICE/waffles/bin/test: test/CMakeFiles/test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable /home/jason.b/Desktop/Github/NICE/waffles/bin/test"
	cd /home/jason.b/Desktop/Github/NICE/waffles/src/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/test.dir/build: /home/jason.b/Desktop/Github/NICE/waffles/bin/test
.PHONY : test/CMakeFiles/test.dir/build

test/CMakeFiles/test.dir/requires: test/CMakeFiles/test.dir/main.cpp.o.requires
.PHONY : test/CMakeFiles/test.dir/requires

test/CMakeFiles/test.dir/clean:
	cd /home/jason.b/Desktop/Github/NICE/waffles/src/test && $(CMAKE_COMMAND) -P CMakeFiles/test.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/test.dir/clean

test/CMakeFiles/test.dir/depend:
	cd /home/jason.b/Desktop/Github/NICE/waffles/src && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jason.b/Desktop/Github/NICE/waffles/src /home/jason.b/Desktop/Github/NICE/waffles/src/test /home/jason.b/Desktop/Github/NICE/waffles/src /home/jason.b/Desktop/Github/NICE/waffles/src/test /home/jason.b/Desktop/Github/NICE/waffles/src/test/CMakeFiles/test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/test.dir/depend

