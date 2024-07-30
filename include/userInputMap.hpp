/*
Date: 30/07/2024

Description: This file contains the user input map class which is responsible for mapping user input to commands.
*/

#include "../include/application.hpp"
#include "../include/invoker.hpp"
#include "../include/priorityQueueElement.hpp"
#include "../include/userInput.hpp"

namespace UserInput
{
        /*
        Map user input to commands.
        */
        class UserInputMap
        {
        public: // Methods
        // User Input Mapping
                CommandSystem::Command mapUserInput(
                        const UserInput& userInput);                            // Map user input to a command
        };
}