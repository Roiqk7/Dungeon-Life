/*
Date: 20/07/2024

Description: This file contains the command queue class which is responsible for storing commands.
*/

#ifndef COMMAND_QUEUE_HPP
#define COMMAND_QUEUE_HPP

#include <condition_variable>
#include <memory>
#include <mutex>
#include <queue>
#include <vector>
#include "command.hpp"

namespace CommandSystem
{
        class CommandQueue
        {
        public: // Methods
        // Constructor
                CommandQueue() = default;                                       // Initialize the command queue
        // Destructor
                ~CommandQueue() = default;                                      // Clean up the command queue
        // Delete copy constructor and copy assignment operator
                CommandQueue(const CommandQueue&) = delete;
                CommandQueue& operator=(const CommandQueue&) = delete;
        // Delete move constructor and move assignment operator
                CommandQueue(CommandQueue&&) = delete;
                CommandQueue& operator=(CommandQueue&&) = delete;
        // Command handling
                void push(pCommand command);                                    // Push a command to the queue
                pCommand pop();                                                 // Pop a command from the queue
                bool empty() const;                                             // Check if the queue is empty
        private: // Methods
                mutable std::mutex mutex;                                       // Mutex to protect the queue (thread-safe)
                std::condition_variable emptyCondition;                         // Condition variable to notify when the queue IS empty
                std::priority_queue<pCommand, std::vector<pCommand>,
                        CommandComparator> queue;                               // Priority queue to store commands
        };
}

#endif // !COMMAND_QUEUE_HPP