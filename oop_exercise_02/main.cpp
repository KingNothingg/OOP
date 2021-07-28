//Тарпанов Даниил, М8О-204Б-19
//Вариант №7, создать класс BitString для работы с 128-битовыми строками. Реализовать традиционные операции
//для работы с битами, сдвиги и операторы сравнения.

#include <iostream>
#include <fstream>
#include "bitstring.cpp"

int main(int argc, char *argv[]) {
    BitString bs1, bs2, bs3;
    unsigned sh1, sh2;
    unsigned long long ull1, ull2;
    if (argc == 1) {
        std::cout << "Enter the first number: ";
        std::cin >> ull1;
        std::cout << "Enter the second number: ";
        std::cin >> ull2;
        std::cout << "Enter the value for the first number right shift: ";
        std::cin >> sh1;
        std::cout << "Enter the value for the second number left shift: ";
        std::cin >> sh2;
    } else {
        std::ifstream file(argv[1]);
        file >> ull1 >> ull2 >> sh1 >> sh2;
        file.close();
    }
    std::cout << "Starting values: " << ull1 << " and " << ull2 << '\n';
    bs1 = ull1;
    bs2 = ull2;
    bs3 = bs1 & bs2;
    std::cout << "Result for num1 & num2: ";
    bs3.Print();
    std::cout << "Result for num1 | num2: ";
    bs3 = bs1 | bs2;
    bs3.Print();
    std::cout << "Result for num1 ^ num2: ";
    bs3 = bs1 ^ bs2;
    bs3.Print();
    std::cout << "Result for ~num1: ";
    bs3 = ~bs1;
    bs3.Print();
    std::cout << "Result for ~num2: ";
    bs3 = ~bs2;
    bs3.Print();
    std::cout << "Result for num1 >> " << sh1 << ": ";
    bs3 = bs1 << sh1;
    bs3.Print();
    std::cout << "Result for num2 << " << sh2 << ": ";
    bs3 = bs2 << sh2;
    bs3.Print();
    std::cout << "Number of \"1\" bits for num1: " << bs1.BitCount() << ", num2: " << bs2.BitCount() << '\n';
    std::cout << "Check logical relation for number of \"1\" bits: \n";
    if(bs1 == bs2) std::cout << "They are equal!\n";
    if(bs1 > bs2) std::cout << "Num1 has more \"1\" bites than num2!\n";
    if(bs1 < bs2) std::cout << "Num2 has more \"1\" bites than num1!\n";
    bs3 = 123_bs;
    std::cout << "Literal initialized number: ";
    bs3.Print();
}