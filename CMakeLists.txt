# This file specifies how the project should be built, using CMake.
# If you are unfamiliar with CMake, don't worry about all the details.
# The sections you might want to edit are marked as such, and
# the comments should hopefully make most of it clear.
#
# For many purposes, you may not need to change anything about this file.

cmake_minimum_required(VERSION 3.0.0)

# --------------------------------------------------------------------------------
#                         Locate files (change as needed).
# --------------------------------------------------------------------------------
# Default name for the library built from src/*.cpp (change if you wish)
set(LIBRARY_NAME cpp-template)

# `source` directory
set(SOURCE_DIR
    src
)

# All .cpp files in src/
set(SOURCES
    ${SOURCE_DIR}/Algorithm.cpp
    ${SOURCE_DIR}/main.cpp
)

# Header files directory
set(HEADERS_DIR
    include/${LIBRARY_NAME}
)

# All .h files in include/
set(HEADERS
    ${HEADERS_DIR}/Algorithm.h
)

