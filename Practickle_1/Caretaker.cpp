#include "Caretaker.h"

void Caretaker::addMemento(Memento* memento) {
    if (memento != NULL) {
        savedMementos.push_back(memento);
    }
}

Memento* Caretaker::getMemento() const {
    return savedMementos.empty() ? NULL : savedMementos.back();
}
