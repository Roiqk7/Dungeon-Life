/*
Date: 01/08/2024

Description: This file implements a singleton class which handles the frame rate of the application.
*/

#include <chrono>
#include "../include/frameHandler.hpp"
#include "../include/invoker.hpp"

namespace FrameHandler
{
        /*
        Handles one frame of the gameplay.
        */
        void FrameHandler::handleFrame()
        {
                // Calculate the delta time
                calculateDeltaTime();

                // Process the commands in the queue for the remaining time
                CommandSystem::Invoker::getInstance().processForDuration(getRemainingTime());

                // Sleep for the remaining time (if any)
                std::this_thread::sleep_for(getRemainingTime());
        }

        /*
        Calculate the delta time between frames.
        */
        void FrameHandler::calculateDeltaTime()
        {
                // Get the current time
                auto currentTime = std::chrono::high_resolution_clock::now();

                // Calculate the delta time
                auto deltaTime = std::chrono::duration_cast<std::chrono::microseconds>(currentTime - m_startTime);

                // Update the start time
                m_startTime = currentTime;
        }

        /*
        Get the remaining time until the next frame.

        @return The remaining time until the next frame.
        */
        std::chrono::microseconds FrameHandler::getRemainingTime()
        {
                // Get the current time
                auto currentTime = std::chrono::high_resolution_clock::now();

                // Calculate the remaining time
                auto remainingTime = std::chrono::duration_cast<std::chrono::microseconds>(m_startTime + std::chrono::microseconds(1000000 / FPS) - currentTime);

                // Check if the remaining time is negative
                if (remainingTime.count() < 0)
                {
                        // Return 0 microseconds (no time remaining)
                        return std::chrono::microseconds(0);
                }

                return remainingTime;
        }
}