cmake_minimum_required(VERSION 3.12.3)
project(untitled30)

enable_testing()

set(LINKER_FLAGS2-ISDL2main)
set(LINKER_FLAGS2-ISDL2)

include_directories(googletest/googletest/include)
add_subdirectory(googletest)

set(CMAKE_CXX_STANDARD 17)

add_executable(main main.cpp classes.h)
add_executable(Test tests.cpp classes.h)