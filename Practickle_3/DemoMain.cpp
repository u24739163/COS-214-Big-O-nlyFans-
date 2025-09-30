#include "ChatRoom.h"
#include "Caretaker.h"
#include <iostream>
#include <string>
#include <limits>

using namespace std;

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void pressEnterToContinue() {
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}

void displayMenu() {
    cout << "\n=== CHAT ROOM SYSTEM MENU ===" << endl;
    cout << "1. Register user to CtrlCat room" << endl;
    cout << "2. Register user to Dogorithm room" << endl;
    cout << "3. Send message in CtrlCat room" << endl;
    cout << "4. Send message in Dogorithm room" << endl;
    cout << "5. View CtrlCat users" << endl;
    cout << "6. View Dogorithm users" << endl;
    cout << "7. View CtrlCat chat history" << endl;
    cout << "8. View Dogorithm chat history" << endl;
    cout << "9. Save chat state (Memento)" << endl;
    cout << "10. Restore chat state (Memento)" << endl;
    cout << "11. Remove user from room" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: ";
}

void displayUsers(Michael& user1, Mulondi& user2, Mundael& user3, Mulondi& user4, Michael& user5) {
    cout << "\nAvailable Users:" << endl;
    cout << "1. " << user1.getName() << " (Michael)" << endl;
    cout << "2. " << user2.getName() << " (Mulondi)" << endl;
    cout << "3. " << user3.getName() << " (Mundael)" << endl;
    cout << "4. " << user4.getName() << " (Mulondi)" << endl;
    cout << "5. " << user5.getName() << " (Michael)" << endl;
}

Users* selectUser(int choice, Michael& user1, Mulondi& user2, Mundael& user3, Mulondi& user4, Michael& user5) {
    switch(choice) {
        case 1: return &user1;
        case 2: return &user2;
        case 3: return &user3;
        case 4: return &user4;
        case 5: return &user5;
        default: return nullptr;
    }
}

int main() 
{
    cout << "=== INTERACTIVE CHAT ROOM SYSTEM DEMO ===" << endl;
    cout << "Demonstrating Mediator, Iterator, Command, and Memento patterns" << endl;
    cout << "This demo shows how the Mediator pattern coordinates communication!" << endl << endl;

    // ============================================
    // INITIALIZE SYSTEM
    // ============================================
    cout << "Initializing Chat Room System..." << endl;
    
    // Create users
    Michael user1("Alice");
    Mulondi user2("Bob");
    Mundael user3("Charlie");
    Mulondi user4("David");
    Michael user5("Eve");
    
    cout << "Created 5 users with different types!" << endl;
    
    // Create chat rooms (Mediator Pattern)
    CtrlCat* catRoom = new CtrlCat();
    Dogorithm* dogRoom = new Dogorithm();
    cout << "Created CtrlCat and Dogorithm chat rooms (Mediators)" << endl;
    
    // Create caretaker for memento pattern
    Caretaker caretaker;
    bool hasMemento = false;
    
    pressEnterToContinue();

    // ============================================
    // INTERACTIVE MENU LOOP
    // ============================================
    int choice;
    do {
        displayMenu();
        cin >> choice;
        clearInputBuffer();

        switch(choice) {
            case 1: {
                cout << "\n=== REGISTER USER TO CTRLCAT ROOM ===" << endl;
                cout << "The Mediator (CtrlCat) will manage this registration!" << endl;
                displayUsers(user1, user2, user3, user4, user5);
                cout << "Select user (1-5): ";
                int userChoice;
                cin >> userChoice;
                clearInputBuffer();
                
                Users* selectedUser = selectUser(userChoice, user1, user2, user3, user4, user5);
                if (selectedUser) {
                    cout << "\nMediator processing registration..." << endl;
                    catRoom->registerUser(*selectedUser);
                    cout << "Mediator completed registration process!" << endl;
                } else {
                    cout << "Invalid user selection!" << endl;
                }
                pressEnterToContinue();
                break;
            }
            
            case 2: {
                cout << "\n=== REGISTER USER TO DOGORITHM ROOM ===" << endl;
                cout << "The Mediator (Dogorithm) will manage this registration!" << endl;
                displayUsers(user1, user2, user3, user4, user5);
                cout << "Select user (1-5): ";
                int userChoice;
                cin >> userChoice;
                clearInputBuffer();
                
                Users* selectedUser = selectUser(userChoice, user1, user2, user3, user4, user5);
                if (selectedUser) {
                    cout << "\nMediator processing registration..." << endl;
                    dogRoom->registerUser(*selectedUser);
                    cout << "Mediator completed registration process!" << endl;
                } else {
                    cout << "Invalid user selection!" << endl;
                }
                pressEnterToContinue();
                break;
            }
            
            case 3: {
                cout << "\n=== SEND MESSAGE IN CTRLCAT ROOM ===" << endl;
                cout << "Watch the Mediator coordinate message delivery!" << endl;
                displayUsers(user1, user2, user3, user4, user5);
                cout << "Select sender (1-5): ";
                int userChoice;
                cin >> userChoice;
                clearInputBuffer();
                
                Users* selectedUser = selectUser(userChoice, user1, user2, user3, user4, user5);
                if (selectedUser) {
                    cout << "Enter your message: ";
                    string message;
                    getline(cin, message);
                    
                    cout << "\n--- MEDIATOR PATTERN IN ACTION ---" << endl;
                    cout << "1. User sends message via Command pattern" << endl;
                    cout << "2. Mediator receives and processes message" << endl;
                    cout << "3. Mediator distributes to all other users" << endl;
                    cout << "4. Mediator saves message to history" << endl;
                    cout << "--- EXECUTING ---" << endl;
                    
                    selectedUser->send(message, catRoom);
                    cout << "--- MEDIATOR COMPLETED MESSAGE COORDINATION ---" << endl;
                } else {
                    cout << "Invalid user selection!" << endl;
                }
                pressEnterToContinue();
                break;
            }
            
            case 4: {
                cout << "\n=== SEND MESSAGE IN DOGORITHM ROOM ===" << endl;
                cout << "Watch the Mediator coordinate message delivery!" << endl;
                displayUsers(user1, user2, user3, user4, user5);
                cout << "Select sender (1-5): ";
                int userChoice;
                cin >> userChoice;
                clearInputBuffer();
                
                Users* selectedUser = selectUser(userChoice, user1, user2, user3, user4, user5);
                if (selectedUser) {
                    cout << "Enter your message: ";
                    string message;
                    getline(cin, message);
                    
                    cout << "\n--- MEDIATOR PATTERN IN ACTION ---" << endl;
                    cout << "1. User sends message via Command pattern" << endl;
                    cout << "2. Mediator receives and processes message" << endl;
                    cout << "3. Mediator distributes to all other users" << endl;
                    cout << "4. Mediator saves message to history" << endl;
                    cout << "--- EXECUTING ---" << endl;
                    
                    selectedUser->send(message, dogRoom);
                    cout << "--- MEDIATOR COMPLETED MESSAGE COORDINATION ---" << endl;
                } else {
                    cout << "Invalid user selection!" << endl;
                }
                pressEnterToContinue();
                break;
            }
            
            case 5: {
                cout << "\n=== CTRLCAT ROOM USERS (Iterator Pattern) ===" << endl;
                cout << "Using Iterator pattern to traverse user list..." << endl;
                catRoom->printUsers();
                pressEnterToContinue();
                break;
            }
            
            case 6: {
                cout << "\n=== DOGORITHM ROOM USERS (Iterator Pattern) ===" << endl;
                cout << "Using Iterator pattern to traverse user list..." << endl;
                dogRoom->printUsers();
                pressEnterToContinue();
                break;
            }
            
            case 7: {
                cout << "\n=== CTRLCAT CHAT HISTORY (Iterator Pattern) ===" << endl;
                cout << "Using Iterator pattern to traverse message history..." << endl;
                catRoom->printChatHistory();
                pressEnterToContinue();
                break;
            }
            
            case 8: {
                cout << "\n=== DOGORITHM CHAT HISTORY (Iterator Pattern) ===" << endl;
                cout << "Using Iterator pattern to traverse message history..." << endl;
                dogRoom->printChatHistory();
                pressEnterToContinue();
                break;
            }
            
            case 9: {
                cout << "\n=== SAVE CHAT STATE (Memento Pattern) ===" << endl;
                cout << "Which room's state do you want to save?" << endl;
                cout << "1. CtrlCat room" << endl;
                cout << "2. Dogorithm room" << endl;
                cout << "Select room (1-2): ";
                int roomChoice;
                cin >> roomChoice;
                clearInputBuffer();
                
                if (roomChoice == 1) {
                    cout << "Capturing CtrlCat chat history state..." << endl;
                    Memento* memento = catRoom->captureCurrent();
                    caretaker.addMemento(memento);
                    hasMemento = true;
                    cout << "State saved successfully!" << endl;
                } else if (roomChoice == 2) {
                    cout << "Capturing Dogorithm chat history state..." << endl;
                    Memento* memento = dogRoom->captureCurrent();
                    caretaker.addMemento(memento);
                    hasMemento = true;
                    cout << "State saved successfully!" << endl;
                } else {
                    cout << "Invalid room selection!" << endl;
                }
                pressEnterToContinue();
                break;
            }
            
            case 10: {
                cout << "\n=== RESTORE CHAT STATE (Memento Pattern) ===" << endl;
                if (!hasMemento) {
                    cout << "No saved state available! Please save a state first (option 9)." << endl;
                } else {
                    cout << "Which room do you want to restore?" << endl;
                    cout << "1. CtrlCat room" << endl;
                    cout << "2. Dogorithm room" << endl;
                    cout << "Select room (1-2): ";
                    int roomChoice;
                    cin >> roomChoice;
                    clearInputBuffer();
                    
                    if (roomChoice == 1) {
                        cout << "Restoring CtrlCat chat history..." << endl;
                        catRoom->undoAction(caretaker.getMemento());
                        cout << "State restored successfully!" << endl;
                    } else if (roomChoice == 2) {
                        cout << "Restoring Dogorithm chat history..." << endl;
                        dogRoom->undoAction(caretaker.getMemento());
                        cout << "State restored successfully!" << endl;
                    } else {
                        cout << "Invalid room selection!" << endl;
                    }
                }
                pressEnterToContinue();
                break;
            }
            
            case 11: {
                cout << "\n=== REMOVE USER FROM ROOM ===" << endl;
                cout << "Which room?" << endl;
                cout << "1. CtrlCat room" << endl;
                cout << "2. Dogorithm room" << endl;
                cout << "Select room (1-2): ";
                int roomChoice;
                cin >> roomChoice;
                clearInputBuffer();
                
                displayUsers(user1, user2, user3, user4, user5);
                cout << "Select user to remove (1-5): ";
                int userChoice;
                cin >> userChoice;
                clearInputBuffer();
                
                Users* selectedUser = selectUser(userChoice, user1, user2, user3, user4, user5);
                if (selectedUser) {
                    if (roomChoice == 1) {
                        cout << "Mediator processing user removal from CtrlCat..." << endl;
                        catRoom->removeUser(*selectedUser);
                    } else if (roomChoice == 2) {
                        cout << "Mediator processing user removal from Dogorithm..." << endl;
                        dogRoom->removeUser(*selectedUser);
                    } else {
                        cout << "Invalid room selection!" << endl;
                    }
                } else {
                    cout << "Invalid user selection!" << endl;
                }
                pressEnterToContinue();
                break;
            }
            
            case 0: {
                cout << "\n=== EXITING CHAT ROOM SYSTEM ===" << endl;
                cout << "Thank you for exploring our design patterns!" << endl;
                break;
            }
            
            default: {
                cout << "Invalid choice! Please select 0-11." << endl;
                pressEnterToContinue();
                break;
            }
        }
    } while (choice != 0);

    // ============================================
    // FINAL SUMMARY
    // ============================================
    cout << "\n=== DESIGN PATTERNS DEMONSTRATED ===" << endl;
    cout << "✓ MEDIATOR PATTERN: ChatRoom objects coordinated all user interactions" << endl;
    cout << "✓ ITERATOR PATTERN: VectorFather/Stepper traversed collections safely" << endl;
    cout << "✓ COMMAND PATTERN: SendMessage/LogMessage commands encapsulated actions" << endl;
    cout << "✓ MEMENTO PATTERN: Caretaker managed chat history state save/restore" << endl;
    cout << "\nThe Mediator pattern was central to all operations, ensuring users" << endl;
    cout << "never communicated directly but always through the chat room mediator!" << endl;

    // ============================================
    // CLEANUP
    // ============================================
    delete catRoom;
    delete dogRoom;
    cout << "\nResources cleaned up. Goodbye!" << endl;

    return 0;
}