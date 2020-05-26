# Homework Task 3

This is the program, that use 2 shared libraries and optionally call the functions depending on passed to compiler parameters.
Technologies: C++, CMake

## How to check

To run the program `cd` to root of the repository and create `build` folder. Then:
1. `cmake -H. -Bbuild -DUSE_STRING_FUNC` 
2. `cmake --build build`
3. `./build/testapp`
