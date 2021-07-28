//Тарпанов Даниил, М8О-204Б-19 ЛР №7
//Вариант 18: Квадрат, прямоугольник, трапеция

#ifndef Rectangle_HPP
#define Rectangle_HPP

#include "figure.hpp"
#include <fstream>
#include <iostream>
#include <utility>

const unsigned short REC_ID = 2;

template<class T>
class Rectangle: public Figure {
    public:
        std::pair<T,T> leftBottom, rightTop;
        void Print(std::ostream &os) override {
            os << *this;
        }
        void Write(std::ofstream& of) override {
            of.write((char*)&REC_ID, sizeof(unsigned short));
            of.write((char*)&leftBottom.first, sizeof(T));
            of.write((char*)&leftBottom.second, sizeof(T));
            of.write((char*)&rightTop.first, sizeof(T));
            of.write((char*)&rightTop.second, sizeof(T));
        }
        Rectangle(std::pair<T,T> _leftBottom, std::pair<T,T> _rightTop) : leftBottom(_leftBottom), rightTop(_rightTop) { }
};

template<class T>
std::ostream& operator << (std::ostream& os, const Rectangle<T> &rec) {
    os << "\nRectangle print:\n";
    os << "Left bottom dot coordinates: (" << rec.leftBottom.first << ", " << rec.leftBottom.second << ")\n";
    os << "Right top dot coordinates: (" << rec.rightTop.first << ", " << rec.rightTop.second << ")\n";
    return os;
}

#endif