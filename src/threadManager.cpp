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
        Request a thread.

        @param func The function to execute in the thread
        @param args The arguments to pass to the function
        */
        template<typename Func, typename... Args>
        void ThreadManager::requestThread(Func&& func, Args&&... args)
        {
                // Check the shutdown flag
                if (!m_shutDown)
                {
                        // Check if the number of threads is less than the maximum
                        // Note: We add 1 as it represents the main thread
                        if (m_threads.size() + 1 <= m_maxThreads)
                        {
                                // Create a new thread
                                m_threads.push_back(std::thread(func, args...));

                                // Update the multi-threaded flag
                                multiThreaded = true;
                        }
                }
        }

        /*
        Constructor.
        */
        ThreadManager::ThreadManager()
                : m_maxThreads(std::thread::hardware_concurrency()),
                multiThreaded(false), m_shutDown(false)
        {
                // Initialize the thread manager
                init();
        }

        /*
        Worker thread function.
        */
        void ThreadManager::worker()
        {
                // Work until the thread manager is shut down
                while (!m_shutDown)
                {
                        // Process the task queue
                        process();
                }
        }

        /*
        Shut down the thread manager.
        */
        void ThreadManager::shutDown()
        {
                // Set the shut down flag
                m_shutDown = true;

                // Join the main thread
                if (m_mainThread.joinable())
                {
                        m_mainThread.join();
                }

                // Join the other threads
                for (auto& thread : m_threads)
                {
                        // Check if the thread is joinable
                        if (thread.joinable())
                        {
                                // Join the thread
                                thread.join();
                        }
                }
        }

        /*
        Initialize the thread manager.
        */
        void ThreadManager::init()
        {
                // Initialize the main thread
                m_mainThread = std::thread(&ThreadManager::worker, this);
        }

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
}