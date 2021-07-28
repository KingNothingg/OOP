//Тарпанов Даниил, М8О-204Б-19 ЛР №4
//Вариант 18: Квадрат, прямоугольник, трапеция

#ifndef Square_HPP
#define Square_HPP

#include <iostream>
#include <utility>

template<class T>
struct Square {
    std::pair<T,T> leftBottom;
    T side;

    Square(std::pair<T,T> _leftBottom, T _side) : leftBottom(_leftBottom), side(_side) { }
};

template<class T>
std::ostream& operator << (std::ostream& os, Square<T> &square) {
    os << "\nSquare print\n";
    os << "Left bottom dot coordinates: (" << square.leftBottom.first << ", " << square.leftBottom.second << ")\n";
    os << "Side length: " << square.side << '\n';
    return os;
}

template<class T>
T GetSquare(Square<T> &square) {
    return square.side * square.side;
}

#endif