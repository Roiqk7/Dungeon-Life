/*
Date: 18/07/2024

Description: This file contains functions control the entire application.
*/

#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "exceptionHandler.hpp"

namespace Application
{
        /*
        Healthy: Indicates the application is running normally without any
                issues.
        Degraded: Indicates the application is running but not at full capacity
                or performance. This could be due to minor issues that don't
                completely stop the application but might affect user experience
                or efficiency.
        Error: Indicates the application has encountered an error that has
                stopped the application from running. This could be due to
                critical issues that need to be resolved before the application
                can continue running.
        Critical: Indicates the application has encountered a critical error
                and will be terminated as soon as possible.
        ShuttingDown: Indicates the application is in the process of shutting
                down and will be terminated.
        ShutDown: Indicates the application has been terminated.
        */
        enum class HealthFlag
        {
                Healthy = 0, Degraded, Error, Critical, ShuttingDown, ShutDown
        };

        class Application
        {
        public: // Methods
        // Constructor
                Application();                                                  // Initialize the application
        // Destructor
                ~Application();                                                 // Clean up the application
        // Application control
                void run();                                                     // Contains the main loop of the application
        private: // Methods
                void init();                                                    // Initialize the application
                void controlFlow();                                             // Control the flow of the application
                void manageHealth();                                            // Manage the health of the application
                void checkHealth();                                             // Check the health of the application
                bool resolveHealth();                                           // Resolve the health of the application
                void close();                                                   // Close the application
        public: // Variables
                HealthFlag healthFlag;                                          // Flag to determine the health of the application
        private: // Variables
                Exception::ExceptionHandler exceptionHandler;                   // Exception handler to handle all exceptions
        };
}

#endif // !APPLICATION_HPP