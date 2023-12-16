#include "FileReader.h"
#include <iostream>
#include <fstream>
#include <iterator>

FileReader::FileReader(const std::string& filename) {
    file.open(filename);

    if (!file.is_open()) {
        std::cerr << "The file could not be opened." << std::endl;
    }
}

std::vector<std::string> FileReader::getLines() const {
    std::vector<std::string> lines;
    std::string line;

    // Используем итераторы для считывания строк
    std::istreambuf_iterator<char> it(file.rdbuf()), end;
    while (it != end) {
        // Считываем строку до символа новой строки
        line.clear();
        while (it != end && *it != '\n') {
            line += *it++;
        }
        lines.push_back(line);

        // Пропускаем символ новой строки, если он есть
        if (it != end) {
            ++it;
        }
    }

    return lines;
}

bool FileReader::isOpen() const {
    return file.is_open();
}

FileReader::~FileReader() {
    if (file.is_open()) {
        file.close();
    }
}