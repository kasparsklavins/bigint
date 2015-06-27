cmake_minimum_required(VERSION 2.8)
project(bigint)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build")

set(SOURCE_FILES
    bigint.cpp
    bigint.h)

add_executable(bigint ${SOURCE_FILES})