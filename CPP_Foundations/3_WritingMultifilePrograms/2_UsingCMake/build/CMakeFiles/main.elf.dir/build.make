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
CMAKE_SOURCE_DIR = /home/clewis/CPP_NanodegreeProgram/CPP_Foundations/3_WritingMultifilePrograms/2_UsingCMake

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/clewis/CPP_NanodegreeProgram/CPP_Foundations/3_WritingMultifilePrograms/2_UsingCMake/build

# Include any dependencies generated for this target.
include CMakeFiles/main.elf.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/main.elf.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/main.elf.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.elf.dir/flags.make

CMakeFiles/main.elf.dir/src/main.cpp.o: CMakeFiles/main.elf.dir/flags.make
CMakeFiles/main.elf.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/main.elf.dir/src/main.cpp.o: CMakeFiles/main.elf.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clewis/CPP_NanodegreeProgram/CPP_Foundations/3_WritingMultifilePrograms/2_UsingCMake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main.elf.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.elf.dir/src/main.cpp.o -MF CMakeFiles/main.elf.dir/src/main.cpp.o.d -o CMakeFiles/main.elf.dir/src/main.cpp.o -c /home/clewis/CPP_NanodegreeProgram/CPP_Foundations/3_WritingMultifilePrograms/2_UsingCMake/src/main.cpp

CMakeFiles/main.elf.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.elf.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/clewis/CPP_NanodegreeProgram/CPP_Foundations/3_WritingMultifilePrograms/2_UsingCMake/src/main.cpp > CMakeFiles/main.elf.dir/src/main.cpp.i

CMakeFiles/main.elf.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.elf.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/clewis/CPP_NanodegreeProgram/CPP_Foundations/3_WritingMultifilePrograms/2_UsingCMake/src/main.cpp -o CMakeFiles/main.elf.dir/src/main.cpp.s

CMakeFiles/main.elf.dir/src/increment_and_sum.cpp.o: CMakeFiles/main.elf.dir/flags.make
CMakeFiles/main.elf.dir/src/increment_and_sum.cpp.o: ../src/increment_and_sum.cpp
CMakeFiles/main.elf.dir/src/increment_and_sum.cpp.o: CMakeFiles/main.elf.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clewis/CPP_NanodegreeProgram/CPP_Foundations/3_WritingMultifilePrograms/2_UsingCMake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/main.elf.dir/src/increment_and_sum.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.elf.dir/src/increment_and_sum.cpp.o -MF CMakeFiles/main.elf.dir/src/increment_and_sum.cpp.o.d -o CMakeFiles/main.elf.dir/src/increment_and_sum.cpp.o -c /home/clewis/CPP_NanodegreeProgram/CPP_Foundations/3_WritingMultifilePrograms/2_UsingCMake/src/increment_and_sum.cpp

CMakeFiles/main.elf.dir/src/increment_and_sum.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.elf.dir/src/increment_and_sum.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/clewis/CPP_NanodegreeProgram/CPP_Foundations/3_WritingMultifilePrograms/2_UsingCMake/src/increment_and_sum.cpp > CMakeFiles/main.elf.dir/src/increment_and_sum.cpp.i

CMakeFiles/main.elf.dir/src/increment_and_sum.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.elf.dir/src/increment_and_sum.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/clewis/CPP_NanodegreeProgram/CPP_Foundations/3_WritingMultifilePrograms/2_UsingCMake/src/increment_and_sum.cpp -o CMakeFiles/main.elf.dir/src/increment_and_sum.cpp.s

CMakeFiles/main.elf.dir/src/vect_add_one.cpp.o: CMakeFiles/main.elf.dir/flags.make
CMakeFiles/main.elf.dir/src/vect_add_one.cpp.o: ../src/vect_add_one.cpp
CMakeFiles/main.elf.dir/src/vect_add_one.cpp.o: CMakeFiles/main.elf.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clewis/CPP_NanodegreeProgram/CPP_Foundations/3_WritingMultifilePrograms/2_UsingCMake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/main.elf.dir/src/vect_add_one.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.elf.dir/src/vect_add_one.cpp.o -MF CMakeFiles/main.elf.dir/src/vect_add_one.cpp.o.d -o CMakeFiles/main.elf.dir/src/vect_add_one.cpp.o -c /home/clewis/CPP_NanodegreeProgram/CPP_Foundations/3_WritingMultifilePrograms/2_UsingCMake/src/vect_add_one.cpp

CMakeFiles/main.elf.dir/src/vect_add_one.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.elf.dir/src/vect_add_one.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/clewis/CPP_NanodegreeProgram/CPP_Foundations/3_WritingMultifilePrograms/2_UsingCMake/src/vect_add_one.cpp > CMakeFiles/main.elf.dir/src/vect_add_one.cpp.i

CMakeFiles/main.elf.dir/src/vect_add_one.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.elf.dir/src/vect_add_one.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/clewis/CPP_NanodegreeProgram/CPP_Foundations/3_WritingMultifilePrograms/2_UsingCMake/src/vect_add_one.cpp -o CMakeFiles/main.elf.dir/src/vect_add_one.cpp.s

# Object files for target main.elf
main_elf_OBJECTS = \
"CMakeFiles/main.elf.dir/src/main.cpp.o" \
"CMakeFiles/main.elf.dir/src/increment_and_sum.cpp.o" \
"CMakeFiles/main.elf.dir/src/vect_add_one.cpp.o"

# External object files for target main.elf
main_elf_EXTERNAL_OBJECTS =

main.elf: CMakeFiles/main.elf.dir/src/main.cpp.o
main.elf: CMakeFiles/main.elf.dir/src/increment_and_sum.cpp.o
main.elf: CMakeFiles/main.elf.dir/src/vect_add_one.cpp.o
main.elf: CMakeFiles/main.elf.dir/build.make
main.elf: CMakeFiles/main.elf.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/clewis/CPP_NanodegreeProgram/CPP_Foundations/3_WritingMultifilePrograms/2_UsingCMake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable main.elf"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.elf.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.elf.dir/build: main.elf
.PHONY : CMakeFiles/main.elf.dir/build

CMakeFiles/main.elf.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main.elf.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main.elf.dir/clean

CMakeFiles/main.elf.dir/depend:
	cd /home/clewis/CPP_NanodegreeProgram/CPP_Foundations/3_WritingMultifilePrograms/2_UsingCMake/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/clewis/CPP_NanodegreeProgram/CPP_Foundations/3_WritingMultifilePrograms/2_UsingCMake /home/clewis/CPP_NanodegreeProgram/CPP_Foundations/3_WritingMultifilePrograms/2_UsingCMake /home/clewis/CPP_NanodegreeProgram/CPP_Foundations/3_WritingMultifilePrograms/2_UsingCMake/build /home/clewis/CPP_NanodegreeProgram/CPP_Foundations/3_WritingMultifilePrograms/2_UsingCMake/build /home/clewis/CPP_NanodegreeProgram/CPP_Foundations/3_WritingMultifilePrograms/2_UsingCMake/build/CMakeFiles/main.elf.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main.elf.dir/depend

