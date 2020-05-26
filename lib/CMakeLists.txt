cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(third_parties)

set(INCLUDES
    header/print.h
    header/multiplier.h)

add_library(print SHARED src/print.cpp)
add_library(multiplier SHARED src/multiplier.cpp)

install(TARGETS print DESTINATION ${CMAKE_SOURCE_DIR}/lib)
install(TARGETS multiplier DESTINATION ${CMAKE_SOURCE_DIR}/lib)

install(FILES ${INCLUDES} DESTINATION ${CMAKE_SOURCE_DIR}/lib/include)
