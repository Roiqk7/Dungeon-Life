/*
Date: 21/07/2024

Description: This file implements the priority queue element class which is used to store elements in a priority queue.
*/

#include <functional>
#include <memory>
#include <string>
#include "../include/globals.hpp"
#include "../include/priorityQueueElement.hpp"

namespace Tool
{
        #ifdef TEST
        /*
        Constructor. Should be used only for testing.

        @param name Name of the element
        @param priority Priority of the element
        */
        PriorityQueueElement(const std::string& name,
                Globals::Priority priority)
                : m_name(name), m_priority(priority), m_type(Globals::Type::Test), m_callback([](){}) {}
        #endif // TEST

        /*
        Constructor.

        @param name Name of the element
        @param priority Priority of the element
        @param type Type of the element
        @param callback Callback function to execute when the element is processed
        */
        PriorityQueueElement::PriorityQueueElement(const std::string& name,
                Globals::Priority priority,
                Globals::Type type, std::function<void()> callback)
                : m_name(name), m_priority(priority), m_type(type), m_callback(callback) {}

        /*
        Get the name of the element.

        @return Name of the element
        */
        const std::string& PriorityQueueElement::getName() const
        {
                return m_name;
        }

        /*
        Get the priority of the element.

        @return Priority of the element
        */
        Globals::Priority PriorityQueueElement::getPriority() const
        {
                return m_priority;
        }

        /*
        Get the type of the element.

        @return Type of the element
        */
        Globals::Type PriorityQueueElement::getType() const
        {
                return m_type;
        }

        /*
        Clone the element.

        @return A unique pointer to a copy of the element
        */
        pPriorityQueueElement PriorityQueueElement::clone() const
        {
                return std::make_unique<PriorityQueueElement>(m_name, m_priority, m_type, m_callback);
        }

        /*
        Execute the callback function.
        */
        void PriorityQueueElement::execute()
        {
                m_callback();
        }

        /*
        Equality operator.

        @param other Other element to compare

        @return True if the elements are equal, false otherwise
        */
        bool PriorityQueueElement::operator==(const PriorityQueueElement& other) const
        {
                return m_name == other.m_name && m_priority == other.m_priority;
        }

        /*
        Less than operator.

        @param other Other element to compare

        @return True if this element is less than the other, false otherwise
        */
        bool PriorityQueueElement::operator<(const PriorityQueueElement& other) const
        {
                return m_priority < other.m_priority;
        }

        /*
        Comparator for priority queue elements.

        @param lhs Left-hand side element
        @param rhs Right-hand side element

        @return True if the left-hand side element is less than the right-hand side element, false otherwise
        */
        bool pPriorityQueueElementComparator::operator()(const pPriorityQueueElement& lhs, const pPriorityQueueElement& rhs) const
        {
                return *lhs < *rhs;
        }
}