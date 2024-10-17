#include <gtest/gtest.h>
#include "Queue.cpp"

// TODO: Uncomment the following test

TEST(QueueTest, InstantiateEmptyQueue)
{
    Queue<int> queue;
    ASSERT_EQ(queue.size(), 0);
}
TEST(QueueTest, InstantiatQueue)
{
    Queue<int> queue;
    queue.enqueue(5);
    queue.enqueue(4);
    queue.enqueue(3);
    ASSERT_EQ(queue.dequeue(), 5);
}
TEST(QueueTest, EmptyQueue)
{
    Queue<int> queue;
    ASSERT_EQ(queue.dequeue(), std::nullopt);
}
TEST(QueueTest, EnqueueDequeue)
{
    Queue<int> queue;
    queue.enqueue(5);
    queue.enqueue(4);
    queue.enqueue(3);
    ASSERT_EQ(queue.size(), 3);  
    ASSERT_EQ(queue.dequeue(), 5); 
    ASSERT_EQ(queue.size(), 2);  
    ASSERT_EQ(queue.dequeue(), 4); 
    ASSERT_EQ(queue.dequeue(), 3); 
    ASSERT_EQ(queue.size(), 0); 
    ASSERT_EQ(queue.dequeue(), std::nullopt); 
}


TEST(QueueTest, DequeueFromEmptyQueue)
{
    Queue<int> queue;
    ASSERT_EQ(queue.dequeue(), std::nullopt);  
}

TEST(QueueTest, SingleElementQueue)
{
    Queue<int> queue;
    queue.enqueue(42);
    ASSERT_EQ(queue.size(), 1);
    ASSERT_EQ(queue.dequeue(), 42); 
    ASSERT_EQ(queue.size(), 0); 
    ASSERT_EQ(queue.dequeue(), std::nullopt);  
}

TEST(QueueTest, QueueWithDifferentDataTypes)
{
    Queue<std::string> queue;
    queue.enqueue("first");
    queue.enqueue("second");
    queue.enqueue("third");
    ASSERT_EQ(queue.dequeue(), "first");
    ASSERT_EQ(queue.dequeue(), "second");
    ASSERT_EQ(queue.dequeue(), "third");
    ASSERT_EQ(queue.size(), 0); 
}
// TODO: add more tests for Queue below
