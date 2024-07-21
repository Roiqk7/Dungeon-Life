"""
Date: 18/07/2024

Description: This script converts a JSON file to a binary file using msgpack and saves it in the specified folder with the same name.

Usage: python3 jsonToBin.py <json_file> <binary_folder>

Note: Requires the msgpack library. Install with `pip install msgpack`.
"""

import argparse
import json
import os
import msgpack

def json_to_binary(json_file, binary_folder):
        # Read the JSON file
        with open(json_file, 'r') as file:
                data = json.load(file)

        # Serialize the data to binary using msgpack
        binary_data = msgpack.packb(data)

        # Construct the binary file path
        base_name = os.path.basename(json_file)
        binary_file_name = os.path.splitext(base_name)[0] + '.bin'
        binary_file_path = os.path.join(binary_folder, binary_file_name)

        # Write the binary data to the file
        with open(binary_file_path, 'wb') as binary_file:
                binary_file.write(binary_data)

        print(f"Converted {json_file} to binary and saved as {binary_file_path}")

def parse_args():
        parser = argparse.ArgumentParser(description='Convert JSON to binary format using msgpack.')
        parser.add_argument('json_file', type=str, help='Path to the input JSON file.')
        parser.add_argument('binary_folder', type=str, help='Path to the output binary folder.')
        return parser.parse_args()

def main():
        args = parse_args()
        json_to_binary(args.json_file, args.binary_folder)

if __name__ == '__main__':
        try:
                main()
        except Exception as e:
                print(e)
