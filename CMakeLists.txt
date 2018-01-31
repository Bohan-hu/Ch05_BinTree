cmake_minimum_required(VERSION 3.8)
project(Ch05_BinTree)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp BinNode.h)
add_executable(Ch05_BinTree ${SOURCE_FILES} main.cpp BinNode.h)