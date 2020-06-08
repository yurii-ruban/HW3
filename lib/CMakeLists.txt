cmake_minimum_required(VERSION 3.0.2 FATAL_ERROR)

project(third_parties)

add_library(logger SHARED src/logger.cpp)
target_include_directories(logger PUBLIC include)

add_library(print SHARED src/print.cpp)
target_include_directories(print PUBLIC include)
target_link_libraries(print PUBLIC logger)

add_library(multiplier SHARED src/multiplier.cpp)
target_include_directories(multiplier PUBLIC include)
target_link_libraries(print PUBLIC logger)
