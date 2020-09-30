////Тарпанов Даниил Александрович вар. 20 реализовать класс бутылки
#include <iostream>
#include <fstream>

class Bottle {
    private:
        double bottle_volume;
        double bottle_filling;
    public: 
        Bottle(){               //конструктор без параметров
            bottle_filling = 0;
            bottle_volume = 0;
        }
        Bottle(double vol, double fill){ // конструктор с параметрами
            bottle_filling = fill;
            bottle_volume = vol;
        }
        void set_volume(double vol){ // сеттеры и геттеры
            bottle_volume = vol;
        }
        void set_filling(double fill){
            bottle_filling = fill;
        }
        double get_volume(){
            return bottle_volume;
        }
        double get_filling(){
            return bottle_filling;
        }
        void print_state(){ // вывод состояния бутылки
            std::cout << "Bottle volume: " << bottle_volume << ", Bottle filling: " << bottle_filling << std::endl;
        }
        friend Bottle operator+(Bottle &a, Bottle &b);
        friend Bottle operator-(Bottle &a, Bottle &b);
        friend bool operator <(Bottle &a, Bottle &b);
        friend bool operator >(Bottle &a, Bottle &b);
        friend bool operator ==(Bottle &a, Bottle &b);
        friend bool operator <=(Bottle &a, Bottle &b);
        friend bool operator >=(Bottle &a, Bottle &b);
};

Bottle operator+(Bottle &a, Bottle &b){
    double liquid_volume = (a.bottle_filling * a.bottle_volume + b.bottle_filling * b.bottle_volume) / a.bottle_volume;
    if (liquid_volume > 1){
        b.bottle_filling = (liquid_volume - 1) / b.bottle_volume;
        liquid_volume = 1;
    } else b.bottle_filling = 0;
    return Bottle(a.bottle_volume, liquid_volume);
}
Bottle operator-(Bottle &a, Bottle &b){
    double liquid_volume = (a.bottle_filling * a.bottle_volume - b.bottle_filling * b.bottle_volume) / a.bottle_volume;
    if (liquid_volume < 0) liquid_volume = 0;
    return Bottle(a.bottle_volume, liquid_volume);
}

bool operator <(Bottle &a, Bottle &b){
    if ((a.bottle_filling * a.bottle_volume) < (b.bottle_filling * b.bottle_volume)) return true;
    return false;
}
bool operator >(Bottle &a, Bottle &b){
    if ((a.bottle_filling * a.bottle_volume) > (b.bottle_filling * b.bottle_volume)) return true;
    return false;
}
bool operator ==(Bottle &a, Bottle &b){
    if ((a.bottle_filling * a.bottle_volume) == (b.bottle_filling * b.bottle_volume)) return true;
    return false;
}
bool operator <=(Bottle &a, Bottle &b){
    if ((a.bottle_filling * a.bottle_volume) <= (b.bottle_filling * b.bottle_volume)) return true;
    return false;
}
bool operator >=(Bottle &a, Bottle &b){
    if ((a.bottle_filling * a.bottle_volume) >= (b.bottle_filling * b.bottle_volume)) return true;
    return false;
}

int main(int argc, char *argv[]){
    double vol_1, fill_1, vol_2, fill_2;
    if (argc == 1){
        std::cout << "Enter bottle volume and bottle filling for first bottle: ";
        std::cin >> vol_1 >> fill_1;
        std::cout << "Enter bottle volume and bottle filling for second bottle: ";
        std::cin >> vol_2 >> fill_2;
    } 
    else{
        std::ifstream file(argv[1]);
        file >> vol_1 >> fill_1 >> vol_2 >> fill_2;
        file.close();
    }
    Bottle bottle_1(vol_1, fill_1), bottle_2, bottle_3;
    bottle_2.set_volume(vol_2);
    bottle_2.set_filling(fill_2);
    std::cout << "Starting values: \nFirst bottle volume is " << bottle_1.get_volume() << ", filling is " << bottle_1.get_filling() << '\n';
    std::cout << "Second bottle volume is " << bottle_2.get_volume() << ", filling is " << bottle_2.get_filling() << '\n';
    bottle_1 = bottle_1 + bottle_2;
    std::cout << "Summ of first and second bottles: ";
    bottle_1.print_state();
    bottle_2 = bottle_2 - bottle_1;
    std::cout << "Difference of second and first bottles: ";
    bottle_2.print_state();
    std::cout << "Check for logical relation: ";
    if(bottle_1 == bottle_2) std::cout << "Bottles are equal!\n";
    if(bottle_1 > bottle_2) std::cout << "First bottle is bigger than second one!\n";
    if(bottle_1 < bottle_2) std::cout << "First bottle is less than second one!\n";
}
