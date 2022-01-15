enable_testing()
find_package(GTest REQUIRED)

find_src(CommandTest tests)

add_executable(CommandTest  ${CommandTest_SOURCES})
target_link_libraries(CommandTest CoreLib gtest gtest_main gmock gmock_main Eigen3::Eigen)

gtest_discover_tests(CommandTest)