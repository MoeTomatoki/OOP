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

    // ���������� ��������� ��� ���������� �����
    std::istreambuf_iterator<char> it(file.rdbuf()), end;
    while (it != end) {
        // ��������� ������ �� ������� ����� ������
        line.clear();
        while (it != end && *it != '\n') {
            line += *it++;
        }
        lines.push_back(line);

        // ���������� ������ ����� ������, ���� �� ����
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