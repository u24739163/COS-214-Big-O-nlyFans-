#include "Shape.h"

Rectangle::Rectangle(int length, int width, string colour, int posX, int posY) {
    this->length = length;
    this->width = width;
    this->colour = colour;
    this->position_X = posX;
    this->position_Y = posY;
}

Square::Square(int length, string colour, int posX, int posY) {
    this->length = length;
    this->width = length;
    this->colour = colour;
    this->position_X = posX;
    this->position_Y = posY;
}

Textbox::Textbox(int length, int width, string colour, int posX, int posY, string text) {
    this->length = length;
    this->width = width;
    this->colour = colour;
    this->position_X = posX;
    this->position_Y = posY;
    this->text = text;
}

Square::Square(const Square& other) : Shape(other) {
    this->length = other.length;
    this->width = other.width;
    this->colour = other.colour;
    this->position_X = other.position_X;
    this->position_Y = other.position_Y;
}
Rectangle::Rectangle(const Rectangle& other) : Shape(other) {
    this->length = other.length;
    this->width = other.width;
    this->colour = other.colour;
    this->position_X = other.position_X;
    this->position_Y = other.position_Y;
}
Textbox::Textbox(const Textbox& other) : Shape(other) {
    this->length = other.length;
    this->width = other.width;
    this->colour = other.colour;
    this->position_X = other.position_X;
    this->position_Y = other.position_Y;
    this->text = other.text;
}

void Rectangle::print() const {
    std::cout << "Rectangle: Length = " << length << ", Width = " << width 
              << ", Colour = " << colour << ", Position = (" << position_X 
              << ", " << position_Y << ")" << std::endl;
}
void Square::print() const {
    std::cout << "Square: Length = " << length << ", Colour = " << colour 
              << ", Position = (" << position_X << ", " << position_Y << ")" << std::endl;
}
void Textbox::print() const {
    std::cout << "Textbox: Length = " << length << ", Width = " << width 
              << ", Colour = " << colour << ", Position = (" << position_X 
              << ", " << position_Y << "), Text = \"" << text << "\"" << std::endl;
}

Shape* Square::clone() const{
    return new Square(*this);
};

Shape* Rectangle::clone() const{
    return new Rectangle(*this);
};

Shape* Textbox::clone() const{
    return new Textbox(*this);
};