#ifndef LINKED_LIST_CPP
#define LINKED_LIST_CPP

#include "LinkedList.hpp"

template <typename T>
LinkedList<T>::LinkedList() : _size(0), _head(NULL), _tail(NULL) {}

template <typename T>
LinkedList<T>::LinkedList(LinkedList<T> &&other)
    : _size(other._size), _head(other._head), _tail(other._tail)
{
    other._size = 0;
    other._head = NULL;
    other._tail = NULL;
}

template <typename T>
LinkedList<T>::LinkedList(const std::vector<T> &items) : _head(NULL), _tail(NULL), _size(0)
{
    for ( auto &item : items)
    {
        append(item);
    }
}

template <typename T>
size_t LinkedList<T>::size() const
{
    return _size;
}

template <typename T>
LinkedListNode<T> *LinkedList<T>::head() const
{
    return _head;
}

template <typename T>
LinkedListNode<T> *LinkedList<T>::tail() const
{
    return _tail;
}

template <typename T>
LinkedListNode<T> *LinkedList<T>::find(T value) const
{
    LinkedListNode<T> *current = _head;
    while (current != NULL)
    {
        if (current->value == value)
        {
            return current;
        }
        current = current->next();
    }
    return NULL;
}

template <typename T>
LinkedListNode<T> *LinkedList<T>::prepend(T value)
{
    LinkedListNode<T> *tmp = new LinkedListNode<T>(value);
    if (_head == NULL || _size==0)
    {
        _head = tmp;
        _tail = tmp;
    }
    else
    {
        tmp->_next = _head;
        _head = tmp;
    }
    _size++;
    return tmp;
}

template <typename T>
LinkedListNode<T> *LinkedList<T>::append(T value)
{
    LinkedListNode<T> *current = new LinkedListNode<T>(value);
    if (_head == NULL || _size==0)
    {
        _head = current;
        _tail = current;
    }
    else
    {
        _tail->_next = current;
        _tail = current;
    }
    _size++;
    return current;
}

template <typename T>
LinkedListNode<T> *LinkedList<T>::insertAfter(LinkedListNode<T> *node, T value)
{
    if (node == NULL)
    {
        return prepend(value);
    }

    LinkedListNode<T> *newNode = new LinkedListNode<T>(value);
    newNode->_next = node->_next;
    node->_next = newNode;

    if (node == _tail)
    {
        _tail = newNode;
    }

    _size++;
    return tmp;
}

template <typename T>
std::optional<T> LinkedList<T>::removeHead()
{
    if (_head == NULL||_size==0)
    {
        return std::nullopt;
    }

    T removedValue = _head->value;
    LinkedListNode<T> *old = _head;

    _head = _head->next();
    if (_head == NULL||_size==0)
    {
        _tail = NULL;
    }

    delete old;
    _size--;
    return removedValue;
}

template <typename T>
bool LinkedList<T>::remove(T value)
{
    if (_head == NULL||_size==0)
    {
        return false;
    }

    if (_head->value == value)
    {
        removeHead();
        return true;
    }

    LinkedListNode<T> *current = _head;
    while (current->_next != NULL)
    {
        if (current->_next->value == value)
        {
            LinkedListNode<T> *nodeToRemove = current->_next;
            current->_next = nodeToRemove->_next;

            if (nodeToRemove == _tail)
            {
                _tail = current;
            }

            delete nodeToRemove;
            _size--;
            return true;
        }
        current = current->_next;
    }

    return false; 
}

template <typename T>
void LinkedList<T>::clear()
{
    LinkedListNode<T> *curr = _head;
    while (curr != NULL)
    {
        LinkedListNode<T> *tmp = curr;
        curr = curr->_next;
        delete tmp;
    }

    _head = NULL;
    _tail = NULL;
    _size = 0;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    clear();
}

#endif