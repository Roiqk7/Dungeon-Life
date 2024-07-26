/*
Date: 20/07/2024

Description: This file implements the priority queue class template which is responsible for storing elements in a priority order.
*/

#include <condition_variable>
#include <math.h>
#include <mutex>
#include <queue>
#include <vector>
#include "../include/globals.hpp"
#include "../include/priorityQueue.hpp"
#include "../include/priorityQueueElement.hpp"
#include "../include/threadManager.hpp"

#ifdef DEVELOPMENT
#include <cassert>
#else // RELEASE
#include "../include/exception.hpp"
#endif // RELEASE

namespace Tool
{
        /*
        Push an element to the queue.

        @param element The element to push.
        */
        void PriorityQueue::push(pPriorityQueueElement element)
        {
                // Validate the element
                if (!element)
                {
                        #ifdef DEVELOPMENT
                        LOG_WARN("PriorityQueue::push: Tried to push a nullptr to the queue.");
                        #endif // DEVELOPMENT

                        return;
                }

                // Check the multi-threaded flag
                if (ThreadManager::ThreadManager::getInstance().multiThreaded)
                {
                        // Lock the mutex
                        std::lock_guard<std::mutex> lock(mutex);
                }

                // Calculate the index of the priority
                size_t index = getPriorityIndex(element->getPriority());

                // Push the element to the queue
                queue[index].push(std::move(element));

                // Notify that the queue is not empty
                notEmptyCondition.notify_one();
        }

        /*
        Pop an element from the queue.

        @return The element popped from the queue. If the queue is empty, a nullptr is returned.
        */
        pPriorityQueueElement PriorityQueue::pop()
        {
                // Check the multi-threaded flag
                if (ThreadManager::ThreadManager::getInstance().multiThreaded)
                {
                        // Lock the mutex
                        std::lock_guard<std::mutex> lock(mutex);
                }

                // Iterate through the queue
                for (auto& q : queue)
                {
                        // Check if the queue is not empty
                        if (!q.empty())
                        {
                                #ifdef DEVELOPMENT
                                // Note: This should never happen
                                assert(q.front() != nullptr);
                                #else // RELEASE
                                // Throw an exception if the front element is a nullptr
                                if (q.front() == nullptr)
                                {
                                        throw Exception::Exception("PriorityQueue::pop: The front element is a nullptr.");
                                }
                                #endif // RELEASE

                                // Get the top element from the queue
                                pPriorityQueueElement element = std::move(q.front());

                                // Pop the element from the queue
                                q.pop();

                                // Return the element
                                return element;
                        }
                }

                // Return a nullptr
                return nullptr;
        }

        /*
        Check if the queue is empty.

        @return True if the queue is empty, false otherwise.
        */
        bool PriorityQueue::empty() const
        {
                // Iterate through the queue
                for (const auto& q : queue)
                {
                        // Check if the queue is not empty
                        if (!q.empty())
                        {
                                // Return false
                                return false;
                        }
                }

                // Return true
                return true;
        }


        /*
        Get the index of the priority in the queue.

        @param priority The priority to get the index of.

        @return The index of the priority in the queue.
        */
        size_t PriorityQueue::getPriorityIndex(Globals::Priority priority) const
        {
                // Convert the priority to size_t
                const size_t convertedPriority = static_cast<size_t>(priority);

                // Convert the Globals::Priority::Size to size_t
                const size_t convertedSize = static_cast<size_t>(Globals::Priority::Size);

                // Calculate the index of the priority
                // Note: This means that the highest priority is at the front of the array
                const size_t index = convertedSize - convertedPriority;

                #ifdef DEVELOPMENT
                // Validate the index
                assert(index < convertedSize);
                #else // RELEASE
                // Throw an exception if the index is invalid
                if (index >= convertedSize)
                {
                        throw Exception::Exception("PriorityQueue::getPriorityIndex: Out of range index.");
                }
                #endif // RELEASE

                // Return the index of the priority in the queue
                return index;
        }
}