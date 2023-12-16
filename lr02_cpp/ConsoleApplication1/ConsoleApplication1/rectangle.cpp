#include "Rectangle.h"
#include <iostream>
#include <algorithm>

Rectangle::Rectangle(double x1, double y1, double x2, double y2)
    : x1(x1), y1(y1), x2(x2), y2(y2) {}

void Rectangle::move(double dx, double dy) {
    x1 += dx;
    y1 += dy;
    x2 += dx;
    y2 += dy;
}

void Rectangle::resize(double dw, double dh) {
    x2 += dw;
    y2 += dh;
}

Rectangle Rectangle::minimumBoundingRectangle(const Rectangle& other) const {
    double minX = std::min(x1, other.x1);
    double minY = std::min(y1, other.y1);
    double maxX = std::max(x2, other.x2);
    double maxY = std::max(y2, other.y2);

    return Rectangle(minX, minY, maxX, maxY);
}

Rectangle Rectangle::intersection(const Rectangle& other) const {
    double intX1 = std::max(x1, other.x1);
    double intY1 = std::max(y1, other.y1);
    double intX2 = std::min(x2, other.x2);
    double intY2 = std::min(y2, other.y2);

    if (intX1 < intX2 && intY1 < intY2) {
        return Rectangle(intX1, intY1, intX2, intY2);
    }
    else {
        // Нет пересечения
        return Rectangle(0, 0, 0, 0);
    }
}

void Rectangle::display() const {
    std::cout << "Rectangle: (" << x1 << ", " << y1 << ") - (" << x2 << ", " << y2 << ")\n";
}