//Тарпанов Даниил, М8О-204Б-19 ЛР №6
//Вариант 18: квадрат, очередь
#ifndef Queue_hpp
#define Queue_hpp

#include <memory>

template<class T, class ALLOCATOR>
class Queue{
private:
    struct Item;
    using allocator_type = typename ALLOCATOR::template rebind<Item>::other;
    struct deleter {
    	allocator_type item_deleter;
    	deleter() : item_deleter() {};
    	deleter(allocator_type* another_deleter) : item_deleter(another_deleter) {}
    	void operator() (void* ptr) {
    		item_deleter.deallocate((Item*)ptr, 1);
    	}
    };
    struct Item {
        T item;
        std::shared_ptr<Item> next;
        Item() : item(), next(nullptr) {}
        Item(const T& _item) : item(_item), next(nullptr) {}

        friend void operator ++(std::shared_ptr<Item> &curr) {
            if(curr) {
                curr = curr->next;
            } else {
                throw(std::runtime_error("Nullpointer iterator!"));
            }
        }
        friend bool operator ==(const Item &lhs, const Item &rhs) {
            return &lhs.item == &rhs.item;
        }
        friend bool operator !=(const Item &lhs, const Item &rhs) {
            return &lhs.item != &rhs.item;
        }
        friend std::ostream& operator <<(std::ostream &os, const Item &currItem) {
            os << currItem.item;
            return os;
        }
    };
public:
    class Iterator  {
    private:
        std::shared_ptr<Item> ptr;
    public:
        using iterator_category = std::forward_iterator_tag;
    	using difference_type = std::ptrdiff_t;
    	using value_type = T;
    	using pointer = T*;
    	using reference = T&;
        Iterator() : ptr(nullptr) {}
        Iterator(const std::shared_ptr<Item>& _ptr) : ptr(_ptr) {}
        bool IsNull() {
            return ptr == nullptr;
        }
        friend void operator ++ (Iterator &it) {
            ++it.ptr;
        }
        friend bool operator != (const Iterator &lhs,const  Iterator &rhs) {
            return lhs.ptr != rhs.ptr;
        }
        Item& operator *() {
            return *ptr;
        }
        friend std::ostream& operator <<(std::ostream &os, const Iterator &it) {
            os << *it.ptr;
            return os;
        }
    };
private:
    std::shared_ptr<Item> first, last;
    deleter queue_deleter;
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
        Item *temp = queue_deleter.item_deleter.allocate(sizeof(Item));
        queue_deleter.item_deleter.construct(temp, elem);
        std::shared_ptr<Item> tempShared(temp, queue_deleter);
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
    void Erase(Iterator &it) {
        if(it.IsNull()) {
            throw(std::runtime_error("Nullpointer iterator!"));
        } else {
            if(*it == *first) {
                first = first->next;
            } else {
                std::shared_ptr<Item> prev = first;
                while(*prev->next != *it) {
                    ++prev;
                }
                prev->next = prev->next->next;
            }
        }
    }
    void Insert(Iterator &it, T &elem) {
        Item *temp = queue_deleter.item_deleter.allocate(sizeof(Item));
        queue_deleter.item_deleter.construct(temp, elem);
        std::shared_ptr<Item> tempShared(temp, queue_deleter);
        if(first) {
            if(*it == *first) {
                tempShared->next = first;
                first = tempShared;
            } else
            if(it.IsNull()) {
                last->next = tempShared;
                last = last->next;
            } else {
                std::shared_ptr<Item> prev =  first;
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
    Iterator begin() {
        return Iterator(first);
    }
    Iterator end() {
        return Iterator(nullptr);
    }

};

#endif