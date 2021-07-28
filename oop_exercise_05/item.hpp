//Тарпанов Даниил, М8О-204Б-19 ЛР №5
//Вариант 18: квадрат, очередь
#ifndef Item_HPP
#define Item_HPP

#include <iostream>
#include <memory>

template<class T>
struct Item {
    T item;
    std::shared_ptr<Item<T>> next;

    Item() : item(), next(nullptr) {}
    Item(const T& _item) : item(_item), next(nullptr) {}

    friend void operator ++(std::shared_ptr<Item<T>> &curr) {
        if(curr) {
            curr = curr->next;
        } else {
            throw(std::runtime_error("Nullpointer iterator!"));
        }
    }
    friend bool operator ==(const Item<T> &lhs, const Item<T> &rhs) {
        return &lhs.item == &rhs.item;
    }
    friend bool operator !=(const Item<T> &lhs, const Item<T> &rhs) {
        return &lhs.item != &rhs.item;
    }
    friend std::ostream& operator <<(std::ostream &os, const Item<T> &currItem) {
        os << currItem.item;
        return os;
    }
};

#endif