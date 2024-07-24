# Specify the minimum version for CMake and the project's name
cmake_minimum_required(VERSION 3.10)
project(DungeonLife VERSION 1.0)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)

# Option to toggle development mode
option(DEVELOPMENT "Build the project in development mode" OFF)
message(STATUS "Development mode: ${DEVELOPMENT}")

# Option to build tests
option(TEST "Build tests" OFF)
message(STATUS "Build tests: ${TEST}")

# Add the main executable
add_executable(DungeonLife src/dungeonLife.cpp)

# Include directories
target_include_directories(DungeonLife PUBLIC "include/")

# External dependencies
# Add SDL2
find_package(SDL2 REQUIRED)
target_include_directories(DungeonLife PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(DungeonLife PRIVATE ${SDL2_LIBRARIES})

# Add JsonCpp
find_library(JSONCPP_LIBRARY jsoncpp)
target_include_directories(DungeonLife PRIVATE ${JSONCPP_INCLUDE_DIR})
target_link_libraries(DungeonLife PRIVATE ${JSONCPP_LIBRARY})

# Add source files
file(GLOB_RECURSE PROJECT_SOURCES "src/*.cpp")
# Exclude main file to avoid duplication
list(REMOVE_ITEM PROJECT_SOURCES "src/dungeonLife.cpp")
target_sources(DungeonLife PRIVATE ${PROJECT_SOURCES})

# Conditionally include spdlog in development mode
if(DEVELOPMENT)
        # Add spdlog
        find_package(spdlog REQUIRED)
        target_link_libraries(DungeonLife PRIVATE spdlog::spdlog)
        # Define DEVELOPMENT preprocessor macro
        target_compile_definitions(DungeonLife PRIVATE DEVELOPMENT=1)
endif()

# Conditionally build tests
if(TEST)
        enable_testing()

        # Automatically include all test source files from the test directory
        file(GLOB_RECURSE TEST_SOURCES "test/*.cpp")

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
endif()