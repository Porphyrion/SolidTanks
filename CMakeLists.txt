cmake_minimum_required(VERSION 3.16)
set(CMAKE_GENERATOR ninja)
project(tank_battle) 

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

enable_testing()
find_package(GTest REQUIRED)

set(SOURCE
   ${SOURCE}
   ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_library(UObjectLib ./src/UObject.cpp ./src/MoveCommand.cpp ./src/MovebleAdapter.cpp ./src/RotateCommand.cpp ./src/RotableAdapter.cpp)
target_link_libraries(UObjectLib CONAN_PKG::eigen)

add_executable(tanks ./src/main.cpp) 
target_link_libraries(tanks UObjectLib )

add_executable(uobject_tests tests/tests.cpp )
target_link_libraries(uobject_tests UObjectLib GTest::GTest GTest::Main CONAN_PKG::eigen)
gtest_discover_tests(uobject_tests)


set_target_properties(tanks UObjectLib uobject_tests PROPERTIES 
                        CXX_STANDARD 20
                        CXX_STANDARD_REQUIRED ON)  

             