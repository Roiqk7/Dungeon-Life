/*
Date: 18/07/2024

Description: This file contains the main function which is the entry point of the program.
*/

#include "../include/globals.hpp"

int main()
{
        // Set log level
        #ifdef DEVELOPMENT
                SET_LOG_LEVEL_DEBUG();
        else // Release
                SET_LOG_LEVEL_ERROR();
        #endif

        // Start the application
        // TODO

        // Run the application
        // TODO

        return 0;
}