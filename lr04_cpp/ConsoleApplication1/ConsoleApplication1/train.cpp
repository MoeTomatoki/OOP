#include "train.h"

// ���������� �������������
TRAIN::TRAIN() : trainNumber(0) {}

TRAIN::TRAIN(const std::string& dest, int num, const std::string& time)
    : destination(dest), trainNumber(num), departureTime(time) {}

// ���������� ������� �������
std::string TRAIN::getDestination() const {
    return destination;
}

int TRAIN::getTrainNumber() const {
    return trainNumber;
}

std::string TRAIN::getDepartureTime() const {
    return departureTime;
}

// ���������� �������� �������
std::ostream& operator<<(std::ostream& os, const TRAIN& train) {
    os << "Destination: " << train.destination << "\n";
    os << "Train Number: " << train.trainNumber << "\n";
    os << "Departure Time: " << train.departureTime << "\n";
    return os;
}

// ���������� �������� ����������
std::istream& operator>>(std::istream& is, TRAIN& train) {
    std::cout << "Enter destination: ";
    is >> train.destination;
    std::cout << "Enter train number: ";
    is >> train.trainNumber;
    std::cout << "Enter departure time: ";
    is >> train.departureTime;
    return is;
}