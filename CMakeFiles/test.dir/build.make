# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/harry/CS/Ophelia

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/harry/CS/Ophelia

# Include any dependencies generated for this target.
include CMakeFiles/test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test.dir/flags.make

CMakeFiles/test.dir/src/board.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/src/board.cpp.o: src/board.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/harry/CS/Ophelia/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test.dir/src/board.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test.dir/src/board.cpp.o -c /home/harry/CS/Ophelia/src/board.cpp

CMakeFiles/test.dir/src/board.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/src/board.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/harry/CS/Ophelia/src/board.cpp > CMakeFiles/test.dir/src/board.cpp.i

CMakeFiles/test.dir/src/board.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/src/board.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/harry/CS/Ophelia/src/board.cpp -o CMakeFiles/test.dir/src/board.cpp.s

CMakeFiles/test.dir/src/move.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/src/move.cpp.o: src/move.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/harry/CS/Ophelia/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/test.dir/src/move.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test.dir/src/move.cpp.o -c /home/harry/CS/Ophelia/src/move.cpp

CMakeFiles/test.dir/src/move.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/src/move.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/harry/CS/Ophelia/src/move.cpp > CMakeFiles/test.dir/src/move.cpp.i

CMakeFiles/test.dir/src/move.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/src/move.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/harry/CS/Ophelia/src/move.cpp -o CMakeFiles/test.dir/src/move.cpp.s

CMakeFiles/test.dir/src/generator.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/src/generator.cpp.o: src/generator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/harry/CS/Ophelia/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/test.dir/src/generator.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test.dir/src/generator.cpp.o -c /home/harry/CS/Ophelia/src/generator.cpp

CMakeFiles/test.dir/src/generator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/src/generator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/harry/CS/Ophelia/src/generator.cpp > CMakeFiles/test.dir/src/generator.cpp.i

CMakeFiles/test.dir/src/generator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/src/generator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/harry/CS/Ophelia/src/generator.cpp -o CMakeFiles/test.dir/src/generator.cpp.s

CMakeFiles/test.dir/src/global.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/src/global.cpp.o: src/global.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/harry/CS/Ophelia/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/test.dir/src/global.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test.dir/src/global.cpp.o -c /home/harry/CS/Ophelia/src/global.cpp

CMakeFiles/test.dir/src/global.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/src/global.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/harry/CS/Ophelia/src/global.cpp > CMakeFiles/test.dir/src/global.cpp.i

CMakeFiles/test.dir/src/global.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/src/global.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/harry/CS/Ophelia/src/global.cpp -o CMakeFiles/test.dir/src/global.cpp.s

CMakeFiles/test.dir/src/main.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/src/main.cpp.o: src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/harry/CS/Ophelia/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/test.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test.dir/src/main.cpp.o -c /home/harry/CS/Ophelia/src/main.cpp

CMakeFiles/test.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/harry/CS/Ophelia/src/main.cpp > CMakeFiles/test.dir/src/main.cpp.i

CMakeFiles/test.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/harry/CS/Ophelia/src/main.cpp -o CMakeFiles/test.dir/src/main.cpp.s

# Object files for target test
test_OBJECTS = \
"CMakeFiles/test.dir/src/board.cpp.o" \
"CMakeFiles/test.dir/src/move.cpp.o" \
"CMakeFiles/test.dir/src/generator.cpp.o" \
"CMakeFiles/test.dir/src/global.cpp.o" \
"CMakeFiles/test.dir/src/main.cpp.o"

# External object files for target test
test_EXTERNAL_OBJECTS =

test: CMakeFiles/test.dir/src/board.cpp.o
test: CMakeFiles/test.dir/src/move.cpp.o
test: CMakeFiles/test.dir/src/generator.cpp.o
test: CMakeFiles/test.dir/src/global.cpp.o
test: CMakeFiles/test.dir/src/main.cpp.o
test: CMakeFiles/test.dir/build.make
test: CMakeFiles/test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/harry/CS/Ophelia/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test.dir/build: test

.PHONY : CMakeFiles/test.dir/build

CMakeFiles/test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test.dir/clean

CMakeFiles/test.dir/depend:
	cd /home/harry/CS/Ophelia && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/harry/CS/Ophelia /home/harry/CS/Ophelia /home/harry/CS/Ophelia /home/harry/CS/Ophelia /home/harry/CS/Ophelia/CMakeFiles/test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test.dir/depend

