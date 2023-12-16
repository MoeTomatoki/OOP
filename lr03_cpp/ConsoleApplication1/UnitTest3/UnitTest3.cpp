#include "pch.h"
#include "CppUnitTest.h"
#include "..\\ConsoleApplication1\stack.h"
#include "..\\ConsoleApplication1\stack.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(StackTests)
{
public:

    TEST_METHOD(TestPushPop)
    {
        stack<int> testStack;
        testStack.push(5);
        Assert::AreEqual(5, testStack.top());

        testStack.pop();
        Assert::IsTrue(testStack.empty());
    }

    TEST_METHOD(TestTopException)
    {
        stack<int> emptyStack;
        try {
            emptyStack.top();
            Assert::Fail(L"Expected exception not thrown");
        }
        catch (const std::out_of_range& e) {
            Assert::AreEqual("Stack is empty. Cannot get top element.", e.what());
        }
    }
};
