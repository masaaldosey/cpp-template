add_library(${LIBRARY_NAME} plus_one.cpp)

target_include_directories(adder PUBLIC ${PROJECT_SOURCE_DIR}/include)


# Set the properties you require, e.g. what C++ standard to use.
# Here applied to library and main (change as needed).
set_target_properties(
    ${LIBRARY_NAME}
      PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED YES
)
