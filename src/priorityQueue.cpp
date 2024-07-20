/*
Date: 20/07/2024

Description: This file implements the priority queue class template which is responsible for storing elements in a priority order.
*/

#include <condition_variable>
#include <mutex>
#include <queue>
#include <vector>
#include "../include/priorityQueue.hpp"

namespace Tool
{
        /*
        Push an element to the queue.

        @param element: The element to push to the queue.
        */
        template<typename T, typename Comparator>
        void PriorityQueue<T, Comparator>::push(const T& element)
        {
                // Lock the mutex
                std::lock_guard<std::mutex> lock(mutex);

                // Push the element to the queue
                queue.push(element);

                // Notify the condition variable that the queue is not empty
                notEmptyCondition.notify_one();
        }

        /*
        Pop an element from the queue.

        @return: The element that was popped from the queue. If the queue is empty, a default-constructed element is returned.
        */
        template<typename T, typename Comparator>
        T PriorityQueue<T, Comparator>::pop()
        {
                // Lock the mutex
                std::unique_lock<std::mutex> lock(mutex);

                // Wait until the queue is not empty
                notEmptyCondition.wait(lock, [this] { return !empty(); });

                // Get the top element from the queue
                T element = std::move(queue.top());
                queue.pop();

                return element;
        }

        /*
        Check if the queue is empty.

        @return: True if the queue is empty, false otherwise.
        */
        template<typename T, typename Comparator>
        bool PriorityQueue<T, Comparator>::empty() const
        {
                // Lock the mutex
                std::lock_guard<std::mutex> lock(mutex);

                // Check if the queue is empty
                return queue.empty();
        }
}