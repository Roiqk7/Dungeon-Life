"""
Date: 18/07/2024

Description: This script converts a binary file to a JSON file using msgpack and saves it with the specified path and name.

Usage: python3 binToJson.py <bin_file> <json_file>

Note: Requires the msgpack library. Install with `pip install msgpack`.
"""

import argparse
import json
import msgpack

def binary_to_json(bin_file, json_file):
	# Read the binary file
	with open(bin_file, 'rb') as binary_file:
		binary_data = binary_file.read()

	# Deserialize the data from binary using msgpack
	data = msgpack.unpackb(binary_data)

	# Write the data to the specified JSON file
	with open(json_file, 'w') as file:
		json.dump(data, file, indent=4)

	print(f"Converted {bin_file} to JSON and saved as {json_file}")

def parse_args():
	parser = argparse.ArgumentParser(description='Convert binary format to JSON using msgpack.')
	parser.add_argument('bin_file', type=str, help='Path to the input binary file.')
	parser.add_argument('json_file', type=str, help='Path to the output JSON file.')
	return parser.parse_args()

def main():
	args = parse_args()
	binary_to_json(args.bin_file, args.json_file)

if __name__ == '__main__':
	try:
		main()
	except Exception as e:
		print(e)