//Тарпанов Даниил, М8О-204Б-19 ЛР №6
//Вариант 18: квадрат, очередь
#ifndef Item_HPP
#define Item_HPP

#include <iostream>
#include <memory>

struct Item;

template<class T, class ALLOCATOR>
using allocator_type = typename ALLOCATOR::template rebind<Item>::other;
template<class T, class ALLOCATOR>
struct deleter {
	allocator_type item_deleter;
	deleter() : item_deleter() {};
	deleter(allocator_type* another_deleter) : item_deleter(another_deleter) {}
	void operator() (void* ptr) {
		item_deleter.deallocate((Item*)ptr, 1);
	}
};

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