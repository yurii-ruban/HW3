cmake_minimum_required(VERSION 3.0.2 FATAL_ERROR)

project(App)

set(SOURCES main.cpp)
add_subdirectory(lib)

add_executable(testapp ${SOURCES})
target_include_directories(testapp PUBLIC include)

target_link_libraries(testapp print)
target_link_libraries(testapp multiplier)
target_link_libraries(testapp matrix)
