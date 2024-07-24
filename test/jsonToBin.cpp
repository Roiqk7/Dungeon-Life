/*
Date: 20/07/2024

Description: This file contains tests for the jsonToBin.py tool.
*/

#ifndef TEST
#error "Tried to compile a test file without the TEST macro defined. Aborting compilation."
#else

#include <json/json.h>
#include <gtest/gtest.h>
#include <string>

#ifdef DEVELOPMENT
#include <spdlog/spdlog.h>
#endif // DEVELOPMENT

// Constants
const std::string JSON_TO_BIN_PATH = "tool/jsonToBin.py";
const std::string BIN_TO_JSON_PATH = "tool/binToJson.py";

// Test for converting a JSON scene to a binary file
TEST(JsonToBin, jsonToBin)
{
        // TODO: Implement test
}

// Test for converting a binary scene to a JSON file
TEST(JsonToBin, binToJson)
{
        // TODO: Implement test
}

// TODO: Add more tests

#endif // TEST