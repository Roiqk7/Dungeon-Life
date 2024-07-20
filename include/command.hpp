/*
Date: 18/07/2024

Description: This file contains commands classes which are then handed to the invoker to execute.

Notes: Follows the command pattern.
*/

#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <memory>
#include <string>
#include <queue>
#include "globals.hpp"

namespace CommandSystem
{
        /*
        Command types are helpful for the invoker to correctly process the commands in the queue.
        */
        enum class CommandType
        {
                None = 0, UserInput, System, Exception
        };

        enum class CommandPriority
        {
                Regular = 0, High, Critical
        };

        /*
        The command class is an abstract class which is inherited by all the commands.
        */
        class Command
        {
        public: // Methods
        // Constructor
                Command(std::string name, CommandType commandType, CommandPriority priority);
        // Virtual methods
                virtual ~Command() = default;
                virtual void execute() = 0;
        // Non-virtual methods
        // Getters
                std::string getName() const;                                    // Get the name of the command
                CommandType getCommandType() const;                             // Get the type of the command
                CommandPriority getPriority() const;                            // Get the priority of the command
        protected: // Variables
                std::string m_name;                                             // Name of the command
                CommandType m_commandType;                                      // Command type
                CommandPriority m_priority;                                     // Command priority
        };

        using pCommand = std::unique_ptr<Command>;                              // Alias for unique_ptr<Command>

        /*
        Comparison operator for commands based on priority.

        Note: Needs to be separate from the Command class because we are comparing unique_ptrs.
        */
        struct CommandComparator
        {
                bool operator()(const pCommand& lhs, const pCommand& rhs) const;
        };
}

#endif // !COMMAND_HPP