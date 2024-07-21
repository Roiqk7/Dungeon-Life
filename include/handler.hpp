/*
Date: 21/04/2021

Description: This file contains the handler base class from which other singleton handler classes inherit from.
*/

#ifndef HANDLER_HPP
#define HANDLER_HPP

#include "priorityQueue.hpp"
#include "priorityQueueElement.hpp"

namespace Handler
{
        /*
        The handler class is a base class from which other singleton handler classes inherit from.
        */
        template<typename Derived>
        class Handler
        {
        public: // Methods
        // Destructor
                virtual ~Handler() = default;
        // Singleton
                static Derived& getInstance();                                  // Get the instance of the handler
                Handler(const Handler&) = delete;                               // Delete copy constructor
                Handler& operator=(const Handler&) = delete;                    // Delete copy assignment operator
        // Task handling
                void submit(Tool::pPriorityQueueElement task);                  // Submit a task to the handler
                void processTasks();                                            // Process all tasks in the queue
        protected: // Methods
        // Constructor
                Handler() = default;                                            // Constructor
        // Initialization
                virtual void init() = 0;                                        // Pure virtual function for initialization
        // Task handling
                virtual void handleTask(Tool::pPriorityQueueElement task) = 0;  // Handle a task
        protected: // Variables
                Tool::PriorityQueue m_queue;                                    // Priority queue of tasks, with type specified by subclass
        };
}

#endif // !HANDLER_HPP