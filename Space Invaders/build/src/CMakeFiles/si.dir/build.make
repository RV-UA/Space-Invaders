# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/robin/git/SpaceInvaders/Space Invaders"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/robin/git/SpaceInvaders/Space Invaders/build"

# Include any dependencies generated for this target.
include src/CMakeFiles/si.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/si.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/si.dir/flags.make

src/CMakeFiles/si.dir/Alien.cpp.o: src/CMakeFiles/si.dir/flags.make
src/CMakeFiles/si.dir/Alien.cpp.o: ../src/Alien.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report "/home/robin/git/SpaceInvaders/Space Invaders/build/CMakeFiles" $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/si.dir/Alien.cpp.o"
	cd "/home/robin/git/SpaceInvaders/Space Invaders/build/src" && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/si.dir/Alien.cpp.o -c "/home/robin/git/SpaceInvaders/Space Invaders/src/Alien.cpp"

src/CMakeFiles/si.dir/Alien.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/si.dir/Alien.cpp.i"
	cd "/home/robin/git/SpaceInvaders/Space Invaders/build/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/home/robin/git/SpaceInvaders/Space Invaders/src/Alien.cpp" > CMakeFiles/si.dir/Alien.cpp.i

src/CMakeFiles/si.dir/Alien.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/si.dir/Alien.cpp.s"
	cd "/home/robin/git/SpaceInvaders/Space Invaders/build/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/home/robin/git/SpaceInvaders/Space Invaders/src/Alien.cpp" -o CMakeFiles/si.dir/Alien.cpp.s

src/CMakeFiles/si.dir/Alien.cpp.o.requires:
.PHONY : src/CMakeFiles/si.dir/Alien.cpp.o.requires

src/CMakeFiles/si.dir/Alien.cpp.o.provides: src/CMakeFiles/si.dir/Alien.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/si.dir/build.make src/CMakeFiles/si.dir/Alien.cpp.o.provides.build
.PHONY : src/CMakeFiles/si.dir/Alien.cpp.o.provides

src/CMakeFiles/si.dir/Alien.cpp.o.provides.build: src/CMakeFiles/si.dir/Alien.cpp.o

src/CMakeFiles/si.dir/Bullet.cpp.o: src/CMakeFiles/si.dir/flags.make
src/CMakeFiles/si.dir/Bullet.cpp.o: ../src/Bullet.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report "/home/robin/git/SpaceInvaders/Space Invaders/build/CMakeFiles" $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/si.dir/Bullet.cpp.o"
	cd "/home/robin/git/SpaceInvaders/Space Invaders/build/src" && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/si.dir/Bullet.cpp.o -c "/home/robin/git/SpaceInvaders/Space Invaders/src/Bullet.cpp"

src/CMakeFiles/si.dir/Bullet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/si.dir/Bullet.cpp.i"
	cd "/home/robin/git/SpaceInvaders/Space Invaders/build/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/home/robin/git/SpaceInvaders/Space Invaders/src/Bullet.cpp" > CMakeFiles/si.dir/Bullet.cpp.i

src/CMakeFiles/si.dir/Bullet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/si.dir/Bullet.cpp.s"
	cd "/home/robin/git/SpaceInvaders/Space Invaders/build/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/home/robin/git/SpaceInvaders/Space Invaders/src/Bullet.cpp" -o CMakeFiles/si.dir/Bullet.cpp.s

src/CMakeFiles/si.dir/Bullet.cpp.o.requires:
.PHONY : src/CMakeFiles/si.dir/Bullet.cpp.o.requires

src/CMakeFiles/si.dir/Bullet.cpp.o.provides: src/CMakeFiles/si.dir/Bullet.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/si.dir/build.make src/CMakeFiles/si.dir/Bullet.cpp.o.provides.build
.PHONY : src/CMakeFiles/si.dir/Bullet.cpp.o.provides

src/CMakeFiles/si.dir/Bullet.cpp.o.provides.build: src/CMakeFiles/si.dir/Bullet.cpp.o

src/CMakeFiles/si.dir/Bunker.cpp.o: src/CMakeFiles/si.dir/flags.make
src/CMakeFiles/si.dir/Bunker.cpp.o: ../src/Bunker.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report "/home/robin/git/SpaceInvaders/Space Invaders/build/CMakeFiles" $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/si.dir/Bunker.cpp.o"
	cd "/home/robin/git/SpaceInvaders/Space Invaders/build/src" && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/si.dir/Bunker.cpp.o -c "/home/robin/git/SpaceInvaders/Space Invaders/src/Bunker.cpp"

src/CMakeFiles/si.dir/Bunker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/si.dir/Bunker.cpp.i"
	cd "/home/robin/git/SpaceInvaders/Space Invaders/build/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/home/robin/git/SpaceInvaders/Space Invaders/src/Bunker.cpp" > CMakeFiles/si.dir/Bunker.cpp.i

src/CMakeFiles/si.dir/Bunker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/si.dir/Bunker.cpp.s"
	cd "/home/robin/git/SpaceInvaders/Space Invaders/build/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/home/robin/git/SpaceInvaders/Space Invaders/src/Bunker.cpp" -o CMakeFiles/si.dir/Bunker.cpp.s

src/CMakeFiles/si.dir/Bunker.cpp.o.requires:
.PHONY : src/CMakeFiles/si.dir/Bunker.cpp.o.requires

src/CMakeFiles/si.dir/Bunker.cpp.o.provides: src/CMakeFiles/si.dir/Bunker.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/si.dir/build.make src/CMakeFiles/si.dir/Bunker.cpp.o.provides.build
.PHONY : src/CMakeFiles/si.dir/Bunker.cpp.o.provides

src/CMakeFiles/si.dir/Bunker.cpp.o.provides.build: src/CMakeFiles/si.dir/Bunker.cpp.o

src/CMakeFiles/si.dir/Entity.cpp.o: src/CMakeFiles/si.dir/flags.make
src/CMakeFiles/si.dir/Entity.cpp.o: ../src/Entity.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report "/home/robin/git/SpaceInvaders/Space Invaders/build/CMakeFiles" $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/si.dir/Entity.cpp.o"
	cd "/home/robin/git/SpaceInvaders/Space Invaders/build/src" && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/si.dir/Entity.cpp.o -c "/home/robin/git/SpaceInvaders/Space Invaders/src/Entity.cpp"

src/CMakeFiles/si.dir/Entity.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/si.dir/Entity.cpp.i"
	cd "/home/robin/git/SpaceInvaders/Space Invaders/build/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/home/robin/git/SpaceInvaders/Space Invaders/src/Entity.cpp" > CMakeFiles/si.dir/Entity.cpp.i

src/CMakeFiles/si.dir/Entity.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/si.dir/Entity.cpp.s"
	cd "/home/robin/git/SpaceInvaders/Space Invaders/build/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/home/robin/git/SpaceInvaders/Space Invaders/src/Entity.cpp" -o CMakeFiles/si.dir/Entity.cpp.s

src/CMakeFiles/si.dir/Entity.cpp.o.requires:
.PHONY : src/CMakeFiles/si.dir/Entity.cpp.o.requires

src/CMakeFiles/si.dir/Entity.cpp.o.provides: src/CMakeFiles/si.dir/Entity.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/si.dir/build.make src/CMakeFiles/si.dir/Entity.cpp.o.provides.build
.PHONY : src/CMakeFiles/si.dir/Entity.cpp.o.provides

src/CMakeFiles/si.dir/Entity.cpp.o.provides.build: src/CMakeFiles/si.dir/Entity.cpp.o

src/CMakeFiles/si.dir/EntityFactory.cpp.o: src/CMakeFiles/si.dir/flags.make
src/CMakeFiles/si.dir/EntityFactory.cpp.o: ../src/EntityFactory.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report "/home/robin/git/SpaceInvaders/Space Invaders/build/CMakeFiles" $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/si.dir/EntityFactory.cpp.o"
	cd "/home/robin/git/SpaceInvaders/Space Invaders/build/src" && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/si.dir/EntityFactory.cpp.o -c "/home/robin/git/SpaceInvaders/Space Invaders/src/EntityFactory.cpp"

src/CMakeFiles/si.dir/EntityFactory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/si.dir/EntityFactory.cpp.i"
	cd "/home/robin/git/SpaceInvaders/Space Invaders/build/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/home/robin/git/SpaceInvaders/Space Invaders/src/EntityFactory.cpp" > CMakeFiles/si.dir/EntityFactory.cpp.i

src/CMakeFiles/si.dir/EntityFactory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/si.dir/EntityFactory.cpp.s"
	cd "/home/robin/git/SpaceInvaders/Space Invaders/build/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/home/robin/git/SpaceInvaders/Space Invaders/src/EntityFactory.cpp" -o CMakeFiles/si.dir/EntityFactory.cpp.s

src/CMakeFiles/si.dir/EntityFactory.cpp.o.requires:
.PHONY : src/CMakeFiles/si.dir/EntityFactory.cpp.o.requires

src/CMakeFiles/si.dir/EntityFactory.cpp.o.provides: src/CMakeFiles/si.dir/EntityFactory.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/si.dir/build.make src/CMakeFiles/si.dir/EntityFactory.cpp.o.provides.build
.PHONY : src/CMakeFiles/si.dir/EntityFactory.cpp.o.provides

src/CMakeFiles/si.dir/EntityFactory.cpp.o.provides.build: src/CMakeFiles/si.dir/EntityFactory.cpp.o

src/CMakeFiles/si.dir/Exception.cpp.o: src/CMakeFiles/si.dir/flags.make
src/CMakeFiles/si.dir/Exception.cpp.o: ../src/Exception.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report "/home/robin/git/SpaceInvaders/Space Invaders/build/CMakeFiles" $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/si.dir/Exception.cpp.o"
	cd "/home/robin/git/SpaceInvaders/Space Invaders/build/src" && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/si.dir/Exception.cpp.o -c "/home/robin/git/SpaceInvaders/Space Invaders/src/Exception.cpp"

src/CMakeFiles/si.dir/Exception.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/si.dir/Exception.cpp.i"
	cd "/home/robin/git/SpaceInvaders/Space Invaders/build/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/home/robin/git/SpaceInvaders/Space Invaders/src/Exception.cpp" > CMakeFiles/si.dir/Exception.cpp.i

src/CMakeFiles/si.dir/Exception.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/si.dir/Exception.cpp.s"
	cd "/home/robin/git/SpaceInvaders/Space Invaders/build/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/home/robin/git/SpaceInvaders/Space Invaders/src/Exception.cpp" -o CMakeFiles/si.dir/Exception.cpp.s

src/CMakeFiles/si.dir/Exception.cpp.o.requires:
.PHONY : src/CMakeFiles/si.dir/Exception.cpp.o.requires

src/CMakeFiles/si.dir/Exception.cpp.o.provides: src/CMakeFiles/si.dir/Exception.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/si.dir/build.make src/CMakeFiles/si.dir/Exception.cpp.o.provides.build
.PHONY : src/CMakeFiles/si.dir/Exception.cpp.o.provides

src/CMakeFiles/si.dir/Exception.cpp.o.provides.build: src/CMakeFiles/si.dir/Exception.cpp.o

src/CMakeFiles/si.dir/gameController.cpp.o: src/CMakeFiles/si.dir/flags.make
src/CMakeFiles/si.dir/gameController.cpp.o: ../src/gameController.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report "/home/robin/git/SpaceInvaders/Space Invaders/build/CMakeFiles" $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/si.dir/gameController.cpp.o"
	cd "/home/robin/git/SpaceInvaders/Space Invaders/build/src" && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/si.dir/gameController.cpp.o -c "/home/robin/git/SpaceInvaders/Space Invaders/src/gameController.cpp"

src/CMakeFiles/si.dir/gameController.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/si.dir/gameController.cpp.i"
	cd "/home/robin/git/SpaceInvaders/Space Invaders/build/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/home/robin/git/SpaceInvaders/Space Invaders/src/gameController.cpp" > CMakeFiles/si.dir/gameController.cpp.i

src/CMakeFiles/si.dir/gameController.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/si.dir/gameController.cpp.s"
	cd "/home/robin/git/SpaceInvaders/Space Invaders/build/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/home/robin/git/SpaceInvaders/Space Invaders/src/gameController.cpp" -o CMakeFiles/si.dir/gameController.cpp.s

src/CMakeFiles/si.dir/gameController.cpp.o.requires:
.PHONY : src/CMakeFiles/si.dir/gameController.cpp.o.requires

src/CMakeFiles/si.dir/gameController.cpp.o.provides: src/CMakeFiles/si.dir/gameController.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/si.dir/build.make src/CMakeFiles/si.dir/gameController.cpp.o.provides.build
.PHONY : src/CMakeFiles/si.dir/gameController.cpp.o.provides

src/CMakeFiles/si.dir/gameController.cpp.o.provides.build: src/CMakeFiles/si.dir/gameController.cpp.o

src/CMakeFiles/si.dir/GameFactory.cpp.o: src/CMakeFiles/si.dir/flags.make
src/CMakeFiles/si.dir/GameFactory.cpp.o: ../src/GameFactory.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report "/home/robin/git/SpaceInvaders/Space Invaders/build/CMakeFiles" $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/si.dir/GameFactory.cpp.o"
	cd "/home/robin/git/SpaceInvaders/Space Invaders/build/src" && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/si.dir/GameFactory.cpp.o -c "/home/robin/git/SpaceInvaders/Space Invaders/src/GameFactory.cpp"

src/CMakeFiles/si.dir/GameFactory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/si.dir/GameFactory.cpp.i"
	cd "/home/robin/git/SpaceInvaders/Space Invaders/build/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/home/robin/git/SpaceInvaders/Space Invaders/src/GameFactory.cpp" > CMakeFiles/si.dir/GameFactory.cpp.i

src/CMakeFiles/si.dir/GameFactory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/si.dir/GameFactory.cpp.s"
	cd "/home/robin/git/SpaceInvaders/Space Invaders/build/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/home/robin/git/SpaceInvaders/Space Invaders/src/GameFactory.cpp" -o CMakeFiles/si.dir/GameFactory.cpp.s

src/CMakeFiles/si.dir/GameFactory.cpp.o.requires:
.PHONY : src/CMakeFiles/si.dir/GameFactory.cpp.o.requires

src/CMakeFiles/si.dir/GameFactory.cpp.o.provides: src/CMakeFiles/si.dir/GameFactory.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/si.dir/build.make src/CMakeFiles/si.dir/GameFactory.cpp.o.provides.build
.PHONY : src/CMakeFiles/si.dir/GameFactory.cpp.o.provides

src/CMakeFiles/si.dir/GameFactory.cpp.o.provides.build: src/CMakeFiles/si.dir/GameFactory.cpp.o

src/CMakeFiles/si.dir/gameModel.cpp.o: src/CMakeFiles/si.dir/flags.make
src/CMakeFiles/si.dir/gameModel.cpp.o: ../src/gameModel.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report "/home/robin/git/SpaceInvaders/Space Invaders/build/CMakeFiles" $(CMAKE_PROGRESS_9)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/si.dir/gameModel.cpp.o"
	cd "/home/robin/git/SpaceInvaders/Space Invaders/build/src" && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/si.dir/gameModel.cpp.o -c "/home/robin/git/SpaceInvaders/Space Invaders/src/gameModel.cpp"

src/CMakeFiles/si.dir/gameModel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/si.dir/gameModel.cpp.i"
	cd "/home/robin/git/SpaceInvaders/Space Invaders/build/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/home/robin/git/SpaceInvaders/Space Invaders/src/gameModel.cpp" > CMakeFiles/si.dir/gameModel.cpp.i

src/CMakeFiles/si.dir/gameModel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/si.dir/gameModel.cpp.s"
	cd "/home/robin/git/SpaceInvaders/Space Invaders/build/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/home/robin/git/SpaceInvaders/Space Invaders/src/gameModel.cpp" -o CMakeFiles/si.dir/gameModel.cpp.s

src/CMakeFiles/si.dir/gameModel.cpp.o.requires:
.PHONY : src/CMakeFiles/si.dir/gameModel.cpp.o.requires

src/CMakeFiles/si.dir/gameModel.cpp.o.provides: src/CMakeFiles/si.dir/gameModel.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/si.dir/build.make src/CMakeFiles/si.dir/gameModel.cpp.o.provides.build
.PHONY : src/CMakeFiles/si.dir/gameModel.cpp.o.provides

src/CMakeFiles/si.dir/gameModel.cpp.o.provides.build: src/CMakeFiles/si.dir/gameModel.cpp.o

src/CMakeFiles/si.dir/gameView.cpp.o: src/CMakeFiles/si.dir/flags.make
src/CMakeFiles/si.dir/gameView.cpp.o: ../src/gameView.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report "/home/robin/git/SpaceInvaders/Space Invaders/build/CMakeFiles" $(CMAKE_PROGRESS_10)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/si.dir/gameView.cpp.o"
	cd "/home/robin/git/SpaceInvaders/Space Invaders/build/src" && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/si.dir/gameView.cpp.o -c "/home/robin/git/SpaceInvaders/Space Invaders/src/gameView.cpp"

src/CMakeFiles/si.dir/gameView.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/si.dir/gameView.cpp.i"
	cd "/home/robin/git/SpaceInvaders/Space Invaders/build/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/home/robin/git/SpaceInvaders/Space Invaders/src/gameView.cpp" > CMakeFiles/si.dir/gameView.cpp.i

src/CMakeFiles/si.dir/gameView.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/si.dir/gameView.cpp.s"
	cd "/home/robin/git/SpaceInvaders/Space Invaders/build/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/home/robin/git/SpaceInvaders/Space Invaders/src/gameView.cpp" -o CMakeFiles/si.dir/gameView.cpp.s

src/CMakeFiles/si.dir/gameView.cpp.o.requires:
.PHONY : src/CMakeFiles/si.dir/gameView.cpp.o.requires

src/CMakeFiles/si.dir/gameView.cpp.o.provides: src/CMakeFiles/si.dir/gameView.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/si.dir/build.make src/CMakeFiles/si.dir/gameView.cpp.o.provides.build
.PHONY : src/CMakeFiles/si.dir/gameView.cpp.o.provides

src/CMakeFiles/si.dir/gameView.cpp.o.provides.build: src/CMakeFiles/si.dir/gameView.cpp.o

src/CMakeFiles/si.dir/Gun.cpp.o: src/CMakeFiles/si.dir/flags.make
src/CMakeFiles/si.dir/Gun.cpp.o: ../src/Gun.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report "/home/robin/git/SpaceInvaders/Space Invaders/build/CMakeFiles" $(CMAKE_PROGRESS_11)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/si.dir/Gun.cpp.o"
	cd "/home/robin/git/SpaceInvaders/Space Invaders/build/src" && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/si.dir/Gun.cpp.o -c "/home/robin/git/SpaceInvaders/Space Invaders/src/Gun.cpp"

src/CMakeFiles/si.dir/Gun.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/si.dir/Gun.cpp.i"
	cd "/home/robin/git/SpaceInvaders/Space Invaders/build/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/home/robin/git/SpaceInvaders/Space Invaders/src/Gun.cpp" > CMakeFiles/si.dir/Gun.cpp.i

src/CMakeFiles/si.dir/Gun.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/si.dir/Gun.cpp.s"
	cd "/home/robin/git/SpaceInvaders/Space Invaders/build/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/home/robin/git/SpaceInvaders/Space Invaders/src/Gun.cpp" -o CMakeFiles/si.dir/Gun.cpp.s

src/CMakeFiles/si.dir/Gun.cpp.o.requires:
.PHONY : src/CMakeFiles/si.dir/Gun.cpp.o.requires

src/CMakeFiles/si.dir/Gun.cpp.o.provides: src/CMakeFiles/si.dir/Gun.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/si.dir/build.make src/CMakeFiles/si.dir/Gun.cpp.o.provides.build
.PHONY : src/CMakeFiles/si.dir/Gun.cpp.o.provides

src/CMakeFiles/si.dir/Gun.cpp.o.provides.build: src/CMakeFiles/si.dir/Gun.cpp.o

src/CMakeFiles/si.dir/read.cpp.o: src/CMakeFiles/si.dir/flags.make
src/CMakeFiles/si.dir/read.cpp.o: ../src/read.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report "/home/robin/git/SpaceInvaders/Space Invaders/build/CMakeFiles" $(CMAKE_PROGRESS_12)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/si.dir/read.cpp.o"
	cd "/home/robin/git/SpaceInvaders/Space Invaders/build/src" && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/si.dir/read.cpp.o -c "/home/robin/git/SpaceInvaders/Space Invaders/src/read.cpp"

src/CMakeFiles/si.dir/read.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/si.dir/read.cpp.i"
	cd "/home/robin/git/SpaceInvaders/Space Invaders/build/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/home/robin/git/SpaceInvaders/Space Invaders/src/read.cpp" > CMakeFiles/si.dir/read.cpp.i

src/CMakeFiles/si.dir/read.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/si.dir/read.cpp.s"
	cd "/home/robin/git/SpaceInvaders/Space Invaders/build/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/home/robin/git/SpaceInvaders/Space Invaders/src/read.cpp" -o CMakeFiles/si.dir/read.cpp.s

src/CMakeFiles/si.dir/read.cpp.o.requires:
.PHONY : src/CMakeFiles/si.dir/read.cpp.o.requires

src/CMakeFiles/si.dir/read.cpp.o.provides: src/CMakeFiles/si.dir/read.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/si.dir/build.make src/CMakeFiles/si.dir/read.cpp.o.provides.build
.PHONY : src/CMakeFiles/si.dir/read.cpp.o.provides

src/CMakeFiles/si.dir/read.cpp.o.provides.build: src/CMakeFiles/si.dir/read.cpp.o

src/CMakeFiles/si.dir/utilities.cpp.o: src/CMakeFiles/si.dir/flags.make
src/CMakeFiles/si.dir/utilities.cpp.o: ../src/utilities.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report "/home/robin/git/SpaceInvaders/Space Invaders/build/CMakeFiles" $(CMAKE_PROGRESS_13)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/si.dir/utilities.cpp.o"
	cd "/home/robin/git/SpaceInvaders/Space Invaders/build/src" && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/si.dir/utilities.cpp.o -c "/home/robin/git/SpaceInvaders/Space Invaders/src/utilities.cpp"

src/CMakeFiles/si.dir/utilities.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/si.dir/utilities.cpp.i"
	cd "/home/robin/git/SpaceInvaders/Space Invaders/build/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/home/robin/git/SpaceInvaders/Space Invaders/src/utilities.cpp" > CMakeFiles/si.dir/utilities.cpp.i

src/CMakeFiles/si.dir/utilities.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/si.dir/utilities.cpp.s"
	cd "/home/robin/git/SpaceInvaders/Space Invaders/build/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/home/robin/git/SpaceInvaders/Space Invaders/src/utilities.cpp" -o CMakeFiles/si.dir/utilities.cpp.s

src/CMakeFiles/si.dir/utilities.cpp.o.requires:
.PHONY : src/CMakeFiles/si.dir/utilities.cpp.o.requires

src/CMakeFiles/si.dir/utilities.cpp.o.provides: src/CMakeFiles/si.dir/utilities.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/si.dir/build.make src/CMakeFiles/si.dir/utilities.cpp.o.provides.build
.PHONY : src/CMakeFiles/si.dir/utilities.cpp.o.provides

src/CMakeFiles/si.dir/utilities.cpp.o.provides.build: src/CMakeFiles/si.dir/utilities.cpp.o

src/CMakeFiles/si.dir/main.cpp.o: src/CMakeFiles/si.dir/flags.make
src/CMakeFiles/si.dir/main.cpp.o: ../src/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report "/home/robin/git/SpaceInvaders/Space Invaders/build/CMakeFiles" $(CMAKE_PROGRESS_14)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/si.dir/main.cpp.o"
	cd "/home/robin/git/SpaceInvaders/Space Invaders/build/src" && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/si.dir/main.cpp.o -c "/home/robin/git/SpaceInvaders/Space Invaders/src/main.cpp"

src/CMakeFiles/si.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/si.dir/main.cpp.i"
	cd "/home/robin/git/SpaceInvaders/Space Invaders/build/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/home/robin/git/SpaceInvaders/Space Invaders/src/main.cpp" > CMakeFiles/si.dir/main.cpp.i

src/CMakeFiles/si.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/si.dir/main.cpp.s"
	cd "/home/robin/git/SpaceInvaders/Space Invaders/build/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/home/robin/git/SpaceInvaders/Space Invaders/src/main.cpp" -o CMakeFiles/si.dir/main.cpp.s

src/CMakeFiles/si.dir/main.cpp.o.requires:
.PHONY : src/CMakeFiles/si.dir/main.cpp.o.requires

src/CMakeFiles/si.dir/main.cpp.o.provides: src/CMakeFiles/si.dir/main.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/si.dir/build.make src/CMakeFiles/si.dir/main.cpp.o.provides.build
.PHONY : src/CMakeFiles/si.dir/main.cpp.o.provides

src/CMakeFiles/si.dir/main.cpp.o.provides.build: src/CMakeFiles/si.dir/main.cpp.o

# Object files for target si
si_OBJECTS = \
"CMakeFiles/si.dir/Alien.cpp.o" \
"CMakeFiles/si.dir/Bullet.cpp.o" \
"CMakeFiles/si.dir/Bunker.cpp.o" \
"CMakeFiles/si.dir/Entity.cpp.o" \
"CMakeFiles/si.dir/EntityFactory.cpp.o" \
"CMakeFiles/si.dir/Exception.cpp.o" \
"CMakeFiles/si.dir/gameController.cpp.o" \
"CMakeFiles/si.dir/GameFactory.cpp.o" \
"CMakeFiles/si.dir/gameModel.cpp.o" \
"CMakeFiles/si.dir/gameView.cpp.o" \
"CMakeFiles/si.dir/Gun.cpp.o" \
"CMakeFiles/si.dir/read.cpp.o" \
"CMakeFiles/si.dir/utilities.cpp.o" \
"CMakeFiles/si.dir/main.cpp.o"

# External object files for target si
si_EXTERNAL_OBJECTS =

src/si: src/CMakeFiles/si.dir/Alien.cpp.o
src/si: src/CMakeFiles/si.dir/Bullet.cpp.o
src/si: src/CMakeFiles/si.dir/Bunker.cpp.o
src/si: src/CMakeFiles/si.dir/Entity.cpp.o
src/si: src/CMakeFiles/si.dir/EntityFactory.cpp.o
src/si: src/CMakeFiles/si.dir/Exception.cpp.o
src/si: src/CMakeFiles/si.dir/gameController.cpp.o
src/si: src/CMakeFiles/si.dir/GameFactory.cpp.o
src/si: src/CMakeFiles/si.dir/gameModel.cpp.o
src/si: src/CMakeFiles/si.dir/gameView.cpp.o
src/si: src/CMakeFiles/si.dir/Gun.cpp.o
src/si: src/CMakeFiles/si.dir/read.cpp.o
src/si: src/CMakeFiles/si.dir/utilities.cpp.o
src/si: src/CMakeFiles/si.dir/main.cpp.o
src/si: /usr/lib/libsfml-system.so
src/si: /usr/lib/libsfml-window.so
src/si: /usr/lib/libsfml-graphics.so
src/si: /usr/lib/libsfml-network.so
src/si: /usr/lib/libsfml-audio.so
src/si: src/CMakeFiles/si.dir/build.make
src/si: src/CMakeFiles/si.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable si"
	cd "/home/robin/git/SpaceInvaders/Space Invaders/build/src" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/si.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/si.dir/build: src/si
.PHONY : src/CMakeFiles/si.dir/build

src/CMakeFiles/si.dir/requires: src/CMakeFiles/si.dir/Alien.cpp.o.requires
src/CMakeFiles/si.dir/requires: src/CMakeFiles/si.dir/Bullet.cpp.o.requires
src/CMakeFiles/si.dir/requires: src/CMakeFiles/si.dir/Bunker.cpp.o.requires
src/CMakeFiles/si.dir/requires: src/CMakeFiles/si.dir/Entity.cpp.o.requires
src/CMakeFiles/si.dir/requires: src/CMakeFiles/si.dir/EntityFactory.cpp.o.requires
src/CMakeFiles/si.dir/requires: src/CMakeFiles/si.dir/Exception.cpp.o.requires
src/CMakeFiles/si.dir/requires: src/CMakeFiles/si.dir/gameController.cpp.o.requires
src/CMakeFiles/si.dir/requires: src/CMakeFiles/si.dir/GameFactory.cpp.o.requires
src/CMakeFiles/si.dir/requires: src/CMakeFiles/si.dir/gameModel.cpp.o.requires
src/CMakeFiles/si.dir/requires: src/CMakeFiles/si.dir/gameView.cpp.o.requires
src/CMakeFiles/si.dir/requires: src/CMakeFiles/si.dir/Gun.cpp.o.requires
src/CMakeFiles/si.dir/requires: src/CMakeFiles/si.dir/read.cpp.o.requires
src/CMakeFiles/si.dir/requires: src/CMakeFiles/si.dir/utilities.cpp.o.requires
src/CMakeFiles/si.dir/requires: src/CMakeFiles/si.dir/main.cpp.o.requires
.PHONY : src/CMakeFiles/si.dir/requires

src/CMakeFiles/si.dir/clean:
	cd "/home/robin/git/SpaceInvaders/Space Invaders/build/src" && $(CMAKE_COMMAND) -P CMakeFiles/si.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/si.dir/clean

src/CMakeFiles/si.dir/depend:
	cd "/home/robin/git/SpaceInvaders/Space Invaders/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/robin/git/SpaceInvaders/Space Invaders" "/home/robin/git/SpaceInvaders/Space Invaders/src" "/home/robin/git/SpaceInvaders/Space Invaders/build" "/home/robin/git/SpaceInvaders/Space Invaders/build/src" "/home/robin/git/SpaceInvaders/Space Invaders/build/src/CMakeFiles/si.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : src/CMakeFiles/si.dir/depend

