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
CMAKE_SOURCE_DIR = /home/jason.b/Desktop/Tests/Kmeans/dlib-18.18/examples

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jason.b/Desktop/Tests/Kmeans/dlib-18.18/examples/build

# Include any dependencies generated for this target.
include CMakeFiles/train_shape_predictor_ex.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/train_shape_predictor_ex.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/train_shape_predictor_ex.dir/flags.make

CMakeFiles/train_shape_predictor_ex.dir/train_shape_predictor_ex.cpp.o: CMakeFiles/train_shape_predictor_ex.dir/flags.make
CMakeFiles/train_shape_predictor_ex.dir/train_shape_predictor_ex.cpp.o: ../train_shape_predictor_ex.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jason.b/Desktop/Tests/Kmeans/dlib-18.18/examples/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/train_shape_predictor_ex.dir/train_shape_predictor_ex.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/train_shape_predictor_ex.dir/train_shape_predictor_ex.cpp.o -c /home/jason.b/Desktop/Tests/Kmeans/dlib-18.18/examples/train_shape_predictor_ex.cpp

CMakeFiles/train_shape_predictor_ex.dir/train_shape_predictor_ex.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/train_shape_predictor_ex.dir/train_shape_predictor_ex.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/jason.b/Desktop/Tests/Kmeans/dlib-18.18/examples/train_shape_predictor_ex.cpp > CMakeFiles/train_shape_predictor_ex.dir/train_shape_predictor_ex.cpp.i

CMakeFiles/train_shape_predictor_ex.dir/train_shape_predictor_ex.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/train_shape_predictor_ex.dir/train_shape_predictor_ex.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/jason.b/Desktop/Tests/Kmeans/dlib-18.18/examples/train_shape_predictor_ex.cpp -o CMakeFiles/train_shape_predictor_ex.dir/train_shape_predictor_ex.cpp.s

CMakeFiles/train_shape_predictor_ex.dir/train_shape_predictor_ex.cpp.o.requires:
.PHONY : CMakeFiles/train_shape_predictor_ex.dir/train_shape_predictor_ex.cpp.o.requires

CMakeFiles/train_shape_predictor_ex.dir/train_shape_predictor_ex.cpp.o.provides: CMakeFiles/train_shape_predictor_ex.dir/train_shape_predictor_ex.cpp.o.requires
	$(MAKE) -f CMakeFiles/train_shape_predictor_ex.dir/build.make CMakeFiles/train_shape_predictor_ex.dir/train_shape_predictor_ex.cpp.o.provides.build
.PHONY : CMakeFiles/train_shape_predictor_ex.dir/train_shape_predictor_ex.cpp.o.provides

CMakeFiles/train_shape_predictor_ex.dir/train_shape_predictor_ex.cpp.o.provides.build: CMakeFiles/train_shape_predictor_ex.dir/train_shape_predictor_ex.cpp.o

# Object files for target train_shape_predictor_ex
train_shape_predictor_ex_OBJECTS = \
"CMakeFiles/train_shape_predictor_ex.dir/train_shape_predictor_ex.cpp.o"

# External object files for target train_shape_predictor_ex
train_shape_predictor_ex_EXTERNAL_OBJECTS =

train_shape_predictor_ex: CMakeFiles/train_shape_predictor_ex.dir/train_shape_predictor_ex.cpp.o
train_shape_predictor_ex: CMakeFiles/train_shape_predictor_ex.dir/build.make
train_shape_predictor_ex: dlib_build/libdlib.a
train_shape_predictor_ex: /usr/lib/x86_64-linux-gnu/libpthread.so
train_shape_predictor_ex: /usr/lib/x86_64-linux-gnu/libnsl.so
train_shape_predictor_ex: /usr/lib/x86_64-linux-gnu/libSM.so
train_shape_predictor_ex: /usr/lib/x86_64-linux-gnu/libICE.so
train_shape_predictor_ex: /usr/lib/x86_64-linux-gnu/libX11.so
train_shape_predictor_ex: /usr/lib/x86_64-linux-gnu/libXext.so
train_shape_predictor_ex: /usr/lib/x86_64-linux-gnu/libpng.so
train_shape_predictor_ex: CMakeFiles/train_shape_predictor_ex.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable train_shape_predictor_ex"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/train_shape_predictor_ex.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/train_shape_predictor_ex.dir/build: train_shape_predictor_ex
.PHONY : CMakeFiles/train_shape_predictor_ex.dir/build

CMakeFiles/train_shape_predictor_ex.dir/requires: CMakeFiles/train_shape_predictor_ex.dir/train_shape_predictor_ex.cpp.o.requires
.PHONY : CMakeFiles/train_shape_predictor_ex.dir/requires

CMakeFiles/train_shape_predictor_ex.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/train_shape_predictor_ex.dir/cmake_clean.cmake
.PHONY : CMakeFiles/train_shape_predictor_ex.dir/clean

CMakeFiles/train_shape_predictor_ex.dir/depend:
	cd /home/jason.b/Desktop/Tests/Kmeans/dlib-18.18/examples/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jason.b/Desktop/Tests/Kmeans/dlib-18.18/examples /home/jason.b/Desktop/Tests/Kmeans/dlib-18.18/examples /home/jason.b/Desktop/Tests/Kmeans/dlib-18.18/examples/build /home/jason.b/Desktop/Tests/Kmeans/dlib-18.18/examples/build /home/jason.b/Desktop/Tests/Kmeans/dlib-18.18/examples/build/CMakeFiles/train_shape_predictor_ex.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/train_shape_predictor_ex.dir/depend

