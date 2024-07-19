/*
Date: 19/07/2024

Description: This file defines a singleton class which handles the frame rate of the application.
*/

#ifndef FRAME_HANDLER_HPP
#define FRAME_HANDLER_HPP

#include <chrono>
#include <thread>
#include "globals.hpp"

namespace FrameHandler
{
        /*
        Calculates the delta time between frames. Makes sure the app runs at a
                constant frame rate.
        */
        class FrameHandler
        {
        public: // Methods
        // Singleton
                static FrameHandler& getInstance();                             // Get the instance of the frame handler
                FrameHandler(const FrameHandler&) = delete;                     // Delete copy constructor
                FrameHandler& operator=(const FrameHandler&) = delete;          // Delete copy assignment operator
        // Frame handling
                void handleFrame();                                             // Handle the frame (sleep if necessary)
                std::chrono::microseconds getDeltaTime();                       // Get the delta time
                std::chrono::microseconds getRemainingTime();                   // Get the remaining time until the next frame
        private: // Methods
                void init();                                                    // Initialize the frame handler
                void calculateDeltaTime();                                      // Calculate the delta time
        private: // Variables
                std::chrono::time_point<std::chrono::high_resolution_clock>
                        m_startTime;                                            // Reference time based on the initiation of the frame handler
                std::chrono::microseconds m_deltaTime;                          // Delta time between frames
        };
}

#endif // !FRAME_HANDLER_HPP