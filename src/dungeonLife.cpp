/*
Date: 18/07/2024

Description: This file contains the main function.
*/

#include "../include/application.hpp"
#include "../include/globals.hpp"

int main()
{
        #ifdef DEVELOPMENT
        SET_LOG_LEVEL_DEBUG();
        #endif // DEVELOPMENT

        // Create the application object
        Application::Application application;

        return 0;
}