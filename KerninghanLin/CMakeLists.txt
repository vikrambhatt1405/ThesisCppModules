cmake_minimum_required(VERSION 3.15)

project(KerninghanLin CXX)

set(CMAKE_CXX_STANDARD 11)

add_executable(KerninghanLin main.cpp
        adjtocsr.cpp
        assert_bisection_valid.cpp
        random_bisection.cpp
        routines.h
        compute_gains.cpp
        partition_cost.cpp weight.cpp update_gains.cpp maximum_gain_swaps.cpp validate_gains.cpp)