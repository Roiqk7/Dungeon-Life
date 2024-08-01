/*
Date: 19/07/2024

Description: This file defines a singleton class which handles the frame rate of the application.
*/

#ifndef FRAME_HANDLER_HPP
#define FRAME_HANDLER_HPP

#include <chrono>
#include <thread>
#include "globals.hpp"
#include "singleton.hpp"

namespace FrameHandler
{
        /*
        Calculates the delta time between frames. Makes sure the app runs at a
                constant frame rate.
        */
        class FrameHandler : public Tool::Singleton<FrameHandler>
        {
        public: // Methods
        // Frame handling
                void handleFrame();                                             // Handle the frame (sleep if necessary)
        private: // Methods
        // Time handling
                void calculateDeltaTime();                                      // Calculate the delta time
                std::chrono::microseconds getRemainingTime();                   // Get the remaining time until the next frame
        private: // Variables
                std::chrono::time_point<std::chrono::high_resolution_clock>
                        m_startTime;                                            // Reference time based on the initiation of the frame handler
        };
}

#endif // !FRAME_HANDLER_HPP