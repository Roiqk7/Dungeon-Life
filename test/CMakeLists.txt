# Date: 24/07/2024
#
# Description: This CMakeLists.txt file is used to build the test executable
# for the project.
#
# Note: This is not intended to be a standalone CMakeLists.txt file.
#
# To build the tests, go into the project's build directory and run:
# ./scripts/build.sh test

# Include the header files from the main include directory and test include directory
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Automatically include all test source files from the test directory
file(GLOB_RECURSE TEST_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

# Define the test executable "Test" and specify the test source files
add_executable(Test ${TEST_SOURCES})

# Define TEST preprocessor macro
target_compile_definitions(Test PRIVATE TEST=1)

# Find and include the Google Test package
find_package(GTest REQUIRED)

# Link the Test executable with the necessary libraries
target_link_libraries(Test PRIVATE ${SDL2_LIBRARIES} ${JSONCPP_LIBRARY} GTest::GTest GTest::Main spdlog::spdlog)

# Add the test to CMake's testing framework
add_test(NAME Test COMMAND Test)