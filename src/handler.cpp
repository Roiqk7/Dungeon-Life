/*
Date: 21/04/2021

Description: This file implements the handler base class from which other singleton handler classes inherit from.
*/

#include "../include/handler.hpp"

namespace Tool
{
        /*
        Submit a task to the handler.

        @param task The task to submit.
        */
        void Handler::submit(Tool::pPriorityQueueElement task)
        {
                // Add the task to the queue
                m_queue.push(task);
        }
}