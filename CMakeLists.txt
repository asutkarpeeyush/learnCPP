cmake_minimum_required(VERSION 3.10)
project(HelloWorldClion)

set(CMAKE_CXX_STANDARD 11)

add_executable(HelloWorldClion src/main.cpp src/fun.cpp src/Log.cpp src/Log.h)
