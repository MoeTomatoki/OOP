#include "train.h"
#include <algorithm>

int main() {
    const int arraySize = 4;
    TRAIN trains[arraySize];

    // Ввод данных в массив
    for (int i = 0; i < arraySize; ++i) {
        std::cout << "Enter details for train " << (i + 1) << ":\n";
        std::cin >> trains[i];
    }

    // Сортировка по названиям пунктов назначения
    std::sort(trains, trains + arraySize, [](const TRAIN& a, const TRAIN& b) {
        return a.getDestination() < b.getDestination();
        });

    // Вывод информации о поездах, отправляющихся после введенного времени
    std::string inputTime;
    std::cout << "\nEnter the departure time to filter trains: ";
    std::cin >> inputTime;

    bool found = false;
    for (const auto& train : trains) {
        if (train.getDepartureTime() > inputTime) {
            std::cout << train;
            found = true;
        }
    }

    // Вывод сообщения, если не найдено ни одного поезда
    if (!found) {
        std::cout << "No trains found after the specified time.\n";
    }

    return 0;
}
