/*
Date: 23/07/2024

Description: This file defines the user input struct which holds the user input data.
*/

#ifndef USER_INPUT_HPP
#define USER_INPUT_HPP

#include <SDL2/SDL.h>

namespace UserInput
{
        /*
        Holds the user input data.
        */
        struct UserInput
        {
                // Keyboard
                bool keyDown = false;                                           // Flag to indicate if a key is down
                SDL_Keycode keyCode = SDLK_UNKNOWN;                             // SDL_Keycode is an enum for keyboard keys

                // Mouse
                bool click = false;                                             // Flag to indicate if a mouse left button is clicked
                int mouseX = 0;                                                 // Mouse X position
                int mouseY = 0;                                                 // Mouse Y position

                // Keyboard constructor
                UserInput(bool keyDown, SDL_Keycode keyCode);

                // Mouse constructor
                UserInput(bool click, int mouseX, int mouseY);
        };
}

#endif // !USER_INPUT_HPP