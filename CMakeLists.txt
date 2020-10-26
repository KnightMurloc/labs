cmake_minimum_required(VERSION 3.13)
project(labs2)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(Polynomial_lib)
add_subdirectory(Test)
add_subdirectory(Test2)

add_executable(start main.cpp)
target_include_directories(start PRIVATE Polynomial_lib/)
target_link_libraries(start lab_lib)