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
                                // Process the key event
                                // TODO: processUserInput(UserInput(event.key.keysym.sym));
                                break;
                        }
                        // Mouse event
                        case SDL_MOUSEBUTTONDOWN:
                        {
                                // Process the mouse event
                                // TODO: processUserInput(UserInput(event.button.button));
                                break;
                        }
                }
        }

        /*
        Process user input.
        */
        void UserInputHandler::processUserInput(const UserInput& input)
        {
                // Validate the user input
                if (validateUserInput(input))
                {
                        // Parse the user input and create a command
                        // TODO: Tool::pPriorityQueueElement command = parseUserInput(input);

                        // Submit the command to the invoker
                        // TODO: CommandSystem::Invoker::getInstance().submitTask(command);
                }
        }

        /*
        Validate user input.
        */
        bool UserInputHandler::validateUserInput(const UserInput& input)
        {
                // TODO: Implement this function
                return false;
        }

        /*
        Parse user input and create a command.
        */
        Tool::pPriorityQueueElement UserInputHandler::parseUserInput(const UserInput& input)
        {
                // TODO: Implement this function
                return nullptr;
        }
}