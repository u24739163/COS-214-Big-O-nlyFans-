#include "ChatRoom.h"

// CtrlCat class function definitions
void CtrlCat::registerUser(User* user) {
    users.push_back(user);
}

void CtrlCat::sendMessage(string message, User* fromUser) {
    for (User* user : users) {
        if (user->getName() != fromUser->getName()) {
            user->receive(message, fromUser, this);
        }
    }
    saveMessage(message, fromUser);
}

void CtrlCat::saveMessage(string message, User* fromUser) {
    string message = fromUser->getName() + ": " + message;
    chatHistory.push_back(message);
}

void CtrlCat::removeUser(User* user) {

}

// Dogorithm class function definitions
void Dogorithm::registerUser(User* user) {
    
}

void Dogorithm::sendMessage(string message, User* fromUser) {

}

void Dogorithm::saveMessage(string message, User* fromUser) {
    
}

void Dogorithm::removeUser(User* user) {

}