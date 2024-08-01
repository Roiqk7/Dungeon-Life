/*
Date: 30/07/2024

Description: This file implements the user input map class which is responsible for mapping user input to commands.
*/

#include <algorithm>
#include <memory>
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

        @param userInput The user input to map. (assumes valid input)
        */
        CommandSystem::Command UserInputMap::mapUserInput(
                const UserInput& userInput)
        {
                // Map the user input to a command
                // Universal key commands
                switch (userInput.keyCode)
                {
                        case SDLK_q:
                        {
                                // TODO: Create a command factory to create commands

                                // Quit the application
                                auto command = std::make_unique<Tool::PriorityQueueElement>(
                                "Quit", Globals::Priority::High, Globals::Type::System, []()
                                {
                                        Application::Application::shouldClose = true;
                                });

                                return command;
                        }
                }

                // Null command
                auto command = std::make_unique<Tool::PriorityQueueElement>(
                        "Null", Globals::Priority::Regular, Globals::Type::System, []()
                        {
                                // Do nothing
                        });

                return command;
        }

        /*
        Validate user input.

        @param userInput The user input to validate.
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