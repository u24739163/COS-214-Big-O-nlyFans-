#include "ChatRoom.h"
#include <algorithm>

void ChatRoom::registerUser(Users user) {
    users.push_back(user);
}

void ChatRoom::sendMessage(string message, Users fromUser) {
    for (Users user : users) {
        if (user != fromUser) {
            user.receive(message, fromUser, *this);
        }
    }
    saveMessage(message, fromUser);
}

void ChatRoom::saveMessage(string message, Users fromUser) {
    string formattedMessage = fromUser.getName() + ": " + message;
    chatHistory.push_back(formattedMessage);
}

void ChatRoom::removeUser(Users user) {
    users.erase(remove(users.begin(), users.end(), user), users.end());
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
    chatHistory.push_back(formattedMessage);
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
    chatHistory.push_back(formattedMessage);
}

void Dogorithm::removeUser(Users user) {
    ChatRoom::removeUser(user);
    cout << "Dogorithm: " << user.getName() << " ate chocolate." << endl;
}