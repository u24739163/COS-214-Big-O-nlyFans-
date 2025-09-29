#include "Memento.h"

Memento::Memento(VectorFather<string> elements) : history(elements) {}

VectorFather<string> Memento::getMemento() const {
    return history;
}

Memento::~Memento() {
    history.getVector()->clear();
}