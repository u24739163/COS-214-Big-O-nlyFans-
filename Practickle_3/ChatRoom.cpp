#include "ChatRoom.h"

void ChatRoom::registerUser(Users user) {
    Stepper<Users>* stepper = users.createStepper();
    Users currentUser = stepper->first();
    while (stepper->hasNext()) {
        if (currentUser == user) {
            cout << "User " << user.getName() << " is already registered in this chat room." << endl;
            delete stepper;
            return;
        }
        stepper->next();
        currentUser = stepper->current();
    }
    users.addItem(user);
}

void ChatRoom::sendMessage(string message, Users fromUser) {
    Stepper<Users>* stepper = users.createStepper();
    Users currentUser = stepper->first();
    while (stepper->hasNext()) {
        if (currentUser != fromUser) {
            currentUser.receive(message, fromUser, *this);
        }
        stepper->next();
        currentUser = stepper->current();
    }
    saveMessage(message, fromUser);
}

void ChatRoom::saveMessage(string message, Users fromUser) {
    string formattedMessage = fromUser.getName() + ": " + message;
    chatHistory.addItem(formattedMessage);
}

void ChatRoom::removeUser(Users user) {
    Stepper<Users>* stepper = users.createStepper();
        while (stepper->hasNext()) {
            if (stepper->current() == user) {
                users.erase(users.begin() + stepper->getCurrentIndex());
                break;
            }
            stepper->next();
        }
        delete stepper;
}


void CtrlCat::registerUser(Users user) {
    ChatRoom::registerUser(user);
    cout << "CtrlCat: " << user.getName() << " has joined the kitten kontrol klub (kkk)." << endl;
}

void CtrlCat::sendMessage(string message, Users fromUser) {
    cout << "CtrlCat: " << fromUser.getName() << " purrs: " << message << endl;
    ChatRoom::sendMessage(message, fromUser);
}

void CtrlCat::saveMessage(string message, Users fromUser) {
    string formattedMessage = "CtrlCat: " + fromUser.getName() + ": " + message;
    chatHistory.addItem(formattedMessage);
}

void CtrlCat::removeUser(Users user) {
    ChatRoom::removeUser(user);
    cout << "CtrlCat: " << user.getName() << " has ran out of lives." << endl;
}


void Dogorithm::registerUser(Users user) {
    ChatRoom::registerUser(user);
    cout << "Dogorithm: " << user.getName() << " was fed a bone." << endl;
}

void Dogorithm::sendMessage(string message, Users fromUser) {
    cout << "Dogorithm: " << fromUser.getName() << " barks: " << message << endl;
    ChatRoom::sendMessage(message, fromUser);
}

void Dogorithm::saveMessage(string message, Users fromUser) {
    string formattedMessage = "Dogorithm: " + fromUser.getName() + ": " + message;
    chatHistory.addItem(formattedMessage);
}

void Dogorithm::removeUser(Users user) {
    ChatRoom::removeUser(user);
    cout << "Dogorithm: " << user.getName() << " ate chocolate." << endl;
}