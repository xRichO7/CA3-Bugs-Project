cmake_minimum_required(VERSION 3.10)
project(CA3_Bugs_Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CA3_Bugs_Project
        main.cpp
        Bug.cpp
        Crawler.cpp
        Hopper.cpp
        Scorpion.cpp
        Board.cpp)