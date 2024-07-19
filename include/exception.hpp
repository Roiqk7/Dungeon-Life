/*
Date: 19/07/2024

Description: This file contains the exception class which is used to handle exceptions in the application.
*/

#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <exception>
#include <queue>
#include <string>

namespace Exception
{
        /*
        Used for handling exceptions in the application. It is a wrapper around std::exception.

        Note: May include standard exceptions or custom exceptions.
        */
        class Exception : public std::exception
        {
        public:
        // Constructors
                explicit Exception(const std::string& message);
        // Methods
                virtual const char* what() const noexcept override;
        private:
        // Variables
                std::string message;
        };

        using pException = std::unique_ptr<Exception>;                          // Alias for unique_ptr<Exception>
        using ExceptionQueue = std::queue<pException>;                          // Alias for queue<pException>
}

#endif // !EXCEPTION_HPP