#pragma once
#ifndef FILEREADER_H
#define FILEREADER_H

#include <fstream>
#include <vector>
#include <string>

class FileReader {
public:
    explicit FileReader(const std::string& filename);
    std::vector<std::string> getLines() const;
    bool isOpen() const;
    ~FileReader();

private:
    std::ifstream file;
};

#endif 