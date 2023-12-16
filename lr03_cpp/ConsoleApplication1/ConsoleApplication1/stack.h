#pragma once
#ifndef STACK_H
#define STACK_H

#include <list>
#include <stdexcept>

template <typename T>
class stack {
private:
    std::list<T> data;

public:
    void push(const T& value);
    void pop();
    T top() const;
    bool empty() const;
};

#endif
