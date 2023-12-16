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
    // Конструкторы
    TRAIN();
    TRAIN(const std::string& dest, int num, const std::string& time);

    // Методы доступа
    std::string getDestination() const;
    int getTrainNumber() const;
    std::string getDepartureTime() const;

    // Перегруженные операции извлечения и вставки
    friend std::ostream& operator<<(std::ostream& os, const TRAIN& train);
    friend std::istream& operator>>(std::istream& is, TRAIN& train);
};

#endif