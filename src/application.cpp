/*
Date: 19/07/2024

Description: This file implements the application class which controls the entire application.
*/

#include "../include/application.hpp"
#include "../include/frameHandler.hpp"
#include "../include/invoker.hpp"
#include "../include/globals.hpp"

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

                // Initialize the application
                init();

                // Check the health of the application
                checkHealth();
        }

        /*
        Destructor.
        */
        Application::~Application()
        {
                // Call the invoker destructor
                CommandSystem::Invoker::getInstance().~Invoker();

                // Set the health flag to shut down
                healthFlag = HealthFlag::ShutDown;

                // Log the destruction of the application instance
                LOG_INFO("Application instance destroyed.");
        }

        /*
        Run the application. This is the main loop of the application.
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

        /*
        Initialize the application.
        */
        void Application::init()
        {
                // Initialize the invoker
                CommandSystem::Invoker::getInstance();

                // Initialize the frame handler
                FrameHandler::FrameHandler::getInstance();

                // Log the initialization of the application
                LOG_INFO("Application initialized.");
        }

        /*
        Control the flow of the application.
        */
        void Application::controlFlow()
        {
                // Get the invoker instance
                auto& invoker = CommandSystem::Invoker::getInstance();

                // If the command queue is empty, wait for a command
                if (invoker.empty)
                {
                        // Wait for a command to be submitted
                        invoker.waitCommand();
                }

                // Process the commands in the queue
                // If we are in a game, we process the commands while
                // running at specified FPS.
                if (context == Context::Gameplay)
                {
                        // Get the remaining time until the next frame
                        auto remainingTime = FrameHandler::FrameHandler::getInstance().getRemainingTime();

                        // Process the commands in the given duration
                        invoker.process(remainingTime);
                }
                // We do not care about FPS so we can handle all the commands
                else
                {
                        // Process the commands
                        invoker.process();
                }
        }

        /*
        Close the application.
        */
        void Application::close()
        {
                // Log the closing of the application
                LOG_INFO("Application is closing...");

                // Set the health flag to shutting down
                healthFlag = HealthFlag::ShuttingDown;
        }
}