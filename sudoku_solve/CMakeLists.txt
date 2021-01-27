cmake_minimum_required(VERSION 3.17)
project(sodoku)

set(CMAKE_CXX_STANDARD 14)

add_executable(sodoku main.cpp sudoku.cpp sudoku.h)


#0 3 0 4 0 9 0 0 7
#0 0 0 0 0 1 0 9 2
#2 0 0 0 0 0 0 0 0
#4 0 2 0 1 5 0 8 0
#0 1 0 0 7 0 3 0 0
#3 0 0 2 4 0 0 7 0
#0 0 7 0 0 0 9 0 0
#5 0 0 0 0 0 0 0 8
#0 0 1 0 5 0 0 3 0