//Тарпанов Даниил, М8О-204Б-19 ЛР №3
//Вариант 18: Квадрат, прямоугольник, трапеция

#ifndef Square_HPP
#define Square_HPP

#include <iostream>
#include "figure.hpp"
#include "coord.hpp"

class Square: public Figure {
    private:
        Coord leftBottom;
        double side;
    public:
        Square() {}

        friend std::istream& operator >>(std::istream &is, Square &obj);

        void Print() override;
        double GetSquare() override;
        Coord GeometricCenter() override;
};

std::istream & operator >>(std::istream& is, Square &obj) {
    std::cout << "\nSquare input:\n" << "Enter left bottom dot coordinates: ";
    is >> obj.leftBottom;
    std::cout << "Enter side length: ";
    is >> obj.side;
    if(obj.side < 0) {
        std::cout << "Invalid input!" << '\n';
        exit(-1);
    }
    return is;
}

void Square::Print() {
    std::cout << "\nSquare print\n" << "Left bottom dot coordinates: " << leftBottom << '\n';
    std::cout << "Side length: " << side << '\n';
}

Coord Square::GeometricCenter() {
    return(Coord(leftBottom.x + side / 2.0, leftBottom.y + side / 2.0));
}

double Square::GetSquare() {
    return side*side;
}

#endif