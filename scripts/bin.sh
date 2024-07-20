#!/bin/bash

# Exit immediately if a command exits with a non-zero status.
set -e

echo "Converting JSON files to binary..."

# Define the directory containing the JSON files and the output directory for binary files
JSON_DIR="data/"
BIN_DIR="bin/"

# Path to the conversion script
CONVERT_SCRIPT="tool/jsonToBin.py"

# Create the output directory if it doesn't exist
if [ ! -d "build" ]; then
        echo "Creating $BIN_DIR directory..."
        mkdir -p "$BIN_DIR"
fi

# Find all JSON files in the JSON_DIR and convert them to binary
find "$JSON_DIR" -type f -name "*.json" | while read -r json_file; do
        # Normalize the path to ensure no double slashes
        normalized_json_path=$(echo "$json_file" | sed 's|//|/|g')

        # Determine the type based on the directory name
        # This strips the JSON_DIR path, ensures no double slashes, and extracts the first directory name as the type
        type=$(echo "$normalized_json_path" | sed "s|^$JSON_DIR||" | cut -d'/' -f1)

        echo "Converting $json_file to binary with type $type..."

        # Call the conversion script
        python3 "$CONVERT_SCRIPT" "$json_file" "$BIN_DIR" --type "$type"
done

echo "Conversion completed."