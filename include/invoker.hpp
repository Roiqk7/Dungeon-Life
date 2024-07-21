/*
Date: 18/07/2024

Description: This file contains the invoker class which is responsible for executing the commands in the queue.

Notes: Follows the command pattern.
*/

#ifndef INVOKER_HPP
#define INVOKER_HPP

#include <chrono>
#include <condition_variable>
#include <memory>
#include <mutex>
#include "command.hpp"
#include "globals.hpp"
#include "handler.hpp"
#include "priorityQueue.hpp"

namespace CommandSystem
{
        class Invoker : public Tool::Handler<Invoker>
        {
        public: // Methods
        // Destructor
                ~Invoker();                                                     // Destructor
        // Command handling
                void waitCommand();                                             // Sleep until a command is submitted
                void processForDuration(
                        const std::chrono::microseconds& duration);             // Process the commands in the queue given a duration
        private: // Methods
        // Initialization
                void init() override;                                           // Initialize the invoker
        // Task handling
                void handleTask(Tool::pPriorityQueueElement task) override;     // Handle a task
        };
}

#endif // !INVOKER_HPP