/*
Date: 18/07/2024

Description: This file contains commands classes which are then handed to the invoker to execute.

Notes: Follows the command pattern.
*/

#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <functional>
#include <memory>
#include <queue>
#include <string>
#include "globals.hpp"

namespace CommandSystem
{
        using namespace Globals;

        /*
        The command class is an abstract class which is inherited by all the commands.
        */
        class Command
        {
        public: // Methods
        // Constructor
                Command(std::string name, Type commandType, Priority priority);
        // Destructor
                ~Command() = default;
        // Execute
                void execute();                                                 // Execute the command function
        // Getters
                std::string getName() const;                                    // Get the name of the command
                Type getType() const;                                           // Get the type of the command
                Priority getPriority() const;                                   // Get the priority of the command
        // Operators
                bool operator<(const Command& other) const;                     // Less than operator
        protected: // Variables
                std::string m_name;                                             // Name of the command
                Type m_type;                                                    // Command type
                Priority m_priority;                                            // Command priority
                std::function<void()> m_function;                               // Function to execute
        };

        using pCommand = std::unique_ptr<Command>;                              // Alias for unique_ptr<Command>
        using CommandQueue = std::queue<pCommand>;                              // Alias for queue<pCommand>
}

#endif // !COMMAND_HPP