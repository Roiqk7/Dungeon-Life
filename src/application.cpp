/*
Date: 19/07/2024

Description: This file implements the application class which controls the entire application.
*/

#include "../include/application.hpp"
#include "../include/invoker.hpp"

namespace Application
{
        /*
        Constructor.
        */
        Application::Application()
                : healthFlag(HealthFlag::Healthy)
        {
                // Log the creation of the application instance
                LOG_INFO("Application instance created.");

                // Initialize the invoker
                CommandSystem::Invoker::getInstance();

                // Initialize the application
                init();
        }

        /*
        Destructor.
        */
        Application::~Application()
        {
                // Call the invoker destructor
                CommandSystem::Invoker::getInstance().~Invoker();

                // Log the destruction of the application instance
                LOG_INFO("Application instance destroyed.");
        }

        /*
        Run the application.
        */
        void Application::run()
        {
                // Check the health flag
                while (healthFlag < HealthFlag::Critical)
                {
                        // Manage the health of the application
                        manageHealth();

                        // Control the flow of the application
                        controlFlow();
                }
        }
}