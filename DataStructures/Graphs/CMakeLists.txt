
CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

add_library(Graphs INTERFACE)

target_include_directories(
    Graphs
    INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(GraphDemo demo.cpp)