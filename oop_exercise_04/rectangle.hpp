//Тарпанов Даниил, М8О-204Б-19 ЛР №4
//Вариант 18: Квадрат, прямоугольник, трапеция

#ifndef Rectangle_HPP
#define Rectangle_HPP

#include <iostream>
#include <utility>

template<class T>
struct Rectangle {
    std::pair<T,T> leftBottom, rightTop;

    Rectangle(std::pair<T,T> _leftBottom, std::pair<T,T> _rightTop) : leftBottom(_leftBottom), rightTop(_rightTop) { }
};

template<class T>
std::ostream& operator << (std::ostream& os, const Rectangle<T> &rec) {
    os << "\nRectangle print:\n";
    os << "Left bottom dot coordinates: (" << rec.leftBottom.first << ", " << rec.leftBottom.second << ")\n";
    os << "Right top dot coordinates: (" << rec.rightTop.first << ", " << rec.leftBottom.second << ")\n";
    return os;
}

template<class T>
T GetSquare(const Rectangle<T> &rec) {
    return ((rec.rightTop.first - rec.leftBottom.first) * (rec.rightTop.second - rec.leftBottom.second));
}

#endif