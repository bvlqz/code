
CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

add_library(Graphs Graph.h Graph.cpp)


add_executable(GraphDemo demo.cpp)

target_link_libraries(GraphDemo PRIVATE Graphs)