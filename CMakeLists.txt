cmake_minimum_required(VERSION 2.8)

add_library(Dodecahedron_Bigint src/bigint.h src/bigint.cpp)
target_include_directories(Dodecahedron_Bigint PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)