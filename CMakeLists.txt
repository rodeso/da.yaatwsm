cmake_minimum_required(VERSION 3.27)
project(YAATWSM)

set(CMAKE_CXX_STANDARD 17)

add_executable(DA1G195 main.cpp
        src/Menu.cpp
        include/Menu.h
        src/Graph.cpp
        include/Graph.h
        src/ReadFunctions.cpp
        include/ReadFunctions.h
        include/Node.h
        include/Include.h
        src/OperationFunctions.cpp
        include/OperationFunctions.h)
