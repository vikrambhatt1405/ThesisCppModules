cmake_minimum_required(VERSION 3.0)
project(MetisExp)
set(CMAKE_CXX_STANDARD 11)
message(${CMAKE_VERSION})
include_directories(.)
find_package(MPI REQUIRED)
include_directories(${MPI_INCLUDE_PATH})
add_executable(MetisExp
        CMakeLists.txt
        main.cpp adjtocsr.cpp)
target_link_libraries(MetisExp ${MPI_LIBRARIES} libparmetis.a libmetis.a)
if(MPI_COMPILE_FLAGS)
    set_target_properties(MetisExp PROPERTIES
            COMPILE_FLAGS "${MPI_COMPILE_FLAGS}")
endif()

if(MPI_LINK_FLAGS)
    set_target_properties(MetisExp PROPERTIES
            LINK_FLAGS "${MPI_LINK_FLAGS}")
endif()


