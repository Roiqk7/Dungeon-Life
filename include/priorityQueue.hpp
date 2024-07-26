/*
Date: 20/07/2024

Description: This file contains the priority queue class template which is responsible for storing elements in a priority order.
*/

#ifndef PRIORITY_QUEUE_HPP
#define PRIORITY_QUEUE_HPP

#include <array>
#include <condition_variable>
#include <mutex>
#include <queue>
#include <vector>
#include "globals.hpp"
#include "priorityQueueElement.hpp"

namespace Tool
{
        /*
        The PriorityQueue class template is responsible for storing elements in a priority order.
        It is a thread-safe priority queue.
        */
        class PriorityQueue
        {
        public: // Methods
        // Constructor
                PriorityQueue() = default;                                      // Initialize the priority queue
        // Destructor
                ~PriorityQueue() = default;                                     // Clean up the priority queue
        // Element handling
                void push(pPriorityQueueElement element) noexcept;              // Push an element to the queue
                pPriorityQueueElement pop() noexcept;                           // Pop an element from the queue
                bool empty() const noexcept;                                    // Check if the queue is empty
        private: // Methods
                size_t getPriorityIndex(Globals::Priority priority) const;      // Get the index of the priority in the queue
        public: // Variables
                mutable std::mutex mutex;                                       // Mutex to protect the queue (thread-safe)
                std::condition_variable notEmptyCondition;                      // Condition variable to notify when the queue is not empty
        private: // Variables
                // Note: Most important priority is at the front of the array
                std::array<std::queue<pPriorityQueueElement>,
                        static_cast<size_t>(Globals::Priority::Size)> queue;    // The priority queue (array of queues)
        };
}

#endif // !PRIORITY_QUEUE_HPP