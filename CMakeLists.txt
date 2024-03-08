cmake_minimum_required(VERSION 3.27)
project(YAATWSM)

set(CMAKE_CXX_STANDARD 17)

add_executable(DA1G195 main.cpp
        src/Menu.cpp
        src/Menu.h
        src/Graph.cpp
        src/Graph.h
        src/ReadFunctions.cpp
        src/ReadFunctions.h)
