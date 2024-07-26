/*
Date: 20/07/2024

Description: This file contains tests for the json and binary conversion tool.
*/

#ifndef TEST
#error "Tried to compile a test file without the TEST macro defined. Aborting compilation."
#else

#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <json/json.h>
#include <gtest/gtest.h>
#include <string>
#include "../include/globals.hpp"

/*
Test for creating a binary file from JSON data

Expected: The function should create a binary file at the correct location and
not be empty.
*/
TEST(JsonToBin, createBinFile)
{
        // TODO: Implement test
}

/*
Test for creating a JSON file from binary file data

Expected: The function should create a JSON file at the correct location and
not be empty.
*/
TEST(JsonToBin, createJsonFile)
{
        // TODO: Implement test
}

/*
Test for converting a JSON scene to a binary file

Expected: The function should convert the JSON data to a binary file.
*/
TEST(JsonToBin, jsonToBin)
{
        // TODO: Implement test
}

/*
Test for converting a binary file to a JSON scene

Expected: The function should convert the binary file to JSON data.
*/
TEST(JsonToBin, binToJson)
{
        // TODO: Implement test
}

// TODO: Add more tests

#endif // TEST