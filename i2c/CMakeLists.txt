cmake_minimum_required(VERSION 3.11)

project(i2c VERSION 0.1.0 LANGUAGES C CXX)

add_library(i2c src/i2c.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)