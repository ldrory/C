cmake_minimum_required(VERSION 3.8)
project(Ex2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        .idea/Ex2.iml
        .idea/misc.xml
        .idea/modules.xml
        .idea/workspace.xml
        MyString.c
        MyString.h)

add_executable(Ex2 ${SOURCE_FILES})