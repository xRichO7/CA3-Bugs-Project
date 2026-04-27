cmake_minimum_required(VERSION 4.1)
project(CA3_Bugs_Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CA3_Bugs_Project
        BugsProject.cpp
        BugsProject.h)
