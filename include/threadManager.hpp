/*
Date: 20/07/2024

Description: This file defines the thread manager class which is responsible for managing threads.
*/

#ifndef THREAD_MANAGER_HPP
#define THREAD_MANAGER_HPP

#include <condition_variable>
#include <functional>
#include <future>
#include <map>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>
#include "globals.hpp"
#include "priorityQueue.hpp"
#include "task.hpp"

namespace ThreadManager
{
        using namespace Globals;

        /*
        Manages threads for the application.
        */
        class ThreadManager
        {
        public: // Methods
        // Destructor
                ~ThreadManager();                                               // Destructor
        // Singleton
                static ThreadManager& getInstance();
                ThreadManager(const ThreadManager&) = delete;                   // Delete copy constructor
                ThreadManager& operator=(const ThreadManager&) = delete;        // Delete copy assignment operator
        // Thread handling
                void submit(pTask task);                                        // Submit a task to the thread manager
        private: // Methods
        // Thread handling
                void worker();                                                  // Worker thread function
                void shutDown();                                                // Shut down the thread manager
        protected: // Constructor
                ThreadManager();                                                // Constructor
        private: // Variables
        // Thread handling
                std::map<Type, std::thread> m_threadPools;                      // Map of threads for each type
                size_t m_maxThreads;                                            // Maximum number of threads available
        // Tasks
                Tool::PriorityQueue<Task> m_queue;                              // Priority queue of tasks
        // System
                bool m_shutDown;                                                // Flag to indicate if the thread manager should shut down
        };
}

#endif // !THREAD_MANAGER_HPP