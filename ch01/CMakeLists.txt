cmake_minimum_required(VERSION 3.11)

project(
    ch01
    VERSION 0.1
    DESCRIPTION "chapter 01"
    LANGUAGES CXX
)

add_executable(emp_test EmployeeTest.cpp Employee.cpp)
add_executable(db_test DatabaseTest.cpp Database.cpp Employee.cpp)
add_executable(main main.cpp Employee.cpp Database.cpp)

target_compile_options(emp_test PUBLIC -std=c++2a)
target_compile_options(db_test PUBLIC -std=c++2a)
target_compile_options(main PUBLIC -std=c++2a)

include(FetchContent)
FetchContent_Declare(
    Fmt
    GIT_REPOSITORY "https://github.com/fmtlib/fmt"
    GIT_TAG "7.1.3"
)
FetchContent_MakeAvailable(Fmt)

target_link_libraries(emp_test PUBLIC fmt)
target_link_libraries(db_test PUBLIC fmt)
target_link_libraries(main PUBLIC fmt)
set(CMAKE_VERBOSE_MAKEFILE ON)
