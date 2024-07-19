/*
Date: 18/07/2024

Description: This file contains functions control the entire application.
*/

#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "exceptionHandler.hpp"

namespace Application
{
        class Application
        {
        public: // Methods
        // Constructor
                Application();                                                  // Initialize the application
        // Destructor
                ~Application();                                                 // Clean up the application
        // Application control
                void run();                                                     // Run the application
        private: // Methods
                void init();                                                    // Initialize the application
                bool checkHealth();                                             // Check the health of the application
                bool checkAssets();                                             // Check if the assets are loaded
        public: // Variables
                bool continueRunning;                                           // Flag to determine if the application should keep running
                bool terminate;                                                 // Flag to determine if the application should terminate
        private: // Variables
                Exception::ExceptionHandler exceptionHandler;                   // Exception handler to handle all exceptions
        };
}

#endif // !APPLICATION_HPP