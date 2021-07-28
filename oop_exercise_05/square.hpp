//Тарпанов Даниил, М8О-204Б-19 ЛР №4
//Вариант 18: квадрат, очередь

#ifndef Square_HPP
#define Square_HPP

#include <iostream>
#include <utility>

template<class T>
struct Square {
    std::pair<T,T> leftBottom;
    T side;
    Square() {}
    Square(std::pair<T,T> _leftBottom, T _side) : leftBottom(_leftBottom), side(_side) { }
};

template<class T>
std::ostream& operator << (std::ostream& os, const Square<T> &square) {
    os << "Square print\n";
    os << "Left bottom dot coordinates: (" << square.leftBottom.first << ", " << square.leftBottom.second << ")\n";
    os << "Side length: " << square.side << '\n';
    return os;
}

template<class T>
std::istream& operator >> (std::istream& is, Square<T> &square) {
    std::cout << "Square read: \n" << "Enter left bottom dot coordinates: ";
    is >> square.leftBottom.first >> square.leftBottom.second;
    std::cout << "Enter side size: ";
    is >> square.side;
    std::cout << '\n';
    if(square.side <= 0) {
        throw(std::runtime_error("Square should have positive side length!\n"));
    }
    return is;
}

template<class T>
T GetSquare(const Square<T> &square) {
    return square.side * square.side;
}

#endif