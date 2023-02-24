cmake_minimum_required(VERSION 3.19)
project(guess_the_number)

set(CMAKE_CXX_STANDARD 11)

add_executable(guess_the_number main.cpp helpers.cpp helpers.h)