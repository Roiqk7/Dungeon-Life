/*
Date: 21/07/2024

Description: This file implements the thread manager class which is responsible for managing threads.
*/

#include <thread>
#include <vector>
#include "../include/priorityQueue.hpp"
#include "../include/threadManager.hpp"

namespace ThreadManager
{
        /*
        Destructor which is responsible for shutting down all threads.
        */
        ThreadManager::~ThreadManager()
        {
                // Shut down the thread manager
                shutDown();
        }

        /*
        Constructor.

        ThreadManager::ThreadManager()
                : m_maxThreads(std::thread::hardware_concurrency()), m_shutDown(false)
        {
                // Create the task handler thread
                m_taskHandler = std::thread(&ThreadManager::handleTask, this);

                // Create single worker thread
                m_threads.push_back(std::thread(&ThreadManager::worker, this));
        }
        */

        /*
        Handle a task.
        */
        void ThreadManager::handleTask(Tool::pPriorityQueueElement task)
        {
                // Handle tasks until the thread manager is shut down
                while (!m_shutDown)
                {
                        // Execute the task
                        task->execute();
                }
        }

        /*
        Worker thread function.
        */
        void ThreadManager::worker()
        {
                // Work until the thread manager is shut down
                while (!m_shutDown)
                {
                        // Lock the mutex
                        std::unique_lock<std::mutex> lock(m_queue.mutex);

                        // Wait until the queue is not empty
                        m_queue.notEmptyCondition.wait(lock, [this] { return !m_queue.empty(); });

                        // Get the next task
                        Tool::pPriorityQueueElement task = m_queue.pop();

                        // Execute the task
                        task->execute();
                }
        }

        /*
        Shut down the thread manager.
        */
        void ThreadManager::shutDown()
        {
                // Set the shut down flag
                m_shutDown = true;

                // Join the worker threads
                for (auto& thread : m_threads)
                {
                        thread.join();
                }

                // Join the task handler thread
                m_taskHandler.join();
        }
}