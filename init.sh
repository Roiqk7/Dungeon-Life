#!/bin/bash

# Exit immediately if a command exits with a non-zero status.
set -e

# Make all the scripts executable
chmod +x scripts/exePerm.sh
./scripts/exePerm.sh

# Set up the project (install dependencies)
./scripts/setup.sh

# Build the project with CMake
./scripts/build.sh "$1"

# Build the binary files
./scripts/bin.sh