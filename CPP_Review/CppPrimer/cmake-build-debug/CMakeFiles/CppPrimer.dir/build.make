# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /home/alex/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/182.4892.24/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/alex/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/182.4892.24/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/alex/WorkPlace/DataStru_Algorithm/CPP_Review/CppPrimer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alex/WorkPlace/DataStru_Algorithm/CPP_Review/CppPrimer/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CppPrimer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CppPrimer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CppPrimer.dir/flags.make

CMakeFiles/CppPrimer.dir/IO/iotest.cpp.o: CMakeFiles/CppPrimer.dir/flags.make
CMakeFiles/CppPrimer.dir/IO/iotest.cpp.o: ../IO/iotest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alex/WorkPlace/DataStru_Algorithm/CPP_Review/CppPrimer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CppPrimer.dir/IO/iotest.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CppPrimer.dir/IO/iotest.cpp.o -c /home/alex/WorkPlace/DataStru_Algorithm/CPP_Review/CppPrimer/IO/iotest.cpp

CMakeFiles/CppPrimer.dir/IO/iotest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CppPrimer.dir/IO/iotest.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alex/WorkPlace/DataStru_Algorithm/CPP_Review/CppPrimer/IO/iotest.cpp > CMakeFiles/CppPrimer.dir/IO/iotest.cpp.i

CMakeFiles/CppPrimer.dir/IO/iotest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CppPrimer.dir/IO/iotest.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alex/WorkPlace/DataStru_Algorithm/CPP_Review/CppPrimer/IO/iotest.cpp -o CMakeFiles/CppPrimer.dir/IO/iotest.cpp.s

# Object files for target CppPrimer
CppPrimer_OBJECTS = \
"CMakeFiles/CppPrimer.dir/IO/iotest.cpp.o"

# External object files for target CppPrimer
CppPrimer_EXTERNAL_OBJECTS =

CppPrimer: CMakeFiles/CppPrimer.dir/IO/iotest.cpp.o
CppPrimer: CMakeFiles/CppPrimer.dir/build.make
CppPrimer: CMakeFiles/CppPrimer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alex/WorkPlace/DataStru_Algorithm/CPP_Review/CppPrimer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CppPrimer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CppPrimer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CppPrimer.dir/build: CppPrimer

.PHONY : CMakeFiles/CppPrimer.dir/build

CMakeFiles/CppPrimer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CppPrimer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CppPrimer.dir/clean

CMakeFiles/CppPrimer.dir/depend:
	cd /home/alex/WorkPlace/DataStru_Algorithm/CPP_Review/CppPrimer/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alex/WorkPlace/DataStru_Algorithm/CPP_Review/CppPrimer /home/alex/WorkPlace/DataStru_Algorithm/CPP_Review/CppPrimer /home/alex/WorkPlace/DataStru_Algorithm/CPP_Review/CppPrimer/cmake-build-debug /home/alex/WorkPlace/DataStru_Algorithm/CPP_Review/CppPrimer/cmake-build-debug /home/alex/WorkPlace/DataStru_Algorithm/CPP_Review/CppPrimer/cmake-build-debug/CMakeFiles/CppPrimer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CppPrimer.dir/depend

