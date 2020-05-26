cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(third_parties)

add_library(print SHARED src/print.cpp)
target_include_directories(print PUBLIC include)

add_library(multiplier SHARED src/multiplier.cpp)
target_include_directories(multiplier PUBLIC include)

