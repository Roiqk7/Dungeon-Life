/*
Date: 21/07/2024

Description: This file contains the singleton base class from which other singleton classes inherit from.
*/

#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include <functional>
#include <vector>

namespace Tool
{
        /*
        The singleton class is a base class from which other singleton classes inherit from.
        */
        template<typename Derived>
        class Singleton
        {
        public: // Methods
        // Destructor
                virtual ~Singleton() = default;
        // Singleton
                static Derived& getInstance();
                Singleton(const Singleton&) = delete;
                Singleton& operator=(const Singleton&) = delete;
        // Central
                static void initAll();
                static void cleanupAll();
        protected: // Methods
        // Constructor
                Singleton() = default;
        // Cleanup
                static void cleanup();
        private: // Methods
        // Cleanup
                static std::vector<std::function<void()>>& getCleanupFunctions();
        // Register cleanup function
                static void registerCleanupFunction(std::function<void()> cleanupFunction);
        };
}

#endif // !SINGLETON_HPP