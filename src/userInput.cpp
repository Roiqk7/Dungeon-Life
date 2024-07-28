/*
Date: 28/07/2024

Description: This file implements the user input struct which is responsible for storing user input.
*/

#include "../include/userInput.hpp"

namespace UserInput
{
        /*
        Keyboard constructor.

        @param keyDown Flag to indicate if a key is down
        @param keyCode SDL_Keycode is an enum for keyboard keys
        */
        UserInput::UserInput(bool keyDown, SDL_Keycode keyCode)
                : keyDown(keyDown), keyCode(keyCode) {}

        /*
        Mouse constructor.

        @param click Flag to indicate if a mouse left button is clicked
        @param mouseX Mouse X position
        @param mouseY Mouse Y position
        */
        UserInput::UserInput(bool click, int mouseX, int mouseY)
                : click(click), mouseX(mouseX), mouseY(mouseY) {}
}