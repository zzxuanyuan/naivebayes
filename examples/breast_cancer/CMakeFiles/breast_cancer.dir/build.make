# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /home/zhe/cmake-3.6.2-Linux-x86_64/bin/cmake

# The command to remove a file.
RM = /home/zhe/cmake-3.6.2-Linux-x86_64/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zhe/naivebayes

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zhe/naivebayes

# Include any dependencies generated for this target.
include examples/breast_cancer/CMakeFiles/breast_cancer.dir/depend.make

# Include the progress variables for this target.
include examples/breast_cancer/CMakeFiles/breast_cancer.dir/progress.make

# Include the compile flags for this target's objects.
include examples/breast_cancer/CMakeFiles/breast_cancer.dir/flags.make

examples/breast_cancer/CMakeFiles/breast_cancer.dir/main.cpp.o: examples/breast_cancer/CMakeFiles/breast_cancer.dir/flags.make
examples/breast_cancer/CMakeFiles/breast_cancer.dir/main.cpp.o: examples/breast_cancer/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhe/naivebayes/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/breast_cancer/CMakeFiles/breast_cancer.dir/main.cpp.o"
	cd /home/zhe/naivebayes/examples/breast_cancer && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/breast_cancer.dir/main.cpp.o -c /home/zhe/naivebayes/examples/breast_cancer/main.cpp

examples/breast_cancer/CMakeFiles/breast_cancer.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/breast_cancer.dir/main.cpp.i"
	cd /home/zhe/naivebayes/examples/breast_cancer && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhe/naivebayes/examples/breast_cancer/main.cpp > CMakeFiles/breast_cancer.dir/main.cpp.i

examples/breast_cancer/CMakeFiles/breast_cancer.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/breast_cancer.dir/main.cpp.s"
	cd /home/zhe/naivebayes/examples/breast_cancer && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhe/naivebayes/examples/breast_cancer/main.cpp -o CMakeFiles/breast_cancer.dir/main.cpp.s

examples/breast_cancer/CMakeFiles/breast_cancer.dir/main.cpp.o.requires:

.PHONY : examples/breast_cancer/CMakeFiles/breast_cancer.dir/main.cpp.o.requires

examples/breast_cancer/CMakeFiles/breast_cancer.dir/main.cpp.o.provides: examples/breast_cancer/CMakeFiles/breast_cancer.dir/main.cpp.o.requires
	$(MAKE) -f examples/breast_cancer/CMakeFiles/breast_cancer.dir/build.make examples/breast_cancer/CMakeFiles/breast_cancer.dir/main.cpp.o.provides.build
.PHONY : examples/breast_cancer/CMakeFiles/breast_cancer.dir/main.cpp.o.provides

examples/breast_cancer/CMakeFiles/breast_cancer.dir/main.cpp.o.provides.build: examples/breast_cancer/CMakeFiles/breast_cancer.dir/main.cpp.o


# Object files for target breast_cancer
breast_cancer_OBJECTS = \
"CMakeFiles/breast_cancer.dir/main.cpp.o"

# External object files for target breast_cancer
breast_cancer_EXTERNAL_OBJECTS =

examples/breast_cancer/breast_cancer: examples/breast_cancer/CMakeFiles/breast_cancer.dir/main.cpp.o
examples/breast_cancer/breast_cancer: examples/breast_cancer/CMakeFiles/breast_cancer.dir/build.make
examples/breast_cancer/breast_cancer: naivebayes/libnaivebayes.a
examples/breast_cancer/breast_cancer: tinyxml2/libtinyxml2.a
examples/breast_cancer/breast_cancer: examples/breast_cancer/CMakeFiles/breast_cancer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zhe/naivebayes/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable breast_cancer"
	cd /home/zhe/naivebayes/examples/breast_cancer && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/breast_cancer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/breast_cancer/CMakeFiles/breast_cancer.dir/build: examples/breast_cancer/breast_cancer

.PHONY : examples/breast_cancer/CMakeFiles/breast_cancer.dir/build

examples/breast_cancer/CMakeFiles/breast_cancer.dir/requires: examples/breast_cancer/CMakeFiles/breast_cancer.dir/main.cpp.o.requires

.PHONY : examples/breast_cancer/CMakeFiles/breast_cancer.dir/requires

examples/breast_cancer/CMakeFiles/breast_cancer.dir/clean:
	cd /home/zhe/naivebayes/examples/breast_cancer && $(CMAKE_COMMAND) -P CMakeFiles/breast_cancer.dir/cmake_clean.cmake
.PHONY : examples/breast_cancer/CMakeFiles/breast_cancer.dir/clean

examples/breast_cancer/CMakeFiles/breast_cancer.dir/depend:
	cd /home/zhe/naivebayes && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zhe/naivebayes /home/zhe/naivebayes/examples/breast_cancer /home/zhe/naivebayes /home/zhe/naivebayes/examples/breast_cancer /home/zhe/naivebayes/examples/breast_cancer/CMakeFiles/breast_cancer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/breast_cancer/CMakeFiles/breast_cancer.dir/depend

