/*
Date: 18/07/2024

Description: This file contains the main function which is the entry point of the program.
*/

#include "../include/application.hpp"
#include "../include/globals.hpp"

int main()
{
        // Set log level
        #ifdef DEVELOPMENT
        SET_LOG_LEVEL_DEBUG();
        #endif

        // Create the application
        Application::Application application;

        // Run the application
        application.run();

        return 0;
}