/*
Date: 21/07/2024

Description: This file contains the singleton base class from which other singleton classes inherit from.
*/

#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include <memory>
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
        // Management
                static const std::vector<std::unique_ptr<Derived>>& getInstances();
        protected: // Methods
        // Constructor
                Singleton() = default;
        private: // Methods
        // Management
                static void registerInstance(std::unique_ptr<Derived> instance);
        private: // Variables
        // Management
                static std::vector<std::unique_ptr<Derived>> m_instances;
        };

        // Initialize the static vector
        template<typename Derived>
        std::vector<std::unique_ptr<Derived>> Singleton<Derived>::m_instances;
}

#endif // !SINGLETON_HPP