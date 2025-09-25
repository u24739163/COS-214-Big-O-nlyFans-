#ifndef CANVAS_H
#define CANVAS_H

#include "Shape.h"
#include "Memento.h"
#include <iostream>
#include <vector>
#include <map>
#include <fstream>

class Canvas {
    public:
        ~Canvas();
        void addShape(Shape* shape);
        void clearCanvas();
        Memento* captureCurrent();
        void undoAction(Memento* prev);
        void print();
    private:
        vector<Shape*> shapes;
};

#endif