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
    cout << "\n=== CHAT ROOM MENU ===" << endl;
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

    Michael user1("michaelsRISEup");
    Mulondi user2("MulondiBoring");
    Mundael user3("Mundael");
    Mulondi user4("MulondiAltAccount");
    Michael user5("Michael2Point0");
    
    cout << "Created 5 users" << endl;
    
    CtrlCat* catRoom = new CtrlCat();
    Dogorithm* dogRoom = new Dogorithm();
    cout << "Created CtrlCat and Dogorithm" << endl;
    
    Caretaker caretaker;
    bool hasMemento = false;
    
    pressEnterToContinue();

    int choice;
    do {
        displayMenu();
        cin >> choice;
        clearInputBuffer();

        switch(choice) {
            case 1: {
                cout << "\n=== REGISTER USER TO CTRLCAT ROOM ===" << endl;
                cout << "The ChatRoom will manage this registration" << endl;
                displayUsers(user1, user2, user3, user4, user5);
                cout << "Select user (1-5): ";
                int userChoice;
                cin >> userChoice;
                clearInputBuffer();
                
                Users* selectedUser = selectUser(userChoice, user1, user2, user3, user4, user5);
                if (selectedUser) {
                    cout << "\nChatRoom processing registration" << endl;
                    catRoom->registerUser(*selectedUser);
                    cout << "ChatRoom completed registration" << endl;
                } else {
                    cout << "LEARN TO READ" << endl;
                }
                pressEnterToContinue();
                break;
            }
            
            case 2: {
                cout << "\n=== REGISTER USER TO DOGORITHM ROOM ===" << endl;
                cout << "The ChatRoom will manage this registration" << endl;
                displayUsers(user1, user2, user3, user4, user5);
                cout << "Select user (1-5): ";
                int userChoice;
                cin >> userChoice;
                clearInputBuffer();
                
                Users* selectedUser = selectUser(userChoice, user1, user2, user3, user4, user5);
                if (selectedUser) {
                    cout << "\nChatRoom processing registration..." << endl;
                    dogRoom->registerUser(*selectedUser);
                    cout << "ChatRoom completed registration process!" << endl;
                } else {
                    cout << "LEARN TO READ" << endl;
                }
                pressEnterToContinue();
                break;
            }
            
            case 3: {
                cout << "\n=== SEND MESSAGE IN CTRLCAT ROOM ===" << endl;
                cout << "Mediator magic watch it go." << endl;
                displayUsers(user1, user2, user3, user4, user5);
                cout << "Select sender (1-5): ";
                int userChoice;
                cin >> userChoice;
                clearInputBuffer();
                
                Users* selectedUser = selectUser(userChoice, user1, user2, user3, user4, user5);
                if (selectedUser) {
                    cout << "Enter your cat-chat related message: ";
                    string message;
                    getline(cin, message);
                    
                    selectedUser->send(message, catRoom);
                    cout << "--- Mediator Magic is over. thx for the message ---" << endl;
                } else {
                    cout << "LEARN TO READ" << endl;
                }
                pressEnterToContinue();
                break;
            }
            
            case 4: {
                cout << "\n=== SEND MESSAGE IN DOGORITHM ROOM ===" << endl;
                cout << "Mediator magic watch it go." << endl;
                displayUsers(user1, user2, user3, user4, user5);
                cout << "Select sender (1-5): ";
                int userChoice;
                cin >> userChoice;
                clearInputBuffer();
                
                Users* selectedUser = selectUser(userChoice, user1, user2, user3, user4, user5);
                if (selectedUser) {
                    cout << "Enter your dawg related message: ";
                    string message;
                    getline(cin, message);
                    
                    selectedUser->send(message, dogRoom);
                    cout << "--- Mediator Magic is over. Thanks for the message ---" << endl;
                } else {
                    cout << "LEARN TO READ" << endl;
                }
                pressEnterToContinue();
                break;
            }
            
            case 5: {
                cout << "\n=== CTRLCAT ROOM USERS (showing iterator) ===" << endl;
                catRoom->printUsers();
                pressEnterToContinue();
                break;
            }
            
            case 6: {
                cout << "\n=== DOGORITHM ROOM USERS (showing iterator) ===" << endl;
                dogRoom->printUsers();
                pressEnterToContinue();
                break;
            }
            
            case 7: {
                cout << "\n=== CTRLCAT CHAT HISTORY (showing iterator) ===" << endl;
                catRoom->printChatHistory();
                pressEnterToContinue();
                break;
            }
            
            case 8: {
                cout << "\n=== DOGORITHM CHAT HISTORY (showing iterator) ===" << endl;
                dogRoom->printChatHistory();
                pressEnterToContinue();
                break;
            }
            
            case 9: {
                cout << "\n=== SAVE CHAT ===" << endl;
                cout << "Which chatroom is your fav <3 ?" << endl;
                cout << "1. CtrlCat" << endl;
                cout << "2. Dogorithm" << endl;
                cout << "Select room (1-2): ";
                int roomChoice;
                cin >> roomChoice;
                clearInputBuffer();
                
                if (roomChoice == 1) {
                    cout << "Saving CtrlCat" << endl;
                    Memento* memento = catRoom->captureCurrent();
                    caretaker.addMemento(memento);
                    hasMemento = true;
                    cout << "CtrlCat would be thankful, since you saved it." << endl;
                } else if (roomChoice == 2) {
                    cout << "Saving Dogorithm" << endl;
                    Memento* memento = dogRoom->captureCurrent();
                    caretaker.addMemento(memento);
                    hasMemento = true;
                    cout << "Dogorigthm would be proud, since you saved it." << endl;
                } else {
                    cout << "Learn to read is rude. but pls just read like what" << endl;
                }
                pressEnterToContinue();
                break;
            }
            
            case 10: {
                cout << "\n=== RESTORE HISTORY ===" << endl;
                if (!hasMemento) {
                    cout << "Save the history first, then you can do this." << endl;
                } else {
                    cout << "Which room do you want to restore?" << endl;
                    cout << "1. CtrlCat room" << endl;
                    cout << "2. Dogorithm room" << endl;
                    cout << "Select room (1-2): ";
                    int roomChoice;
                    cin >> roomChoice;
                    clearInputBuffer();
                    
                    if (roomChoice == 1) {
                        cout << "Restoring CtrlCat's history" << endl;
                        catRoom->undoAction(caretaker.getMemento());
                        cout << "History restored" << endl;
                    } else if (roomChoice == 2) {
                        cout << "Restoring Dogorithm's history" << endl;
                        dogRoom->undoAction(caretaker.getMemento());
                        cout << "History restored" << endl;
                    } else {
                        cout << "thats not a room number bro." << endl;
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
                        cout << "ChatRoom is processing user removal from CtrlCat..." << endl;
                        catRoom->removeUser(*selectedUser);
                    } else if (roomChoice == 2) {
                        cout << "ChatRoom is processing user removal from Dogorithm..." << endl;
                        dogRoom->removeUser(*selectedUser);
                    } else {
                        cout << "dude please stop doing that." << endl;
                    }
                } else {
                    cout << "invaldi number brooo" << endl;
                }
                pressEnterToContinue();
                break;
            }
            
            case 0: {
                cout << "thats it. yippee demo over" << endl;
                break;
            }
            
            default: {
                cout << "bro please bro, take this serious" << endl;
                pressEnterToContinue();
                break;
            }
        }
    } while (choice != 0);

    delete catRoom;
    delete dogRoom;

    return 0;
}