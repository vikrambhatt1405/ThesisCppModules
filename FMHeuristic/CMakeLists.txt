cmake_minimum_required(VERSION 3.15)

project(FMHeuristic CXX)

set(CMAKE_CXX_STANDARD 11)

add_executable(FMHeuristic main.cpp adjtocsr.cpp
        partition_cost.cpp
        maximum_gain_swaps.cpp update_gains.cpp
        validate_gains.cpp random_bisection.cpp
        assert_bisection_valid.cpp
        routines.h create_gains_table.cpp doubly_linked_list.h assert_valid_tables.cpp update_partx.cpp update_party.cpp remove_node.cpp choose_maxgain_vtx.cpp)