/*
Date: 30/07/2024

Description: This file contains the user input map class which is responsible for mapping user input to commands.
*/

#include <SDL2/SDL.h>
#include <vector>
#include "application.hpp"
#include "invoker.hpp"
#include "priorityQueueElement.hpp"
#include "userInput.hpp"

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
                bool validateUserInput(
                        const UserInput& userInput);                            // Validate user input
        private: // Variables
        // User Input Mapping
                const std::vector<SDL_Keycode> validKeys = {
                        SDLK_w, SDLK_a, SDLK_s, SDLK_d,            // WASD keys
                        SDLK_q
                        // TODO: Add more keys as needed
                };
        };
}