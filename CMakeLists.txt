cmake_minimum_required(VERSION 3.13)
project(lottery_simulator)

set(CMAKE_CXX_STANDARD 11)

add_executable(lottery_simulator main.cpp util.cpp util.h)