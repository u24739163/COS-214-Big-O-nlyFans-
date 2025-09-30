#include "ChatRoom.h"
#include "Memento.h"

bool ChatRoom::isUserRegistered(Users user) {
    Stepper<Users>* stepper = users.createStepper();
    stepper->first();
    while (stepper->hasNext()) {
        if (stepper->current() == user) {
            delete stepper;
            return true;
        }
        stepper->next();
    }
    delete stepper;
    return false;
}

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
    delete stepper;
}

void ChatRoom::sendMessage(string message, Users fromUser) {
    if (!isUserRegistered(fromUser)) {
        cout << "User " << fromUser.getName() << " is not registered in this chat room and cannot send messages." << endl;
        return;
    }
    
    Stepper<Users>* stepper = users.createStepper();
    Users currentUser = stepper->first();
    while (stepper->hasNext()) {
        if (currentUser != fromUser) {
            currentUser.receive(message, fromUser, this);
        }
        stepper->next();
        currentUser = stepper->current();
    }
    delete stepper;
}

void ChatRoom::saveMessage(string message, Users fromUser) {

    if (!isUserRegistered(fromUser)) {
        cout << "User " << fromUser.getName() << " is not registered in this chat room and cannot save messages." << endl;
        return;
    }
    
    string formattedMessage = fromUser.getName() + ": " + message;
    chatHistory.addItem(formattedMessage);
}

void ChatRoom::removeUser(Users user) {
    if (!isUserRegistered(user)) {
        cout << "User " << user.getName() << " is not registered in this chat room and cannot be removed." << endl;
        return;
    }
    
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

void ChatRoom::printChatHistory() {
    cout << "Chat history size: " << chatHistory.getVector()->size() << endl; 
    Stepper<string>* stepper = chatHistory.createStepper();
    stepper->first();
    while (stepper->hasNext()) {
        cout << " " << stepper->current() << endl;
        stepper->next();
    }
    delete stepper;
}

void ChatRoom::printUsers() {
    Stepper<Users>* stepper = users.createStepper();
    stepper->first();
    while (stepper->hasNext()) {
        cout << " " << stepper->current().getName() << endl;
        stepper->next();
    }
    delete stepper;
}

void CtrlCat::registerUser(Users user) {
    ChatRoom::registerUser(user);
    if (isUserRegistered(user)) {
        cout << "CtrlCat: " << user.getName() << " has joined the Kitten Kontrol Klub." << endl;
    }
}

void CtrlCat::sendMessage(string message, Users fromUser) {
    if (!isUserRegistered(fromUser)) {
        cout << "CtrlCat: " << fromUser.getName() << " is not registered in this chat room and cannot send messages." << endl;
        return;
    }
    
    cout << "CtrlCat: " << fromUser.getName() << " purrs: " << message << endl;
    ChatRoom::sendMessage(message, fromUser);
}

void CtrlCat::saveMessage(string message, Users fromUser) {
    if (!isUserRegistered(fromUser)) {
        cout << "CtrlCat: " << fromUser.getName() << " is not registered in this chat room and cannot save messages." << endl;
        return;
    }
    
    string formattedMessage = "CtrlCat: " + fromUser.getName() + ": " + message;
    chatHistory.addItem(formattedMessage);
}

void CtrlCat::removeUser(Users user) {
    if (!isUserRegistered(user)) {
        cout << "CtrlCat: " << user.getName() << " is not registered in this chat room and cannot be removed." << endl;
        return;
    }
    
    ChatRoom::removeUser(user);
    cout << "CtrlCat: " << user.getName() << " has ran out of lives." << endl;
}

void Dogorithm::registerUser(Users user) {
    ChatRoom::registerUser(user);
    if (isUserRegistered(user)) {
        cout << "Dogorithm: " << user.getName() << " was fed a bone." << endl;
    }
}

void Dogorithm::sendMessage(string message, Users fromUser) {
    if (!isUserRegistered(fromUser)) {
        cout << "Dogorithm: " << fromUser.getName() << " is not registered in this chat room and cannot send messages." << endl;
        return;
    }
    
    cout << "Dogorithm: " << fromUser.getName() << " barks: " << message << endl;
    ChatRoom::sendMessage(message, fromUser);
}

void Dogorithm::saveMessage(string message, Users fromUser) {
    if (!isUserRegistered(fromUser)) {
        cout << "Dogorithm: " << fromUser.getName() << " is not registered in this chat room and cannot save messages." << endl;
        return;
    }
    
    string formattedMessage = "Dogorithm: " + fromUser.getName() + ": " + message;
    chatHistory.addItem(formattedMessage);
}

void Dogorithm::removeUser(Users user) {
    if (!isUserRegistered(user)) {
        cout << "Dogorithm: " << user.getName() << " is not registered in this chat room and cannot be removed." << endl;
        return;
    }
    
    ChatRoom::removeUser(user);
    cout << "Dogorithm: " << user.getName() << " ate chocolate." << endl;
}

Memento* ChatRoom::captureCurrent()
{
    return new Memento(chatHistory);
}

void ChatRoom::undoAction(Memento* prev)
{
    clearHistory();
    chatHistory = prev->getMemento();
}

void ChatRoom::clearHistory()
{
    chatHistory.getVector()->clear();
}