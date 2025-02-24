cmake_minimum_required(VERSION 3.20)
project(MetisMinimal)

find_package(SCOTCH)

include_directories(${SCOTCH_INCLUDE_DIR})
add_executable(metis_minimal src/main.cpp)



