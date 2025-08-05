cmake_minimum_required(VERSION 3.30.0)
project(untitledutils VERSION 4 LANGUAGES CXX)
include(CTest)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE source/logger.cc)

add_library(untitledutils SHARED ${SOURCE})
target_include_directories(untitledutils PUBLIC include)

add_subdirectory(test)