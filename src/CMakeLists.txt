find_src(CoreLib src)

add_library(CoreLib ${CoreLib_SOURCES}) 
target_link_libraries(CoreLib Eigen3::Eigen Boost::atomic)