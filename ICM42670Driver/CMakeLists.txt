cmake_minimum_required(VERSION 3.11)

project(ICM42670Driver VERSION 0.1.0 LANGUAGES C CXX)

add_library(ICM42670Driver src/ICM42670Driver.cpp)

target_link_libraries(ICM42670Driver PRIVATE i2c)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)

