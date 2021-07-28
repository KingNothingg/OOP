//Тарпанов Даниил, М8О-204Б-19 ЛР №6
//Вариант 18: квадрат, очередь

#include<algorithm>
#include "queue.hpp"
#include "square.hpp"
#include "allocator.hpp"

void PrintMenu() {
    std::cout << "================" << std::endl;
	std::cout << "Menu:" << std::endl;
	std::cout << "1) Push back square" << std::endl;
	std::cout << "2) Erase square" << std::endl;
	std::cout << "3) Print queue" << std::endl;
    std::cout << "4) Insert square" << std::endl;
    std::cout << "5) Print menu again" << std::endl;
    std::cout << "6) Pop square from queue" << std::endl;
    std::cout << "7) Show front square" << std::endl;
	std::cout << "0) Quit" << std::endl;
}

const std::size_t BLOCK_SIZE = 256;

int main() {
    short action;
    int ind = 0;
    auto Print = [](const auto &square) {
		std::cout << square;
	};
    
    Square<int> square;
    Queue<Square<int>, linear_allocator_t< Square<int>, BLOCK_SIZE >> queue;
    PrintMenu();
    while(true) {
        std::cin >> action;
        if(action == 0) break;
        if(action == 1) {
            std::cin >> square;
            queue.Push(square);
        }
        if(action == 2) {
            std::cout << "Input index to erase from queue: ";
            std::cin >> ind;
            if(ind < 0) throw(std::runtime_error("Wrond index format"));
            Queue<Square<int>, linear_allocator_t< Square<int>, BLOCK_SIZE >>::Iterator it = queue.begin();
            while(ind > 1) {
                ++it;
                --ind;
            }
            queue.Erase(it);
        }
        if(action == 3) std::for_each(queue.begin(), queue.end(), Print);
        if(action == 4) {
            std::cout << "Input index to insert square: ";
            std::cin >> ind;
            if(ind < 0) throw(std::runtime_error("Wrong index format"));
            std::cin >> square;
            Queue<Square<int>, linear_allocator_t< Square<int>, BLOCK_SIZE >>::Iterator it = queue.begin();
            while(ind > 1) {
                ++it;
                --ind;
            }
            queue.Insert(it, square);
        }
        if(action == 5) PrintMenu();
        if(action == 6) {
            std::cout << "Square popped\n";
            queue.Pop();
        }
        if(action == 7) std::cout << queue.Front();
        if(action == 0) break;
        if(action < 0 || action > 7) std::cout << "Wrong action format!\n";
    }
}