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
CMAKE_SOURCE_DIR = /home/george/cgpiozero

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/george/cgpiozero/build

# Include any dependencies generated for this target.
include src/CMakeFiles/cgpiozero.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/cgpiozero.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/cgpiozero.dir/flags.make

src/CMakeFiles/cgpiozero.dir/data.cpp.o: src/CMakeFiles/cgpiozero.dir/flags.make
src/CMakeFiles/cgpiozero.dir/data.cpp.o: ../src/data.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/george/cgpiozero/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/cgpiozero.dir/data.cpp.o"
	cd /home/george/cgpiozero/build/src && /bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cgpiozero.dir/data.cpp.o -c /home/george/cgpiozero/src/data.cpp

src/CMakeFiles/cgpiozero.dir/data.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cgpiozero.dir/data.cpp.i"
	cd /home/george/cgpiozero/build/src && /bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/george/cgpiozero/src/data.cpp > CMakeFiles/cgpiozero.dir/data.cpp.i

src/CMakeFiles/cgpiozero.dir/data.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cgpiozero.dir/data.cpp.s"
	cd /home/george/cgpiozero/build/src && /bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/george/cgpiozero/src/data.cpp -o CMakeFiles/cgpiozero.dir/data.cpp.s

src/CMakeFiles/cgpiozero.dir/devices.cpp.o: src/CMakeFiles/cgpiozero.dir/flags.make
src/CMakeFiles/cgpiozero.dir/devices.cpp.o: ../src/devices.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/george/cgpiozero/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/cgpiozero.dir/devices.cpp.o"
	cd /home/george/cgpiozero/build/src && /bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cgpiozero.dir/devices.cpp.o -c /home/george/cgpiozero/src/devices.cpp

src/CMakeFiles/cgpiozero.dir/devices.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cgpiozero.dir/devices.cpp.i"
	cd /home/george/cgpiozero/build/src && /bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/george/cgpiozero/src/devices.cpp > CMakeFiles/cgpiozero.dir/devices.cpp.i

src/CMakeFiles/cgpiozero.dir/devices.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cgpiozero.dir/devices.cpp.s"
	cd /home/george/cgpiozero/build/src && /bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/george/cgpiozero/src/devices.cpp -o CMakeFiles/cgpiozero.dir/devices.cpp.s

src/CMakeFiles/cgpiozero.dir/mixins.cpp.o: src/CMakeFiles/cgpiozero.dir/flags.make
src/CMakeFiles/cgpiozero.dir/mixins.cpp.o: ../src/mixins.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/george/cgpiozero/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/cgpiozero.dir/mixins.cpp.o"
	cd /home/george/cgpiozero/build/src && /bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cgpiozero.dir/mixins.cpp.o -c /home/george/cgpiozero/src/mixins.cpp

src/CMakeFiles/cgpiozero.dir/mixins.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cgpiozero.dir/mixins.cpp.i"
	cd /home/george/cgpiozero/build/src && /bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/george/cgpiozero/src/mixins.cpp > CMakeFiles/cgpiozero.dir/mixins.cpp.i

src/CMakeFiles/cgpiozero.dir/mixins.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cgpiozero.dir/mixins.cpp.s"
	cd /home/george/cgpiozero/build/src && /bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/george/cgpiozero/src/mixins.cpp -o CMakeFiles/cgpiozero.dir/mixins.cpp.s

src/CMakeFiles/cgpiozero.dir/pi.cpp.o: src/CMakeFiles/cgpiozero.dir/flags.make
src/CMakeFiles/cgpiozero.dir/pi.cpp.o: ../src/pi.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/george/cgpiozero/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/cgpiozero.dir/pi.cpp.o"
	cd /home/george/cgpiozero/build/src && /bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cgpiozero.dir/pi.cpp.o -c /home/george/cgpiozero/src/pi.cpp

src/CMakeFiles/cgpiozero.dir/pi.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cgpiozero.dir/pi.cpp.i"
	cd /home/george/cgpiozero/build/src && /bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/george/cgpiozero/src/pi.cpp > CMakeFiles/cgpiozero.dir/pi.cpp.i

src/CMakeFiles/cgpiozero.dir/pi.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cgpiozero.dir/pi.cpp.s"
	cd /home/george/cgpiozero/build/src && /bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/george/cgpiozero/src/pi.cpp -o CMakeFiles/cgpiozero.dir/pi.cpp.s

src/CMakeFiles/cgpiozero.dir/pin.cpp.o: src/CMakeFiles/cgpiozero.dir/flags.make
src/CMakeFiles/cgpiozero.dir/pin.cpp.o: ../src/pin.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/george/cgpiozero/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/cgpiozero.dir/pin.cpp.o"
	cd /home/george/cgpiozero/build/src && /bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cgpiozero.dir/pin.cpp.o -c /home/george/cgpiozero/src/pin.cpp

src/CMakeFiles/cgpiozero.dir/pin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cgpiozero.dir/pin.cpp.i"
	cd /home/george/cgpiozero/build/src && /bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/george/cgpiozero/src/pin.cpp > CMakeFiles/cgpiozero.dir/pin.cpp.i

src/CMakeFiles/cgpiozero.dir/pin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cgpiozero.dir/pin.cpp.s"
	cd /home/george/cgpiozero/build/src && /bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/george/cgpiozero/src/pin.cpp -o CMakeFiles/cgpiozero.dir/pin.cpp.s

src/CMakeFiles/cgpiozero.dir/utilities.cpp.o: src/CMakeFiles/cgpiozero.dir/flags.make
src/CMakeFiles/cgpiozero.dir/utilities.cpp.o: ../src/utilities.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/george/cgpiozero/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/CMakeFiles/cgpiozero.dir/utilities.cpp.o"
	cd /home/george/cgpiozero/build/src && /bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cgpiozero.dir/utilities.cpp.o -c /home/george/cgpiozero/src/utilities.cpp

src/CMakeFiles/cgpiozero.dir/utilities.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cgpiozero.dir/utilities.cpp.i"
	cd /home/george/cgpiozero/build/src && /bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/george/cgpiozero/src/utilities.cpp > CMakeFiles/cgpiozero.dir/utilities.cpp.i

src/CMakeFiles/cgpiozero.dir/utilities.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cgpiozero.dir/utilities.cpp.s"
	cd /home/george/cgpiozero/build/src && /bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/george/cgpiozero/src/utilities.cpp -o CMakeFiles/cgpiozero.dir/utilities.cpp.s

# Object files for target cgpiozero
cgpiozero_OBJECTS = \
"CMakeFiles/cgpiozero.dir/data.cpp.o" \
"CMakeFiles/cgpiozero.dir/devices.cpp.o" \
"CMakeFiles/cgpiozero.dir/mixins.cpp.o" \
"CMakeFiles/cgpiozero.dir/pi.cpp.o" \
"CMakeFiles/cgpiozero.dir/pin.cpp.o" \
"CMakeFiles/cgpiozero.dir/utilities.cpp.o"

# External object files for target cgpiozero
cgpiozero_EXTERNAL_OBJECTS =

lib/libcgpiozero.a: src/CMakeFiles/cgpiozero.dir/data.cpp.o
lib/libcgpiozero.a: src/CMakeFiles/cgpiozero.dir/devices.cpp.o
lib/libcgpiozero.a: src/CMakeFiles/cgpiozero.dir/mixins.cpp.o
lib/libcgpiozero.a: src/CMakeFiles/cgpiozero.dir/pi.cpp.o
lib/libcgpiozero.a: src/CMakeFiles/cgpiozero.dir/pin.cpp.o
lib/libcgpiozero.a: src/CMakeFiles/cgpiozero.dir/utilities.cpp.o
lib/libcgpiozero.a: src/CMakeFiles/cgpiozero.dir/build.make
lib/libcgpiozero.a: src/CMakeFiles/cgpiozero.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/george/cgpiozero/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX static library ../lib/libcgpiozero.a"
	cd /home/george/cgpiozero/build/src && $(CMAKE_COMMAND) -P CMakeFiles/cgpiozero.dir/cmake_clean_target.cmake
	cd /home/george/cgpiozero/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cgpiozero.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/cgpiozero.dir/build: lib/libcgpiozero.a

.PHONY : src/CMakeFiles/cgpiozero.dir/build

src/CMakeFiles/cgpiozero.dir/clean:
	cd /home/george/cgpiozero/build/src && $(CMAKE_COMMAND) -P CMakeFiles/cgpiozero.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/cgpiozero.dir/clean

src/CMakeFiles/cgpiozero.dir/depend:
	cd /home/george/cgpiozero/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/george/cgpiozero /home/george/cgpiozero/src /home/george/cgpiozero/build /home/george/cgpiozero/build/src /home/george/cgpiozero/build/src/CMakeFiles/cgpiozero.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/cgpiozero.dir/depend

