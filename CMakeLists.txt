cmake_minimum_required(VERSION 3.6)
project(connectN)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Game.cpp Game.h PlayerAI.cpp PlayerAI.h PlayerHuman.cpp PlayerHuman.h GameBoard.cpp GameBoard.h)
add_executable(connectN ${SOURCE_FILES})