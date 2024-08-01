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

                // Register the instance of the singleton class
                registerInstance(std::make_unique<Derived>(instance));

                // Return the instance of the singleton class
                return instance;
        }

        /*
        Get the instances of the singleton class.

        @return Instances of the singleton class
        */
        template<typename Derived>
        const std::vector<std::unique_ptr<Derived>>& Singleton<Derived>::getInstances()
        {
                // Return the instances of the singleton class
                return m_instances;
        }

        /*
        Register the instance of the singleton class.

        @param instance Instance of the singleton class
        */
        template<typename Derived>
        void Singleton<Derived>::registerInstance(std::unique_ptr<Derived> instance)
        {
                // Add the instance to the vector of instances
                m_instances.push_back(std::move(instance));
        }
}