cmake_minimum_required(VERSION 3.16)
set(CMAKE_GENERATOR ninja)
project(tank_battle) 

enable_testing()
find_package(GTest REQUIRED)

add_executable(tank main.cpp)

set_target_properties(tank  PROPERTIES 
                        CXX_STANDARD 17
                        CXX_STANDARD_REQUIRED ON)   
                        