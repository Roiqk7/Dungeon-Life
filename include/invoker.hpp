/*
Date: 18/07/2024

Description: This file contains the invoker class which is responsible for executing the commands in the queue.

Notes: Follows the command pattern.
*/

#ifndef INVOKER_HPP
#define INVOKER_HPP

#include <condition_variable>
#include <memory>
#include <mutex>
#include <queue>
#include "command.hpp"
#include "globals.hpp"

namespace CommandSystem
{
        /*
        Handles the execution of commands in the queue.
        */
        class Invoker                                                           // Singleton class
        {
        public: // Variables
                bool run;                                                       // Flag which indicates if the invoker should keep running
        public: // Methods
        // Destructor
                ~Invoker();
        // Singleton
                static Invoker& getInstance();
                Invoker(const Invoker&) = delete;                              // Delete copy constructor
                Invoker& operator=(const Invoker&) = delete;                   // Delete copy assignment operator
        // Command handling
                void waitCommand();                                            // Sleep until a command is submitted
                void submit(pCommand command);                                 // Submit a command to the invoker
                void process();                                                // Process the commands in the queue
        private: // Variables
        // Command system
                std::mutex m_mutex;                                             // Mutex for the command queue
                std::condition_variable m_conditionVariable;                    // Condition variable for the command queue
        // Command handling
                CommandQueue m_commandQueue;                                    // Queue of commands ordered by priority
        private: // Methods
                void init();                                                    // Initialize the invoker
                void clean();                                                   // Clean up the invoker
        protected: // Constructor
                Invoker();                                                      // Constructor
        };
}

#endif // !INVOKER_HPP