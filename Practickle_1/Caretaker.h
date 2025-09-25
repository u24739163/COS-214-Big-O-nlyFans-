#ifndef CARETAKER_H
#define CARETAKER_H

#include "Memento.h"
#include <list>

class Caretaker {
    public:
        void addMemento(Memento* memento);
        Memento* getMemento() const;
    private:
        list<Memento*> savedMementos;
};

#endif