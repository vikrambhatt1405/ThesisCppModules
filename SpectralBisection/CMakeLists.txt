cmake_minimum_required(VERSION 3.15)
project(SpectralBisection)

set(CMAKE_CXX_STANDARD 17)
add_executable(SpectralBisection main.cpp adjtocsr.cpp routines.h algebraic_connectivity.cpp process_mem_usage.cpp)
target_link_libraries(SpectralBisection libmetis.a)
