cmake_minimum_required(VERSION 3.11)
project(ICM42670 LANGUAGES C CXX)

add_subdirectory(apps)
add_subdirectory(ICM42670Driver)

include(CTest)
enable_testing()

