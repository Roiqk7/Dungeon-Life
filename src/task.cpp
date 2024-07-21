/*
Date: 21/07/2024

Description: This file implements the task class which is a wrapper for tasks that can be executed by the thread manager.
*/

#include "../include/task.hpp"

namespace ThreadManager
{
        /*
        Constructor.
        */
        Task::Task(std::function<void()> task, Type type, Priority priority)
                : m_task(task), m_type(type), m_priority(priority) {}

        /*
        Execute the task.
        */
        void Task::execute()
        {
                // Execute the task
                m_task();
        }

        /*
        Get the priority of the task.

        @return The priority of the task.
        */
        Priority Task::getPriority() const
        {
                return m_priority;
        }

        /*
        Get the type of the task.

        @return The type of the task.
        */
        Type Task::getType() const
        {
                return m_type;
        }

        /*
        Less than operator.

        @param other: The other task to compare to.

        @return True if this task has a lower priority than the other task, false otherwise.
        */
        bool Task::operator<(const Task& other) const
        {
                return m_priority < other.m_priority;
        }
}