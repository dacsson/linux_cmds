# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_SOURCE_DIR = /home/artjom/Desktop/Projects/linux_cmds/ls

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/artjom/Desktop/Projects/linux_cmds/ls/cmake-build

# Include any dependencies generated for this target.
include CMakeFiles/test_ls.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/test_ls.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/test_ls.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_ls.dir/flags.make

CMakeFiles/test_ls.dir/test/test_ls.cpp.o: CMakeFiles/test_ls.dir/flags.make
CMakeFiles/test_ls.dir/test/test_ls.cpp.o: /home/artjom/Desktop/Projects/linux_cmds/ls/test/test_ls.cpp
CMakeFiles/test_ls.dir/test/test_ls.cpp.o: CMakeFiles/test_ls.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/artjom/Desktop/Projects/linux_cmds/ls/cmake-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_ls.dir/test/test_ls.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test_ls.dir/test/test_ls.cpp.o -MF CMakeFiles/test_ls.dir/test/test_ls.cpp.o.d -o CMakeFiles/test_ls.dir/test/test_ls.cpp.o -c /home/artjom/Desktop/Projects/linux_cmds/ls/test/test_ls.cpp

CMakeFiles/test_ls.dir/test/test_ls.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_ls.dir/test/test_ls.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/artjom/Desktop/Projects/linux_cmds/ls/test/test_ls.cpp > CMakeFiles/test_ls.dir/test/test_ls.cpp.i

CMakeFiles/test_ls.dir/test/test_ls.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_ls.dir/test/test_ls.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/artjom/Desktop/Projects/linux_cmds/ls/test/test_ls.cpp -o CMakeFiles/test_ls.dir/test/test_ls.cpp.s

CMakeFiles/test_ls.dir/src/ls.c.o: CMakeFiles/test_ls.dir/flags.make
CMakeFiles/test_ls.dir/src/ls.c.o: /home/artjom/Desktop/Projects/linux_cmds/ls/src/ls.c
CMakeFiles/test_ls.dir/src/ls.c.o: CMakeFiles/test_ls.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/artjom/Desktop/Projects/linux_cmds/ls/cmake-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/test_ls.dir/src/ls.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/test_ls.dir/src/ls.c.o -MF CMakeFiles/test_ls.dir/src/ls.c.o.d -o CMakeFiles/test_ls.dir/src/ls.c.o -c /home/artjom/Desktop/Projects/linux_cmds/ls/src/ls.c

CMakeFiles/test_ls.dir/src/ls.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_ls.dir/src/ls.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/artjom/Desktop/Projects/linux_cmds/ls/src/ls.c > CMakeFiles/test_ls.dir/src/ls.c.i

CMakeFiles/test_ls.dir/src/ls.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_ls.dir/src/ls.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/artjom/Desktop/Projects/linux_cmds/ls/src/ls.c -o CMakeFiles/test_ls.dir/src/ls.c.s

# Object files for target test_ls
test_ls_OBJECTS = \
"CMakeFiles/test_ls.dir/test/test_ls.cpp.o" \
"CMakeFiles/test_ls.dir/src/ls.c.o"

# External object files for target test_ls
test_ls_EXTERNAL_OBJECTS =

/home/artjom/Desktop/Projects/linux_cmds/ls/build/test_ls: CMakeFiles/test_ls.dir/test/test_ls.cpp.o
/home/artjom/Desktop/Projects/linux_cmds/ls/build/test_ls: CMakeFiles/test_ls.dir/src/ls.c.o
/home/artjom/Desktop/Projects/linux_cmds/ls/build/test_ls: CMakeFiles/test_ls.dir/build.make
/home/artjom/Desktop/Projects/linux_cmds/ls/build/test_ls: lib/libgtest.a
/home/artjom/Desktop/Projects/linux_cmds/ls/build/test_ls: lib/libgtest_main.a
/home/artjom/Desktop/Projects/linux_cmds/ls/build/test_ls: libsrc.a
/home/artjom/Desktop/Projects/linux_cmds/ls/build/test_ls: lib/libgtest.a
/home/artjom/Desktop/Projects/linux_cmds/ls/build/test_ls: CMakeFiles/test_ls.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/artjom/Desktop/Projects/linux_cmds/ls/cmake-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable /home/artjom/Desktop/Projects/linux_cmds/ls/build/test_ls"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_ls.dir/link.txt --verbose=$(VERBOSE)
	/usr/bin/cmake -D TEST_TARGET=test_ls -D TEST_EXECUTABLE=/home/artjom/Desktop/Projects/linux_cmds/ls/build/test_ls -D TEST_EXECUTOR= -D TEST_WORKING_DIR=/home/artjom/Desktop/Projects/linux_cmds/ls/cmake-build -D TEST_EXTRA_ARGS= -D TEST_PROPERTIES= -D TEST_PREFIX= -D TEST_SUFFIX= -D TEST_FILTER= -D NO_PRETTY_TYPES=FALSE -D NO_PRETTY_VALUES=FALSE -D TEST_LIST=test_ls_TESTS -D CTEST_FILE=/home/artjom/Desktop/Projects/linux_cmds/ls/cmake-build/test_ls[1]_tests.cmake -D TEST_DISCOVERY_TIMEOUT=5 -D TEST_XML_OUTPUT_DIR= -P /usr/share/cmake-3.25/Modules/GoogleTestAddTests.cmake

# Rule to build all files generated by this target.
CMakeFiles/test_ls.dir/build: /home/artjom/Desktop/Projects/linux_cmds/ls/build/test_ls
.PHONY : CMakeFiles/test_ls.dir/build

CMakeFiles/test_ls.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_ls.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_ls.dir/clean

CMakeFiles/test_ls.dir/depend:
	cd /home/artjom/Desktop/Projects/linux_cmds/ls/cmake-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/artjom/Desktop/Projects/linux_cmds/ls /home/artjom/Desktop/Projects/linux_cmds/ls /home/artjom/Desktop/Projects/linux_cmds/ls/cmake-build /home/artjom/Desktop/Projects/linux_cmds/ls/cmake-build /home/artjom/Desktop/Projects/linux_cmds/ls/cmake-build/CMakeFiles/test_ls.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_ls.dir/depend

