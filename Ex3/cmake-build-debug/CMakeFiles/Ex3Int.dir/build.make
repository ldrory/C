# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /cygdrive/c/Users/Liran/.CLion2017.3/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/Liran/.CLion2017.3/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/Liran/Documents/GitHub/C/Ex3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/Liran/Documents/GitHub/C/Ex3/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Ex3Int.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Ex3Int.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Ex3Int.dir/flags.make

CMakeFiles/Ex3Int.dir/HashIntSearch.c.o: CMakeFiles/Ex3Int.dir/flags.make
CMakeFiles/Ex3Int.dir/HashIntSearch.c.o: ../HashIntSearch.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/Liran/Documents/GitHub/C/Ex3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Ex3Int.dir/HashIntSearch.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Ex3Int.dir/HashIntSearch.c.o   -c /cygdrive/c/Users/Liran/Documents/GitHub/C/Ex3/HashIntSearch.c

CMakeFiles/Ex3Int.dir/HashIntSearch.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Ex3Int.dir/HashIntSearch.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /cygdrive/c/Users/Liran/Documents/GitHub/C/Ex3/HashIntSearch.c > CMakeFiles/Ex3Int.dir/HashIntSearch.c.i

CMakeFiles/Ex3Int.dir/HashIntSearch.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Ex3Int.dir/HashIntSearch.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /cygdrive/c/Users/Liran/Documents/GitHub/C/Ex3/HashIntSearch.c -o CMakeFiles/Ex3Int.dir/HashIntSearch.c.s

CMakeFiles/Ex3Int.dir/HashIntSearch.c.o.requires:

.PHONY : CMakeFiles/Ex3Int.dir/HashIntSearch.c.o.requires

CMakeFiles/Ex3Int.dir/HashIntSearch.c.o.provides: CMakeFiles/Ex3Int.dir/HashIntSearch.c.o.requires
	$(MAKE) -f CMakeFiles/Ex3Int.dir/build.make CMakeFiles/Ex3Int.dir/HashIntSearch.c.o.provides.build
.PHONY : CMakeFiles/Ex3Int.dir/HashIntSearch.c.o.provides

CMakeFiles/Ex3Int.dir/HashIntSearch.c.o.provides.build: CMakeFiles/Ex3Int.dir/HashIntSearch.c.o


CMakeFiles/Ex3Int.dir/MyIntFunctions.c.o: CMakeFiles/Ex3Int.dir/flags.make
CMakeFiles/Ex3Int.dir/MyIntFunctions.c.o: ../MyIntFunctions.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/Liran/Documents/GitHub/C/Ex3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Ex3Int.dir/MyIntFunctions.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Ex3Int.dir/MyIntFunctions.c.o   -c /cygdrive/c/Users/Liran/Documents/GitHub/C/Ex3/MyIntFunctions.c

CMakeFiles/Ex3Int.dir/MyIntFunctions.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Ex3Int.dir/MyIntFunctions.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /cygdrive/c/Users/Liran/Documents/GitHub/C/Ex3/MyIntFunctions.c > CMakeFiles/Ex3Int.dir/MyIntFunctions.c.i

CMakeFiles/Ex3Int.dir/MyIntFunctions.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Ex3Int.dir/MyIntFunctions.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /cygdrive/c/Users/Liran/Documents/GitHub/C/Ex3/MyIntFunctions.c -o CMakeFiles/Ex3Int.dir/MyIntFunctions.c.s

CMakeFiles/Ex3Int.dir/MyIntFunctions.c.o.requires:

.PHONY : CMakeFiles/Ex3Int.dir/MyIntFunctions.c.o.requires

CMakeFiles/Ex3Int.dir/MyIntFunctions.c.o.provides: CMakeFiles/Ex3Int.dir/MyIntFunctions.c.o.requires
	$(MAKE) -f CMakeFiles/Ex3Int.dir/build.make CMakeFiles/Ex3Int.dir/MyIntFunctions.c.o.provides.build
.PHONY : CMakeFiles/Ex3Int.dir/MyIntFunctions.c.o.provides

CMakeFiles/Ex3Int.dir/MyIntFunctions.c.o.provides.build: CMakeFiles/Ex3Int.dir/MyIntFunctions.c.o


CMakeFiles/Ex3Int.dir/GenericHashTable.c.o: CMakeFiles/Ex3Int.dir/flags.make
CMakeFiles/Ex3Int.dir/GenericHashTable.c.o: ../GenericHashTable.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/Liran/Documents/GitHub/C/Ex3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Ex3Int.dir/GenericHashTable.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Ex3Int.dir/GenericHashTable.c.o   -c /cygdrive/c/Users/Liran/Documents/GitHub/C/Ex3/GenericHashTable.c

CMakeFiles/Ex3Int.dir/GenericHashTable.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Ex3Int.dir/GenericHashTable.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /cygdrive/c/Users/Liran/Documents/GitHub/C/Ex3/GenericHashTable.c > CMakeFiles/Ex3Int.dir/GenericHashTable.c.i

CMakeFiles/Ex3Int.dir/GenericHashTable.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Ex3Int.dir/GenericHashTable.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /cygdrive/c/Users/Liran/Documents/GitHub/C/Ex3/GenericHashTable.c -o CMakeFiles/Ex3Int.dir/GenericHashTable.c.s

CMakeFiles/Ex3Int.dir/GenericHashTable.c.o.requires:

.PHONY : CMakeFiles/Ex3Int.dir/GenericHashTable.c.o.requires

CMakeFiles/Ex3Int.dir/GenericHashTable.c.o.provides: CMakeFiles/Ex3Int.dir/GenericHashTable.c.o.requires
	$(MAKE) -f CMakeFiles/Ex3Int.dir/build.make CMakeFiles/Ex3Int.dir/GenericHashTable.c.o.provides.build
.PHONY : CMakeFiles/Ex3Int.dir/GenericHashTable.c.o.provides

CMakeFiles/Ex3Int.dir/GenericHashTable.c.o.provides.build: CMakeFiles/Ex3Int.dir/GenericHashTable.c.o


CMakeFiles/Ex3Int.dir/TableErrorHandle.c.o: CMakeFiles/Ex3Int.dir/flags.make
CMakeFiles/Ex3Int.dir/TableErrorHandle.c.o: ../TableErrorHandle.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/Liran/Documents/GitHub/C/Ex3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/Ex3Int.dir/TableErrorHandle.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Ex3Int.dir/TableErrorHandle.c.o   -c /cygdrive/c/Users/Liran/Documents/GitHub/C/Ex3/TableErrorHandle.c

CMakeFiles/Ex3Int.dir/TableErrorHandle.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Ex3Int.dir/TableErrorHandle.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /cygdrive/c/Users/Liran/Documents/GitHub/C/Ex3/TableErrorHandle.c > CMakeFiles/Ex3Int.dir/TableErrorHandle.c.i

CMakeFiles/Ex3Int.dir/TableErrorHandle.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Ex3Int.dir/TableErrorHandle.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /cygdrive/c/Users/Liran/Documents/GitHub/C/Ex3/TableErrorHandle.c -o CMakeFiles/Ex3Int.dir/TableErrorHandle.c.s

CMakeFiles/Ex3Int.dir/TableErrorHandle.c.o.requires:

.PHONY : CMakeFiles/Ex3Int.dir/TableErrorHandle.c.o.requires

CMakeFiles/Ex3Int.dir/TableErrorHandle.c.o.provides: CMakeFiles/Ex3Int.dir/TableErrorHandle.c.o.requires
	$(MAKE) -f CMakeFiles/Ex3Int.dir/build.make CMakeFiles/Ex3Int.dir/TableErrorHandle.c.o.provides.build
.PHONY : CMakeFiles/Ex3Int.dir/TableErrorHandle.c.o.provides

CMakeFiles/Ex3Int.dir/TableErrorHandle.c.o.provides.build: CMakeFiles/Ex3Int.dir/TableErrorHandle.c.o


# Object files for target Ex3Int
Ex3Int_OBJECTS = \
"CMakeFiles/Ex3Int.dir/HashIntSearch.c.o" \
"CMakeFiles/Ex3Int.dir/MyIntFunctions.c.o" \
"CMakeFiles/Ex3Int.dir/GenericHashTable.c.o" \
"CMakeFiles/Ex3Int.dir/TableErrorHandle.c.o"

# External object files for target Ex3Int
Ex3Int_EXTERNAL_OBJECTS =

Ex3Int.exe: CMakeFiles/Ex3Int.dir/HashIntSearch.c.o
Ex3Int.exe: CMakeFiles/Ex3Int.dir/MyIntFunctions.c.o
Ex3Int.exe: CMakeFiles/Ex3Int.dir/GenericHashTable.c.o
Ex3Int.exe: CMakeFiles/Ex3Int.dir/TableErrorHandle.c.o
Ex3Int.exe: CMakeFiles/Ex3Int.dir/build.make
Ex3Int.exe: CMakeFiles/Ex3Int.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/Liran/Documents/GitHub/C/Ex3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable Ex3Int.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Ex3Int.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Ex3Int.dir/build: Ex3Int.exe

.PHONY : CMakeFiles/Ex3Int.dir/build

CMakeFiles/Ex3Int.dir/requires: CMakeFiles/Ex3Int.dir/HashIntSearch.c.o.requires
CMakeFiles/Ex3Int.dir/requires: CMakeFiles/Ex3Int.dir/MyIntFunctions.c.o.requires
CMakeFiles/Ex3Int.dir/requires: CMakeFiles/Ex3Int.dir/GenericHashTable.c.o.requires
CMakeFiles/Ex3Int.dir/requires: CMakeFiles/Ex3Int.dir/TableErrorHandle.c.o.requires

.PHONY : CMakeFiles/Ex3Int.dir/requires

CMakeFiles/Ex3Int.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Ex3Int.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Ex3Int.dir/clean

CMakeFiles/Ex3Int.dir/depend:
	cd /cygdrive/c/Users/Liran/Documents/GitHub/C/Ex3/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/Liran/Documents/GitHub/C/Ex3 /cygdrive/c/Users/Liran/Documents/GitHub/C/Ex3 /cygdrive/c/Users/Liran/Documents/GitHub/C/Ex3/cmake-build-debug /cygdrive/c/Users/Liran/Documents/GitHub/C/Ex3/cmake-build-debug /cygdrive/c/Users/Liran/Documents/GitHub/C/Ex3/cmake-build-debug/CMakeFiles/Ex3Int.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Ex3Int.dir/depend

