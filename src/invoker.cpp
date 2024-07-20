/*
Date: 20/07/2024

Description: This file implements the invoker class which is responsible for executing the commands in the queue.
*/

#include "../include/invoker.hpp"
#include "../include/globals.hpp"

namespace CommandSystem
{
        /*
        Destructor. Cleans up the invoker.
        */
        Invoker::~Invoker()
        {
                // Log the destruction of the invoker
                LOG_INFO("Invoker instance destroyed.");
        }

        /*
        Returns the instance of the invoker.

        @return The instance of the invoker.
        */
        Invoker& Invoker::getInstance()
        {
                static Invoker instance;
                return instance;
        }

        /*
        Sleep until a command is submitted.
        */
        void Invoker::waitCommand()
        {
                // Lock the mutex
                std::unique_lock<std::mutex> lock(m_commandQueue.mutex);

                // Wait until the queue is not empty
                m_commandQueue.notEmptyCondition.wait(lock, [this] { return !m_commandQueue.empty(); });
        }

        /*
        Submit a command to the invoker.

        @param command: The command to submit.
        */
        void Invoker::submit(pCommand command)
        {
                // Push the command to the queue
                m_commandQueue.push(std::move(command));
        }

        /*
        Process all the commands in the queue.
        */
        void Invoker::process()
        {
                // While the queue is not empty
                while(!m_commandQueue.empty())
                {
                        // Process the command
                        processCommand(m_commandQueue.pop());
                }
        }

        /*
        Process the commands in the queue given a duration.

        @param duration: The duration to process the commands.
        */
        void Invoker::process(const std::chrono::microseconds& duration)
        {
                // Get the start time
                auto startTime = std::chrono::high_resolution_clock::now();

                // While the queue is not empty and the duration has not elapsed
                // TODO: Make the duration check into a function
                while(!m_commandQueue.empty() && std::chrono::high_resolution_clock::now() - startTime < duration)
                {
                        // Process the command
                        processCommand(m_commandQueue.pop());
                }
        }

        /*
        Constructor. Initializes the invoker.
        */
        Invoker::Invoker()
        {
                // Log the creation of the invoker
                LOG_INFO("Invoker instance created.");
        }

        /*
        Process a command.

        @param command: The command to process.
        */
        void Invoker::processCommand(pCommand command)
        {
                // Check if the command is valid
                if (command)
                {
                        // Log the command execution
                        LOG_TRACE("Executing command: " + command->getName());

                        // Execute the command
                        command->execute();
                }
        }
}