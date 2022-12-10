message(STATUS "Adding tests under ${CMAKE_PROJECT_SOURCE_DIR}/tests...")

# TODO: add all test .cpp files
set(TEST_SOURCES
    test_adder.cpp
)

# Locate GTest
find_package(GTest REQUIRED)

# Check if GoogleMock needs to be used
if(${CMAKE_PROJECT_NAME}_USE_GOOGLE_MOCK)
  set(GOOGLE_MOCK_LIBRARIES GTest::gmock GTest::gmock_main)
endif()

# Setup code coverage if enabled
if (${CMAKE_PROJECT_NAME}_ENABLE_CODE_COVERAGE)
  target_compile_options(${LIBRARY_NAME} PUBLIC -O0 -g -fprofile-arcs -ftest-coverage)
  target_link_options(${LIBRARY_NAME} PUBLIC -fprofile-arcs -ftest-coverage)
  verbose_message("Code coverage is enabled and provided with GCC.")
endif()

# Loop over each test source file
foreach(file ${TEST_SOURCES})

  # test_*.cpp --> test_* (name of test executable)
  string(REGEX REPLACE "[.]cpp" "" test_name ${file})
  add_executable(${test_name} ${file})

  # Set the compiler standard
  target_compile_features(${test_name} PUBLIC cxx_std_17)
  if(${CMAKE_PROJECT_NAME}_USE_GTEST)
    target_link_libraries(
      ${test_name}
      PUBLIC
        GTest::GTest
        GTest::Main
        ${GOOGLE_MOCK_LIBRARIES}
        ${LIBRARY_NAME}
    )
  else()
    message(FATAL_ERROR "Unknown testing library. Please setup your desired unit testing library by using `target_link_libraries`.")  
  endif()

  # Add the unit tests
  add_test(
    NAME
      ${test_name}
    COMMAND
      ${test_name}
  )
endforeach()

verbose_message("Finished adding unit tests for ${CMAKE_PROJECT_NAME}.\n")
