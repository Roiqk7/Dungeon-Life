/*
Date: 21/07/2024

Description: This file contains the priority queue element class which is used to store elements in a priority queue.
*/

#ifndef PRIORITY_QUEUE_ELEMENT_HPP
#define PRIORITY_QUEUE_ELEMENT_HPP

#include <functional>
#include <string>
#include "globals.hpp"

namespace Tool
{
        /*
        Base class for priority queue elements
        */
        class PriorityQueueElement
        {
        public: // Methods
        // Constructor
                PriorityQueueElement(const std::string& name, Globals::Priority priority,
                        Globals::Type type, std::function<void()> callback);
        // Destructor
                virtual ~PriorityQueueElement() = default;
        // Callback execution
                void execute();                                                 // Execute the callback function
        // Operators
                bool operator<(const PriorityQueueElement& other) const;        // Less than operator
        protected: // Variables
                std::string m_name;                                             // Name of the element
                Globals::Priority m_priority;                                   // Priority of the element
                Globals::Type m_type;                                           // Type of the element
                std::function<void()> m_callback;                               // Callback function to execute when the element is processed
        };

        using pPriorityQueueElement = std::unique_ptr<PriorityQueueElement>;    // Alias for unique_ptr<PriorityQueueElement>

        /*
        Comparator for priority queue elements
        */
        struct pPriorityQueueElementComparator
        {
        // Operator
                bool operator()(const pPriorityQueueElement& lhs, const pPriorityQueueElement& rhs) const;
        };
}

#endif // !PRIORITY_QUEUE_ELEMENT_HPP