cmake_minimum_required(VERSION 3.16)
set(CMAKE_GENERATOR ninja)
project(tank_battle) 

enable_testing()
find_package(GTest REQUIRED)

find_package(Eigen3 3.3 REQUIRED NO_MODULE)

set(SOURCE
   ${SOURCE}
   ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_library(UObjectLib ./src/UObject.cpp ./src/MoveCommand.cpp ./src/MovebleAdapter.cpp ./src/RotateCommand.cpp ./src/RotableAdapter.cpp)
target_link_libraries(UObjectLib Eigen3::Eigen)

add_executable(tanks ./src/main.cpp) 
target_link_libraries(tanks UObjectLib )

add_executable(uobject_tests tests/tests.cpp )
target_link_libraries(uobject_tests UObjectLib GTest::GTest GTest::Main Eigen3::Eigen)
gtest_discover_tests(uobject_tests)


set_target_properties(tanks UObjectLib uobject_tests PROPERTIES 
                        CXX_STANDARD 20
                        CXX_STANDARD_REQUIRED ON)  

             