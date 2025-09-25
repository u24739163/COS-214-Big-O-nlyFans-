#ifndef MEMENTO_H
#define MEMENTO_H

#include "Shape.h"
#include <vector>

class Memento {

    public:
        vector<Shape*> getMemento() const;
        ~Memento();
    private:
    friend class Canvas;
        vector<Shape*> shapes;
        Memento(vector<Shape*> elements);
};

#endif