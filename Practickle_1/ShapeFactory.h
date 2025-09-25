#ifndef SHAPEFACTORY_H
#define SHAPEFACTORY_H

#include "Shape.h"
#include <iostream>
using namespace std;
class ShapeFactory {
    protected:
        virtual Shape* createShape(int length = 0, int width = 0, string colour = "white", int posX = 0, int posY = 0, string text = "") const = 0;
        virtual void toString() const = 0;
};

class SquareFactory : public ShapeFactory {
    public:
        Shape* createShape(int length = 0, int width = 0, string colour = "white", int posX = 0, int posY = 0, string text = "") const override;
        void toString() const override;
};

class RectangleFactory : public ShapeFactory {
    public:
        Shape* createShape(int length = 0, int width = 0, string colour = "white", int posX = 0, int posY = 0, string text = "") const override;
        void toString() const override;
};

class TextboxFactory : public ShapeFactory {
    public:
        Shape* createShape(int length = 0, int width = 0, string colour = "white", int posX = 0, int posY = 0, string text = "") const override;
        void toString() const override;
};

#endif