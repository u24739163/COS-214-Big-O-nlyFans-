#include "StepFather.h"
#include <iostream>
#include <string>

int main() {
    // Create a VectorFather to manage integers
    VectorFather<int> intContainer;
    
    // Add some items
    intContainer.addItem(10);
    intContainer.addItem(20);
    intContainer.addItem(30);
    intContainer.addItem(40);
    intContainer.addItem(50);
    
    // Create an iterator (stepper)
    Stepper<int>* intStepper = intContainer.createStepper();
    
    cout << "Iterating through integers:" << endl;
    intStepper->first(); // Start from beginning
    
    while (intStepper->hasNext()) {
        cout << "Current: " << intStepper->current() << endl;
        intStepper->next();
    }
    
    delete intStepper;
    
    cout << "\n" << endl;
    
    // Example with strings
    VectorFather<string> stringContainer;
    stringContainer.addItem("Hello");
    stringContainer.addItem("World");
    stringContainer.addItem("Iterator");
    stringContainer.addItem("Pattern");
    
    Stepper<string>* stringStepper = stringContainer.createStepper();
    
    cout << "Iterating through strings:" << endl;
    stringStepper->first();
    
    while (stringStepper->hasNext()) {
        cout << "Current: " << stringStepper->current() << endl;
        stringStepper->next();
    }
    
    delete stringStepper;
    
    // Test empty container
    cout << "\nTesting empty container:" << endl;
    cout << "Is container empty? " << (stringContainer.isEmpty() ? "No" : "Yes") << endl;
    
    // Remove all items
    while (!stringContainer.isEmpty()) {
        stringContainer.removeItem();
    }
    
    cout << "After removing all items, is container empty? " << (stringContainer.isEmpty() ? "Yes" : "No") << endl;
    
    return 0;
}