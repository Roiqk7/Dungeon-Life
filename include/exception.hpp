/*
Date: 19/07/2024

Description: This file contains the exception class which is used to handle exceptions in the application.
*/

#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <exception>
#include <functional>
#include <queue>
#include <string>

#ifdef DEVELOPMENT
#include <spdlog/spdlog.h>
#endif // DEVELOPMENT

namespace Exception
{
        /*
        Used for handling exceptions in the application. It is a wrapper around std::exception.

        Note: May include standard exceptions or custom exceptions.
        */
        class Exception : public std::exception
        {
        public: // Methods
        // Constructors
                explicit Exception(const std::string& message);                 // Constructor with message
                #ifdef DEVELOPMENT
                explicit Exception(const std::string& message,
                        spdlog::level::level_enum logLevel);                    // Constructor with message and log level (for development)
                #endif // DEVELOPMENT
        // Methods
                virtual const char* what() const noexcept override;
        protected: // Methods
                #ifdef DEVELOPMENT
                void log(spdlog::level::level_enum logLevel
                        = spdlog::level::warning);                              // Log the exception (warning by default)
                #endif
        public: // Variables
                bool fatal;                                                     // Flag to determine if the exception is fatal and should terminate the application
                std::function<void()> callback;                                 // Callback function to execute to handle the exception
        protected: // Variables
                std::string message;
        };

        using pException = std::unique_ptr<Exception>;                          // Alias for unique_ptr<Exception>
        using ExceptionQueue = std::queue<pException>;                          // Alias for queue<pException>
}

#endif // !EXCEPTION_HPP