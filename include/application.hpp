/*
Date: 18/07/2024

Description: This file contains functions control the entire application.
*/

#ifndef APPLICATION_HPP
#define APPLICATION_HPP

namespace Application
{
        void initApplication();                                                 // Checks if the application is ready to run and initializes it
        void runApplication();                                                  // Runs the application loop
        void endApplication();                                                  // Ends the application gracefully
        void exitApplication();                                                 // Exits the application immediately
}

#endif // !APPLICATION_HPP