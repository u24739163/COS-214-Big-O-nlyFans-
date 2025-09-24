#include "Memento.h"

    Memento::Memento(vector<Shape*> elements)
    {
        for (Shape* shape : elements) {
            if (shape != nullptr) {
                shapes.push_back(shape->clone());
            }
        }
    };

    vector<Shape*> Memento::getMemento() const{
        vector<Shape*> copy;
        for (Shape* shape : shapes) {
            if (shape != nullptr) {
                copy.push_back(shape->clone());
            }
        }
        return copy;
    };

    Memento::~Memento() {
        for (Shape* shape : shapes) {
            delete shape;
        }
        shapes.clear();
    }
