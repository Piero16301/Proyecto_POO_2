# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /opt/clion-2019.1.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2019.1.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/piero/Documents/Proyecto_POO_2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/piero/Documents/Proyecto_POO_2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Proyecto_POO_2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Proyecto_POO_2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Proyecto_POO_2.dir/flags.make

CMakeFiles/Proyecto_POO_2.dir/main.cpp.o: CMakeFiles/Proyecto_POO_2.dir/flags.make
CMakeFiles/Proyecto_POO_2.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/piero/Documents/Proyecto_POO_2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Proyecto_POO_2.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Proyecto_POO_2.dir/main.cpp.o -c /home/piero/Documents/Proyecto_POO_2/main.cpp

CMakeFiles/Proyecto_POO_2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Proyecto_POO_2.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/piero/Documents/Proyecto_POO_2/main.cpp > CMakeFiles/Proyecto_POO_2.dir/main.cpp.i

CMakeFiles/Proyecto_POO_2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Proyecto_POO_2.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/piero/Documents/Proyecto_POO_2/main.cpp -o CMakeFiles/Proyecto_POO_2.dir/main.cpp.s

CMakeFiles/Proyecto_POO_2.dir/Juego.cpp.o: CMakeFiles/Proyecto_POO_2.dir/flags.make
CMakeFiles/Proyecto_POO_2.dir/Juego.cpp.o: ../Juego.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/piero/Documents/Proyecto_POO_2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Proyecto_POO_2.dir/Juego.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Proyecto_POO_2.dir/Juego.cpp.o -c /home/piero/Documents/Proyecto_POO_2/Juego.cpp

CMakeFiles/Proyecto_POO_2.dir/Juego.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Proyecto_POO_2.dir/Juego.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/piero/Documents/Proyecto_POO_2/Juego.cpp > CMakeFiles/Proyecto_POO_2.dir/Juego.cpp.i

CMakeFiles/Proyecto_POO_2.dir/Juego.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Proyecto_POO_2.dir/Juego.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/piero/Documents/Proyecto_POO_2/Juego.cpp -o CMakeFiles/Proyecto_POO_2.dir/Juego.cpp.s

CMakeFiles/Proyecto_POO_2.dir/Partida.cpp.o: CMakeFiles/Proyecto_POO_2.dir/flags.make
CMakeFiles/Proyecto_POO_2.dir/Partida.cpp.o: ../Partida.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/piero/Documents/Proyecto_POO_2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Proyecto_POO_2.dir/Partida.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Proyecto_POO_2.dir/Partida.cpp.o -c /home/piero/Documents/Proyecto_POO_2/Partida.cpp

CMakeFiles/Proyecto_POO_2.dir/Partida.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Proyecto_POO_2.dir/Partida.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/piero/Documents/Proyecto_POO_2/Partida.cpp > CMakeFiles/Proyecto_POO_2.dir/Partida.cpp.i

CMakeFiles/Proyecto_POO_2.dir/Partida.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Proyecto_POO_2.dir/Partida.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/piero/Documents/Proyecto_POO_2/Partida.cpp -o CMakeFiles/Proyecto_POO_2.dir/Partida.cpp.s

CMakeFiles/Proyecto_POO_2.dir/Ranking.cpp.o: CMakeFiles/Proyecto_POO_2.dir/flags.make
CMakeFiles/Proyecto_POO_2.dir/Ranking.cpp.o: ../Ranking.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/piero/Documents/Proyecto_POO_2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Proyecto_POO_2.dir/Ranking.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Proyecto_POO_2.dir/Ranking.cpp.o -c /home/piero/Documents/Proyecto_POO_2/Ranking.cpp

CMakeFiles/Proyecto_POO_2.dir/Ranking.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Proyecto_POO_2.dir/Ranking.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/piero/Documents/Proyecto_POO_2/Ranking.cpp > CMakeFiles/Proyecto_POO_2.dir/Ranking.cpp.i

CMakeFiles/Proyecto_POO_2.dir/Ranking.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Proyecto_POO_2.dir/Ranking.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/piero/Documents/Proyecto_POO_2/Ranking.cpp -o CMakeFiles/Proyecto_POO_2.dir/Ranking.cpp.s

# Object files for target Proyecto_POO_2
Proyecto_POO_2_OBJECTS = \
"CMakeFiles/Proyecto_POO_2.dir/main.cpp.o" \
"CMakeFiles/Proyecto_POO_2.dir/Juego.cpp.o" \
"CMakeFiles/Proyecto_POO_2.dir/Partida.cpp.o" \
"CMakeFiles/Proyecto_POO_2.dir/Ranking.cpp.o"

# External object files for target Proyecto_POO_2
Proyecto_POO_2_EXTERNAL_OBJECTS =

Proyecto_POO_2: CMakeFiles/Proyecto_POO_2.dir/main.cpp.o
Proyecto_POO_2: CMakeFiles/Proyecto_POO_2.dir/Juego.cpp.o
Proyecto_POO_2: CMakeFiles/Proyecto_POO_2.dir/Partida.cpp.o
Proyecto_POO_2: CMakeFiles/Proyecto_POO_2.dir/Ranking.cpp.o
Proyecto_POO_2: CMakeFiles/Proyecto_POO_2.dir/build.make
Proyecto_POO_2: CMakeFiles/Proyecto_POO_2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/piero/Documents/Proyecto_POO_2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable Proyecto_POO_2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Proyecto_POO_2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Proyecto_POO_2.dir/build: Proyecto_POO_2

.PHONY : CMakeFiles/Proyecto_POO_2.dir/build

CMakeFiles/Proyecto_POO_2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Proyecto_POO_2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Proyecto_POO_2.dir/clean

CMakeFiles/Proyecto_POO_2.dir/depend:
	cd /home/piero/Documents/Proyecto_POO_2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/piero/Documents/Proyecto_POO_2 /home/piero/Documents/Proyecto_POO_2 /home/piero/Documents/Proyecto_POO_2/cmake-build-debug /home/piero/Documents/Proyecto_POO_2/cmake-build-debug /home/piero/Documents/Proyecto_POO_2/cmake-build-debug/CMakeFiles/Proyecto_POO_2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Proyecto_POO_2.dir/depend

