/*
Date: 20/07/2024

Description: This file defines the thread manager class which is responsible for managing threads.
*/

#ifndef THREAD_MANAGER_HPP
#define THREAD_MANAGER_HPP

#include <thread>
#include <vector>
#include "handler.hpp"
#include "priorityQueue.hpp"
#include "task.hpp"

namespace ThreadManager
{
        using namespace Globals;

        class ThreadManager : public Handler::Handler<ThreadManager>
        {
        public: // Methods
        // Destructor
                ~ThreadManager();                                               // Destructor which is responsible for shutting down all threads
        private: // Methods
        // Thread handling
                void worker();                                                  // Worker thread function
                void shutDown();                                                // Shut down the thread manager
        private: // Methods
        // Initialization
                void init() override;                                           // Initialize the thread manager
        // Task handling
                void handleTask(Tool::pPriorityQueueElement task) override;     // Handle a task
        private: // Variables
        // Thread handling
                std::vector<std::thread> m_threads;                             // Vector of threads which are dynamically created based on the workload
                std::thread m_taskHandler;                                      // Thread to handle tasks (used by the thread manager)
                size_t m_maxThreads;                                            // Maximum number of threads available
        // Tasks
                Tool::PriorityQueue m_queue;                                    // Priority queue of tasks
        // System
                bool m_shutDown;                                                // Flag to indicate if the thread manager should shut down
        };
}

#endif // !THREAD_MANAGER_HPP