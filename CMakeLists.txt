cmake_minimum_required(VERSION 3.10.0)
project(untitledmath VERSION 0.1.0 LANGUAGES CXX)
enable_testing()

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_library(untitledmath SHARED
            source/objects.cc
            source/functions.cc)

target_include_directories(untitledmath PUBLIC include include/math)


add_subdirectory(tests)