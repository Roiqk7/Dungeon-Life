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
#include "priorityQueue.hpp"

namespace CommandSystem
{
        /*
        Handles the execution of commands in the queue.
        */
        class Invoker                                                           // Singleton class
        {
        public: // Methods
        // Destructor
                ~Invoker();
        // Singleton
                static Invoker& getInstance();
                Invoker(const Invoker&) = delete;                               // Delete copy constructor
                Invoker& operator=(const Invoker&) = delete;                    // Delete copy assignment operator
        // Command handling
                void waitCommand();                                             // Sleep until a command is submitted
                void submit(pCommand command);                                  // Submit a command to the invoker
                void process();                                                 // Process all the commands in the queue
                void process(const std::chrono::microseconds& duration);        // Process the commands in the queue given a duration
        // Checks
                bool empty() const;                                             // Check if the queue is empty
        protected: // Constructor
                Invoker();                                                      // Constructor
        private: // Methods
        // Command handling
                void processCommand(pCommand command);                          // Process a command
        private: // Variables
        // Command handling
                Tool::PriorityQueue<pCommand> m_queue;                          // Priority queue to hold commands
        };
}

#endif // !INVOKER_HPP