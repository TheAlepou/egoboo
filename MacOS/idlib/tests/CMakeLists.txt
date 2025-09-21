# Minimum required CMake version.
cmake_minimum_required (VERSION 3.8)
# Project name and settings.
project(idlib-test CXX)
message("building Idlib Tests")

# 1) sanity: make sure the file exists
if(NOT EXISTS "${CMAKE_CURRENT_LIST_DIR}/buildsystem/set_project_default_properties.cmake")
  message(FATAL_ERROR "Missing: ${CMAKE_CURRENT_LIST_DIR}/buildsystem/set_project_default_properties.cmake")
endif()

# 2) include it (this defines the macro)
include("${CMAKE_CURRENT_LIST_DIR}/buildsystem/set_project_default_properties.cmake")

# 3) now you can call it
set_project_default_properties()

# Include directory locations.
include_directories(${PROJECT_SOURCE_DIR}/../library/src)
include_directories(${PROJECT_SOURCE_DIR})

# Build a list of all tests.
file(GLOB_RECURSE test_files ${PROJECT_SOURCE_DIR}/idlib/tests/*.cpp)

add_executable(idlib-tests-executable ${test_files})
target_link_libraries(idlib-tests-executable idlib-library)
target_link_libraries(idlib-tests-executable GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(idlib-tests-executable)
