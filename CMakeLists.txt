cmake_minimum_required(VERSION 3.6)
project(connectN)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Node.cpp Node.h Tree.cpp Tree.h)
add_executable(connectN ${SOURCE_FILES})