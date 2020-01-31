cmake_minimum_required(VERSION 3.15)
project(FiedlerValueCalculation)

set(CMAKE_CXX_STANDARD 14)
include_directories(/opt/slate/include)
link_directories(/opt/slate/lib)
add_executable(
        FiedlerValueCalculation
        main.cpp
        adjtocsr.cpp
        routines.h
        assert_bisection_valid.cpp
        random_bisection.cpp
        partition_cost.cpp calculate_fiedler_values.cpp)
target_link_libraries(FiedlerValueCalculation /usr/lib/libarmadillo.so.9)