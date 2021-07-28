//Тарпанов Даниил, М8О-204Б-19 ЛР №7
//Вариант 18: Квадрат, прямоугольник, трапеция

#ifndef Document_HPP
#define Document_HPP

#include <list>
#include <stack>

#include "factory.hpp"

template<class T>
class Document {
    private:
        std::list<std::shared_ptr<Figure>> figures;

        struct Action {
            virtual void Act(Document &doc) = 0;
            virtual ~Action() {}
        };
        
        class AddToDoc : public Action {
            private:
                size_t position;
                std::shared_ptr<Figure> figure;
            public:
                AddToDoc(const size_t &pos, const std::shared_ptr<Figure> &fig) : position(pos), figure(fig) {}
                void Act(Document &doc) override {
                    doc.AddFigure(position, figure);
                }
        };

        class DeleteFromDoc : public Action {
            private:
                size_t position;
            public:
                DeleteFromDoc(const size_t &pos) : position(pos) {}
                void Act(Document &doc) override {
                    doc.Delete(position);
                }
        };

        std::stack<std::shared_ptr<Action>> actions;

    public:
        Document() = default;
        void ClearDocument() {
            figures.clear();
            while(!actions.empty()) {
                actions.pop();
            }
        }
        void AddFigure(const size_t &pos, const std::shared_ptr<Figure> &fig) {
            if (pos > figures.size()) {
                figures.push_back(fig);
                DeleteFromDoc* del = new DeleteFromDoc(figures.size());
                actions.push(std::shared_ptr<Action>(del));
            } else {
                size_t curr = 0;
                std::list<std::shared_ptr<Figure>>::const_iterator it = figures.begin();
                while(curr < pos) {
                    ++curr;
                    ++it;
                }
                figures.insert(it, fig);
                DeleteFromDoc* del = new DeleteFromDoc(pos + 1);
                actions.push(std::shared_ptr<Action>(del));
            }
        }
        void Delete(const size_t &pos) {
            if (figures.empty()) {
                std::cout << "Document is empty\n";
                return;
            }
            if(pos > figures.size()) {
                AddToDoc* add = new AddToDoc(figures.size() - 1, figures.back());
                actions.push(std::shared_ptr<Action>(add));
                figures.pop_back();
            } else {
                size_t curr = 1;
                std::list<std::shared_ptr<Figure>>::const_iterator it = figures.begin();
                while(curr < pos) {
                    ++curr;
                    ++it;
                }
                AddToDoc* add = new AddToDoc(curr - 1, *it);
                actions.push(std::shared_ptr<Action>(add));
                figures.erase(it);
            }
        }
        void Undo() {
            if (actions.empty()) {
                std::cout << "Nothing to undo\n";
                return;
            }
            actions.top()->Act(*this);
            actions.pop();
            actions.pop();
        }
        void Save(std::ofstream &of) {
            size_t size = figures.size();
            of.write((char*)&size, sizeof(size_t));
            for(auto it = figures.begin(); it != figures.end(); ++it) {
                (*it)->Write(of);
            }
        }
        void Load(std::ifstream &is) {
            ClearDocument();
            size_t size;
            is.read((char*)&size, sizeof(size_t));
            for(size_t i = 0; i < size; ++i) {
                unsigned short id;
                is.read((char*)&id, sizeof(unsigned short));
                if(id == SQUARE_ID) {
                    figures.push_back(Factory<T, Square<T>>::Read(is));
                }
                if(id == REC_ID) {
                    figures.push_back(Factory<T, Rectangle<T>>::Read(is));
                }
                if(id == TRAP_ID) {
                    figures.push_back(Factory<T, Trapeze<T>>::Read(is));
                }
            }
        }
        void Add(const size_t &pos, const unsigned short &id) {
            if(id == SQUARE_ID) {
                AddFigure(pos, Factory<T, Square<T>>::Read());
            }
            if(id == REC_ID) {
                AddFigure(pos, Factory<T, Rectangle<T>>::Read());
            }
            if(id == TRAP_ID) {
                AddFigure(pos, Factory<T, Trapeze<T>>::Read());
            }
        }
        template<class L>
        friend std::ostream& operator << (std::ostream &os, const Document<L> &doc) {
            auto it = doc.figures.begin();
            for(size_t i = 0; i < doc.figures.size(); ++i) {
                os << i + 1 << ".";
                (*it)->Print(os);
                ++it;
            }
            return os;
        }
};



#endif