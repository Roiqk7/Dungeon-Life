/*
Date: 23/07/2024

Description: This file implements the user input handler class which is responsible for handling user input.
*/

#include "../include/globals.hpp"
#include "../include/invoker.hpp"
#include "../include/threadManager.hpp"
#include "../include/userInputHandler.hpp"

namespace UserInput
{
        /*
        Wait for user input.
        */
        void UserInputHandler::waitForUserInput()
        {
                // TODO: Implement
        }

        /*
        Constructor.
        */
        UserInputHandler::UserInputHandler()
        {
                // Log the creation of the user input handler instance
                LOG_INFO("User input handler instance created.");

                // Request a thread for user input handling
                ThreadManager::ThreadManager::getInstance().requestThread(
                        &UserInputHandler::waitForUserInput, this);
        }
}