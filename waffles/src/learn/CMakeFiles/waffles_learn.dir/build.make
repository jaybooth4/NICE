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
include learn/CMakeFiles/waffles_learn.dir/depend.make

# Include the progress variables for this target.
include learn/CMakeFiles/waffles_learn.dir/progress.make

# Include the compile flags for this target's objects.
include learn/CMakeFiles/waffles_learn.dir/flags.make

learn/CMakeFiles/waffles_learn.dir/main.cpp.o: learn/CMakeFiles/waffles_learn.dir/flags.make
learn/CMakeFiles/waffles_learn.dir/main.cpp.o: learn/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jason.b/Desktop/Github/NICE/waffles/src/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object learn/CMakeFiles/waffles_learn.dir/main.cpp.o"
	cd /home/jason.b/Desktop/Github/NICE/waffles/src/learn && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/waffles_learn.dir/main.cpp.o -c /home/jason.b/Desktop/Github/NICE/waffles/src/learn/main.cpp

learn/CMakeFiles/waffles_learn.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/waffles_learn.dir/main.cpp.i"
	cd /home/jason.b/Desktop/Github/NICE/waffles/src/learn && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/jason.b/Desktop/Github/NICE/waffles/src/learn/main.cpp > CMakeFiles/waffles_learn.dir/main.cpp.i

learn/CMakeFiles/waffles_learn.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/waffles_learn.dir/main.cpp.s"
	cd /home/jason.b/Desktop/Github/NICE/waffles/src/learn && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/jason.b/Desktop/Github/NICE/waffles/src/learn/main.cpp -o CMakeFiles/waffles_learn.dir/main.cpp.s

learn/CMakeFiles/waffles_learn.dir/main.cpp.o.requires:
.PHONY : learn/CMakeFiles/waffles_learn.dir/main.cpp.o.requires

learn/CMakeFiles/waffles_learn.dir/main.cpp.o.provides: learn/CMakeFiles/waffles_learn.dir/main.cpp.o.requires
	$(MAKE) -f learn/CMakeFiles/waffles_learn.dir/build.make learn/CMakeFiles/waffles_learn.dir/main.cpp.o.provides.build
.PHONY : learn/CMakeFiles/waffles_learn.dir/main.cpp.o.provides

learn/CMakeFiles/waffles_learn.dir/main.cpp.o.provides.build: learn/CMakeFiles/waffles_learn.dir/main.cpp.o

# Object files for target waffles_learn
waffles_learn_OBJECTS = \
"CMakeFiles/waffles_learn.dir/main.cpp.o"

# External object files for target waffles_learn
waffles_learn_EXTERNAL_OBJECTS =

/home/jason.b/Desktop/Github/NICE/waffles/bin/waffles_learn: learn/CMakeFiles/waffles_learn.dir/main.cpp.o
/home/jason.b/Desktop/Github/NICE/waffles/bin/waffles_learn: learn/CMakeFiles/waffles_learn.dir/build.make
/home/jason.b/Desktop/Github/NICE/waffles/bin/waffles_learn: /home/jason.b/Desktop/Github/NICE/waffles/lib/libGClasses.a
/home/jason.b/Desktop/Github/NICE/waffles/bin/waffles_learn: learn/CMakeFiles/waffles_learn.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable /home/jason.b/Desktop/Github/NICE/waffles/bin/waffles_learn"
	cd /home/jason.b/Desktop/Github/NICE/waffles/src/learn && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/waffles_learn.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
learn/CMakeFiles/waffles_learn.dir/build: /home/jason.b/Desktop/Github/NICE/waffles/bin/waffles_learn
.PHONY : learn/CMakeFiles/waffles_learn.dir/build

learn/CMakeFiles/waffles_learn.dir/requires: learn/CMakeFiles/waffles_learn.dir/main.cpp.o.requires
.PHONY : learn/CMakeFiles/waffles_learn.dir/requires

learn/CMakeFiles/waffles_learn.dir/clean:
	cd /home/jason.b/Desktop/Github/NICE/waffles/src/learn && $(CMAKE_COMMAND) -P CMakeFiles/waffles_learn.dir/cmake_clean.cmake
.PHONY : learn/CMakeFiles/waffles_learn.dir/clean

learn/CMakeFiles/waffles_learn.dir/depend:
	cd /home/jason.b/Desktop/Github/NICE/waffles/src && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jason.b/Desktop/Github/NICE/waffles/src /home/jason.b/Desktop/Github/NICE/waffles/src/learn /home/jason.b/Desktop/Github/NICE/waffles/src /home/jason.b/Desktop/Github/NICE/waffles/src/learn /home/jason.b/Desktop/Github/NICE/waffles/src/learn/CMakeFiles/waffles_learn.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : learn/CMakeFiles/waffles_learn.dir/depend

