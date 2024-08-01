/*
Date: 30/07/2024

Description: This file implements the user input map class which is responsible for mapping user input to commands.
*/

#include <algorithm>
#include <vector>
#include "../include/application.hpp"
#include "../include/invoker.hpp"
#include "../include/priorityQueueElement.hpp"
#include "../include/userInput.hpp"
#include "../include/userInputMap.hpp"

namespace UserInput
{
        /*
        Map user input to commands.
        */
        CommandSystem::Command UserInputMap::mapUserInput(
                const UserInput& userInput)
        {
                // TODO: Implement the mapping of user input to commands
        }

        /*
        Validate user input.
        */
        bool UserInputMap::validateUserInput(
                const UserInput& userInput)
        {
                // Check if the key is valid
                if (std::find(validKeys.begin(), validKeys.end(), userInput.keyCode) != validKeys.end())
                {
                        return true;
                }

                return false;
        }
}