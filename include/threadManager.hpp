/*
Date: 20/07/2024

Description: This file defines the thread manager class which is responsible for managing threads.
*/

#ifndef THREAD_MANAGER_HPP
#define THREAD_MANAGER_HPP

#include <atomic>
#include <functional>
#include <thread>
#include <vector>
#include "handler.hpp"
#include "priorityQueue.hpp"

namespace ThreadManager
{
        using namespace Globals;

        class ThreadManager : public Tool::Handler<ThreadManager>
        {
        public: // Methods
        // Destructor
                ~ThreadManager();                                               // Destructor which is responsible for shutting down all threads
        private: // Methods
        // Constructor
                ThreadManager();                                                // Constructor
        // Thread handling
                void worker();                                                  // Worker thread function
                void shutDown();                                                // Shut down the thread manager
                template<typename Func, typename... Args>
                void requestThread(Func&& func, Args&&... args);                // Request a thread
        // Initialization
                void init() override;                                           // Initialize the thread manager
        // Task handling
                void handleTask(Tool::pPriorityQueueElement task) override;     // Handle a task
        public: // Variables
                bool multiThreaded;                                             // Flag to indicate if the system is multi-threaded
        private: // Variables
        // Thread handling
                std::vector<std::thread> m_threads;                             // Vector of threads which are dynamically created based on the workload
                size_t m_maxThreads;                                            // Maximum number of threads available
        // System
                std::atomic<bool> m_shutDown;                                   // Flag to indicate if the thread manager should shut down
        };
}

#endif // !THREAD_MANAGER_HPP