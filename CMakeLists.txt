cmake_minimum_required(VERSION 3.20)
project(rstats_cxx)

set(CMAKE_CXX_STANDARD 14)

add_executable(rstats_cxx main.cpp Stats.cpp Stats.h)
