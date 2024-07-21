/*
Date: 19/07/2024

Description: This file contains the exception handler class which is used to handle all exceptions in the application.
*/

#ifndef EXCEPTION_HANDLER_HPP
#define EXCEPTION_HANDLER_HPP

#include "exception.hpp"
#include "handler.hpp"

namespace Exception
{
        /*
        The exception handler class is used to handle all exceptions in the application.
        */
        class ExceptionHandler : public Handler::Handler<ExceptionHandler>
        {
        private: // Methods
        // Initialization
                void init() override;                                           // Initialize the exception handler
        // Task handling
                void handleTask(Tool::pPriorityQueueElement task) override;     // Handle a task
        };
}

#endif // !EXCEPTION_HANDLER_HPP