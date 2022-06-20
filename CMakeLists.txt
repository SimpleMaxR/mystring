cmake_minimum_required(VERSION 3.20)
project(mystring)

set(CMAKE_CXX_STANDARD 11)

add_executable(mystring main.cpp mystring.cpp mystring.h test.cpp test.h)
