/*
Date: 20/07/2024

Description: This file contains the priority queue class template which is responsible for storing elements in a priority order.
*/

#ifndef PRIORITY_QUEUE_HPP
#define PRIORITY_QUEUE_HPP

#include <condition_variable>
#include <mutex>
#include <queue>
#include <vector>

namespace Tool
{
	/*
	The PriorityQueue class template is responsible for storing elements in a priority order.
	It is a thread-safe priority queue.
	*/
	template<typename T, typename Comparator = std::less<T>>
	class PriorityQueue
	{
	public: // Methods
	// Constructor
		PriorityQueue() = default;                                      // Initialize the priority queue
	// Destructor
		~PriorityQueue() = default;                                     // Clean up the priority queue
	// Element handling
		void push(const T& element);                                    // Push an element to the queue
		T pop();                                                        // Pop an element from the queue
		bool empty() const;                                             // Check if the queue is empty
	public: // Variables
                mutable std::mutex mutex;                                       // Mutex to protect the queue (thread-safe)
                std::condition_variable notEmptyCondition;                      // Condition variable to notify when the queue is not empty
	private: // Variables
                std::priority_queue<T, std::vector<T>, Comparator> queue;       // Priority queue
	};
}

#endif // !PRIORITY_QUEUE_HPP