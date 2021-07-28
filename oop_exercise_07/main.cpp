//Тарпанов Даниил, М8О-204Б-19 ЛР №7
//Вариант 18: Квадрат, прямоугольник, трапеция

#include "document.hpp"

void PrintMenu() {
    std::cout << "================" << std::endl;
	std::cout << "Menu:" << std::endl;
	std::cout << "1) Add new figure" << std::endl;
	std::cout << "2) Delete figure" << std::endl;
	std::cout << "3) Print document" << std::endl;
    std::cout << "4) Save document" << std::endl;
    std::cout << "5) Print menu again" << std::endl;
    std::cout << "6) Load document" << std::endl;
    std::cout << "7) Undo changes" << std::endl;
	std::cout << "0) Quit" << std::endl;
    std::cout << "================" << std::endl;
}

int main() {
    Document<int> doc;
    std::string fileName;
    int action;
    PrintMenu();
    while(true) {
        std::cin >> action;
        if (action == 0) {
            break;
        }
        if (action == 1) {
            size_t pos;
            unsigned short id;
            std::cout << "Enter position: ";
            std::cin >> pos;
            std::cout << "Enter figure type (1 - square, 2 - rectangle, 3 - trapeze): ";
            std::cin >> id;
            doc.Add(pos, id);
            std::cout << "Added\n";
        }
        if (action == 2) {
            size_t pos;
            std::cout << "Enter position: ";
            std::cin >> pos;
            doc.Delete(pos);
            std::cout << "Deleted\n";
        }
        if (action == 3) {
            std::cout << doc;
        }
        if (action == 4) {
            std::cout << "Enter the filename: ";
            std::cin >> fileName;
            std::ofstream of;
            of.open(fileName, std::ios::binary);
            if(of.bad()) {
                std::cout << "Can't open file\n";
            } else {
                doc.Save(of);
                of.close();
                std::cout << "Saved\n";
            }
        }
        if (action == 5) {
            PrintMenu();
        }
        if (action == 6) {
            std::cout << "Enter the filename: ";
            std::cin >> fileName;
            std::ifstream is;
            is.open(fileName, std::ios::binary);
            if(is.bad()) {
                std::cout << "Can't open file\n";
            } else {
                doc.Load(is);
                is.close();
                std::cout << "Loaded\n";
            }
        }
        if (action == 7) {
            doc.Undo();
            std::cout << "Undone\n";
        }
        if (action < 0 || action > 7) {
            std::cout << "Unknown command\n";
        }
    }
}
