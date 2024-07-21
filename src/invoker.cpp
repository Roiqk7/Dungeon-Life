/*
Date: 20/07/2024

Description: This file implements the invoker class which is responsible for executing the commands in the queue.
*/

#include "../include/invoker.hpp"
#include "../include/globals.hpp"
#include "../include/threadManager.hpp"

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
        Sleep until a command is submitted.
        */
        void Invoker::waitCommand()
        {
                // Lock the mutex
                std::unique_lock<std::mutex> lock(m_queue.mutex);

                // Wait until the queue is not empty
                m_queue.notEmptyCondition.wait(lock, [this] { return !m_queue.empty(); });
        }

        /*
        Process the commands in the queue given a duration.

        @param duration: The duration to process the commands.
        */
        void Invoker::processForDuration(const std::chrono::microseconds& duration)
        {
                // Get the start time
                auto startTime = std::chrono::high_resolution_clock::now();

                // While the queue is not empty and the duration has not elapsed
                // TODO: Make the duration check into a function
                while(!m_queue.empty() && std::chrono::high_resolution_clock::now() - startTime < duration)
                {
                        // Process the command
                        handleTask(m_queue.pop());
                }
        }

        /*
        Constructor. Initializes the invoker.
        */
        Invoker::Invoker()
        {
                // Log the creation of the invoker
                LOG_INFO("Invoker instance created.");

                // Initialize the invoker
                init();
        }

        /*
        Process a command.

        @param command: The command to process.
        */
        void Invoker::handleTask(Tool::pPriorityQueueElement task)
        {
                // Check if the command is valid
                if (task)
                {
                        // Log the command execution
                        LOG_TRACE("Executing command: " + task->getName());

                        // Execute the command
                        ThreadManager::ThreadManager::getInstance().submit(std::move(task));
                }
        }
}