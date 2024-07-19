/*
Date: 18/07/2024

Description: This file contains functions control the entire application.
*/

#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "exception.hpp"
#include "globals.hpp"

namespace Application
{
        class Application
        {
        public: // Variables
                bool continueRunning;                                           // Flag to determine if the application should keep running
                bool terminate;                                                 // Flag to determine if the application should terminate
        public: // Methods
        // Constructor
                Application();
        // Destructor
                ~Application();
        // Application control
                void run();                                                     // Run the application
        private: // Methods
                void init();                                                    // Initialize the application
                bool checkHealth();                                             // Check the health of the application
                bool checkAssets();                                             // Check if the assets are loaded
        };
}

#endif // !APPLICATION_HPP