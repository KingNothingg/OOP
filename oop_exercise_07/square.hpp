//Тарпанов Даниил, М8О-204Б-19 ЛР №7
//Вариант 18: Квадрат, прямоугольник, трапеция

#ifndef Square_HPP
#define Square_HPP

#include "figure.hpp"
#include <fstream>
#include <iostream>
#include <utility>

const unsigned short SQUARE_ID = 1;

template<class T>
class Square : public Figure {
    public:
        std::pair<T,T> leftBottom;
        T side;
        void Print(std::ostream &os) override {
            os << *this;
        }
        void Write(std::ofstream &of) override {
            of.write((char*)&SQUARE_ID, sizeof(unsigned short));
            of.write((char*)&leftBottom.first, sizeof(T));
            of.write((char*)&leftBottom.second, sizeof(T));
            of.write((char*)&side, sizeof(T));
        }
        Square(std::pair<T,T> _leftBottom, T _side) : leftBottom(_leftBottom), side(_side) { }
};

template<class T>
std::ostream& operator << (std::ostream& os, Square<T> &square) {
    os << "\nSquare print\n";
    os << "Left bottom dot coordinates: (" << square.leftBottom.first << ", " << square.leftBottom.second << ")\n";
    os << "Side length: " << square.side << '\n';
    return os;
}


#endif