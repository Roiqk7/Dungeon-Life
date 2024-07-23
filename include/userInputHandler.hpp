/*
Date: 20/07/2024

Description: This file defines the user input handler class which is responsible for handling user input.
*/

#ifndef USER_INPUT_HANDLER_HPP
#define USER_INPUT_HANDLER_HPP

#include "priorityQueueElement.hpp"
#include "singleton.hpp"

namespace UserInputHandler
{
        // User input handler class
        class UserInputHandler : public Tool::Singleton<UserInputHandler>
        {
        public: // Methods
        // User input
                void handleUserInput();                                         // Is responsible for handling user input and submitting it to the invoker
                void listenForUserInput();                                      // Catches user input
        private: // Methods
        // User input
                void processUserInput();                                        // Process user input (validate, parse and create command)
                bool validateUserInput();                                       // Validate user input
                Tool::pPriorityQueueElement parseUserInput();                   // Parse user input and create a command
        };
}

#endif // !USER_INPUT_HANDLER_HPP