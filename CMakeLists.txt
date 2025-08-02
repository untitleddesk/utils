cmake_minimum_required(VERSION 3.10.0)
project(log VERSION 0.1.0 LANGUAGES CXX)
include(CTest)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(log source/logger.cc)
target_include_directories(log PUBLIC include)

add_subdirectory(test)