//Тарпанов Даниил, М8О-204Б-19 ЛР №3
//Вариант 18: Квадрат, прямоугольник, трапеция

#ifndef Trapeze_HPP
#define Trapeze_HPP

#include "coord.hpp"
#include "figure.hpp"
#include <cmath>


class Trapeze : public Figure {
    private:
        Coord leftBottom, leftTop;
        double largerBase, smallerBase, sideSize;
    public:
        Trapeze() {}

        friend std::istream& operator >>(std::istream & is, Trapeze& obj);

        void Print() override;
        double GetSquare() override;
        Coord GeometricCenter() override;
};

std::istream& operator >>(std::istream& is, Trapeze &obj) {
    std::cout << "\nTrapeze input:\n" << "Enter left bottom dot coordinates: ";
    std::cin >> obj.leftBottom;
    std::cout << "Enter left top dot coordinates: ";
    std::cin >> obj.leftTop;
    std::cout << "Enter smaller base: ";
    std::cin >> obj.smallerBase;
    std::cout << "Enter larger base: ";
    std::cin >> obj.largerBase;
    std::cout << "Enter side size: ";
    std::cin >> obj.sideSize;
    if (obj.smallerBase < 0 || obj.largerBase < 0 || obj.sideSize < 0) {
        std::cout << "Invalid input!" << '\n';
        exit(-1);
    }
    return is;
}

void Trapeze::Print() {
    std::cout << "\nTrapeze print:\n" << "Left bottom dot coordinates: " << leftBottom << '\n';
    std::cout << "Left top dot coordinates: " << leftTop << '\n';
    std::cout << "Size of smaller and larger bases: " << smallerBase << ", " << largerBase << '\n';
    std::cout << "Size of side: " << sideSize << '\n';
}

Coord Trapeze::GeometricCenter() {
    double height = leftTop.y - leftBottom.y;
    double distance = (height/3) * ((2*largerBase + smallerBase)/(smallerBase + largerBase));
    return Coord(leftBottom.x + largerBase/2, leftTop.y - distance);
}

double Trapeze::GetSquare() {
    double height = leftTop.y - leftBottom.y;
    return height * (smallerBase + largerBase) / 2;
}


#endif