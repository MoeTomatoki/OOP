#include "WordCounter.h"
#include <sstream>

int WordCounter::countShortWords(const std::string& text) {
    std::istringstream iss(text);
    std::string word;
    int count = 0;

    while (iss >> word) {
        if (word.length() <= 4) {
            count++;
        }
    }

    return count;
}
