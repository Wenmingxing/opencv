cmake_minimum_required(VERSION 2.8)
project(highgui)
find_package( OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(trackbar src/trackbar.cpp)
target_link_libraries(trackbar ${OpenCV_LIBS})

