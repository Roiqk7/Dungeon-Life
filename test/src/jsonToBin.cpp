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

#ifdef DEVELOPMENT
#include <spdlog/spdlog.h>
#endif // DEVELOPMENT

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