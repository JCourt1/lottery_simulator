cmake_minimum_required(VERSION 3.13)
project(lottery_simulator)

set(CMAKE_CXX_STANDARD 11)
add_definitions("-std=c++11")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(lottery_simulator main.cpp LotteryLogic.cpp PrizeProbabilities.cpp)
target_link_libraries(lottery_simulator ${CONAN_LIBS})
