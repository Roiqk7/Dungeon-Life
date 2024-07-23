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
                bool keyDown;                                                   // Flag to indicate if a key is down
                SDL_Keycode keyCode;                                            // SDL_Keycode is an enum for keyboard keys

                // Mouse
                bool click;                                                     // Flag to indicate if a mouse left button is clicked
                int mouseX;                                                     // Mouse X position
                int mouseY;                                                     // Mouse Y position
        };
}

#endif // !USER_INPUT_HPP