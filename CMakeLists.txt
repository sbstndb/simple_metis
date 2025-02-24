cmake_minimum_required(VERSION 3.20)
project(MetisMinimal)

find_package(SCOTCH REQUIRED)

link_directories(${SCOTCH_LIBRARY_DIR})
include_directories(${SCOTCH_INCLUDE_DIR})
add_executable(metis_minimal src/main.cpp)

target_link_libraries(metis_minimal PRIVATE scotch scotcherr)

