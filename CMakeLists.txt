cmake_minimum_required(VERSION 3.13)
project(labs2)

set(CMAKE_CXX_STANDARD 17)

add_executable(labs2 main.cpp Polynomial.cpp Polynomial.h Tests/test.cpp Tests/test.h Tests/Test2.cpp Tests/Test2.h)