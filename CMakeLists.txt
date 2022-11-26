# This file specifies how the project should be built, using CMake.
# If you are unfamiliar with CMake, don't worry about all the details.
# The sections you might want to edit are marked as such, and
# the comments should hopefully make most of it clear.
#
# For many purposes, you may not need to change anything about this file.

cmake_minimum_required(VERSION 3.0.0)

# --------------------------------------------------------------------------------
#                 Set variables needed for build (change as needed).
# --------------------------------------------------------------------------------

# TODO: Change project name
set(PROJECT_NAME "cpp-template" VERSION 0.1.0 LANGUAGES CXX)

# TODO: Change library name; same as project name
set(LIBRARY_NAME cpp-template)

set(HEADERS_DIR
    include/${LIBRARY_NAME}
)
set(HEADERS
    ${HEADERS_DIR}/Algorithm.h
)
set(SOURCE_DIR
    src
)
set(SOURCE
    ${SOURCE_DIR}/Algorithm.cpp
)

# --------------------------------------------------------------------------------
#                            Build! (Change as needed)
# --------------------------------------------------------------------------------

project(${PROJECT_NAME})

add_library(${LIBRARY_NAME} STATIC
    ${HEADERS}
    ${SOURCE}
)

# When used internally, import Algorithm.h as #include "Algorithm.h"
target_include_directories(${LIBRARY_NAME} PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/${LIBRARY_NAME}>
    $<INSTALL_INTERFACE:include/${LIBRARY_NAME}>
)

# When used externally, import Algorithm.h as #include <cpp-template/Algorithm.h>
target_include_directories(${LIBRARY_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# Name of executable and location of file.
add_executable(bin_main ${SOURCE_DIR}/main.cpp)

# Link the executable to library (if it uses it).
target_link_libraries(bin_main
    PRIVATE
        ${LIBRARY_NAME}
)

# Set the properties you require, e.g. what C++ standard to use.
# Here applied to library and main (change as needed).
set_target_properties(
    ${LIBRARY_NAME} bin_main
      PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED YES
)
