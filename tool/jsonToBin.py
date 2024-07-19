"""
Date: 18/07/2024

Description: This script converts a JSON file to a binary file based on the type of JSON data.

Usage: python jsonToBin.py <json_file> <binary_folder> --type <type>

Note: Has not yet been tested. May require additional modifications. Created by the copilot.
"""

import argparse
import json
import os
import struct

def json_to_binary_scene(json_file, binary_folder):
        # Extract the base name of the json file to use for the binary file name
        base_name = os.path.basename(json_file)
        binary_file_name = os.path.splitext(base_name)[0] + '.bin'
        binary_file_path = os.path.join(binary_folder, binary_file_name)

        with open(json_file, 'r') as f:
                data = json.load(f)

        with open(binary_file_path, 'wb') as bf:
                # Serialize the scene name length and scene name
                scene_name = data['sceneName'].encode('utf-8')
                bf.write(struct.pack('I', len(scene_name)) + scene_name)

                # Serialize dimensions
                width, height = data['dimensions']['width'], data['dimensions']['height']
                bf.write(struct.pack('II', width, height))

                # Serialize position
                position_x, position_y = data['position']['x'], data['position']['y']
                bf.write(struct.pack('II', position_x, position_y))

                # Serialize elements count
                elements = data['elements']
                bf.write(struct.pack('I', len(elements)))

                for element in elements:
                        # Serialize each element's type as an integer
                        element_type = {'image': 1, 'sprite': 2, 'text': 3, 'button': 4}.get(element['type'], 0)
                        bf.write(struct.pack('I', element_type))

                        # Serialize element name
                        name = element['name'].encode('utf-8')
                        bf.write(struct.pack('I', len(name)) + name)

                        # Serialize additional properties based on element type
                        if element_type in [1, 2]:  # Image or Sprite
                                path = element.get('path', '').encode('utf-8')
                                bf.write(struct.pack('I', len(path)) + path)

                                # Serialize dimensions
                                elem_width, elem_height = element['dimensions']['width'], element['dimensions']['height']
                                bf.write(struct.pack('II', elem_width, elem_height))

                                # Serialize position
                                pos_type = element['position']['type'].encode('utf-8')
                                bf.write(struct.pack('I', len(pos_type)) + pos_type)
                                if 'x' in element['position'] and 'y' in element['position']:
                                        pos_x, pos_y = element['position']['x'], element['position']['y']
                                        bf.write(struct.pack('II', pos_x, pos_y))

                        if element_type == 2:  # Sprite
                                # Serialize components
                                components = element.get('components', [])
                                bf.write(struct.pack('I', len(components)))
                                for component in components:
                                        comp_type = component['type'].encode('utf-8')
                                        bf.write(struct.pack('I', len(comp_type)) + comp_type)
                                        sprite_path = component['spritePath'].encode('utf-8')
                                        bf.write(struct.pack('I', len(sprite_path)) + sprite_path)

                        if element_type == 3:  # Text
                                text = element['text'].encode('utf-8')
                                bf.write(struct.pack('I', len(text)) + text)

                        if element_type == 4:  # Button
                                label = element['label'].encode('utf-8')
                                bf.write(struct.pack('I', len(label)) + label)
                                action = element['action'].encode('utf-8')
                                bf.write(struct.pack('I', len(action)) + action)

                                # Serialize style
                                style = element['style']
                                backgroundColor = style['backgroundColor'].encode('utf-8')
                                textColor = style['textColor'].encode('utf-8')
                                borderWidth = style['borderWidth'].encode('utf-8')
                                borderStyle = style['borderStyle'].encode('utf-8')
                                borderColor = style['borderColor'].encode('utf-8')
                                bf.write(struct.pack('I', len(backgroundColor)) + backgroundColor)
                                bf.write(struct.pack('I', len(textColor)) + textColor)
                                bf.write(struct.pack('I', len(borderWidth)) + borderWidth)
                                bf.write(struct.pack('I', len(borderStyle)) + borderStyle)
                                bf.write(struct.pack('I', len(borderColor)) + borderColor)

# Placeholder for other types of JSON serialization
def json_to_binary_other(json_file, binary_folder):
        pass

def parse_args():
        parser = argparse.ArgumentParser(description='Convert JSON to binary format based on type.')
        parser.add_argument('json_file', type=str, help='Path to the input JSON file.')
        parser.add_argument('binary_folder', type=str, help='Path to the output binary folder.')
        parser.add_argument('--type', type=str, help='Type of the JSON (e.g., "scene").')
        return parser.parse_args()

def main():
        args = parse_args()
        if args.type == 'scene':
                json_to_binary_scene(args.json_file, args.binary_folder)
        else:
                json_to_binary_other(args.json_file, args.binary_folder)

if __name__ == '__main__':
        try:
                main()
        except Exception as e:
                print(e)
