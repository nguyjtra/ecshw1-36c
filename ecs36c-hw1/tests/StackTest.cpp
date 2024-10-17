#include <gtest/gtest.h>
#include "Stack.cpp"

// TODO: Uncomment the following test

TEST(StackTest, InstantiateEmptyStack)
{
    Stack<int> stack;
    ASSERT_EQ(stack.size(), 0);
    ASSERT_EQ(stack.top(), std::nullopt);
}

TEST(StackTest, InstantiateStack)
{
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    ASSERT_EQ(stack.size(), 5);
    ASSERT_EQ(stack.top(), 5);
}
TEST(StackTest, InstantiateStack123)
{
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    ASSERT_EQ(stack.size(), 5);
    ASSERT_EQ(stack.pop(), 5);
    ASSERT_EQ(stack.top(), 4);
}
TEST(StackTest, PushPop)
{
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    ASSERT_EQ(stack.size(), 3); 
    ASSERT_EQ(stack.top(), 3); 
    ASSERT_EQ(stack.pop(), 3); 
    ASSERT_EQ(stack.top(), 2); 
    ASSERT_EQ(stack.pop(), 2); 
    ASSERT_EQ(stack.pop(), 1); 
    ASSERT_EQ(stack.size(), 0);  
    ASSERT_EQ(stack.pop(), std::nullopt);  
}

TEST(StackTest, PopFromEmptyStack)
{
    Stack<int> stack;
    ASSERT_EQ(stack.pop(), std::nullopt);  
}

TEST(StackTest, SingleElementStack)
{
    Stack<int> stack;
    stack.push(99);
    ASSERT_EQ(stack.size(), 1);
    ASSERT_EQ(stack.top(), 99);  
    ASSERT_EQ(stack.pop(), 99);  
    ASSERT_EQ(stack.size(), 0);  
    ASSERT_EQ(stack.top(), std::nullopt); 
}

// Test the Stack with different data types
TEST(StackTest, StackWithDifferentDataTypes)
{
    Stack<std::string> stack;
    stack.push("apple");
    stack.push("banana");
    stack.push("cherry");
    ASSERT_EQ(stack.top(), "cherry");  
    ASSERT_EQ(stack.pop(), "cherry");
    ASSERT_EQ(stack.pop(), "banana");
    ASSERT_EQ(stack.pop(), "apple");
    ASSERT_EQ(stack.size(), 0); 
}
// TODO: Add more tests for Stack here
