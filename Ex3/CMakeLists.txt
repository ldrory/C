cmake_minimum_required(VERSION 3.8)
project(Ex3)

set(CMAKE_C_STANDARD 99)
set(SOURCE_FILES HashIntSearch.c MyIntFunctions.c MyIntFunctions.h GenericHashTable.c GenericHashTable.h key.h TableErrorHandle.c TableErrorHandle.h)

#add_library(Ex3 ${SOURCE_FILES})
add_executable(Ex3 ${SOURCE_FILES})