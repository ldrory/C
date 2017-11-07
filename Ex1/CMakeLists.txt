cmake_minimum_required(VERSION 3.8)
project(Ex1)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES library.c library.h)
add_library(Ex1 ${SOURCE_FILES})