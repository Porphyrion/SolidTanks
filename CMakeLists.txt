cmake_minimum_required(VERSION 3.16)
set(CMAKE_GENERATOR ninja)
project(tank_battle) 

enable_testing()
find_package(GTest REQUIRED)

find_package(Eigen3 3.3 REQUIRED NO_MODULE)

add_executable(tank main.cpp UObject.cpp MovebleAdapter.cpp MoveCommand.cpp) 

add_executable(testik tests/tests.cpp UObject.cpp)
target_link_libraries(testik GTest::GTest GTest::Main)
gtest_discover_tests(testik)

target_link_libraries(tank  Eigen3::Eigen)

set_target_properties(tank testik PROPERTIES 
                        CXX_STANDARD 20
                        CXX_STANDARD_REQUIRED ON)  

             