//Тарпанов Даниил, М8О-204Б-19 ЛР №7
//Вариант 18: Квадрат, прямоугольник, трапеция

#ifndef Figure_HPP
#define Figure_HPP

#include<iostream>
#include<fstream>
#include<tuple>

class Figure {
    public:
        virtual void Print(std::ostream &os) = 0;
        virtual void Write(std::ofstream &of) = 0;
        virtual ~Figure() {}
};

#endif