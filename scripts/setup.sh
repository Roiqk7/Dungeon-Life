#!/bin/bash

# Exit immediately if a command exits with a non-zero status.
set -e

# Function to check if Homebrew is installed and install it if it's not
install_homebrew()
{
        # Check if Homebrew is installed
        if ! command -v brew >/dev/null 2>&1; then
                echo "Homebrew not found. Installing Homebrew..."
                /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
        else
                echo "Homebrew is already installed."
        fi
}

# Function to install dependencies using Homebrew
install_dependencies()
{
        echo "Installing dependencies using Homebrew..."
        # Check if the script was called with the 'dev' argument
        if [ "${1}" == "dev" ]; then
                echo "Setting up the project in development mode..."
                brew install spdlog
        fi

        # Install dependencies using Homebrew
        brew install cmake
}

# Detect operating system using uname
OS=$(uname -s)

# Check if the operating system is MacOS
if [ "${OS}" = "Darwin" ]; then
        # Install Homebrew if it's not installed
        install_homebrew

        # Install dependencies
        install_dependencies "$1"
else
        echo "[Error] This script is intended for MacOS users."
fi