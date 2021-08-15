project(Dodecahedron_Bigint CXX)

cmake_minimum_required(VERSION 3.10)

add_library(Dodecahedron_Bigint src/bigint.h src/bigint.cpp)
target_include_directories(Dodecahedron_Bigint PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

project(bigint_tests)
add_executable(bigint_tests src/tests/main.cpp)
target_link_libraries(bigint_tests PUBLIC Dodecahedron_Bigint)
target_include_directories(bigint_tests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/tests)
