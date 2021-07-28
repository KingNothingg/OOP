//Тарпанов Даниил, М8О-204Б-19 ЛР №4
//Вариант 18: Квадрат, прямоугольник, трапеция

#ifndef Trapeze_HPP
#define Trapeze_HPP

#include <iostream>
#include <utility>
#include <cmath>


template<class T>
struct Trapeze {
    std::pair<T,T> leftBottom;
    T smallerBase, largerBase, sideSize;

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

template<class T>
T GetSquare(Trapeze<T> &trap) {
    T pp = sqrt(trap.sideSize * trap.sideSize - (trap.largerBase - trap.smallerBase) * (trap.largerBase - trap.smallerBase) / 4);
    return pp * (trap.smallerBase + trap.largerBase) / 2;
}

#endif