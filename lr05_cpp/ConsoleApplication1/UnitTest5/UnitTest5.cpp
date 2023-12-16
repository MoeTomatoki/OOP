#include "pch.h"
#include "CppUnitTest.h"
#include "..\ConsoleApplication1\FileReader.h"
#include "..\ConsoleApplication1\WordCounter.h"
#include "..\ConsoleApplication1\FileReader.cpp"
#include "..\ConsoleApplication1\WordCounter.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(WordCounterTest) {
public:
    TEST_METHOD(CountShortWords) {
        // Подготовка данных
        std::string text = "This is a test file. \
            It contains words of varying lengths. \
            Some short words are here. \
            Longer words are also included. \
            Check the program's output for the correct count.";

        // Выполнение теста
        int result = WordCounter::countShortWords(text);

        // Проверка результата
        Assert::AreEqual(13, result);
    }
};

TEST_CLASS(FileReaderTest) {
public:
    TEST_METHOD(GetLines) {
        // Подготовка данных
        const std::string filename = "testfile.txt";
        std::ofstream testFile(filename);
        testFile << "Line 1\nLine 2\nLine 3";
        testFile.close();

        FileReader fileReader(filename);

        // Выполнение теста
        std::vector<std::string> lines = fileReader.getLines();

        // Проверка результата
        Assert::AreEqual(static_cast<size_t>(3), lines.size()); // Замените 3 на ожидаемое количество строк
    }
};
