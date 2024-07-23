/*
Date: 19/07/2024

Description: This file implements the application class which controls the entire application.
*/

#include "../include/application.hpp"
#include "../include/frameHandler.hpp"
#include "../include/globals.hpp"
#include "../include/invoker.hpp"
#include "../include/threadManager.hpp"
#include "../include/userInputHandler.hpp"

namespace Application
{
        /*
        Constructor. Initializes the necessary components of the application.
        And checks the health of the application.
        */
        Application::Application()
                : healthFlag(HealthFlag::Healthy), context(Context::System)
        {
                // Log the creation of the application instance
                LOG_INFO("Application instance created.");

                // Initialize the application
                init();

                // Check the health of the application
                checkHealth();
        }

        /*
        Destructor. Cleans up the application and sets the shut down flag.
        */
        Application::~Application()
        {
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
                // Log the entry to the main application loop
                LOG_INFO("Application main loop started.");

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
                // Request a thread for user input handling
                ThreadManager::ThreadManager::getInstance().requestThread(
                        &UserInput::UserInputHandler::waitForUserInput, this);

                // Log the initialization of the application
                LOG_INFO("Application initialized.");
        }

        /*
        Manage the health of the application.
        */
        void Application::manageHealth()
        {
                // TODO: Add assets health and game stats checks

                // Check the health of the application
                checkHealth();

                // Resolve the health of the application
                resolveHealth();
        }

        /*
        Check the health of the application.
        */
        void Application::checkHealth()
        {
                // TODO: Add more health checks here

                // Log the health status of the application
                LOG_INFO("Application health status: " +
                        std::to_string(static_cast<int>(healthFlag)));
        }

        /*
        Resolve the health of the application.

        @return True if the health was resolved, false otherwise.
        */
        bool Application::resolveHealth()
        {
                // TODO: Add more health resolutions here

                // If the health flag is critical or above, close the application
                if (healthFlag >= HealthFlag::Critical)
                {
                        // Close the application
                        close();

                        return true;
                }

                return false;
        }

        /*
        Control the flow of the application.
        */
        void Application::controlFlow()
        {
                // Get the invoker instance
                auto& invoker = CommandSystem::Invoker::getInstance();

                // Check if the invoker has any commands
                if (!invoker.empty())
                {
                        // Process the commands in the queue based on the context
                        // If we are in a game, we process the commands while
                        // running at specified FPS.
                        if (context == Context::Gameplay)
                        {
                                // get the frame handler instance
                                auto& frameHandler =
                                        FrameHandler::FrameHandler::getInstance();

                                // Get the remaining time until the next frame
                                auto remainingTime = frameHandler.getRemainingTime();

                                // Process the commands in the given duration
                                invoker.processForDuration(remainingTime);
                        }
                        // We do not care about FPS so we can handle all the commands
                        // without any restrictions.
                        else
                        {
                                // Process all of the commands
                                invoker.process();
                        }
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

                // Shut down the thread manager
                ThreadManager::ThreadManager::getInstance().shutDown();

                // Set the health flag to shut down
                healthFlag = HealthFlag::ShutDown;

                // Log the closure of the application
                LOG_INFO("Application closed.");
        }
}