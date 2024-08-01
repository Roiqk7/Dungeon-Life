/*
Date: 01/08/2024

Description: This file implements the exception class which is used to handle exceptions in the application.
*/

#include "../include/exception.hpp"

namespace Exception
{
        // Constructor with message
        Exception::Exception(const std::string& message)
                : message(message), fatal(false) {}

        #ifdef DEVELOPMENT
        // Constructor with message and log level (for development)
        Exception::Exception(const std::string& message,
                spdlog::level::level_enum logLevel)
                : message(message), fatal(false)
        {
                // Log the exception
                log(logLevel);
        }
        #endif // DEVELOPMENT

        // Log the exception (warning by default)
        #ifdef DEVELOPMENT
        void Exception::log(spdlog::level::level_enum logLevel)
        {
                // Log the exception
                spdlog::get("logger")->log(logLevel, message);
        }
        #endif // DEVELOPMENT

        // Return the message of the exception
        const char* Exception::what() const noexcept
        {
                return message.c_str();
        }
}