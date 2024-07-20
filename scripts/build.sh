#!/bin/bash

# Exit immediately if a command exits with a non-zero status.
set -e

# Save the current directory
original_dir=$(pwd)

# Create a build directory if it doesn't exist
if [ ! -d "build" ]; then
        echo "Creating build directory..."
        mkdir build
fi

# Initialize CMake flags
cmake_flags=""

# Parse arguments
for arg in "$@"
do
        # Check the argument(s) passed to the script
        case $arg in
                dev)
                        echo "Configuring the project with CMake in development mode..."
                        cmake_flags+="-DDEVELOPMENT=ON "
                        ;;
                test)
                        echo "Configuring the project with CMake for testing..."
                        cmake_flags+="-DTEST=ON "
                        ;;
                *)
                        # Handle unknown options
                        echo "Unknown option: $arg"
                        ;;
        esac
done

# If no flags were added, configure in release mode by default
if [ -z "$cmake_flags" ]; then
        echo "Configuring the project with CMake in release mode..."
        cmake_flags="-DDEVELOPMENT=OFF -DTEST=OFF"
fi

# Configure the project with CMake
cmake .. $cmake_flags

echo "Building the project..."

# Build the project
make

# Move back to the original directory after building
echo "Moving back to the original directory..."
cd "$original_dir"