# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/wen/Dev/GomokuEngine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wen/Dev/GomokuEngine/build

# Include any dependencies generated for this target.
include CMakeFiles/kanazawa.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/kanazawa.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/kanazawa.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/kanazawa.dir/flags.make

CMakeFiles/kanazawa.dir/src/main.cpp.o: CMakeFiles/kanazawa.dir/flags.make
CMakeFiles/kanazawa.dir/src/main.cpp.o: /home/wen/Dev/GomokuEngine/src/main.cpp
CMakeFiles/kanazawa.dir/src/main.cpp.o: CMakeFiles/kanazawa.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/wen/Dev/GomokuEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/kanazawa.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/kanazawa.dir/src/main.cpp.o -MF CMakeFiles/kanazawa.dir/src/main.cpp.o.d -o CMakeFiles/kanazawa.dir/src/main.cpp.o -c /home/wen/Dev/GomokuEngine/src/main.cpp

CMakeFiles/kanazawa.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/kanazawa.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wen/Dev/GomokuEngine/src/main.cpp > CMakeFiles/kanazawa.dir/src/main.cpp.i

CMakeFiles/kanazawa.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/kanazawa.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wen/Dev/GomokuEngine/src/main.cpp -o CMakeFiles/kanazawa.dir/src/main.cpp.s

CMakeFiles/kanazawa.dir/src/human_player.cpp.o: CMakeFiles/kanazawa.dir/flags.make
CMakeFiles/kanazawa.dir/src/human_player.cpp.o: /home/wen/Dev/GomokuEngine/src/human_player.cpp
CMakeFiles/kanazawa.dir/src/human_player.cpp.o: CMakeFiles/kanazawa.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/wen/Dev/GomokuEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/kanazawa.dir/src/human_player.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/kanazawa.dir/src/human_player.cpp.o -MF CMakeFiles/kanazawa.dir/src/human_player.cpp.o.d -o CMakeFiles/kanazawa.dir/src/human_player.cpp.o -c /home/wen/Dev/GomokuEngine/src/human_player.cpp

CMakeFiles/kanazawa.dir/src/human_player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/kanazawa.dir/src/human_player.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wen/Dev/GomokuEngine/src/human_player.cpp > CMakeFiles/kanazawa.dir/src/human_player.cpp.i

CMakeFiles/kanazawa.dir/src/human_player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/kanazawa.dir/src/human_player.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wen/Dev/GomokuEngine/src/human_player.cpp -o CMakeFiles/kanazawa.dir/src/human_player.cpp.s

CMakeFiles/kanazawa.dir/src/game.cpp.o: CMakeFiles/kanazawa.dir/flags.make
CMakeFiles/kanazawa.dir/src/game.cpp.o: /home/wen/Dev/GomokuEngine/src/game.cpp
CMakeFiles/kanazawa.dir/src/game.cpp.o: CMakeFiles/kanazawa.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/wen/Dev/GomokuEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/kanazawa.dir/src/game.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/kanazawa.dir/src/game.cpp.o -MF CMakeFiles/kanazawa.dir/src/game.cpp.o.d -o CMakeFiles/kanazawa.dir/src/game.cpp.o -c /home/wen/Dev/GomokuEngine/src/game.cpp

CMakeFiles/kanazawa.dir/src/game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/kanazawa.dir/src/game.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wen/Dev/GomokuEngine/src/game.cpp > CMakeFiles/kanazawa.dir/src/game.cpp.i

CMakeFiles/kanazawa.dir/src/game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/kanazawa.dir/src/game.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wen/Dev/GomokuEngine/src/game.cpp -o CMakeFiles/kanazawa.dir/src/game.cpp.s

# Object files for target kanazawa
kanazawa_OBJECTS = \
"CMakeFiles/kanazawa.dir/src/main.cpp.o" \
"CMakeFiles/kanazawa.dir/src/human_player.cpp.o" \
"CMakeFiles/kanazawa.dir/src/game.cpp.o"

# External object files for target kanazawa
kanazawa_EXTERNAL_OBJECTS =

kanazawa: CMakeFiles/kanazawa.dir/src/main.cpp.o
kanazawa: CMakeFiles/kanazawa.dir/src/human_player.cpp.o
kanazawa: CMakeFiles/kanazawa.dir/src/game.cpp.o
kanazawa: CMakeFiles/kanazawa.dir/build.make
kanazawa: CMakeFiles/kanazawa.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/wen/Dev/GomokuEngine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable kanazawa"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/kanazawa.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/kanazawa.dir/build: kanazawa
.PHONY : CMakeFiles/kanazawa.dir/build

CMakeFiles/kanazawa.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/kanazawa.dir/cmake_clean.cmake
.PHONY : CMakeFiles/kanazawa.dir/clean

CMakeFiles/kanazawa.dir/depend:
	cd /home/wen/Dev/GomokuEngine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wen/Dev/GomokuEngine /home/wen/Dev/GomokuEngine /home/wen/Dev/GomokuEngine/build /home/wen/Dev/GomokuEngine/build /home/wen/Dev/GomokuEngine/build/CMakeFiles/kanazawa.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/kanazawa.dir/depend

