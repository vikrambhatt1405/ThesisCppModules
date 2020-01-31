cmake_minimum_required(VERSION 3.15)
project(HeuristicAlgorithm)

set(CMAKE_CXX_STANDARD 14)

add_executable(HeuristicAlgorithm main.cpp
        adjtocsr.cpp
        assert_bisection_valid.cpp
        random_bisection.cpp
        compute_gains.cpp
        partition_cost.cpp weight.cpp
        update_gains.cpp
        maximum_gain_swaps.cpp
        validate_gains.cpp
        calculate_fiedler_values.cpp
        routines.h)

target_link_libraries(HeuristicAlgorithm /usr/local/lib/libmetis.a)
target_link_libraries(HeuristicAlgorithm /usr/lib/libarmadillo.so.9)