//Тарпанов Даниил, М8О-204Б-19 ЛР №4
//Вариант 18: квадрат, очередь
#ifndef Queue_hpp
#define Queue_hpp

#include"item.hpp"
#include"iterator.hpp"
#include <memory>

template<class T>
class Queue{
private:
    std::shared_ptr<Item<T>> first, last;
public:
    Queue() : first(nullptr), last(nullptr) {}

    void Pop() {
        if(first) {
            first = first->next;
        } else {
            throw(std::runtime_error("Queue is empty!"));
        }
    }
    void Push(const T &elem) {
        Item<T> *temp = new Item<T>(elem);
        std::shared_ptr<Item<T>> tempShared(temp);
        if(last == nullptr) {
            first = tempShared;
            last = tempShared;
        } else {
            last->next = tempShared;
            last = tempShared;
        }
    }
    T& Front() const {
        if(first) {
            return first->item;
        } else {
            throw(std::runtime_error("Queue is empty!"));
        }
    }
    void Erase(Iterator<T> &it) {
        if(it.IsNull()) {
            throw(std::runtime_error("Nullpointer iterator!"));
        } else {
            if(*it == *first) {
                first = first->next;
            } else {
                std::shared_ptr<Item<T>> prev = first;
                while(*prev->next != *it) {
                    ++prev;
                }
                prev->next = prev->next->next;
            }
        }
    }
    void Insert(Iterator<T> &it, T &elem) {
        Item<T> *temp = new Item<T>(elem);
        std::shared_ptr<Item<T>> tempShared(temp);
        if(first) {
            if(*it == *first) {
                tempShared->next = first;
                first = tempShared;
            } else
            if(it.IsNull()) {
                last->next = tempShared;
                last = last->next;
            } else {
                std::shared_ptr<Item<T>> prev =  first;
                while(*prev != *it) {
                    ++prev;
                }
                tempShared->next = prev->next;
                prev->next = tempShared;
                std::swap(prev->item, prev->next->item);
            }
        } else {
            first = tempShared;
        }
    }
    Iterator<T> begin() {
        return Iterator<T>(first);
    }
    Iterator<T> end() {
        return Iterator<T>(nullptr);
    }

};

#endif