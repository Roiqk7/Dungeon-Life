/*
Date: 20/07/2024

Description: This file defines the thread manager class which is responsible for managing threads.
*/

#ifndef THREAD_MANAGER_HPP
#define THREAD_MANAGER_HPP

#include <condition_variable>
#include <functional>
#include <future>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>
#include "globals.hpp"
#include "priorityQueue.hpp"
#include "task.hpp"

namespace ThreadManager
{
        /*
        Manages threads for the application.
        */
        class ThreadManager
        {
        public: // Methods
        // Constructor
                ThreadManager();                                                // Constructor
        // Destructor
                ~ThreadManager();                                               // Destructor
        // Thread handling
                void submit(pTask task);                                        // Submit a task to the thread manager
                void shutDown();                                                // Shut down the thread manager
        private: // Methods
        // Thread handling
                void worker();                                                  // Worker thread function
        private: // Variables
                std::vector<std::thread> m_threads;                             // Vector to hold worker threads
                Tool::PriorityQueue<Task> m_queue;                              // Priority queue of tasks
                bool m_shutDown;                                                // Flag to indicate if the thread manager should shut down

        };
}

#endif // !THREAD_MANAGER_HPP