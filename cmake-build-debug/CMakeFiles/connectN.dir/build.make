# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.7

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files (x86)\JetBrains\CLion 2017.1\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files (x86)\JetBrains\CLion 2017.1\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\mendo\Git\ConnectN

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\mendo\Git\ConnectN\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/connectN.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/connectN.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/connectN.dir/flags.make

CMakeFiles/connectN.dir/main.cpp.obj: CMakeFiles/connectN.dir/flags.make
CMakeFiles/connectN.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\mendo\Git\ConnectN\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/connectN.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\connectN.dir\main.cpp.obj -c C:\Users\mendo\Git\ConnectN\main.cpp

CMakeFiles/connectN.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/connectN.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\mendo\Git\ConnectN\main.cpp > CMakeFiles\connectN.dir\main.cpp.i

CMakeFiles/connectN.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/connectN.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\mendo\Git\ConnectN\main.cpp -o CMakeFiles\connectN.dir\main.cpp.s

CMakeFiles/connectN.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/connectN.dir/main.cpp.obj.requires

CMakeFiles/connectN.dir/main.cpp.obj.provides: CMakeFiles/connectN.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\connectN.dir\build.make CMakeFiles/connectN.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/connectN.dir/main.cpp.obj.provides

CMakeFiles/connectN.dir/main.cpp.obj.provides.build: CMakeFiles/connectN.dir/main.cpp.obj


CMakeFiles/connectN.dir/Game.cpp.obj: CMakeFiles/connectN.dir/flags.make
CMakeFiles/connectN.dir/Game.cpp.obj: ../Game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\mendo\Git\ConnectN\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/connectN.dir/Game.cpp.obj"
	C:\MinGW\bin\g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\connectN.dir\Game.cpp.obj -c C:\Users\mendo\Git\ConnectN\Game.cpp

CMakeFiles/connectN.dir/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/connectN.dir/Game.cpp.i"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\mendo\Git\ConnectN\Game.cpp > CMakeFiles\connectN.dir\Game.cpp.i

CMakeFiles/connectN.dir/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/connectN.dir/Game.cpp.s"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\mendo\Git\ConnectN\Game.cpp -o CMakeFiles\connectN.dir\Game.cpp.s

CMakeFiles/connectN.dir/Game.cpp.obj.requires:

.PHONY : CMakeFiles/connectN.dir/Game.cpp.obj.requires

CMakeFiles/connectN.dir/Game.cpp.obj.provides: CMakeFiles/connectN.dir/Game.cpp.obj.requires
	$(MAKE) -f CMakeFiles\connectN.dir\build.make CMakeFiles/connectN.dir/Game.cpp.obj.provides.build
.PHONY : CMakeFiles/connectN.dir/Game.cpp.obj.provides

CMakeFiles/connectN.dir/Game.cpp.obj.provides.build: CMakeFiles/connectN.dir/Game.cpp.obj


CMakeFiles/connectN.dir/PlayerAI.cpp.obj: CMakeFiles/connectN.dir/flags.make
CMakeFiles/connectN.dir/PlayerAI.cpp.obj: ../PlayerAI.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\mendo\Git\ConnectN\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/connectN.dir/PlayerAI.cpp.obj"
	C:\MinGW\bin\g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\connectN.dir\PlayerAI.cpp.obj -c C:\Users\mendo\Git\ConnectN\PlayerAI.cpp

CMakeFiles/connectN.dir/PlayerAI.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/connectN.dir/PlayerAI.cpp.i"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\mendo\Git\ConnectN\PlayerAI.cpp > CMakeFiles\connectN.dir\PlayerAI.cpp.i

CMakeFiles/connectN.dir/PlayerAI.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/connectN.dir/PlayerAI.cpp.s"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\mendo\Git\ConnectN\PlayerAI.cpp -o CMakeFiles\connectN.dir\PlayerAI.cpp.s

CMakeFiles/connectN.dir/PlayerAI.cpp.obj.requires:

.PHONY : CMakeFiles/connectN.dir/PlayerAI.cpp.obj.requires

CMakeFiles/connectN.dir/PlayerAI.cpp.obj.provides: CMakeFiles/connectN.dir/PlayerAI.cpp.obj.requires
	$(MAKE) -f CMakeFiles\connectN.dir\build.make CMakeFiles/connectN.dir/PlayerAI.cpp.obj.provides.build
.PHONY : CMakeFiles/connectN.dir/PlayerAI.cpp.obj.provides

CMakeFiles/connectN.dir/PlayerAI.cpp.obj.provides.build: CMakeFiles/connectN.dir/PlayerAI.cpp.obj


CMakeFiles/connectN.dir/PlayerHuman.cpp.obj: CMakeFiles/connectN.dir/flags.make
CMakeFiles/connectN.dir/PlayerHuman.cpp.obj: ../PlayerHuman.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\mendo\Git\ConnectN\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/connectN.dir/PlayerHuman.cpp.obj"
	C:\MinGW\bin\g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\connectN.dir\PlayerHuman.cpp.obj -c C:\Users\mendo\Git\ConnectN\PlayerHuman.cpp

CMakeFiles/connectN.dir/PlayerHuman.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/connectN.dir/PlayerHuman.cpp.i"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\mendo\Git\ConnectN\PlayerHuman.cpp > CMakeFiles\connectN.dir\PlayerHuman.cpp.i

CMakeFiles/connectN.dir/PlayerHuman.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/connectN.dir/PlayerHuman.cpp.s"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\mendo\Git\ConnectN\PlayerHuman.cpp -o CMakeFiles\connectN.dir\PlayerHuman.cpp.s

CMakeFiles/connectN.dir/PlayerHuman.cpp.obj.requires:

.PHONY : CMakeFiles/connectN.dir/PlayerHuman.cpp.obj.requires

CMakeFiles/connectN.dir/PlayerHuman.cpp.obj.provides: CMakeFiles/connectN.dir/PlayerHuman.cpp.obj.requires
	$(MAKE) -f CMakeFiles\connectN.dir\build.make CMakeFiles/connectN.dir/PlayerHuman.cpp.obj.provides.build
.PHONY : CMakeFiles/connectN.dir/PlayerHuman.cpp.obj.provides

CMakeFiles/connectN.dir/PlayerHuman.cpp.obj.provides.build: CMakeFiles/connectN.dir/PlayerHuman.cpp.obj


CMakeFiles/connectN.dir/GameBoard.cpp.obj: CMakeFiles/connectN.dir/flags.make
CMakeFiles/connectN.dir/GameBoard.cpp.obj: ../GameBoard.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\mendo\Git\ConnectN\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/connectN.dir/GameBoard.cpp.obj"
	C:\MinGW\bin\g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\connectN.dir\GameBoard.cpp.obj -c C:\Users\mendo\Git\ConnectN\GameBoard.cpp

CMakeFiles/connectN.dir/GameBoard.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/connectN.dir/GameBoard.cpp.i"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\mendo\Git\ConnectN\GameBoard.cpp > CMakeFiles\connectN.dir\GameBoard.cpp.i

CMakeFiles/connectN.dir/GameBoard.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/connectN.dir/GameBoard.cpp.s"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\mendo\Git\ConnectN\GameBoard.cpp -o CMakeFiles\connectN.dir\GameBoard.cpp.s

CMakeFiles/connectN.dir/GameBoard.cpp.obj.requires:

.PHONY : CMakeFiles/connectN.dir/GameBoard.cpp.obj.requires

CMakeFiles/connectN.dir/GameBoard.cpp.obj.provides: CMakeFiles/connectN.dir/GameBoard.cpp.obj.requires
	$(MAKE) -f CMakeFiles\connectN.dir\build.make CMakeFiles/connectN.dir/GameBoard.cpp.obj.provides.build
.PHONY : CMakeFiles/connectN.dir/GameBoard.cpp.obj.provides

CMakeFiles/connectN.dir/GameBoard.cpp.obj.provides.build: CMakeFiles/connectN.dir/GameBoard.cpp.obj


# Object files for target connectN
connectN_OBJECTS = \
"CMakeFiles/connectN.dir/main.cpp.obj" \
"CMakeFiles/connectN.dir/Game.cpp.obj" \
"CMakeFiles/connectN.dir/PlayerAI.cpp.obj" \
"CMakeFiles/connectN.dir/PlayerHuman.cpp.obj" \
"CMakeFiles/connectN.dir/GameBoard.cpp.obj"

# External object files for target connectN
connectN_EXTERNAL_OBJECTS =

connectN.exe: CMakeFiles/connectN.dir/main.cpp.obj
connectN.exe: CMakeFiles/connectN.dir/Game.cpp.obj
connectN.exe: CMakeFiles/connectN.dir/PlayerAI.cpp.obj
connectN.exe: CMakeFiles/connectN.dir/PlayerHuman.cpp.obj
connectN.exe: CMakeFiles/connectN.dir/GameBoard.cpp.obj
connectN.exe: CMakeFiles/connectN.dir/build.make
connectN.exe: CMakeFiles/connectN.dir/linklibs.rsp
connectN.exe: CMakeFiles/connectN.dir/objects1.rsp
connectN.exe: CMakeFiles/connectN.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\mendo\Git\ConnectN\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable connectN.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\connectN.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/connectN.dir/build: connectN.exe

.PHONY : CMakeFiles/connectN.dir/build

CMakeFiles/connectN.dir/requires: CMakeFiles/connectN.dir/main.cpp.obj.requires
CMakeFiles/connectN.dir/requires: CMakeFiles/connectN.dir/Game.cpp.obj.requires
CMakeFiles/connectN.dir/requires: CMakeFiles/connectN.dir/PlayerAI.cpp.obj.requires
CMakeFiles/connectN.dir/requires: CMakeFiles/connectN.dir/PlayerHuman.cpp.obj.requires
CMakeFiles/connectN.dir/requires: CMakeFiles/connectN.dir/GameBoard.cpp.obj.requires

.PHONY : CMakeFiles/connectN.dir/requires

CMakeFiles/connectN.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\connectN.dir\cmake_clean.cmake
.PHONY : CMakeFiles/connectN.dir/clean

CMakeFiles/connectN.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\mendo\Git\ConnectN C:\Users\mendo\Git\ConnectN C:\Users\mendo\Git\ConnectN\cmake-build-debug C:\Users\mendo\Git\ConnectN\cmake-build-debug C:\Users\mendo\Git\ConnectN\cmake-build-debug\CMakeFiles\connectN.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/connectN.dir/depend

