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
include sparse/CMakeFiles/waffles_sparse.dir/depend.make

# Include the progress variables for this target.
include sparse/CMakeFiles/waffles_sparse.dir/progress.make

# Include the compile flags for this target's objects.
include sparse/CMakeFiles/waffles_sparse.dir/flags.make

sparse/CMakeFiles/waffles_sparse.dir/main.cpp.o: sparse/CMakeFiles/waffles_sparse.dir/flags.make
sparse/CMakeFiles/waffles_sparse.dir/main.cpp.o: sparse/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jason.b/Desktop/Github/NICE/waffles/src/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object sparse/CMakeFiles/waffles_sparse.dir/main.cpp.o"
	cd /home/jason.b/Desktop/Github/NICE/waffles/src/sparse && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/waffles_sparse.dir/main.cpp.o -c /home/jason.b/Desktop/Github/NICE/waffles/src/sparse/main.cpp

sparse/CMakeFiles/waffles_sparse.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/waffles_sparse.dir/main.cpp.i"
	cd /home/jason.b/Desktop/Github/NICE/waffles/src/sparse && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/jason.b/Desktop/Github/NICE/waffles/src/sparse/main.cpp > CMakeFiles/waffles_sparse.dir/main.cpp.i

sparse/CMakeFiles/waffles_sparse.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/waffles_sparse.dir/main.cpp.s"
	cd /home/jason.b/Desktop/Github/NICE/waffles/src/sparse && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/jason.b/Desktop/Github/NICE/waffles/src/sparse/main.cpp -o CMakeFiles/waffles_sparse.dir/main.cpp.s

sparse/CMakeFiles/waffles_sparse.dir/main.cpp.o.requires:
.PHONY : sparse/CMakeFiles/waffles_sparse.dir/main.cpp.o.requires

sparse/CMakeFiles/waffles_sparse.dir/main.cpp.o.provides: sparse/CMakeFiles/waffles_sparse.dir/main.cpp.o.requires
	$(MAKE) -f sparse/CMakeFiles/waffles_sparse.dir/build.make sparse/CMakeFiles/waffles_sparse.dir/main.cpp.o.provides.build
.PHONY : sparse/CMakeFiles/waffles_sparse.dir/main.cpp.o.provides

sparse/CMakeFiles/waffles_sparse.dir/main.cpp.o.provides.build: sparse/CMakeFiles/waffles_sparse.dir/main.cpp.o

# Object files for target waffles_sparse
waffles_sparse_OBJECTS = \
"CMakeFiles/waffles_sparse.dir/main.cpp.o"

# External object files for target waffles_sparse
waffles_sparse_EXTERNAL_OBJECTS =

/home/jason.b/Desktop/Github/NICE/waffles/bin/waffles_sparse: sparse/CMakeFiles/waffles_sparse.dir/main.cpp.o
/home/jason.b/Desktop/Github/NICE/waffles/bin/waffles_sparse: sparse/CMakeFiles/waffles_sparse.dir/build.make
/home/jason.b/Desktop/Github/NICE/waffles/bin/waffles_sparse: /home/jason.b/Desktop/Github/NICE/waffles/lib/libGClasses.a
/home/jason.b/Desktop/Github/NICE/waffles/bin/waffles_sparse: sparse/CMakeFiles/waffles_sparse.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable /home/jason.b/Desktop/Github/NICE/waffles/bin/waffles_sparse"
	cd /home/jason.b/Desktop/Github/NICE/waffles/src/sparse && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/waffles_sparse.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
sparse/CMakeFiles/waffles_sparse.dir/build: /home/jason.b/Desktop/Github/NICE/waffles/bin/waffles_sparse
.PHONY : sparse/CMakeFiles/waffles_sparse.dir/build

sparse/CMakeFiles/waffles_sparse.dir/requires: sparse/CMakeFiles/waffles_sparse.dir/main.cpp.o.requires
.PHONY : sparse/CMakeFiles/waffles_sparse.dir/requires

sparse/CMakeFiles/waffles_sparse.dir/clean:
	cd /home/jason.b/Desktop/Github/NICE/waffles/src/sparse && $(CMAKE_COMMAND) -P CMakeFiles/waffles_sparse.dir/cmake_clean.cmake
.PHONY : sparse/CMakeFiles/waffles_sparse.dir/clean

sparse/CMakeFiles/waffles_sparse.dir/depend:
	cd /home/jason.b/Desktop/Github/NICE/waffles/src && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jason.b/Desktop/Github/NICE/waffles/src /home/jason.b/Desktop/Github/NICE/waffles/src/sparse /home/jason.b/Desktop/Github/NICE/waffles/src /home/jason.b/Desktop/Github/NICE/waffles/src/sparse /home/jason.b/Desktop/Github/NICE/waffles/src/sparse/CMakeFiles/waffles_sparse.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : sparse/CMakeFiles/waffles_sparse.dir/depend

