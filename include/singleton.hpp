/*
Date: 21/07/2024

Description: This file contains the singleton base class from which other singleton classes inherit from.
*/

#ifndef SINGLETON_HPP
#define SINGLETON_HPP

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
        protected: // Methods
        // Constructor
                Singleton() = default;
        };
}

#endif // !SINGLETON_HPP