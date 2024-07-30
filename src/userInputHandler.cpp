/*
Date: 23/07/2024

Description: This file implements the user input handler class which is responsible for handling user input.
*/

#include <SDL2/SDL.h>
#include "../include/application.hpp"
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
                // Initialize the event
                SDL_Event event;

                // SDL_WaitEvent will block until an event is available
                SDL_WaitEvent(&event);

                // Handle the event
                switch (event.type)
                {
                        // Quit event
                        case SDL_QUIT:
                        {
                                // Shut down the application
                                Application::Application::shouldClose = true;
                                break;
                        }
                        // Keyboard event
                        case SDL_KEYDOWN:
                        {
                                // Log the key event
                                LOG_TRACE("Key pressed: " + std::to_string(event.key.keysym.sym));

                                // Process the key event
                                processUserInput(UserInput(true, event.key.keysym.sym));
                                break;
                        }
                        // Mouse event
                        case SDL_MOUSEBUTTONDOWN:
                        {
                                // Log the mouse event
                                LOG_TRACE("Mouse clicked at: " + std::to_string(event.button.x) + ", " + std::to_string(event.button.y));

                                // Process the mouse event
                                processUserInput(UserInput(true, event.button.x, event.button.y));
                                break;
                        }
                }
        }

        /*
        Validate user input and create a command.

        @param input: The user input to process.
        */
        void UserInputHandler::processUserInput(const UserInput& input)
        {
                // Validate the user input
                if (validateUserInput(input))
                {
                        // Parse the user input and create a command
                        CommandSystem::Command command = parseUserInput(input);

                        // Submit the command to the invoker
                        CommandSystem::Invoker::getInstance().submit(std::move(command));
                }
        }

        /*
        Validate user input.

        @param input: The user input to validate.
        */
        bool UserInputHandler::validateUserInput(const UserInput& input)
        {
                // TODO: Implement this function
                return false;
        }

        /*
        Parse user input and create a command.

        @param input: The user input to parse.
        */
        Tool::pPriorityQueueElement UserInputHandler::parseUserInput(const UserInput& input)
        {
                // TODO: Implement this function
                return nullptr;
        }
}