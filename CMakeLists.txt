cmake_minimum_required(VERSION 3.0.2 FATAL_ERROR)

project(App)

option(USE_STRING_FUNC "Use print lib instead of multiplier lib" OFF) #OFF by default

set(SOURCES main.cpp)
add_subdirectory(lib)

add_executable(testapp ${SOURCES})
target_include_directories(testapp PUBLIC include)

if(USE_STRING_FUNC)
    add_definitions(-DUSE_STRING_FUNC)
    target_link_libraries(testapp print)
else()
    target_link_libraries(testapp multiplier)

endif(USE_STRING_FUNC)