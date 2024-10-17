#ifndef STACK_CPP
#define STACK_CPP

#include "Stack.hpp"

template <typename T>
Stack<T>::Stack(): _llist() {}


template <typename T>
Stack<T>::Stack(const std::vector<T> &items) {
    for (const auto &item : items) {
        push(item); 
    }
}

template <typename T>
std::optional<T> Stack<T>::top() const {
    if( _llist.head()!=NULL){
    return  _llist.head()->value;}
    else{
        return std::nullopt;
    }

}


template <typename T>
size_t Stack<T>::size() const {
    return _llist.size();
}

template <typename T>
std::optional<T> Stack<T>::pop() {
    return _llist.removeHead(); 
}


template <typename T>
void Stack<T>:: push(T value){
    _llist.prepend(std::move(value));
};
#endif
