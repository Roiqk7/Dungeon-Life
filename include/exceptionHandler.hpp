/*
Date: 19/07/2024

Description: This file contains the exception handler class which is used to handle all exceptions in the application.
*/

#ifndef EXCEPTION_HANDLER_HPP
#define EXCEPTION_HANDLER_HPP

#include "exception.hpp"

namespace Exception
{
        /*
        The exception handler class is used to handle all exceptions in the application.
        */
        class ExceptionHandler
        {
        public: // Methods
        // Destructor
                ~ExceptionHandler();                                            // Destructor which is responsible for processing all exceptions
        // Singleton
                static ExceptionHandler& getInstance();
                ExceptionHandler(const ExceptionHandler&) = delete;             // Delete copy constructor
                ExceptionHandler& operator=(const ExceptionHandler&) = delete;  // Delete copy assignment operator
        // Exception handling
                void processExceptions();                                       // Process all exceptions in the queue
        private: // Methods
                void handleException(pException& exception);                    // Handle a specific exception
        public: // Variables
                ExceptionQueue exceptions;                                      // Queue of unprocessed exceptions
        };
}

#endif // !EXCEPTION_HANDLER_HPP