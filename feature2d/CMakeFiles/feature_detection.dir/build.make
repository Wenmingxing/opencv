# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/erian/opencv_code/feature2d

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/erian/opencv_code/feature2d

# Include any dependencies generated for this target.
include CMakeFiles/feature_detection.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/feature_detection.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/feature_detection.dir/flags.make

CMakeFiles/feature_detection.dir/src/featrue_detection.cpp.o: CMakeFiles/feature_detection.dir/flags.make
CMakeFiles/feature_detection.dir/src/featrue_detection.cpp.o: src/featrue_detection.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/erian/opencv_code/feature2d/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/feature_detection.dir/src/featrue_detection.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/feature_detection.dir/src/featrue_detection.cpp.o -c /home/erian/opencv_code/feature2d/src/featrue_detection.cpp

CMakeFiles/feature_detection.dir/src/featrue_detection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/feature_detection.dir/src/featrue_detection.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/erian/opencv_code/feature2d/src/featrue_detection.cpp > CMakeFiles/feature_detection.dir/src/featrue_detection.cpp.i

CMakeFiles/feature_detection.dir/src/featrue_detection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/feature_detection.dir/src/featrue_detection.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/erian/opencv_code/feature2d/src/featrue_detection.cpp -o CMakeFiles/feature_detection.dir/src/featrue_detection.cpp.s

CMakeFiles/feature_detection.dir/src/featrue_detection.cpp.o.requires:

.PHONY : CMakeFiles/feature_detection.dir/src/featrue_detection.cpp.o.requires

CMakeFiles/feature_detection.dir/src/featrue_detection.cpp.o.provides: CMakeFiles/feature_detection.dir/src/featrue_detection.cpp.o.requires
	$(MAKE) -f CMakeFiles/feature_detection.dir/build.make CMakeFiles/feature_detection.dir/src/featrue_detection.cpp.o.provides.build
.PHONY : CMakeFiles/feature_detection.dir/src/featrue_detection.cpp.o.provides

CMakeFiles/feature_detection.dir/src/featrue_detection.cpp.o.provides.build: CMakeFiles/feature_detection.dir/src/featrue_detection.cpp.o


# Object files for target feature_detection
feature_detection_OBJECTS = \
"CMakeFiles/feature_detection.dir/src/featrue_detection.cpp.o"

# External object files for target feature_detection
feature_detection_EXTERNAL_OBJECTS =

feature_detection: CMakeFiles/feature_detection.dir/src/featrue_detection.cpp.o
feature_detection: CMakeFiles/feature_detection.dir/build.make
feature_detection: /opt/ros/kinetic/lib/libopencv_xphoto3.so.3.1.0
feature_detection: /opt/ros/kinetic/lib/libopencv_xobjdetect3.so.3.1.0
feature_detection: /opt/ros/kinetic/lib/libopencv_tracking3.so.3.1.0
feature_detection: /opt/ros/kinetic/lib/libopencv_surface_matching3.so.3.1.0
feature_detection: /opt/ros/kinetic/lib/libopencv_structured_light3.so.3.1.0
feature_detection: /opt/ros/kinetic/lib/libopencv_stereo3.so.3.1.0
feature_detection: /opt/ros/kinetic/lib/libopencv_saliency3.so.3.1.0
feature_detection: /opt/ros/kinetic/lib/libopencv_rgbd3.so.3.1.0
feature_detection: /opt/ros/kinetic/lib/libopencv_reg3.so.3.1.0
feature_detection: /opt/ros/kinetic/lib/libopencv_plot3.so.3.1.0
feature_detection: /opt/ros/kinetic/lib/libopencv_optflow3.so.3.1.0
feature_detection: /opt/ros/kinetic/lib/libopencv_line_descriptor3.so.3.1.0
feature_detection: /opt/ros/kinetic/lib/libopencv_hdf3.so.3.1.0
feature_detection: /opt/ros/kinetic/lib/libopencv_fuzzy3.so.3.1.0
feature_detection: /opt/ros/kinetic/lib/libopencv_dpm3.so.3.1.0
feature_detection: /opt/ros/kinetic/lib/libopencv_dnn3.so.3.1.0
feature_detection: /opt/ros/kinetic/lib/libopencv_datasets3.so.3.1.0
feature_detection: /opt/ros/kinetic/lib/libopencv_cvv3.so.3.1.0
feature_detection: /opt/ros/kinetic/lib/libopencv_ccalib3.so.3.1.0
feature_detection: /opt/ros/kinetic/lib/libopencv_bioinspired3.so.3.1.0
feature_detection: /opt/ros/kinetic/lib/libopencv_bgsegm3.so.3.1.0
feature_detection: /opt/ros/kinetic/lib/libopencv_aruco3.so.3.1.0
feature_detection: /opt/ros/kinetic/lib/libopencv_viz3.so.3.1.0
feature_detection: /opt/ros/kinetic/lib/libopencv_videostab3.so.3.1.0
feature_detection: /opt/ros/kinetic/lib/libopencv_superres3.so.3.1.0
feature_detection: /opt/ros/kinetic/lib/libopencv_stitching3.so.3.1.0
feature_detection: /opt/ros/kinetic/lib/libopencv_photo3.so.3.1.0
feature_detection: /opt/ros/kinetic/lib/libopencv_text3.so.3.1.0
feature_detection: /opt/ros/kinetic/lib/libopencv_face3.so.3.1.0
feature_detection: /opt/ros/kinetic/lib/libopencv_ximgproc3.so.3.1.0
feature_detection: /opt/ros/kinetic/lib/libopencv_xfeatures2d3.so.3.1.0
feature_detection: /opt/ros/kinetic/lib/libopencv_shape3.so.3.1.0
feature_detection: /opt/ros/kinetic/lib/libopencv_video3.so.3.1.0
feature_detection: /opt/ros/kinetic/lib/libopencv_objdetect3.so.3.1.0
feature_detection: /opt/ros/kinetic/lib/libopencv_calib3d3.so.3.1.0
feature_detection: /opt/ros/kinetic/lib/libopencv_features2d3.so.3.1.0
feature_detection: /opt/ros/kinetic/lib/libopencv_ml3.so.3.1.0
feature_detection: /opt/ros/kinetic/lib/libopencv_highgui3.so.3.1.0
feature_detection: /opt/ros/kinetic/lib/libopencv_videoio3.so.3.1.0
feature_detection: /opt/ros/kinetic/lib/libopencv_imgcodecs3.so.3.1.0
feature_detection: /opt/ros/kinetic/lib/libopencv_imgproc3.so.3.1.0
feature_detection: /opt/ros/kinetic/lib/libopencv_flann3.so.3.1.0
feature_detection: /opt/ros/kinetic/lib/libopencv_core3.so.3.1.0
feature_detection: CMakeFiles/feature_detection.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/erian/opencv_code/feature2d/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable feature_detection"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/feature_detection.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/feature_detection.dir/build: feature_detection

.PHONY : CMakeFiles/feature_detection.dir/build

CMakeFiles/feature_detection.dir/requires: CMakeFiles/feature_detection.dir/src/featrue_detection.cpp.o.requires

.PHONY : CMakeFiles/feature_detection.dir/requires

CMakeFiles/feature_detection.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/feature_detection.dir/cmake_clean.cmake
.PHONY : CMakeFiles/feature_detection.dir/clean

CMakeFiles/feature_detection.dir/depend:
	cd /home/erian/opencv_code/feature2d && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/erian/opencv_code/feature2d /home/erian/opencv_code/feature2d /home/erian/opencv_code/feature2d /home/erian/opencv_code/feature2d /home/erian/opencv_code/feature2d/CMakeFiles/feature_detection.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/feature_detection.dir/depend
