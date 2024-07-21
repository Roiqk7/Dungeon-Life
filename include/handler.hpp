/*
Date: 21/04/2021

Description: This file contains the handler base class from which other singleton handler classes inherit from.
*/

#ifndef HANDLER_HPP
#define HANDLER_HPP

#include "priorityQueue.hpp"

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
        protected: // Methods
        // Constructor
                Handler() = default;                                            // Constructor
        // Initialization
                virtual void init() = 0;                                        // Pure virtual function for initialization
        protected: // Variables
                Tool::PriorityQueue m_queue;                                    // Priority queue of tasks, with type specified by subclass
        };
}

#endif // !HANDLER_HPP