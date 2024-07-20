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

namespace ThreadManager
{
        /*
        Manages threads for the application.
        */
        class ThreadManager
        {
        private: // Variables
                std::vector<std::thread> m_threads;                             // Vector to hold worker threads
        };
}

#endif // !THREAD_MANAGER_HPP