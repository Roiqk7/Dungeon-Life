#!/bin/bash

# Exit immediately if a command exits with a non-zero status.
set -e

# Define red color code
RED='\033[0;31m'

echo "Converting JSON files to binary..."

# Define the directory containing the JSON files and the output directory for binary files
JSON_DIR="data"
BIN_DIR="bin"

# Path to the conversion script
CONVERT_SCRIPT="tool/jsonToBin.py"

# Create the output directory if it doesn't exist
if [ ! -d "$BIN_DIR" ]; then
        echo "Creating $BIN_DIR/ directory..."
        mkdir "$BIN_DIR"
fi

# Ensure the script is run from the correct directory
if [ ! -d "$JSON_DIR" ] || [ ! -d "$BIN_DIR" ] || [ ! -f "$CONVERT_SCRIPT" ]; then
        echo "${RED}[Error] Make sure to run this script from the project directory where $JSON_DIR, $BIN_DIR, and $CONVERT_SCRIPT exist."
        # Check if the BIN_DIR was created earlier in this script and delete it if it exists
        if [ -d "$BIN_DIR" ]; then
                echo "Removing $BIN_DIR directory due to incorrect script execution location..."
                rm -rf "$BIN_DIR/"
        fi
        exit 1
fi

# Find all JSON files in the JSON_DIR and convert them to binary
find "$JSON_DIR" -type f -name "*.json" | while read -r json_file; do
        # Extract the filename without the extension
        json_filename=$(basename "$json_file" .json)

        # Construct the output binary file path
        bin_file_path="$BIN_DIR/${json_filename}.bin"

        # Adjust json_file path for display to avoid double slash
        display_json_file="${json_file#$JSON_DIR/}"

        echo "Converting $display_json_file to binary file $bin_file_path..."

        # Call the conversion script with corrected arguments
        python3 "$CONVERT_SCRIPT" "$json_file" "$bin_file_path"
done

echo "Conversion completed."