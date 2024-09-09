# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/user/Robopro/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/user/Robopro/build

# Include any dependencies generated for this target.
include matrix/CMakeFiles/Matrix.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include matrix/CMakeFiles/Matrix.dir/compiler_depend.make

# Include the progress variables for this target.
include matrix/CMakeFiles/Matrix.dir/progress.make

# Include the compile flags for this target's objects.
include matrix/CMakeFiles/Matrix.dir/flags.make

matrix/CMakeFiles/Matrix.dir/matrix.c.o: matrix/CMakeFiles/Matrix.dir/flags.make
matrix/CMakeFiles/Matrix.dir/matrix.c.o: /home/user/Robopro/src/matrix/matrix.c
matrix/CMakeFiles/Matrix.dir/matrix.c.o: matrix/CMakeFiles/Matrix.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/user/Robopro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object matrix/CMakeFiles/Matrix.dir/matrix.c.o"
	cd /home/user/Robopro/build/matrix && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT matrix/CMakeFiles/Matrix.dir/matrix.c.o -MF CMakeFiles/Matrix.dir/matrix.c.o.d -o CMakeFiles/Matrix.dir/matrix.c.o -c /home/user/Robopro/src/matrix/matrix.c

matrix/CMakeFiles/Matrix.dir/matrix.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Matrix.dir/matrix.c.i"
	cd /home/user/Robopro/build/matrix && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/user/Robopro/src/matrix/matrix.c > CMakeFiles/Matrix.dir/matrix.c.i

matrix/CMakeFiles/Matrix.dir/matrix.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Matrix.dir/matrix.c.s"
	cd /home/user/Robopro/build/matrix && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/user/Robopro/src/matrix/matrix.c -o CMakeFiles/Matrix.dir/matrix.c.s

# Object files for target Matrix
Matrix_OBJECTS = \
"CMakeFiles/Matrix.dir/matrix.c.o"

# External object files for target Matrix
Matrix_EXTERNAL_OBJECTS =

matrix/libMatrix.a: matrix/CMakeFiles/Matrix.dir/matrix.c.o
matrix/libMatrix.a: matrix/CMakeFiles/Matrix.dir/build.make
matrix/libMatrix.a: matrix/CMakeFiles/Matrix.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/user/Robopro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libMatrix.a"
	cd /home/user/Robopro/build/matrix && $(CMAKE_COMMAND) -P CMakeFiles/Matrix.dir/cmake_clean_target.cmake
	cd /home/user/Robopro/build/matrix && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Matrix.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
matrix/CMakeFiles/Matrix.dir/build: matrix/libMatrix.a
.PHONY : matrix/CMakeFiles/Matrix.dir/build

matrix/CMakeFiles/Matrix.dir/clean:
	cd /home/user/Robopro/build/matrix && $(CMAKE_COMMAND) -P CMakeFiles/Matrix.dir/cmake_clean.cmake
.PHONY : matrix/CMakeFiles/Matrix.dir/clean

matrix/CMakeFiles/Matrix.dir/depend:
	cd /home/user/Robopro/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/Robopro/src /home/user/Robopro/src/matrix /home/user/Robopro/build /home/user/Robopro/build/matrix /home/user/Robopro/build/matrix/CMakeFiles/Matrix.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : matrix/CMakeFiles/Matrix.dir/depend

