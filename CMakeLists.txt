# This file specifies how the project should be built, using CMake.
# If you are unfamiliar with CMake, don't worry about all the details.
# The sections you might want to edit are marked as such, and
# the comments should hopefully make most of it clear.
#
# For many purposes, you may not need to change anything about this file.

cmake_minimum_required(VERSION 3.15.0..3.24.0)

include(cmake/StaticAnalyzers.cmake)
include(cmake/Utils.cmake)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release")
endif()


# --------------------------------------------------------------------------------
#                 Set variables needed for build (change as needed).
# --------------------------------------------------------------------------------

# TODO: Change project name
project("cpp-template" VERSION 0.2.0 LANGUAGES CXX)
# Library name can be same as project name
set(LIBRARY_NAME adder)

message(STATUS "Started CMake for ${PROJECT_NAME} v${PROJECT_VERSION}...\n")

# TODO: Various options for the project. Can be toggled ON/OFF as needed.
option(${PROJECT_NAME}_ENABLE_CLANG_TIDY "Enable static analysis with Clang-Tidy." ON)
option(${PROJECT_NAME}_VERBOSE_OUTPUT "Enable verbose output, allowing for a better understanding of each step taken." ON)
option(${PROJECT_NAME}_BUILD_EXAMPLES "Generate executables of the examples (from the `examples` subdirectory)." ON)
option(${PROJECT_NAME}_ENABLE_UNIT_TESTING "Enable unit tests for the projects (from the `tests` subdirectory)." ON)
option(${PROJECT_NAME}_ENABLE_CODE_COVERAGE "Enable code coverage through GCC." OFF)
option(${PROJECT_NAME}_USE_GTEST "Use the GoogleTest project for creating unit tests." ON)
option(${PROJECT_NAME}_USE_GOOGLE_MOCK "Use the GoogleMock project for extending the unit tests." OFF)


# Compile the library
add_subdirectory(src)
message(STATUS "Successfully added all dependencies and linked against them.")

# Check if executables of the examples need to be generated
if(${PROJECT_NAME}_BUILD_EXAMPLES)
  verbose_message("Executables of the examples will be generated.\n")
  add_subdirectory(examples)
endif()

if(${PROJECT_NAME}_ENABLE_UNIT_TESTING)
  enable_testing()
  verbose_message("TESTING is enabled for the project.")
  add_subdirectory(tests)
endif()
