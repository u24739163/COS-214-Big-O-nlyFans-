#include <iostream>
#include "Canvas.h"
#include "Shape.h"
#include "ShapeFactory.h"
#include "ExportCanvas.h"
#include "Caretaker.h"
#include "Memento.h"

int main() {
    std::cout << "=== COS214 Shape Drawing App Thorough Test ===\n" << std::endl;

    // Create canvas and factories
    Canvas canvas;
    SquareFactory squareFactory;
    RectangleFactory rectangleFactory;
    TextboxFactory textboxFactory;

    // Create shapes using factories
    Shape* square1 = squareFactory.createShape(5, 0, "blue", 10, 10);
    Shape* rectangle1 = rectangleFactory.createShape(10, 5, "red", 20, 20);
    Shape* textbox1 = textboxFactory.createShape(15, 10, "green", 30, 30, "Hello World");

    // Clone shapes
    Shape* square2 = square1->clone();
    Shape* rectangle2 = rectangle1->clone();
    Shape* textbox2 = textbox1->clone();

    // Add shapes to canvas
    canvas.addShape(square1);
    canvas.addShape(rectangle1);
    canvas.addShape(textbox1);

    std::cout << "\nCanvas after adding 3 shapes:" << std::endl;
    canvas.print();

    // Test edge case: add nullptr
    std::cout << "\nTesting addShape(nullptr):" << std::endl;
    canvas.addShape(nullptr);

    // Capture current state
    Caretaker caretaker;
    Memento* memento1 = canvas.captureCurrent();
    caretaker.addMemento(memento1);

    // Add more shapes
    canvas.addShape(square2);
    canvas.addShape(rectangle2);
    canvas.addShape(textbox2);

    std::cout << "\nCanvas after adding 3 more shapes:" << std::endl;
    canvas.print();

    // Capture new state
    Memento* memento2 = canvas.captureCurrent();
    caretaker.addMemento(memento2);

    // Undo to previous state (should show 3 shapes)
    std::cout << "\nUndo to previous state (should show 3 shapes):" << std::endl;
    canvas.undoAction(memento1);
    canvas.print();

    // Redo to latest state (should show 6 shapes)
    std::cout << "\nRedo to latest state (should show 6 shapes):" << std::endl;
    canvas.undoAction(memento2);
    canvas.print();

    // Test clear canvas
    std::cout << "\nClearing canvas (should be empty):" << std::endl;
    canvas.clearCanvas();
    canvas.print();

    // Test undo after clear (should restore 6 shapes)
    std::cout << "\nUndo after clear (should show 6 shapes):" << std::endl;
    canvas.undoAction(memento2);
    canvas.print();

    // Test multiple undos/redos with caretaker
    std::cout << "\nTesting multiple undos/redos:" << std::endl;
    canvas.undoAction(memento1);
    canvas.print();
    canvas.undoAction(memento2);
    canvas.print();

    // Export canvas
    std::cout << "\nTesting export (PNG and PDF):" << std::endl;
    PNGExporter pngExporter(&canvas);
    PDFExporter pdfExporter(&canvas);
    pngExporter.exportToFile();
    pdfExporter.exportToFile();

    // Clean up
    delete square1;
    delete rectangle1;
    delete textbox1;
    delete square2;
    delete rectangle2;
    delete textbox2;
    delete memento1;
    delete memento2;

    std::cout << "\n=== Thorough Testing Completed Successfully ===" << std::endl;
    return 0;
}