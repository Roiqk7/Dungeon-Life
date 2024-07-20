/*
Date: 18/07/2024

Description: This file contains global variables, macros etc. that are used throughout the program.

Notes: x
*/

#ifndef GLOBALS_HPP
#define GLOBALS_HPP

#include <cstddef>

#ifdef DEVELOPMENT
// Include the spdlog library for logging
#include <spdlog/spdlog.h>
// Macro for development logging
#define LOG_TRACE(...) spdlog::trace(__VA_ARGS__)
#define LOG_INFO(...) spdlog::info(__VA_ARGS__)
#define LOG_WARN(...) spdlog::warn(__VA_ARGS__)
#define LOG_ERROR(...) spdlog::error(__VA_ARGS__)
#define LOG_CRITICAL(...) spdlog::critical(__VA_ARGS__)

// Macros to set log level
#define SET_LOG_LEVEL_TRACE() spdlog::set_level(spdlog::level::trace)
#define SET_LOG_LEVEL_DEBUG() spdlog::set_level(spdlog::level::debug)
#define SET_LOG_LEVEL_INFO() spdlog::set_level(spdlog::level::info)
#define SET_LOG_LEVEL_WARN() spdlog::set_level(spdlog::level::warn)
#define SET_LOG_LEVEL_ERROR() spdlog::set_level(spdlog::level::err)
#define SET_LOG_LEVEL_CRITICAL() spdlog::set_level(spdlog::level::critical)
#define SET_LOG_LEVEL_OFF() spdlog::set_level(spdlog::level::off)

#else // Release mode
// Define macros as no-operation if not in development mode
#define LOG_TRACE(...) (void)0
#define LOG_INFO(...) (void)0
#define LOG_WARN(...) (void)0
#define LOG_ERROR(...) (void)0
#define LOG_CRITICAL(...) (void)0

// Define SET_LOG_LEVEL macros as no-operation if not in development mode
#define SET_LOG_LEVEL_TRACE() (void)0
#define SET_LOG_LEVEL_DEBUG() (void)0
#define SET_LOG_LEVEL_INFO() (void)0
#define SET_LOG_LEVEL_WARN() (void)0
#define SET_LOG_LEVEL_ERROR() (void)0
#define SET_LOG_LEVEL_CRITICAL() (void)0
#define SET_LOG_LEVEL_OFF() (void)0

#endif // !DEVELOPMENT

namespace Globals
{
        // Constants
        namespace Constants
        {
        // Application
        // Command System
                const size_t COMMAND_BATCH_SIZE = 5;                            // Number of commands to process in a batch
        // Gameplay
                const int FPS = 60;                                             // Frames per second
        }

        /*
        Helps to determine the type of data. (commands, tasks etc.)
        */
        enum class Type
        {
                None = 0, UserInput, System, Exception
        };

        /*
        Helps to determine priority of various data types. (commands, tasks etc.)
        */
        enum class Priority
        {
                Regular = 0, High, Critical
        };
}

#endif // !GLOBALS_HPP