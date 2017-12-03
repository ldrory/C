cmake_minimum_required(VERSION 3.8)
project(Ex3)

set(CMAKE_C_STANDARD 99)
set(SOURCE_FILES GenericHashTable.c GenericHashTable.h)
add_library(Ex3 ${SOURCE_FILES})