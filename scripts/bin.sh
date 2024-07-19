#!/bin/bash

# Exit immediately if a command exits with a non-zero status.
set -e

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
        # Determine the type based on the directory name
        # This strips the JSON_DIR path and extracts the first directory name as the type
        type=$(echo "$json_file" | sed "s|^$JSON_DIR||" | cut -d'/' -f1)

        echo "Converting $json_file to binary with type $type..."

        # Call the conversion script
        python "$CONVERT_SCRIPT" "$json_file" "$BIN_DIR" --type "$type"
done

echo "Conversion completed."