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
CMAKE_SOURCE_DIR = /home/erian/opencv_code/DisplayImage

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/erian/opencv_code/DisplayImage

# Include any dependencies generated for this target.
include CMakeFiles/cvt_gray_image.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cvt_gray_image.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cvt_gray_image.dir/flags.make

CMakeFiles/cvt_gray_image.dir/src/cvt_gray_image.cpp.o: CMakeFiles/cvt_gray_image.dir/flags.make
CMakeFiles/cvt_gray_image.dir/src/cvt_gray_image.cpp.o: src/cvt_gray_image.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/erian/opencv_code/DisplayImage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cvt_gray_image.dir/src/cvt_gray_image.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cvt_gray_image.dir/src/cvt_gray_image.cpp.o -c /home/erian/opencv_code/DisplayImage/src/cvt_gray_image.cpp

CMakeFiles/cvt_gray_image.dir/src/cvt_gray_image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cvt_gray_image.dir/src/cvt_gray_image.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/erian/opencv_code/DisplayImage/src/cvt_gray_image.cpp > CMakeFiles/cvt_gray_image.dir/src/cvt_gray_image.cpp.i

CMakeFiles/cvt_gray_image.dir/src/cvt_gray_image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cvt_gray_image.dir/src/cvt_gray_image.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/erian/opencv_code/DisplayImage/src/cvt_gray_image.cpp -o CMakeFiles/cvt_gray_image.dir/src/cvt_gray_image.cpp.s

CMakeFiles/cvt_gray_image.dir/src/cvt_gray_image.cpp.o.requires:

.PHONY : CMakeFiles/cvt_gray_image.dir/src/cvt_gray_image.cpp.o.requires

CMakeFiles/cvt_gray_image.dir/src/cvt_gray_image.cpp.o.provides: CMakeFiles/cvt_gray_image.dir/src/cvt_gray_image.cpp.o.requires
	$(MAKE) -f CMakeFiles/cvt_gray_image.dir/build.make CMakeFiles/cvt_gray_image.dir/src/cvt_gray_image.cpp.o.provides.build
.PHONY : CMakeFiles/cvt_gray_image.dir/src/cvt_gray_image.cpp.o.provides

CMakeFiles/cvt_gray_image.dir/src/cvt_gray_image.cpp.o.provides.build: CMakeFiles/cvt_gray_image.dir/src/cvt_gray_image.cpp.o


# Object files for target cvt_gray_image
cvt_gray_image_OBJECTS = \
"CMakeFiles/cvt_gray_image.dir/src/cvt_gray_image.cpp.o"

# External object files for target cvt_gray_image
cvt_gray_image_EXTERNAL_OBJECTS =

cvt_gray_image: CMakeFiles/cvt_gray_image.dir/src/cvt_gray_image.cpp.o
cvt_gray_image: CMakeFiles/cvt_gray_image.dir/build.make
cvt_gray_image: /opt/ros/kinetic/lib/libopencv_xphoto3.so.3.1.0
cvt_gray_image: /opt/ros/kinetic/lib/libopencv_xobjdetect3.so.3.1.0
cvt_gray_image: /opt/ros/kinetic/lib/libopencv_tracking3.so.3.1.0
cvt_gray_image: /opt/ros/kinetic/lib/libopencv_surface_matching3.so.3.1.0
cvt_gray_image: /opt/ros/kinetic/lib/libopencv_structured_light3.so.3.1.0
cvt_gray_image: /opt/ros/kinetic/lib/libopencv_stereo3.so.3.1.0
cvt_gray_image: /opt/ros/kinetic/lib/libopencv_saliency3.so.3.1.0
cvt_gray_image: /opt/ros/kinetic/lib/libopencv_rgbd3.so.3.1.0
cvt_gray_image: /opt/ros/kinetic/lib/libopencv_reg3.so.3.1.0
cvt_gray_image: /opt/ros/kinetic/lib/libopencv_plot3.so.3.1.0
cvt_gray_image: /opt/ros/kinetic/lib/libopencv_optflow3.so.3.1.0
cvt_gray_image: /opt/ros/kinetic/lib/libopencv_line_descriptor3.so.3.1.0
cvt_gray_image: /opt/ros/kinetic/lib/libopencv_hdf3.so.3.1.0
cvt_gray_image: /opt/ros/kinetic/lib/libopencv_fuzzy3.so.3.1.0
cvt_gray_image: /opt/ros/kinetic/lib/libopencv_dpm3.so.3.1.0
cvt_gray_image: /opt/ros/kinetic/lib/libopencv_dnn3.so.3.1.0
cvt_gray_image: /opt/ros/kinetic/lib/libopencv_datasets3.so.3.1.0
cvt_gray_image: /opt/ros/kinetic/lib/libopencv_cvv3.so.3.1.0
cvt_gray_image: /opt/ros/kinetic/lib/libopencv_ccalib3.so.3.1.0
cvt_gray_image: /opt/ros/kinetic/lib/libopencv_bioinspired3.so.3.1.0
cvt_gray_image: /opt/ros/kinetic/lib/libopencv_bgsegm3.so.3.1.0
cvt_gray_image: /opt/ros/kinetic/lib/libopencv_aruco3.so.3.1.0
cvt_gray_image: /opt/ros/kinetic/lib/libopencv_viz3.so.3.1.0
cvt_gray_image: /opt/ros/kinetic/lib/libopencv_videostab3.so.3.1.0
cvt_gray_image: /opt/ros/kinetic/lib/libopencv_superres3.so.3.1.0
cvt_gray_image: /opt/ros/kinetic/lib/libopencv_stitching3.so.3.1.0
cvt_gray_image: /opt/ros/kinetic/lib/libopencv_photo3.so.3.1.0
cvt_gray_image: /opt/ros/kinetic/lib/libopencv_text3.so.3.1.0
cvt_gray_image: /opt/ros/kinetic/lib/libopencv_face3.so.3.1.0
cvt_gray_image: /opt/ros/kinetic/lib/libopencv_ximgproc3.so.3.1.0
cvt_gray_image: /opt/ros/kinetic/lib/libopencv_xfeatures2d3.so.3.1.0
cvt_gray_image: /opt/ros/kinetic/lib/libopencv_shape3.so.3.1.0
cvt_gray_image: /opt/ros/kinetic/lib/libopencv_video3.so.3.1.0
cvt_gray_image: /opt/ros/kinetic/lib/libopencv_objdetect3.so.3.1.0
cvt_gray_image: /opt/ros/kinetic/lib/libopencv_calib3d3.so.3.1.0
cvt_gray_image: /opt/ros/kinetic/lib/libopencv_features2d3.so.3.1.0
cvt_gray_image: /opt/ros/kinetic/lib/libopencv_ml3.so.3.1.0
cvt_gray_image: /opt/ros/kinetic/lib/libopencv_highgui3.so.3.1.0
cvt_gray_image: /opt/ros/kinetic/lib/libopencv_videoio3.so.3.1.0
cvt_gray_image: /opt/ros/kinetic/lib/libopencv_imgcodecs3.so.3.1.0
cvt_gray_image: /opt/ros/kinetic/lib/libopencv_imgproc3.so.3.1.0
cvt_gray_image: /opt/ros/kinetic/lib/libopencv_flann3.so.3.1.0
cvt_gray_image: /opt/ros/kinetic/lib/libopencv_core3.so.3.1.0
cvt_gray_image: CMakeFiles/cvt_gray_image.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/erian/opencv_code/DisplayImage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable cvt_gray_image"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cvt_gray_image.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cvt_gray_image.dir/build: cvt_gray_image

.PHONY : CMakeFiles/cvt_gray_image.dir/build

CMakeFiles/cvt_gray_image.dir/requires: CMakeFiles/cvt_gray_image.dir/src/cvt_gray_image.cpp.o.requires

.PHONY : CMakeFiles/cvt_gray_image.dir/requires

CMakeFiles/cvt_gray_image.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cvt_gray_image.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cvt_gray_image.dir/clean

CMakeFiles/cvt_gray_image.dir/depend:
	cd /home/erian/opencv_code/DisplayImage && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/erian/opencv_code/DisplayImage /home/erian/opencv_code/DisplayImage /home/erian/opencv_code/DisplayImage /home/erian/opencv_code/DisplayImage /home/erian/opencv_code/DisplayImage/CMakeFiles/cvt_gray_image.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cvt_gray_image.dir/depend

