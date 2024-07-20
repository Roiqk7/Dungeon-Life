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
        class CommandPriorityQueue
        {
        public: // Methods
        // Constructor
                CommandPriorityQueue() = default;                               // Initialize the command queue
        // Destructor
                ~CommandPriorityQueue() = default;                              // Clean up the command queue
        // Command handling
                void push(pCommand command);                                    // Push a command to the queue
                pCommand pop();                                                 // Pop a command from the queue
                bool empty() const;                                             // Check if the queue is empty
        private: // Methods
                mutable std::mutex mutex;                                       // Mutex to protect the queue (thread-safe)
                std::condition_variable notEmptyCondition;                      // Condition variable to notify when the queue is not empty
                std::array<CommandQueue,
                        static_cast<size_t>(CommandPriority::Size)> queues;     // Array of queues based on priority
        };
}

#endif // !COMMAND_QUEUE_HPP