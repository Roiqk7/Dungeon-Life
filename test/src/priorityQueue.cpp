/*
Date: 20/07/2024

Description: This file contains tests for the priority queue.
*/

#ifndef TEST
#error "Tried to compile a test file without the TEST macro defined. Aborting compilation."
#else

#include <fstream>
#include <gtest/gtest.h>
#include <string>
#include "../../include/globals.hpp"
#include "../../include/priorityQueue.hpp"
#include "../../include/priorityQueueElement.hpp"

#ifdef DEVELOPMENT
#include <spdlog/spdlog.h>
#endif // DEVELOPMENT

/*
Pushing an element to the queue.

Expected: The method should push the element to the queue. Thus the queue
should not be empty.
*/
TEST(PriorityQueue, pushElement)
{
        // Create a priority queue
        Tool::PriorityQueue queue;

        // Create a priority queue element
        Tool::pPriorityQueueElement element = std::make_unique<Tool::PriorityQueueElement>(
                "Name", Globals::Priority::High);

        // Push the element to the queue
        queue.push(std::move(element));

        // Check if the queue is not empty
        EXPECT_TRUE(!queue.empty());
}

/*
Pushing nullptr to the queue.

Expected: The method should not push the nullptr to the queue. Thus the queue
should remain empty.
*/
TEST(PriorityQueue, pushNullptr)
{
        // Create a priority queue
        Tool::PriorityQueue queue;

        // Push a nullptr to the queue
        queue.push(nullptr);

        // Check if the queue is empty
        EXPECT_TRUE(queue.empty());
}

/*
Popping an element from the queue.

Expected: The method should pop the element from the queue. The popped element
should be the same as the element pushed to the queue.
*/
TEST(PriorityQueue, popElement)
{
        // Create a priority queue
        Tool::PriorityQueue queue;

        // Create a priority queue element
        Tool::pPriorityQueueElement element = std::make_unique<Tool::PriorityQueueElement>(
                "Name", Globals::Priority::High);

        // Clone the element
        Tool::pPriorityQueueElement clone = element->clone();

        // Push the element to the queue
        queue.push(std::move(element));

        // Pop the element from the queue
        Tool::pPriorityQueueElement poppedElement = queue.pop();

        // Check if the popped element is equal to the clone
        CHECK_EQ(*poppedElement, *clone);
}

/*
Popping an element from an empty queue.

Expected: The method should return nullptr if the queue is empty.
*/
TEST(PriorityQueue, popEmptyQueue)
{
        // Create a priority queue
        Tool::PriorityQueue queue;

        // Pop an element from the queue
        Tool::pPriorityQueueElement poppedElement = queue.pop();

        // Check if the popped element is nullptr
        EXPECT_TRUE(poppedElement == nullptr);
}

/*
Checking if the queue is empty.

Expected: The method should return true if the queue is empty, false otherwise.
*/
TEST(PriorityQueue, emptyQueue)
{
        // Create a priority queue
        Tool::PriorityQueue queue;

        // Check if the queue is empty
        EXPECT_TRUE(queue.empty());
}

/*
Checking if the queue is not empty.

Expected: The method should return false if the queue is not empty, true otherwise.
*/
TEST(PriorityQueue, notEmptyQueue)
{
        // Create a priority queue
        Tool::PriorityQueue queue;

        // Create a priority queue element
        Tool::pPriorityQueueElement element = std::make_unique<Tool::PriorityQueueElement>(
                "Name", Globals::Priority::High);

        // Push the element to the queue
        queue.push(std::move(element));

        // Check if the queue is not empty
        EXPECT_TRUE(!queue.empty());
}

#endif // TEST