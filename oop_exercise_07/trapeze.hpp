//Тарпанов Даниил, М8О-204Б-19 ЛР №7
//Вариант 18: Квадрат, прямоугольник, трапеция

#ifndef Trapeze_HPP
#define Trapeze_HPP

#include "figure.hpp"
#include <fstream>
#include <iostream>
#include <utility>

const unsigned short TRAP_ID = 3;

template<class T>
class Trapeze : public Figure{
    public:
        std::pair<T,T> leftBottom;
        T smallerBase, largerBase, sideSize;
        void Print(std::ostream &os) override {
            os << *this;
        }
        void Write(std::ofstream &of) {
            of.write((char*)&TRAP_ID, sizeof(unsigned short));
            of.write((char*)&leftBottom.first, sizeof(T));
            of.write((char*)&leftBottom.second, sizeof(T));
            of.write((char*)&smallerBase, sizeof(T));
            of.write((char*)&largerBase, sizeof(T));
            of.write((char*)&sideSize, sizeof(T));
        }
        Trapeze(std::pair<T,T> _lBot, T _sB, T _lB, T _sS) : leftBottom(_lBot), smallerBase(_sB), largerBase(_lB), sideSize(_sS) { }
};

template<class T>
std::ostream& operator <<(std::ostream &os, Trapeze<T> &trap) {
    os << "\nTrapeze print:\n";
    os << "Left bottom dot coordinates: (" << trap.leftBottom.first << ", " << trap.leftBottom.second << ")\n";
    os << "Size of smaller and larger bases: " << trap.smallerBase << ", " << trap.largerBase << '\n';
    os << "Size of side: " << trap.sideSize << '\n';
    return os;
}

#endif