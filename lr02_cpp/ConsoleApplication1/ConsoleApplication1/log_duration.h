#pragma once

#include <iostream>
#include <chrono>

class LogDuration {
public:
    explicit LogDuration(const std::string& message);
    ~LogDuration();

private:
    std::string message;
    std::chrono::steady_clock::time_point start;
};