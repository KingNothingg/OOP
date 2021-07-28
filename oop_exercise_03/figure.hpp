//Тарпанов Даниил, М8О-204Б-19 ЛР №3
//Вариант 18: Квадрат, прямоугольник, трапеция

#ifndef Figure_HPP
#define Figure_HPP

#include "Coord.hpp"

class Figure {
    public:
        virtual double GetSquare() = 0;
        virtual void Print() = 0;
        virtual Coord GeometricCenter() = 0;
};

#endif