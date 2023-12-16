#include "stack.h"

template <typename T>
void stack<T>::push(const T& value) {
    data.push_back(value);
}

template <typename T>
void stack<T>::pop() {
    if (empty()) {
        throw std::out_of_range("Stack is empty. Cannot pop.");
    }
    data.pop_back();
}

template <typename T>
T stack<T>::top() const {
    if (empty()) {
        throw std::out_of_range("Stack is empty. Cannot get top element.");
    }
    return data.back();
}

template <typename T>
bool stack<T>::empty() const {
    return data.empty();
}