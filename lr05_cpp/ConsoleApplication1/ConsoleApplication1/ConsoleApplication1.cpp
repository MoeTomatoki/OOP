#include <iostream>
#include "FileReader.h"
#include "WordCounter.h"

int main() {
    std::string filename;
    std::cout << "Enter the file name: ";
    std::cin >> filename;

    FileReader fileReader(filename);

    if (!fileReader.isOpen()) {
        return 1;
    }

    std::vector<std::string> lines = fileReader.getLines();

    int totalShortWords = 0;

    for (const auto& currentLine : lines) {
        totalShortWords += WordCounter::countShortWords(currentLine);
    }

    std::cout << "The number of words of no more than four letters: " << totalShortWords << std::endl;

    return 0;
}