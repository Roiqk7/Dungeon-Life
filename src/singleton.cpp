/*
Date: 21/07/2024

Description: This file implements the singleton base class from which other singleton classes inherit from.
*/

#include "../include/singleton.hpp"

namespace Tool
{
        /*
        Get the instance of the singleton class.
        */
        template<typename Derived>
        Derived& Singleton<Derived>::getInstance()
        {
                // Create the instance of the singleton class
                static Derived instance;

                // Return the instance of the singleton class
                return instance;
        }
}