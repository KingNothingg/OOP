//Тарпанов Даниил, М8О-204Б-19 ЛР №7
//Вариант 18: Квадрат, прямоугольник, трапеция

#ifndef Factory_HPP
#define Factory_HPP

#include <memory>
#include <iostream>

#include "rectangle.hpp"
#include "square.hpp"
#include "trapeze.hpp"

template<class T, class FigureType>
class Factory;

template<class T>
class Factory<T, Square<T>> {
    public:
        static std::shared_ptr<Figure> Read() {
            std::pair<T, T> leftBottom;
            T side;
            std::cout << "\nSquare input:\n" << "Enter left bottom dot coordinates: ";
            std::cin >> leftBottom.first >> leftBottom.second;
            std::cout << "Enter side length: ";
            std::cin >> side;
            if(side <= 0) {
                std::cout << "Invalid input!" << '\n';
                exit(-1);
            }
            Square<T>* tempSquare = new Square<T>(leftBottom, side);
            return std::shared_ptr<Figure>(tempSquare);
        }
        static std::shared_ptr<Figure> Read(std::ifstream &is) {
            std::pair<T, T> leftBottom;
            T side;
            is.read((char*)&leftBottom.first, sizeof(T));
            is.read((char*)&leftBottom.second, sizeof(T));
            is.read((char*)&side, sizeof(T));
            Square<T>* tempSquare = new Square<T>(leftBottom, side);
            return std::shared_ptr<Figure>(tempSquare);
        }
};

template<class T>
class Factory<T, Rectangle<T>> {
    public:
        static std::shared_ptr<Figure> Read() {
            std::pair<T, T> leftBottom;
            std::pair<T, T> rightTop;
            std::cout << "\nRectangle input:\n" << "Enter left bottom dot coordinates: ";
            std::cin >> leftBottom.first >> leftBottom.second;
            std::cout << "Enter top right dot coordinates: ";
            std::cin >> rightTop.first >> rightTop.second;
            if((rightTop.first < leftBottom.first) ||(rightTop.second < leftBottom.second)) {
                std::cout << "Invalid input!" << '\n';
                exit(-1);
            }
            Rectangle<T>* tempRec = new Rectangle<T>(leftBottom, rightTop);
            return std::shared_ptr<Figure>(tempRec);
        }
        static std::shared_ptr<Figure> Read(std::ifstream &is) {
            std::pair<T, T> leftBottom;
            std::pair<T, T> rightTop;
            is.read((char*)&leftBottom.first, sizeof(T));
            is.read((char*)&leftBottom.second, sizeof(T));
            is.read((char*)&rightTop.first, sizeof(T));
            is.read((char*)&rightTop.second, sizeof(T));
            Rectangle<T>* tempRec = new Rectangle<T>(leftBottom, rightTop);
            return std::shared_ptr<Figure>(tempRec);
        }
};

template<class T>
class Factory<T, Trapeze<T>> {
    public:
        static std::shared_ptr<Figure> Read() {
            std::pair<T, T> leftBottom;
            T smallerBase, largerBase, sideSize;
            std::cout << "\nTrapeze input:\n" << "Enter left bottom dot coordinates: ";
            std::cin >> leftBottom.first >> leftBottom.second;
            std::cout << "Enter smaller base: ";
            std::cin >> smallerBase;
            std::cout << "Enter larger base: ";
            std::cin >> largerBase;
            std::cout << "Enter side size: ";
            std::cin >> sideSize;
            if (smallerBase < 0 || largerBase < 0 || sideSize < 0) {
                std::cout << "Invalid input!" << '\n';
                exit(-1);
            }
            Trapeze<T>* tempTrap = new Trapeze<T>(leftBottom, smallerBase, largerBase, sideSize);
            return std::shared_ptr<Figure>(tempTrap);
        }
        static std::shared_ptr<Figure> Read(std::ifstream &is) {
            std::pair<T, T> leftBottom;
            T smallerBase, largerBase, sideSize;
            is.read((char*)&leftBottom.first, sizeof(T));
            is.read((char*)&leftBottom.second, sizeof(T));
            is.read((char*)&smallerBase, sizeof(T));
            is.read((char*)&largerBase, sizeof(T));
            is.read((char*)&sideSize, sizeof(T));
            Trapeze<T>* tempTrap = new Trapeze<T>(leftBottom, smallerBase, largerBase, sideSize);
            return std::shared_ptr<Figure>(tempTrap);
        }
};


#endif