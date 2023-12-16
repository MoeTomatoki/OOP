#include <iostream>
#include "stack.h"
#include "stack.cpp"

int main() {
    try {
        // Использование шаблонного класса stack с типами int, double, std::string
        stack<int> intStack;
        intStack.push(1);
        intStack.push(2);
        intStack.push(3);

        std::cout << "Top element of intStack: " << intStack.top() << std::endl;
        intStack.pop();

        stack<double> doubleStack;
        doubleStack.push(1.5);
        doubleStack.push(2.5);
        doubleStack.push(3.5);

        std::cout << "Top element of doubleStack: " << doubleStack.top() << std::endl;
        doubleStack.pop();

        stack<std::string> stringStack;
        stringStack.push("one");
        stringStack.push("two");
        stringStack.push("three");

        std::cout << "Top element of stringStack: " << stringStack.top() << std::endl;
        stringStack.pop();

        // Попытка извлечь элемент из пустого стека
        stack<int> emptyStack;
        emptyStack.pop();

    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
