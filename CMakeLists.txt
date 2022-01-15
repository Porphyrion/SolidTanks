cmake_minimum_required(VERSION 3.16)

set(CMAKE_GENERATOR ninja)
project(tank_battle) 

include(${CMAKE_BINARY_DIR}/conan_paths.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/helper.cmake)

find_package(Boost REQUIRED)
find_package(Eigen3 3.3 REQUIRED NO_MODULE)    

include_directories(${Boost_INCLUDE_DIR})

add_subdirectory(${CMAKE_SOURCE_DIR}/src/)
add_subdirectory(${CMAKE_SOURCE_DIR}/app/)
add_subdirectory(${CMAKE_SOURCE_DIR}/tests/)

set_target_properties(app CoreLib CommandTest PROPERTIES 
                        CXX_STANDARD 20
                        CXX_STANDARD_REQUIRED ON)  

             