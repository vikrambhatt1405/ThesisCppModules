cmake_minimum_required(VERSION 3.15)

project(SimulatedAnnealing CXX)

set(CMAKE_CXX_STANDARD 11)

add_executable(SimulatedAnnealing main.cpp adjtocsr.cpp
        maximum_gain_swaps.cpp
        random_bisection.cpp partition_cost.cpp
        assert_bisection_valid.cpp weight.cpp
        routines.h random_movement.cpp f.cpp)