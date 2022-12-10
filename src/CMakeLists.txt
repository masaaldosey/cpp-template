add_library(${LIBRARY_NAME} plus_one.cpp)

# Builds interface to avoid having paths while
# installing the library for downstream use
target_include_directories(${LIBRARY_NAME} PUBLIC  
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include/>  
    $<INSTALL_INTERFACE:include/>
)

# Set the properties you require, e.g. what C++ standard to use.
# Here applied to library and main (change as needed).
set_target_properties(
    ${LIBRARY_NAME}
      PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED YES
)
