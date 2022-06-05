cmake_minimum_required(VERSION 3.20)
project(mystring)

set(CMAKE_CXX_STANDARD 11)

add_executable(mystring main.cpp basic.cpp basic.h mystring.cpp mystring.h funcionForTest.cpp test.cpp test.h)
