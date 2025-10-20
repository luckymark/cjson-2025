cmake_minimum_required(VERSION 3.29)
project(json_parse)

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME} parser_test.cpp parse.cpp)
