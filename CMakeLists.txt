cmake_minimum_required(VERSION 3.30.0)
project(UDLogger VERSION 4 LANGUAGES CXX)
include(CTest)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(untitledlogger SHARED source/logger.cc)
target_include_directories(untitledlogger PUBLIC include)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CPACK_PACKAGE_VENDOR "untitleddesk")
set(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_SOURCE_DIR}/DESCRIPTION.txt")
set(CPACK_PACKAGE_HOMEPAGE_URL "https://github.com/untitleddesk")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/LICENSE")

# RPM settings

set(CPACK_RPM_PACKAGE_LICENSE "MIT")

install(TARGETS untitledlogger LIBRARY DESTINATION lib)
install(DIRECTORY include/ DESTINATION include/untitled)
install(FILES LICENSE README.md DESTINATION "share/doc/${PROJECT_NAME}")
include(CPack)
add_subdirectory(test)