//Тарпанов Даниил, М8О-204Б-19 ЛР №3
//Вариант 18: Квадрат, прямоугольник, трапеция

#ifndef Coord_HPP
#define Coord_HPP

#include <iostream>

class Coord {
        
    public:
        double x, y;
        Coord() {
            x = 0;
            y = 0;
        }
        Coord(double f, double s) {
            x = f;
            y = s;
        }
        Coord& operator =(Coord &other);

        ~Coord() {}
        friend std::istream & operator >> (std::istream &is, Coord &crd) {
            is >> crd.x >> crd.y;
            return is;
        }
        friend std::ostream & operator << (std::ostream &os, const Coord &crd) {
            os << "(" << crd.x << ", " << crd.y << ")";
            return os;
        }
};

Coord& Coord::operator=(Coord &other) {
    this->x = other.x;
    this->y = other.y;
    return *this;
}

#endif
