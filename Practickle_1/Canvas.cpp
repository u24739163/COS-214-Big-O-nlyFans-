#include "Canvas.h"
    Canvas :: ~Canvas()
    {
        clearCanvas();
    }

    void Canvas::addShape(Shape* shape)
    {
        if (shape != nullptr) {
            shapes.push_back(shape->clone());    
        } 
        else 
        {
            std::cout << "Canvas.cpp addShape shape is nullptr." << std::endl;
        }
    }

    Memento* Canvas::captureCurrent()
    {
        return new Memento(shapes);
    }

    void Canvas :: undoAction(Memento* prev)
    {
        clearCanvas();
        shapes = prev->getMemento();
    }

    void Canvas :: clearCanvas() 
    {
        for (Shape* shape : shapes) {
        delete shape;
        }
        shapes.clear();
    }

    void Canvas::print()
    {
        std::cout << "Canvas contains the following shapes:" << std::endl;
        for (const auto& shape : shapes) {
            if (shape != nullptr) {
                shape->print();
            }
        }
    }
