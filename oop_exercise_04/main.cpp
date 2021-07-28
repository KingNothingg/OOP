//Тарпанов Даниил, М8О-204Б-19 ЛР №4
//Вариант 18: Квадрат, прямоугольник, трапеция

#include <iostream>
#include <utility>
#include <tuple>
#include "square.hpp"
#include "trapeze.hpp"
#include "rectangle.hpp"

#define intPair std::pair<int,int>
#define doublePair std::pair<double, double> 

template<class T, unsigned short ind = 0>
void Print(T &tuple) {
    if constexpr (ind < std::tuple_size<T>::value) {
        std::cout << std::get<ind>(tuple) << '\n';
        Print<T, ind + 1>(tuple);
    }
}

template<class T, unsigned short ind = 0>
double SummOfSquares(T& tuple) {
    if constexpr(ind < std::tuple_size<T>::value) {
        return (double)GetSquare(std::get<ind>(tuple)) + SummOfSquares<T, ind + 1>(tuple);
    } else return 0;
}

int main() {
    Square<int> intSquare(intPair(10, 10), 5);
    Rectangle<int> intRec(intPair(0, 0), intPair(1, 1));
    Trapeze<int> intTrap(intPair(2, 2), 3, 4, 5);
    Square<double> doubleSquare(doublePair(1.5, 1.5), 3.5);
    Rectangle<double> doubleRec(doublePair(1.3, 9.8), doublePair(4.6, 11.2));
    Trapeze<double> doubleTrap(doublePair(4.9, 18.2), 13.3, 17.8, 19.9);

    auto tuple = std::make_tuple(intSquare, intRec, intTrap, doubleSquare, doubleRec, doubleTrap);
    Print(tuple);
    std::cout << "Summ of squares is: " << SummOfSquares(tuple) << '\n';
}