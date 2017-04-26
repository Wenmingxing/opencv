cmake_minimum_required(VERSION 2.8)
project (feature2d)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(harris_corner src/harris_corner.cpp)
add_executable(shi_tomasi_corner src/shi_tomasi_corner.cpp)
add_executable(cornersubpix src/cornersubpix.cpp)
#add_executable(feature_detection src/featrue_detection.cpp)

#target_link_libraries(feature_detection ${OpenCV_LIBS})
target_link_libraries(cornersubpix ${OpenCV_LIBS})
target_link_libraries(shi_tomasi_corner ${OpenCV_LIBS})
target_link_libraries(harris_corner ${OpenCV_LIBS})
