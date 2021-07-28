//Тарпанов Даниил, М8О-204Б-19 ЛР №
//Вариант 18: квадрат, очередь
#ifndef Iterator_hpp
#define Iterator_hpp

#include <memory>
#include <iostream>
#include "item.hpp"

template <typename T>
class Iterator  {
    private:
        std::shared_ptr<Item<T>> ptr;
    public:
        using iterator_category = std::forward_iterator_tag;
		using difference_type = std::ptrdiff_t;
		using value_type = T;
		using pointer = T*;
		using reference = T&;
        
        Iterator() : ptr(nullptr) {}
        Iterator(const std::shared_ptr<Item<T>>& _ptr) : ptr(_ptr) {}

        bool IsNull() {
            return ptr == nullptr;
        }

        friend void operator ++ (Iterator &it) {
            ++it.ptr;
        }
        friend bool operator != (const Iterator &lhs,const  Iterator &rhs) {
            return lhs.ptr != rhs.ptr;
        }
        Item<T>& operator *() {
            return *ptr;
        }
        friend std::ostream& operator <<(std::ostream &os, const Iterator &it) {
            os << *it.ptr;
            return os;
        }
};
#endif