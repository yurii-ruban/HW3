cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(App)

option(USE_STRING_FUNC "Use MY_LIB instead of THEIR_LIB" OFF) #OFF by default
if(USE_STRING_FUNC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DUSE_STRING_FUNC")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
endif(USE_STRING_FUNC)
unset(USE_STRING_FUNC CACHE)

set(SOURCES main.cpp)
add_subdirectory(lib)

add_executable(testapp ${SOURCES})
target_link_libraries(testapp print)
target_link_libraries(testapp multiplier)
install(TARGETS testapp DESTINATION bin)
