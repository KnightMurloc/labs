project(Catch_tests)

add_compile_options(-Winvalid-pch)

include_directories("../Polynomial_lib")

add_executable(CatchTest_run catch_amalgamated.hpp catch_amalgamated.cpp test3.cpp)
target_link_libraries(CatchTest_run lab_lib)

target_precompile_headers(CatchTest_run PRIVATE catch_amalgamated.hpp)