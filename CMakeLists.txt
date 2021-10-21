cmake_minimum_required(VERSION 3.16)
set(CMAKE_GENERATOR ninja)
project(tank_battle) 

# enable_testing()
# find_package(GTest REQUIRED)

add_library(uobject UObject.cpp)

add_executable(tank main.cpp)

target_link_libraries(tank uobject)

set_target_properties(tank uobject PROPERTIES 
                        CXX_STANDARD 20
                        CXX_STANDARD_REQUIRED ON)   
                        