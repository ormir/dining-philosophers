cmake_minimum_required(VERSION 3.21)
project(dining_philosophers)

set(CMAKE_CXX_STANDARD 20)

add_executable(dining_philosophers main.cpp Philosopher.cpp Philosopher.h Fork.cpp Fork.h)
