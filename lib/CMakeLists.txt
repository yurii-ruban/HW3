cmake_minimum_required(VERSION 3.0.2 FATAL_ERROR)

project(third_parties)

if(USE_STRING_FUNC)
    add_library(print SHARED src/print.cpp)
    target_include_directories(print PUBLIC include)
else()
    add_library(multiplier SHARED src/multiplier.cpp)
    target_include_directories(multiplier PUBLIC include)
endif()



