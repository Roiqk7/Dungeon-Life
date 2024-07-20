/*
Date: 20/07/2024

Description: This file implements the command queue class which is responsible for storing commands.
*/

#include <condition_variable>
#include <cstddef>
#include <memory>
#include <mutex>
#include "../include/CommandPriorityQueue.hpp"
#include "../include/globals.hpp"

namespace CommandSystem
{
        /*
        Push a command to the queue.

        @param command: The command to push to the queue.
        */
        void CommandPriorityQueue::push(pCommand command)
        {
                // Lock the mutex
                std::lock_guard<std::mutex> lock(mutex);

                // Push the command to the appropriate queue based on priority
                queues[static_cast<size_t>(command->getPriority())].push(std::move(command));

                // Notify the condition variable that the queue is not empty
                notEmptyCondition.notify_one();
        }

        /*
        Pop a command from the queue.

        @return: The command that was popped from the queue. If the queue is empty, nullptr is returned.
        */
        pCommand CommandPriorityQueue::pop()
        {
                // Lock the mutex
                std::unique_lock<std::mutex> lock(mutex);

                // Wait until the queue is not empty
                notEmptyCondition.wait(lock, [this] { return !empty(); });

                // Get the index of the queue with the highest priority that is not empty
                size_t topQueueIndex = getTopQueueIndex();

                // Check if the index is valid
                if (topQueueIndex != SIZE_T_MAX)
                {
                        // Pop the top command from the queue
                        pCommand command = std::move(queues[topQueueIndex].front());
                        queues[topQueueIndex].pop();

                        return command;
                }

                // Else return nullptr
                return nullptr;
        }

        /*
        Check if the queue is empty.

        @return: True if the queue is empty, false otherwise.
        */
        bool CommandPriorityQueue::empty() const
        {
                // Check if all queues are empty
                for (const auto& queue : queues)
                {
                        if (!queue.empty())
                        {
                                return false;
                        }
                }

                return true;
        }

        /*
        Get the index of the queue with the highest priority that is not empty.

        @return: The index of the queue with the highest priority that is not empty. If all queues are empty, SIZE_T_MAX is returned.
        */
        size_t CommandPriorityQueue::getTopQueueIndex() const
        {
                // Iterate through the queues in reverse order (highest priority first)
                // Note: We can not go bellow 0 because size_t is unsigned
                for (size_t i = queues.size(); i > 0; --i)
                {
                        // Check if the queue is not empty
                        if (!queues[i - 1].empty())
                        {
                                return i - 1;
                        }
                }

                return SIZE_T_MAX;
        }
}