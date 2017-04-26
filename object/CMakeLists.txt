cmake_minimum_required(VERSION 2.8)
project(object)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(cascade_classfier src/cascade_classier.cpp)

target_link_libraries(cascade_classfier ${OpenCV_LIBS})
