#!/bin/bash

# Exit immediately if a command exits with a non-zero status.
set -e

echo "Initializing the project..."

# Make all the scripts executable
chmod +x scripts/exePerm.sh
./scripts/exePerm.sh

# Set up the project (install dependencies)
./scripts/setup.sh

# Build the project with CMake and pass all the arguments to the script
./scripts/build.sh "$@"

# Build the binary files
./scripts/bin.sh