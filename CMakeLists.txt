cmake_minimum_required(VERSION 3.20)
project(MinimalPartitioner)

find_package(SCOTCH REQUIRED)

link_directories(${SCOTCH_LIBRARY_DIR})
include_directories(${SCOTCH_INCLUDE_DIR})
add_executable(scotch_minimal src/scotch.cpp)

target_link_libraries(scotch_minimal PRIVATE scotch scotcherr)

