#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle {
private:
    double x1, y1;
    double x2, y2;

public:
    Rectangle(double x1, double y1, double x2, double y2);
    void move(double dx, double dy);
    void resize(double dw, double dh);
    Rectangle minimumBoundingRectangle(const Rectangle& other) const;
    Rectangle intersection(const Rectangle& other) const;
    void display() const;

    double getX1() const { return x1; }
    double getY1() const { return y1; }
    double getX2() const { return x2; }
    double getY2() const { return y2; }
};

#endif 