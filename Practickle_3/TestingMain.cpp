#include "ChatRoom.h"
#include "Caretaker.h"
#include <iostream>

int main() 
{
    cout << "1. CREATING USERS" << endl;
    Michael user1("Alice");
    Mulondi user2("Bob");
    Mundael user3("Charlie");
    Mulondi user4("David");
    Michael user5("Eve");
    
    cout << "Created users: " << user1.getName() << " (Michael), " 
         << user2.getName() << " (Mulondi), " << user3.getName() << " (Mundael), "
         << user4.getName() << " (Mulondi), " << user5.getName() << " (Michael)" << endl << endl;

    cout << "2. CREATING CHAT ROOMS (Mediator Pattern)" << endl;
    cout << "=========================================" << endl;
    CtrlCat* catRoom = new CtrlCat();
    Dogorithm* dogRoom = new Dogorithm();
    cout << "Created CtrlCat and Dogorithm chat rooms" << endl << endl;

    cout << "3. REGISTERING USERS (Iterator Pattern in action)" << endl;
    cout << "================================================" << endl;
    cout << "Registering users to CtrlCat room:" << endl;
    catRoom->registerUser(user1);
    catRoom->registerUser(user2);
    catRoom->registerUser(user3);
    catRoom->registerUser(user4);
    
    cout << endl << "Registering users to Dogorithm room:" << endl;
    dogRoom->registerUser(user1);
    dogRoom->registerUser(user3);
    dogRoom->registerUser(user5);
    
    cout << endl << "Attempting to register duplicate user:" << endl;
    catRoom->registerUser(user1); // Should show duplicate message
    cout << endl;

    // ============================================
    // 4. DISPLAY CURRENT USERS (Iterator Pattern)
    // ============================================
    cout << "4. CURRENT USERS IN ROOMS (Iterator Pattern)" << endl;
    cout << "=============================================" << endl;
    cout << "CtrlCat room users:" << endl;
    catRoom->printUsers();
    cout << endl << "Dogorithm room users:" << endl;
    dogRoom->printUsers();
    cout << endl;

    // ============================================
    // 5. SEND MESSAGES (Command Pattern)
    // ============================================
    cout << "5. SENDING MESSAGES (Command Pattern)" << endl;
    cout << "====================================" << endl;
    cout << "Messages in CtrlCat room:" << endl;
    user1.send("Hello everyone! Welcome to the kitten klub!", catRoom);
    user2.send("Hi Alice! Meow meow!", catRoom);
    user3.send("Hey folks! This is pawsome!", catRoom);
    user4.send("Purr-fect chat room!", catRoom);
    
    cout << endl << "Messages in Dogorithm room:" << endl;
    user1.send("Woof woof! Dogs rule!", dogRoom);
    user3.send("Bark bark! Let's fetch some data!", dogRoom);
    user5.send("Arf! This algorithm is ruff!", dogRoom);
    cout << endl;

    // ============================================
    // 6. MEMENTO PATTERN - SAVE STATE
    // ============================================
    cout << "6. MEMENTO PATTERN - SAVING CHAT HISTORY STATE" << endl;
    cout << "===============================================" << endl;
    Caretaker caretaker;
    cout << "Capturing current CtrlCat chat history..." << endl;
    Memento* savedState = catRoom->captureCurrent();
    caretaker.addMemento(savedState);
    cout << "State saved to caretaker!" << endl << endl;

    // ============================================
    // 7. MORE MESSAGES AFTER SAVE
    // ============================================
    cout << "7. ADDING MORE MESSAGES AFTER SAVE" << endl;
    cout << "==================================" << endl;
    user2.send("This message will be lost after undo!", catRoom);
    user4.send("So will this one!", catRoom);
    user1.send("And this temporary message too!", catRoom);
    cout << endl;

    // ============================================
    // 8. DISPLAY CURRENT CHAT HISTORY
    // ============================================
    cout << "8. CURRENT CHAT HISTORY (Before Undo)" << endl;
    cout << "=====================================" << endl;
    cout << "CtrlCat chat history:" << endl;
    catRoom->printChatHistory();
    cout << endl << "Dogorithm chat history:" << endl;
    dogRoom->printChatHistory();
    cout << endl;

    // ============================================
    // 9. USER MANAGEMENT - ADD/REMOVE
    // ============================================
    cout << "9. USER MANAGEMENT - ADDING AND REMOVING USERS" << endl;
    cout << "===============================================" << endl;
    cout << "Adding Bob to Dogorithm room:" << endl;
    dogRoom->registerUser(user2);
    
    cout << endl << "Bob sends a message in Dogorithm:" << endl;
    user2.send("I don't like dogs much...", dogRoom);
    
    cout << endl << "Removing Bob from Dogorithm room:" << endl;
    dogRoom->removeUser(user2);
    
    cout << endl << "Updated Dogorithm users:" << endl;
    dogRoom->printUsers();
    cout << endl;

    // ============================================
    // 10. MEMENTO PATTERN - RESTORE STATE
    // ============================================
    cout << "10. MEMENTO PATTERN - RESTORING SAVED STATE" << endl;
    cout << "============================================" << endl;
    cout << "Restoring CtrlCat chat history to saved state..." << endl;
    catRoom->undoAction(caretaker.getMemento());
    cout << "State restored!" << endl << endl;

    // ============================================
    // 11. DISPLAY RESTORED CHAT HISTORY
    // ============================================
    cout << "11. CHAT HISTORY AFTER RESTORATION" << endl;
    cout << "==================================" << endl;
    cout << "CtrlCat chat history (after undo):" << endl;
    catRoom->printChatHistory();
    cout << endl;

    // ============================================
    // 12. ITERATOR PATTERN DEMO
    // ============================================
    cout << "12. ITERATOR PATTERN DEMONSTRATION" << endl;
    cout << "==================================" << endl;
    cout << "Creating a custom VectorFather container:" << endl;
    VectorFather<string> stringContainer;
    stringContainer.addItem("First item");
    stringContainer.addItem("Second item");
    stringContainer.addItem("Third item");
    
    cout << "Iterating through container using Stepper:" << endl;
    Stepper<string>* stepper = stringContainer.createStepper();
    stepper->first();
    int count = 1;
    while (stepper->hasNext()) {
        cout << "Item " << count << ": " << stepper->current() << endl;
        stepper->next();
        count++;
    }
    delete stepper;
    cout << endl;

    // ============================================
    // 13. FINAL STATE SUMMARY
    // ============================================
    cout << "13. FINAL SYSTEM STATE SUMMARY" << endl;
    cout << "==============================" << endl;
    cout << "CtrlCat room final users:" << endl;
    catRoom->printUsers();
    cout << endl << "Dogorithm room final users:" << endl;
    dogRoom->printUsers();
    cout << endl;
    
    cout << "Final chat histories:" << endl;
    cout << "CtrlCat:" << endl;
    catRoom->printChatHistory();
    cout << endl << "Dogorithm:" << endl;
    dogRoom->printChatHistory();
    cout << endl;

    // ============================================
    // 14. PATTERN SUMMARY
    // ============================================
    cout << "14. DESIGN PATTERNS DEMONSTRATED" << endl;
    cout << "================================" << endl;
    cout << "✓ MEDIATOR PATTERN: ChatRoom coordinates communication between Users" << endl;
    cout << "✓ ITERATOR PATTERN: VectorFather/Stepper for traversing collections" << endl;
    cout << "✓ COMMAND PATTERN: SendMessageCommand/LogMessageCommand encapsulate actions" << endl;
    cout << "✓ MEMENTO PATTERN: Save/restore chat history states via Caretaker" << endl;
    cout << endl;

    // ============================================
    // 15. CLEANUP
    // ============================================
    cout << "15. CLEANING UP RESOURCES" << endl;
    cout << "=========================" << endl;
    delete catRoom;
    delete dogRoom;
    cout << "All resources cleaned up successfully!" << endl;
    cout << endl << "=== DEMO COMPLETE ===" << endl;

    return 0;
}