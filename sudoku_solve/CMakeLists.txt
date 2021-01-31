cmake_minimum_required(VERSION 3.17)
project(sodoku)

set(CMAKE_CXX_STANDARD 14)

add_executable(sodoku main.cpp sudoku.cpp sudoku.h)

