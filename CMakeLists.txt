cmake_minimum_required(VERSION 3.8)
project(lab6AllFiles)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        ArrayList.h ArrayLib.h
        Lab6Tester.cpp ArrayList.cpp ArrayLib.cpp)

add_executable(lab6AllFiles ${SOURCE_FILES})