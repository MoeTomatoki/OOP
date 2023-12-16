#pragma once
#ifndef WORDCOUNTER_H
#define WORDCOUNTER_H

#include <string>

class WordCounter {
public:
    static int countShortWords(const std::string& text);
};

#endif