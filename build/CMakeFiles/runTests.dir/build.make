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
CMAKE_SOURCE_DIR = /data/technicalTest/build

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /data/technicalTest/build

# Include any dependencies generated for this target.
include CMakeFiles/runTests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/runTests.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/runTests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/runTests.dir/flags.make

CMakeFiles/runTests.dir/data/technicalTest/tests/tests.cpp.o: CMakeFiles/runTests.dir/flags.make
CMakeFiles/runTests.dir/data/technicalTest/tests/tests.cpp.o: /data/technicalTest/tests/tests.cpp
CMakeFiles/runTests.dir/data/technicalTest/tests/tests.cpp.o: CMakeFiles/runTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/technicalTest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/runTests.dir/data/technicalTest/tests/tests.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/runTests.dir/data/technicalTest/tests/tests.cpp.o -MF CMakeFiles/runTests.dir/data/technicalTest/tests/tests.cpp.o.d -o CMakeFiles/runTests.dir/data/technicalTest/tests/tests.cpp.o -c /data/technicalTest/tests/tests.cpp

CMakeFiles/runTests.dir/data/technicalTest/tests/tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runTests.dir/data/technicalTest/tests/tests.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/technicalTest/tests/tests.cpp > CMakeFiles/runTests.dir/data/technicalTest/tests/tests.cpp.i

CMakeFiles/runTests.dir/data/technicalTest/tests/tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runTests.dir/data/technicalTest/tests/tests.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/technicalTest/tests/tests.cpp -o CMakeFiles/runTests.dir/data/technicalTest/tests/tests.cpp.s

CMakeFiles/runTests.dir/data/technicalTest/client/Client.cpp.o: CMakeFiles/runTests.dir/flags.make
CMakeFiles/runTests.dir/data/technicalTest/client/Client.cpp.o: /data/technicalTest/client/Client.cpp
CMakeFiles/runTests.dir/data/technicalTest/client/Client.cpp.o: CMakeFiles/runTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/technicalTest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/runTests.dir/data/technicalTest/client/Client.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/runTests.dir/data/technicalTest/client/Client.cpp.o -MF CMakeFiles/runTests.dir/data/technicalTest/client/Client.cpp.o.d -o CMakeFiles/runTests.dir/data/technicalTest/client/Client.cpp.o -c /data/technicalTest/client/Client.cpp

CMakeFiles/runTests.dir/data/technicalTest/client/Client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runTests.dir/data/technicalTest/client/Client.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/technicalTest/client/Client.cpp > CMakeFiles/runTests.dir/data/technicalTest/client/Client.cpp.i

CMakeFiles/runTests.dir/data/technicalTest/client/Client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runTests.dir/data/technicalTest/client/Client.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/technicalTest/client/Client.cpp -o CMakeFiles/runTests.dir/data/technicalTest/client/Client.cpp.s

CMakeFiles/runTests.dir/data/technicalTest/file/File.cpp.o: CMakeFiles/runTests.dir/flags.make
CMakeFiles/runTests.dir/data/technicalTest/file/File.cpp.o: /data/technicalTest/file/File.cpp
CMakeFiles/runTests.dir/data/technicalTest/file/File.cpp.o: CMakeFiles/runTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/technicalTest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/runTests.dir/data/technicalTest/file/File.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/runTests.dir/data/technicalTest/file/File.cpp.o -MF CMakeFiles/runTests.dir/data/technicalTest/file/File.cpp.o.d -o CMakeFiles/runTests.dir/data/technicalTest/file/File.cpp.o -c /data/technicalTest/file/File.cpp

CMakeFiles/runTests.dir/data/technicalTest/file/File.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runTests.dir/data/technicalTest/file/File.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/technicalTest/file/File.cpp > CMakeFiles/runTests.dir/data/technicalTest/file/File.cpp.i

CMakeFiles/runTests.dir/data/technicalTest/file/File.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runTests.dir/data/technicalTest/file/File.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/technicalTest/file/File.cpp -o CMakeFiles/runTests.dir/data/technicalTest/file/File.cpp.s

# Object files for target runTests
runTests_OBJECTS = \
"CMakeFiles/runTests.dir/data/technicalTest/tests/tests.cpp.o" \
"CMakeFiles/runTests.dir/data/technicalTest/client/Client.cpp.o" \
"CMakeFiles/runTests.dir/data/technicalTest/file/File.cpp.o"

# External object files for target runTests
runTests_EXTERNAL_OBJECTS =

runTests: CMakeFiles/runTests.dir/data/technicalTest/tests/tests.cpp.o
runTests: CMakeFiles/runTests.dir/data/technicalTest/client/Client.cpp.o
runTests: CMakeFiles/runTests.dir/data/technicalTest/file/File.cpp.o
runTests: CMakeFiles/runTests.dir/build.make
runTests: /usr/lib/x86_64-linux-gnu/libgtest.a
runTests: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so.1.74.0
runTests: /usr/lib/x86_64-linux-gnu/libboost_system.so.1.74.0
runTests: CMakeFiles/runTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/data/technicalTest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable runTests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/runTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/runTests.dir/build: runTests
.PHONY : CMakeFiles/runTests.dir/build

CMakeFiles/runTests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/runTests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/runTests.dir/clean

CMakeFiles/runTests.dir/depend:
	cd /data/technicalTest/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /data/technicalTest/build /data/technicalTest/build /data/technicalTest/build /data/technicalTest/build /data/technicalTest/build/CMakeFiles/runTests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/runTests.dir/depend

