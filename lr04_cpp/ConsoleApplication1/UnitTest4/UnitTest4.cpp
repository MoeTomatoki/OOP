#include <algorithm>
#include <vector>
#include "pch.h"
#include "CppUnitTest.h"
#include "../ConsoleApplication1/train.h"
#include "../ConsoleApplication1/train.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TRAINTests
{
    TEST_CLASS(TRAINTests)
    {
    public:

        TEST_METHOD(TestTrainSorting)
        {
            // Тест сортировки поездов по пунктам назначения

            TRAIN trains[3];

            // Заполнение массива поездов
            trains[0] = TRAIN("Paris", 123, "08:00");
            trains[1] = TRAIN("Berlin", 456, "09:30");
            trains[2] = TRAIN("London", 789, "10:45");

            // Ожидаемый порядок после сортировки
            TRAIN expectedOrder[3] = { TRAIN("Berlin", 456, "09:30"),
                                       TRAIN("London", 789, "10:45"),
                                       TRAIN("Paris", 123, "08:00") };

            // Ручная сортировка (пузырьковая сортировка для примера)
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 2 - i; ++j) {
                    if (trains[j].getDestination() > trains[j + 1].getDestination()) {
                        std::swap(trains[j], trains[j + 1]);
                    }
                }
            }

            // Проверка сортировки
            for (int i = 0; i < 3; ++i) {
                Assert::AreEqual(expectedOrder[i].getDestination(), trains[i].getDestination());
                Assert::AreEqual(expectedOrder[i].getTrainNumber(), trains[i].getTrainNumber());
                Assert::AreEqual(expectedOrder[i].getDepartureTime(), trains[i].getDepartureTime());
            }
        }

        TEST_METHOD(TestTrainFiltering)
        {
            // Тест фильтрации поездов по времени отправления

            TRAIN trains[3];

            // Заполнение массива поездов
            trains[0] = TRAIN("Paris", 123, "08:00");
            trains[1] = TRAIN("Berlin", 456, "09:30");
            trains[2] = TRAIN("London", 789, "10:45");

            // Ожидаемые поезда после фильтрации
            TRAIN expectedTrains[2] = { TRAIN("Berlin", 456, "09:30"),
                                        TRAIN("London", 789, "10:45") };

            // Фильтрация по времени
            std::string filterTime = "09:00";
            int filteredCount = 0;

            for (int i = 0; i < 3; ++i) {
                if (trains[i].getDepartureTime() > filterTime) {
                    // Печать или другая обработка вместо добавления в вектор
                    // std::cout << trains[i];
                    ++filteredCount;
                }
            }

            // Проверка фильтрации
            Assert::AreEqual(2, filteredCount);
        }

        TEST_METHOD(TestTrainConstructor)
        {
            TRAIN train("TestDestination", 123, "12:34");
            Assert::AreEqual("TestDestination", train.getDestination().c_str());
            Assert::AreEqual(123, train.getTrainNumber());
            Assert::AreEqual("12:34", train.getDepartureTime().c_str());
        }

    };
}

