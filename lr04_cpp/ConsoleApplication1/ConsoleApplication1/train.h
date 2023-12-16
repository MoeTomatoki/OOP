#pragma once
#ifndef TRAIN_H
#define TRAIN_H

#include <iostream>
#include <string>

class TRAIN {
private:
    std::string destination;
    int trainNumber;
    std::string departureTime;

public:
    // ������������
    TRAIN();
    TRAIN(const std::string& dest, int num, const std::string& time);

    // ������ �������
    std::string getDestination() const;
    int getTrainNumber() const;
    std::string getDepartureTime() const;

    // ������������� �������� ���������� � �������
    friend std::ostream& operator<<(std::ostream& os, const TRAIN& train);
    friend std::istream& operator>>(std::istream& is, TRAIN& train);
};

#endif