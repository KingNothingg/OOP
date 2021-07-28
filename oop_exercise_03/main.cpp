//Тарпанов Даниил, М8О-204Б-19 ЛР №3
//Вариант 18: Квадрат, прямоугольник, трапеция

#include <iostream>
#include <vector>
#include "coord.hpp"
#include "figure.hpp"
#include "square.hpp"
#include "trapeze.hpp"
#include "rectangle.hpp"

double SummOfSquares(std::vector<Figure *> &array) {
    double summ = 0.0;
    for (auto figure: array) {
        summ += figure->GetSquare();
    }
    return summ;
}

int main() {
    std::vector<Figure *> array;
    Square square;
    Rectangle rectangle;
    Trapeze trapeze;
    std::cin >> square >> rectangle >> trapeze;
    array.push_back(&square);
    array.push_back(&rectangle);
    array.push_back(&trapeze);
    Coord coord;
    for (auto figure: array) {
        figure->Print();
        std::cout << "Figure geometric center is in: " << figure->GeometricCenter() << '\n';
        std::cout << "Figure square is: " << figure->GetSquare() << '\n';
    }
    std::cout << "\nSumm of squares is: " << SummOfSquares(array) << '\n';
    std::cout << "Enter index of figure to remove it: ";
    signed int i = 0;
    std::cin >> i;
    for (auto it = array.begin(); it != array.end(); ++it) {
        --i;
        if (i == 0) array.erase(it);
    }
    std::cout << "Printing all remaining figures:\n";
    for (auto figure: array) {
        figure->Print();
    }
    std::cout << "\nSumm of squares after removal: " << SummOfSquares(array) << '\n';
}