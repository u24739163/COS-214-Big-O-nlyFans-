#include "ShapeFactory.h"

Shape* SquareFactory::createShape(int length, int width, string colour, int posX, int posY, string text) const {
    SquareFactory::toString();
    return new Square(length, colour, posX, posY);
}
void SquareFactory::toString() const {
    cout << "Square Factory: Creates a Square shape." << endl;
}
Shape* RectangleFactory::createShape(int length, int width, string colour, int posX, int posY, string text) const {
    RectangleFactory::toString();
    return new Rectangle(length, width, colour, posX, posY);
}
void RectangleFactory::toString() const {
    cout << "Rectangle Factory: Creates a Rectangle shape." << endl;
}
Shape* TextboxFactory::createShape(int length, int width, string colour, int posX, int posY, string text) const {
    TextboxFactory::toString();
    return new Textbox(length, width, colour, posX, posY, text);
}
void TextboxFactory::toString() const {
    cout << "Textbox Factory: Creates a Textbox shape." << endl;
}