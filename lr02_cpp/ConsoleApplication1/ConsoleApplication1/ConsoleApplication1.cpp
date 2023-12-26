#include "Rectangle.h"
#include "log_duration.h"
#include <iostream>

#define LOG_DURATION(message) LogDuration UNIQ_ID(__LINE__){message};
#define UNIQ_ID_IMPL(lineno) _a_local_var_##lineno
#define UNIQ_ID(lineno) UNIQ_ID_IMPL(lineno)

int main() {
    // Создание двух прямоугольников с левой нижней и правой верхней координаты
    Rectangle rect1(1, 1, 4, 4);
    Rectangle rect2(3, 2, 6, 5);

    LOG_DURATION("endl");
    int choice;
    do {
        // Отображаем меню
        std::cout << "\nMenu:\n";
        std::cout << "1. Move Rectangle\n";
        std::cout << "2. Resize Rectangle\n";
        std::cout << "3. Minimum Bounding Rectangle\n";
        std::cout << "4. Intersection Rectangle\n";
        std::cout << "5. Display Rectangles\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        // Выполнение соотвествующий команды
        LOG_DURATION("endl");
        switch (choice) {
        case 1: {
            double dx, dy;
            std::cout << "Enter displacement along x and y: ";
            std::cin >> dx >> dy;
            rect1.move(dx, dy);
            rect2.move(dx, dy);
            break;
        }
        case 2: {
            double dw, dh;
            std::cout << "Enter change in width and height: ";
            std::cin >> dw >> dh;
            rect1.resize(dw, dh);
            rect2.resize(dw, dh);
            break;
        }
        case 3: {
            Rectangle boundingRect = rect1.minimumBoundingRectangle(rect2);
            std::cout << "Minimum Bounding Rectangle:\n";
            boundingRect.display();
            break;
        }
        case 4: {
            Rectangle intersectionRect = rect1.intersection(rect2);
            std::cout << "Intersection Rectangle:\n";
            intersectionRect.display();
            break;
        }
        case 5:
            std::cout << "Rectangles:\n";
            std::cout << "Rectangle 1: ";
            rect1.display();
            std::cout << "Rectangle 2: ";
            rect2.display();
            break;
        case 0:
            std::cout << "Exiting program.\n";
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}