/*
Date: 20/07/2024

Description: This file defines the task class which is a wrapper for tasks that can be executed by the thread manager.
*/

#ifndef TASK_HPP
#define TASK_HPP

#include <functional>
#include <memory>
#include "globals.hpp"

namespace ThreadManager
{
        using namespace Globals;

        /*
        The task class is a wrapper for tasks that can be executed by the thread manager.
        */
        class Task
        {
        public: // Methods
        // Constructor
                Task(std::function<void()> task, Type type, Priority priority); // Constructor
        // Task handling
                void execute();                                                 // Execute the task
        // Getters
                Priority getPriority() const;                                   // Get the priority of the task
                Type getType() const;                                           // Get the type of the task
        // Operators
                bool operator<(const Task& other) const;                        // Less than operator
        public: // Variables
                std::function<void()> m_task;                                   // Task to be executed
                Type m_type;                                                    // Type of the task
                Priority m_priority;                                            // Priority of the task
        };

        using pTask = std::unique_ptr<Task>;                                    // Alias for unique_ptr<Task>
}

#endif // !TASK_HPP