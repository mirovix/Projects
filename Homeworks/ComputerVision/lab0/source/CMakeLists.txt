cmake_minimum_required(VERSION 2.8)
project(lab0)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(lab0 lab0.cpp)

target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})

file(COPY img.png DESTINATION ${CMAKE_BINARY_DIR})
