"""
Date: 18/07/2024

Description: This script converts a JSON file to a binary file using msgpack and saves it with the specified path and name.

Usage: python3 jsonToBin.py <json_file> <bin_file>

Note: Requires the msgpack library. Install with `pip install msgpack`.
"""

import argparse
import json
import msgpack

def json_to_binary(json_file, bin_file):
        # Read the JSON file
        with open(json_file, 'r') as file:
                data = json.load(file)

        # Serialize the data to binary using msgpack
        binary_data = msgpack.packb(data)

        # Write the binary data to the specified bin file
        with open(bin_file, 'wb') as binary_file:
                binary_file.write(binary_data)

        print(f"Converted {json_file} to binary and saved as {bin_file}")

def parse_args():
        parser = argparse.ArgumentParser(description='Convert JSON to binary format using msgpack.')
        parser.add_argument('json_file', type=str, help='Path to the input JSON file.')
        parser.add_argument('bin_file', type=str, help='Path to the output binary file.')
        return parser.parse_args()

def main():
        args = parse_args()
        json_to_binary(args.json_file, args.bin_file)

if __name__ == '__main__':
        try:
                main()
        except Exception as e:
                print(e)
