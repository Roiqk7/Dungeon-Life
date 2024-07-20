/*
Date: 20/07/2024

Description: This file implements the invoker class which is responsible for executing the commands in the queue.
*/

#include "../include/invoker.hpp"
#include "../include/globals.hpp"

namespace CommandSystem
{
        /*
        Destructor. Cleans up the invoker.
        */
        Invoker::~Invoker()
        {
                // Clean up the invoker
                clean();
        }

        /*
        Returns the instance of the invoker.

        @return The instance of the invoker.
        */
        Invoker& Invoker::getInstance()
        {
                static Invoker instance;
                return instance;
        }
}