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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jason.b/Desktop/Github/NICE/shogun-4.1.0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake

# Include any dependencies generated for this target.
include examples/undocumented/libshogun/CMakeFiles/classifier_minimal_svm.dir/depend.make

# Include the progress variables for this target.
include examples/undocumented/libshogun/CMakeFiles/classifier_minimal_svm.dir/progress.make

# Include the compile flags for this target's objects.
include examples/undocumented/libshogun/CMakeFiles/classifier_minimal_svm.dir/flags.make

examples/undocumented/libshogun/CMakeFiles/classifier_minimal_svm.dir/classifier_minimal_svm.cpp.o: examples/undocumented/libshogun/CMakeFiles/classifier_minimal_svm.dir/flags.make
examples/undocumented/libshogun/CMakeFiles/classifier_minimal_svm.dir/classifier_minimal_svm.cpp.o: ../examples/undocumented/libshogun/classifier_minimal_svm.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object examples/undocumented/libshogun/CMakeFiles/classifier_minimal_svm.dir/classifier_minimal_svm.cpp.o"
	cd /home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/classifier_minimal_svm.dir/classifier_minimal_svm.cpp.o -c /home/jason.b/Desktop/Github/NICE/shogun-4.1.0/examples/undocumented/libshogun/classifier_minimal_svm.cpp

examples/undocumented/libshogun/CMakeFiles/classifier_minimal_svm.dir/classifier_minimal_svm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/classifier_minimal_svm.dir/classifier_minimal_svm.cpp.i"
	cd /home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/jason.b/Desktop/Github/NICE/shogun-4.1.0/examples/undocumented/libshogun/classifier_minimal_svm.cpp > CMakeFiles/classifier_minimal_svm.dir/classifier_minimal_svm.cpp.i

examples/undocumented/libshogun/CMakeFiles/classifier_minimal_svm.dir/classifier_minimal_svm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/classifier_minimal_svm.dir/classifier_minimal_svm.cpp.s"
	cd /home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/jason.b/Desktop/Github/NICE/shogun-4.1.0/examples/undocumented/libshogun/classifier_minimal_svm.cpp -o CMakeFiles/classifier_minimal_svm.dir/classifier_minimal_svm.cpp.s

examples/undocumented/libshogun/CMakeFiles/classifier_minimal_svm.dir/classifier_minimal_svm.cpp.o.requires:
.PHONY : examples/undocumented/libshogun/CMakeFiles/classifier_minimal_svm.dir/classifier_minimal_svm.cpp.o.requires

examples/undocumented/libshogun/CMakeFiles/classifier_minimal_svm.dir/classifier_minimal_svm.cpp.o.provides: examples/undocumented/libshogun/CMakeFiles/classifier_minimal_svm.dir/classifier_minimal_svm.cpp.o.requires
	$(MAKE) -f examples/undocumented/libshogun/CMakeFiles/classifier_minimal_svm.dir/build.make examples/undocumented/libshogun/CMakeFiles/classifier_minimal_svm.dir/classifier_minimal_svm.cpp.o.provides.build
.PHONY : examples/undocumented/libshogun/CMakeFiles/classifier_minimal_svm.dir/classifier_minimal_svm.cpp.o.provides

examples/undocumented/libshogun/CMakeFiles/classifier_minimal_svm.dir/classifier_minimal_svm.cpp.o.provides.build: examples/undocumented/libshogun/CMakeFiles/classifier_minimal_svm.dir/classifier_minimal_svm.cpp.o

# Object files for target classifier_minimal_svm
classifier_minimal_svm_OBJECTS = \
"CMakeFiles/classifier_minimal_svm.dir/classifier_minimal_svm.cpp.o"

# External object files for target classifier_minimal_svm
classifier_minimal_svm_EXTERNAL_OBJECTS =

examples/undocumented/libshogun/classifier_minimal_svm: examples/undocumented/libshogun/CMakeFiles/classifier_minimal_svm.dir/classifier_minimal_svm.cpp.o
examples/undocumented/libshogun/classifier_minimal_svm: examples/undocumented/libshogun/CMakeFiles/classifier_minimal_svm.dir/build.make
examples/undocumented/libshogun/classifier_minimal_svm: src/shogun/libshogun.so.17.1
examples/undocumented/libshogun/classifier_minimal_svm: /usr/lib/liblapack.so
examples/undocumented/libshogun/classifier_minimal_svm: /usr/lib/libf77blas.so.3gf
examples/undocumented/libshogun/classifier_minimal_svm: /usr/lib/libatlas.so.3gf
examples/undocumented/libshogun/classifier_minimal_svm: /usr/lib/libcblas.so.3
examples/undocumented/libshogun/classifier_minimal_svm: /usr/lib/libarpack.so
examples/undocumented/libshogun/classifier_minimal_svm: /usr/lib/x86_64-linux-gnu/libxml2.so
examples/undocumented/libshogun/classifier_minimal_svm: /usr/lib/x86_64-linux-gnu/libz.so
examples/undocumented/libshogun/classifier_minimal_svm: /usr/lib/libsnappy.so
examples/undocumented/libshogun/classifier_minimal_svm: examples/undocumented/libshogun/CMakeFiles/classifier_minimal_svm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable classifier_minimal_svm"
	cd /home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/classifier_minimal_svm.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/undocumented/libshogun/CMakeFiles/classifier_minimal_svm.dir/build: examples/undocumented/libshogun/classifier_minimal_svm
.PHONY : examples/undocumented/libshogun/CMakeFiles/classifier_minimal_svm.dir/build

examples/undocumented/libshogun/CMakeFiles/classifier_minimal_svm.dir/requires: examples/undocumented/libshogun/CMakeFiles/classifier_minimal_svm.dir/classifier_minimal_svm.cpp.o.requires
.PHONY : examples/undocumented/libshogun/CMakeFiles/classifier_minimal_svm.dir/requires

examples/undocumented/libshogun/CMakeFiles/classifier_minimal_svm.dir/clean:
	cd /home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun && $(CMAKE_COMMAND) -P CMakeFiles/classifier_minimal_svm.dir/cmake_clean.cmake
.PHONY : examples/undocumented/libshogun/CMakeFiles/classifier_minimal_svm.dir/clean

examples/undocumented/libshogun/CMakeFiles/classifier_minimal_svm.dir/depend:
	cd /home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jason.b/Desktop/Github/NICE/shogun-4.1.0 /home/jason.b/Desktop/Github/NICE/shogun-4.1.0/examples/undocumented/libshogun /home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake /home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun /home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/CMakeFiles/classifier_minimal_svm.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/undocumented/libshogun/CMakeFiles/classifier_minimal_svm.dir/depend

