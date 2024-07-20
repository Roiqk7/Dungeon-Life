/*
Date: 20/07/2024

Description: This file implementss commands classes which are then handed to the invoker to execute.

Notes: Follows the command pattern.
*/

#include "../include/command.hpp"
#include "../include/globals.hpp"
#include "../include/task.hpp"
#include "../include/threadManager.hpp"

namespace CommandSystem
{
        using namespace Globals;

// Command base class
        /*
        Constructor. Initializes the command.

        @param name: The name of the command.
        @param commandType: The type of the command.
        @param priority: The priority of the command.
        */
        Command::Command(std::string name, Type type, Priority priority)
                : m_name(name), m_type(type), m_priority(priority) {}

        /*
        Execute the command function.
        */
        void Command::execute()
        {
                // Create the task
                ThreadManager::pTask task =
                        std::make_unique<ThreadManager::Task>(
                        m_function, m_priority);

                // Submit the task to the thread manager
                ThreadManager::ThreadManager::getInstance().submit(std::move(task));
        }

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
        Type Command::getType() const
        {
                return m_type;
        }

        /*
        Get the priority of the command.

        @return The priority of the command.
        */
        Priority Command::getPriority() const
        {
                return m_priority;
        }

        /*
        Less than operator.

        @param other: The other command to compare to.

        @return True if this command has a lower priority than the other command, false otherwise.
        */
        bool Command::operator<(const Command& other) const
        {
                return m_priority < other.m_priority;
        }
}