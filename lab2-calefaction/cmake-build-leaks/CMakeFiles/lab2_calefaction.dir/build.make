# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /opt/cmake-3.13.4-Linux-x86_64/bin/cmake

# The command to remove a file.
RM = /opt/cmake-3.13.4-Linux-x86_64/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /tmp/tmp.FNcZJ7oGKp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /tmp/tmp.FNcZJ7oGKp/cmake-build-leaks

# Include any dependencies generated for this target.
include CMakeFiles/lab2_calefaction.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lab2_calefaction.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab2_calefaction.dir/flags.make

CMakeFiles/lab2_calefaction.dir/main.c.o: CMakeFiles/lab2_calefaction.dir/flags.make
CMakeFiles/lab2_calefaction.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.FNcZJ7oGKp/cmake-build-leaks/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/lab2_calefaction.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lab2_calefaction.dir/main.c.o   -c /tmp/tmp.FNcZJ7oGKp/main.c

CMakeFiles/lab2_calefaction.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab2_calefaction.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/tmp.FNcZJ7oGKp/main.c > CMakeFiles/lab2_calefaction.dir/main.c.i

CMakeFiles/lab2_calefaction.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab2_calefaction.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/tmp.FNcZJ7oGKp/main.c -o CMakeFiles/lab2_calefaction.dir/main.c.s

# Object files for target lab2_calefaction
lab2_calefaction_OBJECTS = \
"CMakeFiles/lab2_calefaction.dir/main.c.o"

# External object files for target lab2_calefaction
lab2_calefaction_EXTERNAL_OBJECTS =

lab2_calefaction: CMakeFiles/lab2_calefaction.dir/main.c.o
lab2_calefaction: CMakeFiles/lab2_calefaction.dir/build.make
lab2_calefaction: CMakeFiles/lab2_calefaction.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/tmp/tmp.FNcZJ7oGKp/cmake-build-leaks/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable lab2_calefaction"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab2_calefaction.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab2_calefaction.dir/build: lab2_calefaction

.PHONY : CMakeFiles/lab2_calefaction.dir/build

CMakeFiles/lab2_calefaction.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab2_calefaction.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab2_calefaction.dir/clean

CMakeFiles/lab2_calefaction.dir/depend:
	cd /tmp/tmp.FNcZJ7oGKp/cmake-build-leaks && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /tmp/tmp.FNcZJ7oGKp /tmp/tmp.FNcZJ7oGKp /tmp/tmp.FNcZJ7oGKp/cmake-build-leaks /tmp/tmp.FNcZJ7oGKp/cmake-build-leaks /tmp/tmp.FNcZJ7oGKp/cmake-build-leaks/CMakeFiles/lab2_calefaction.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab2_calefaction.dir/depend

