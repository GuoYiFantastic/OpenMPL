# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/fantastic_na/OpenMPL/OpenMPL

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fantastic_na/OpenMPL/OpenMPL/build

# Include any dependencies generated for this target.
include thirdparty/Limbo/limbo/thirdparty/Csdp/CMakeFiles/theta.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include thirdparty/Limbo/limbo/thirdparty/Csdp/CMakeFiles/theta.dir/compiler_depend.make

# Include the progress variables for this target.
include thirdparty/Limbo/limbo/thirdparty/Csdp/CMakeFiles/theta.dir/progress.make

# Include the compile flags for this target's objects.
include thirdparty/Limbo/limbo/thirdparty/Csdp/CMakeFiles/theta.dir/flags.make

thirdparty/Limbo/limbo/thirdparty/Csdp/CMakeFiles/theta.dir/theta/theta.c.o: thirdparty/Limbo/limbo/thirdparty/Csdp/CMakeFiles/theta.dir/flags.make
thirdparty/Limbo/limbo/thirdparty/Csdp/CMakeFiles/theta.dir/theta/theta.c.o: ../thirdparty/Limbo/limbo/thirdparty/Csdp/theta/theta.c
thirdparty/Limbo/limbo/thirdparty/Csdp/CMakeFiles/theta.dir/theta/theta.c.o: thirdparty/Limbo/limbo/thirdparty/Csdp/CMakeFiles/theta.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fantastic_na/OpenMPL/OpenMPL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object thirdparty/Limbo/limbo/thirdparty/Csdp/CMakeFiles/theta.dir/theta/theta.c.o"
	cd /home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/Csdp && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT thirdparty/Limbo/limbo/thirdparty/Csdp/CMakeFiles/theta.dir/theta/theta.c.o -MF CMakeFiles/theta.dir/theta/theta.c.o.d -o CMakeFiles/theta.dir/theta/theta.c.o -c /home/fantastic_na/OpenMPL/OpenMPL/thirdparty/Limbo/limbo/thirdparty/Csdp/theta/theta.c

thirdparty/Limbo/limbo/thirdparty/Csdp/CMakeFiles/theta.dir/theta/theta.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/theta.dir/theta/theta.c.i"
	cd /home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/Csdp && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/fantastic_na/OpenMPL/OpenMPL/thirdparty/Limbo/limbo/thirdparty/Csdp/theta/theta.c > CMakeFiles/theta.dir/theta/theta.c.i

thirdparty/Limbo/limbo/thirdparty/Csdp/CMakeFiles/theta.dir/theta/theta.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/theta.dir/theta/theta.c.s"
	cd /home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/Csdp && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/fantastic_na/OpenMPL/OpenMPL/thirdparty/Limbo/limbo/thirdparty/Csdp/theta/theta.c -o CMakeFiles/theta.dir/theta/theta.c.s

# Object files for target theta
theta_OBJECTS = \
"CMakeFiles/theta.dir/theta/theta.c.o"

# External object files for target theta
theta_EXTERNAL_OBJECTS =

thirdparty/Limbo/limbo/thirdparty/Csdp/bin/theta: thirdparty/Limbo/limbo/thirdparty/Csdp/CMakeFiles/theta.dir/theta/theta.c.o
thirdparty/Limbo/limbo/thirdparty/Csdp/bin/theta: thirdparty/Limbo/limbo/thirdparty/Csdp/CMakeFiles/theta.dir/build.make
thirdparty/Limbo/limbo/thirdparty/Csdp/bin/theta: thirdparty/Limbo/limbo/thirdparty/Csdp/libsdp.a
thirdparty/Limbo/limbo/thirdparty/Csdp/bin/theta: thirdparty/Limbo/limbo/thirdparty/OpenBLAS/libopenblas-st.a
thirdparty/Limbo/limbo/thirdparty/Csdp/bin/theta: thirdparty/Limbo/limbo/thirdparty/Csdp/CMakeFiles/theta.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fantastic_na/OpenMPL/OpenMPL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable bin/theta"
	cd /home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/Csdp && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/theta.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
thirdparty/Limbo/limbo/thirdparty/Csdp/CMakeFiles/theta.dir/build: thirdparty/Limbo/limbo/thirdparty/Csdp/bin/theta
.PHONY : thirdparty/Limbo/limbo/thirdparty/Csdp/CMakeFiles/theta.dir/build

thirdparty/Limbo/limbo/thirdparty/Csdp/CMakeFiles/theta.dir/clean:
	cd /home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/Csdp && $(CMAKE_COMMAND) -P CMakeFiles/theta.dir/cmake_clean.cmake
.PHONY : thirdparty/Limbo/limbo/thirdparty/Csdp/CMakeFiles/theta.dir/clean

thirdparty/Limbo/limbo/thirdparty/Csdp/CMakeFiles/theta.dir/depend:
	cd /home/fantastic_na/OpenMPL/OpenMPL/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fantastic_na/OpenMPL/OpenMPL /home/fantastic_na/OpenMPL/OpenMPL/thirdparty/Limbo/limbo/thirdparty/Csdp /home/fantastic_na/OpenMPL/OpenMPL/build /home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/Csdp /home/fantastic_na/OpenMPL/OpenMPL/build/thirdparty/Limbo/limbo/thirdparty/Csdp/CMakeFiles/theta.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : thirdparty/Limbo/limbo/thirdparty/Csdp/CMakeFiles/theta.dir/depend

