/*
Date: 21/04/2021

Description: This file implements the handler base class from which other singleton handler classes inherit from.
*/

#include "../include/handler.hpp"

#ifdef DEVELOPMENT
#include <cassert>
#endif

namespace Tool
{
        /*
        Submit a task to the handler.

        @param task The task to submit.
        */
        template<typename Derived>
        void Handler<Derived>::submit(Tool::pPriorityQueueElement task)
        {
                // Check if the task is valid
                #ifdef DEVELOPMENT
                assert(task != nullptr);
                #endif

                // Add the task to the queue
                m_queue.push(task);
        }

        /*
        Process all tasks in the queue.
        */
        template<typename Derived>
        void Handler<Derived>::process()
        {
                // Process all tasks in the queue
                while (!m_queue.empty())
                {
                        // Get the top task from the queue
                        Tool::pPriorityQueueElement task = m_queue.pop();

                        // Handle the task
                        handleTask(task);
                }
        }

        /*
        Check if the queue is empty.

        @return True if the queue is empty, false otherwise.
        */
        template<typename Derived>
        bool Handler<Derived>::empty() const
        {
                // Check if the queue is empty
                return m_queue.empty();
        }
}