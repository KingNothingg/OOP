//Тарпанов Даниил, М8О-204Б-19 ЛР №3
//Вариант 18: Квадрат, прямоугольник, трапеция

#ifndef Rectangle_HPP
#define Rectangle_HPP

#include <iostream>
#include "coord.hpp"
#include "figure.hpp"

class Rectangle: public Figure {
    private:
        Coord leftBottom, rightTop;
    public:
        Rectangle() {}
        
        friend std::istream& operator >>(std::istream &is, Rectangle& obj);

        void Print() override;
        Coord GeometricCenter() override;
        double GetSquare() override;
};

std::istream& operator >>(std::istream &is, Rectangle& obj) {
    std::cout << "\nRectangle input:\n" << "Enter left bottom dot coordinates: ";
    is >> obj.leftBottom;
    std::cout << "Enter right top dot coordinates: ";
    is >> obj.rightTop;
    return is;
}

void Rectangle::Print() {
    std::cout << "\nRectangle print:\n" << "Left bottom dot coordinates: " << leftBottom << '\n';
    std::cout << "Right top dot coordinates: " << rightTop << '\n';
}

Coord Rectangle::GeometricCenter() {
    return Coord(leftBottom.x + (rightTop.x - leftBottom.x)/2, leftBottom.y + (rightTop.y - leftBottom.y)/2);
}

double Rectangle::GetSquare() {
    return ((rightTop.x - leftBottom.x) * (rightTop.y - leftBottom.y));
}

#endif