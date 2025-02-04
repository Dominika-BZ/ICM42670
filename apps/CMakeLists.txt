cmake_minimum_required(VERSION 3.11)
project(ICM42670 VERSION 0.1.0 LANGUAGES C CXX)

add_executable(main main.cpp)

target_link_libraries(main PRIVATE ICM42670Driver)
target_link_libraries(main PRIVATE i2c)

target_include_directories(main PUBLIC ${PROJECT_SOURCE_DIR}/include)

include(CTest)
enable_testing()

