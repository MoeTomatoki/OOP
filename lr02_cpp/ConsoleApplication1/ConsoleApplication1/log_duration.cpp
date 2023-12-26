#include "log_duration.h"

LogDuration::LogDuration(const std::string& message)
    : message(message + ": "), start(std::chrono::steady_clock::now()) {}

LogDuration::~LogDuration() {
    auto finish = std::chrono::steady_clock::now();
    auto duration = finish - start;
    std::cerr << message
        << std::chrono::duration_cast<std::chrono::milliseconds>(duration).count()
        << " ms" << std::endl;
}