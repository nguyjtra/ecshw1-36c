#include <gtest/gtest.h>
#include "LinkedList.cpp"

TEST(LinkedListTest, InstantiateEmptyList)
{
    LinkedList<int> llist;

    ASSERT_EQ(llist.head(), nullptr);
    ASSERT_EQ(llist.tail(), nullptr);
    ASSERT_EQ(llist.size(), 0);
}

TEST(LinkedListTest, InstantiateFromVector)
{
    LinkedList<int> llist(std::vector<int>{17, 19, 23});

    ASSERT_EQ(llist.size(), 3);

    LinkedListNode<int> *node = llist.head();
    ASSERT_EQ(node->value, 17);
    ASSERT_EQ(node->next()->value, 19);
    ASSERT_EQ(node->next()->next()->value, 23);
    ASSERT_EQ(node->next()->next()->next(), nullptr);
}

TEST(LinkedListTest, AppendToEmptyList)
{
    LinkedList<int> llist;
    LinkedListNode<int> *node = llist.append(17);

    ASSERT_EQ(node, llist.head());
    ASSERT_EQ(node, llist.tail());
    ASSERT_EQ(node->value, 17);
    ASSERT_EQ(node->next(), nullptr);
    ASSERT_EQ(llist.size(), 1);
}

TEST(LinkedListTest, AppendToNonEmptyList)
{
    LinkedList<int> llist;
    LinkedListNode<int> *first = llist.append(17);
    LinkedListNode<int> *second = llist.append(19);

    ASSERT_EQ(first, llist.head());
    ASSERT_EQ(first->value, 17);
    ASSERT_EQ(first->next(), second);

    ASSERT_EQ(second, llist.tail());
    ASSERT_EQ(second->value, 19);
    ASSERT_EQ(second->next(), nullptr);

    ASSERT_EQ(llist.size(), 2);
}

TEST(LinkedListTest, AppendToNonEmptyList111)
{
    LinkedList<int> llist;
    LinkedListNode<int> *first = llist.append(17);
    LinkedListNode<int> *second = llist.append(19);
    ASSERT_EQ(llist.remove(17), true);
}

TEST(LinkedListTest, AppendToNonEmptyList121)
{
    LinkedList<int> llist;
    LinkedListNode<int> *first = llist.append(17);
    LinkedListNode<int> *second = llist.append(19);
    ASSERT_EQ(llist.removeHead(), 17);
}

TEST(LinkedListTest, AppendToNonEmptyList1221)
{
    LinkedList<int> llist;
    LinkedListNode<int> *first = llist.append(17);
    LinkedListNode<int> *second = llist.prepend(19);
    ASSERT_EQ(llist.removeHead(), 19);
}

// TODO: Add more tests for LinkedList here
TEST(LinkedListTest, PrependToEmptyList)
{
    LinkedList<int> llist;
    LinkedListNode<int> *node = llist.prepend(42);

    ASSERT_EQ(node, llist.head());
    ASSERT_EQ(node, llist.tail());
    ASSERT_EQ(node->value, 42);
    ASSERT_EQ(node->next(), nullptr);
    ASSERT_EQ(llist.size(), 1);
}

TEST(LinkedListTest, PrependToNonEmptyList)
{
    LinkedList<int> llist;
    LinkedListNode<int> *first = llist.append(17);
    LinkedListNode<int> *second = llist.prepend(42);

    ASSERT_EQ(second, llist.head());
    ASSERT_EQ(second->value, 42);
    ASSERT_EQ(second->next(), first);

    ASSERT_EQ(first, llist.tail());
    ASSERT_EQ(first->value, 17);
    ASSERT_EQ(first->next(), nullptr);

    ASSERT_EQ(llist.size(), 2);
}

TEST(LinkedListTest, InsertAfterNullptr)
{
    LinkedList<int> llist;
    LinkedListNode<int> *node = llist.insertAfter(nullptr, 99);

    ASSERT_EQ(node, llist.head());
    ASSERT_EQ(node, llist.tail());
    ASSERT_EQ(node->value, 99);
    ASSERT_EQ(node->next(), nullptr);
    ASSERT_EQ(llist.size(), 1);
}

TEST(LinkedListTest, InsertAfterHead)
{
    LinkedList<int> llist;
    LinkedListNode<int> *first = llist.append(17);
    LinkedListNode<int> *second = llist.insertAfter(first, 23);

    ASSERT_EQ(first, llist.head());
    ASSERT_EQ(first->next(), second);
    ASSERT_EQ(second, llist.tail());
    ASSERT_EQ(second->value, 23);
    ASSERT_EQ(second->next(), nullptr);
    ASSERT_EQ(llist.size(), 2);
}

TEST(LinkedListTest, FindElementInList)
{
    LinkedList<int> llist(std::vector<int>{17, 19, 23});

    LinkedListNode<int> *node = llist.find(19);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->value, 19);
}

TEST(LinkedListTest, FindElementNotInList)
{
    LinkedList<int> llist(std::vector<int>{17, 19, 23});

    LinkedListNode<int> *node = llist.find(42);
    ASSERT_EQ(node, nullptr);
}

TEST(LinkedListTest, RemoveElementFromMiddle)
{
    LinkedList<int> llist(std::vector<int>{17, 19, 23});

    bool removed = llist.remove(19);
    ASSERT_TRUE(removed);
    ASSERT_EQ(llist.size(), 2);

    LinkedListNode<int> *node = llist.head();
    ASSERT_EQ(node->value, 17);
    ASSERT_EQ(node->next()->value, 23);
    ASSERT_EQ(node->next()->next(), nullptr);
}

TEST(LinkedListTest, RemoveElementNotFound)
{
    LinkedList<int> llist(std::vector<int>{17, 19, 23});

    bool removed = llist.remove(99);
    ASSERT_FALSE(removed);
    ASSERT_EQ(llist.size(), 3);
}

TEST(LinkedListTest, ClearList)
{
    LinkedList<int> llist(std::vector<int>{17, 19, 23});
    llist.clear();

    ASSERT_EQ(llist.size(), 0);
    ASSERT_EQ(llist.head(), nullptr);
    ASSERT_EQ(llist.tail(), nullptr);
}

TEST(LinkedListTest, MoveConstructor)
{
    LinkedList<int> llist1(std::vector<int>{17, 19, 23});
    LinkedList<int> llist2(std::move(llist1));

    ASSERT_EQ(llist1.size(), 0);
    ASSERT_EQ(llist1.head(), nullptr);
    ASSERT_EQ(llist1.tail(), nullptr);

    ASSERT_EQ(llist2.size(), 3);
    LinkedListNode<int> *node = llist2.head();
    ASSERT_EQ(node->value, 17);
    ASSERT_EQ(node->next()->value, 19);
    ASSERT_EQ(node->next()->next()->value, 23);
    ASSERT_EQ(node->next()->next()->next(), nullptr);
}