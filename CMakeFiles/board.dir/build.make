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
include CMakeFiles/board.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/board.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/board.dir/flags.make

CMakeFiles/board.dir/src/board.cpp.o: CMakeFiles/board.dir/flags.make
CMakeFiles/board.dir/src/board.cpp.o: src/board.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/harry/CS/Ophelia/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/board.dir/src/board.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/board.dir/src/board.cpp.o -c /home/harry/CS/Ophelia/src/board.cpp

CMakeFiles/board.dir/src/board.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/board.dir/src/board.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/harry/CS/Ophelia/src/board.cpp > CMakeFiles/board.dir/src/board.cpp.i

CMakeFiles/board.dir/src/board.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/board.dir/src/board.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/harry/CS/Ophelia/src/board.cpp -o CMakeFiles/board.dir/src/board.cpp.s

# Object files for target board
board_OBJECTS = \
"CMakeFiles/board.dir/src/board.cpp.o"

# External object files for target board
board_EXTERNAL_OBJECTS =

board: CMakeFiles/board.dir/src/board.cpp.o
board: CMakeFiles/board.dir/build.make
board: CMakeFiles/board.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/harry/CS/Ophelia/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable board"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/board.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/board.dir/build: board

.PHONY : CMakeFiles/board.dir/build

CMakeFiles/board.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/board.dir/cmake_clean.cmake
.PHONY : CMakeFiles/board.dir/clean

CMakeFiles/board.dir/depend:
	cd /home/harry/CS/Ophelia && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/harry/CS/Ophelia /home/harry/CS/Ophelia /home/harry/CS/Ophelia /home/harry/CS/Ophelia /home/harry/CS/Ophelia/CMakeFiles/board.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/board.dir/depend
