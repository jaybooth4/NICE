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
CMAKE_SOURCE_DIR = /home/jason.b/NICE/waffles/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jason.b/NICE/waffles/src/build

# Include any dependencies generated for this target.
include plot/CMakeFiles/waffles_plot.dir/depend.make

# Include the progress variables for this target.
include plot/CMakeFiles/waffles_plot.dir/progress.make

# Include the compile flags for this target's objects.
include plot/CMakeFiles/waffles_plot.dir/flags.make

plot/CMakeFiles/waffles_plot.dir/main.cpp.o: plot/CMakeFiles/waffles_plot.dir/flags.make
plot/CMakeFiles/waffles_plot.dir/main.cpp.o: ../plot/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jason.b/NICE/waffles/src/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object plot/CMakeFiles/waffles_plot.dir/main.cpp.o"
	cd /home/jason.b/NICE/waffles/src/build/plot && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/waffles_plot.dir/main.cpp.o -c /home/jason.b/NICE/waffles/src/plot/main.cpp

plot/CMakeFiles/waffles_plot.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/waffles_plot.dir/main.cpp.i"
	cd /home/jason.b/NICE/waffles/src/build/plot && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/jason.b/NICE/waffles/src/plot/main.cpp > CMakeFiles/waffles_plot.dir/main.cpp.i

plot/CMakeFiles/waffles_plot.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/waffles_plot.dir/main.cpp.s"
	cd /home/jason.b/NICE/waffles/src/build/plot && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/jason.b/NICE/waffles/src/plot/main.cpp -o CMakeFiles/waffles_plot.dir/main.cpp.s

plot/CMakeFiles/waffles_plot.dir/main.cpp.o.requires:
.PHONY : plot/CMakeFiles/waffles_plot.dir/main.cpp.o.requires

plot/CMakeFiles/waffles_plot.dir/main.cpp.o.provides: plot/CMakeFiles/waffles_plot.dir/main.cpp.o.requires
	$(MAKE) -f plot/CMakeFiles/waffles_plot.dir/build.make plot/CMakeFiles/waffles_plot.dir/main.cpp.o.provides.build
.PHONY : plot/CMakeFiles/waffles_plot.dir/main.cpp.o.provides

plot/CMakeFiles/waffles_plot.dir/main.cpp.o.provides.build: plot/CMakeFiles/waffles_plot.dir/main.cpp.o

# Object files for target waffles_plot
waffles_plot_OBJECTS = \
"CMakeFiles/waffles_plot.dir/main.cpp.o"

# External object files for target waffles_plot
waffles_plot_EXTERNAL_OBJECTS =

../bin/waffles_plot: plot/CMakeFiles/waffles_plot.dir/main.cpp.o
../bin/waffles_plot: plot/CMakeFiles/waffles_plot.dir/build.make
../bin/waffles_plot: ../lib/libGClasses.a
../bin/waffles_plot: plot/CMakeFiles/waffles_plot.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../../bin/waffles_plot"
	cd /home/jason.b/NICE/waffles/src/build/plot && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/waffles_plot.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
plot/CMakeFiles/waffles_plot.dir/build: ../bin/waffles_plot
.PHONY : plot/CMakeFiles/waffles_plot.dir/build

plot/CMakeFiles/waffles_plot.dir/requires: plot/CMakeFiles/waffles_plot.dir/main.cpp.o.requires
.PHONY : plot/CMakeFiles/waffles_plot.dir/requires

plot/CMakeFiles/waffles_plot.dir/clean:
	cd /home/jason.b/NICE/waffles/src/build/plot && $(CMAKE_COMMAND) -P CMakeFiles/waffles_plot.dir/cmake_clean.cmake
.PHONY : plot/CMakeFiles/waffles_plot.dir/clean

plot/CMakeFiles/waffles_plot.dir/depend:
	cd /home/jason.b/NICE/waffles/src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jason.b/NICE/waffles/src /home/jason.b/NICE/waffles/src/plot /home/jason.b/NICE/waffles/src/build /home/jason.b/NICE/waffles/src/build/plot /home/jason.b/NICE/waffles/src/build/plot/CMakeFiles/waffles_plot.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : plot/CMakeFiles/waffles_plot.dir/depend
