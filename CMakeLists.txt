cmake_minimum_required(VERSION 3.28)
project(Project_3)

set(CMAKE_CXX_STANDARD 17)

add_executable(Project_3 main.cpp
        Graph.cpp
        Graph.h
        MyVector.cpp
        MyVector.h
        MyStack.cpp
        MyStackNode.cpp
)
