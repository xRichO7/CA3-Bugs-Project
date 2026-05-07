cmake_minimum_required(VERSION 4.1)
project(Bugs_Report_CA3)

set(CMAKE_CXX_STANDARD 20)

add_executable(Bugs_Report_CA3 main.cpp
        Board/Board.cpp
        Board/Board.h
        Bugs/Bug.cpp
        Bugs/Bug.h
        Bugs/Crawler.cpp
        Bugs/Crawler.h
        Bugs/Hopper.cpp
        Bugs/Hopper.h
        Bugs/Scorpion.cpp
        Bugs/Scorpion.h)
