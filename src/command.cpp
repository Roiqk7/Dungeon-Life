/*
Date: 20/07/2024

Description: This file implementss commands classes which are then handed to the invoker to execute.

Notes: Follows the command pattern.
*/

#include "../include/command.hpp"
#include "../include/globals.hpp"

namespace CommandSystem
{
// Command base class
        /*
        Constructor. Initializes the command.

        @param name: The name of the command.
        @param commandType: The type of the command.
        @param priority: The priority of the command.
        */
        Command::Command(std::string name, CommandType commandType, CommandPriority priority)
                : m_name(name), m_commandType(commandType), m_priority(priority) {}

        /*
        Get the name of the command.

        @return The name of the command.
        */
        std::string Command::getName() const
        {
                return m_name;
        }

        /*
        Get the type of the command.

        @return The type of the command.
        */
        CommandType Command::getCommandType() const
        {
                return m_commandType;
        }

        /*
        Get the priority of the command.

        @return The priority of the command.
        */
        CommandPriority Command::getPriority() const
        {
                return m_priority;
        }
}