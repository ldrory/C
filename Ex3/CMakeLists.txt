cmake_minimum_required(VERSION 3.8)
project(Ex3Str)
project(Ex3Int)

set(CMAKE_C_STANDARD 99)
set(SOURCE_FILES_STR HashStrSearch.c MyStringFunctions.c MyStringFunctions.h GenericHashTable.c GenericHashTable.h key.h TableErrorHandle.c TableErrorHandle.h)
set(SOURCE_FILES_INT HashIntSearch.c MyIntFunctions.c MyIntFunctions.h GenericHashTable.c GenericHashTable.h key.h TableErrorHandle.c TableErrorHandle.h)

#add_library(Ex3 ${SOURCE_FILES})
add_executable(Ex3Str ${SOURCE_FILES_STR})
add_executable(Ex3Int ${SOURCE_FILES_INT})