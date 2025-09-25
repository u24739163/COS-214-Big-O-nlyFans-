#include "ChatRoom.h"

void ChatRoom::registerUser(User user) {
    users.push_back(user);
}

// Broadcast message to all users except the sender
void ChatRoom::sendMessage(string message, User fromUser) {
    for (User user : users) {
        if (user != fromUser) {
            user.receive(message, fromUser, this);
        }
    }
    saveMessage(message, fromUser);
}

void ChatRoom::saveMessage(string message, User fromUser) {
    string formattedMessage = fromUser.getName() + ": " + message;
    chatHistory.push_back(formattedMessage);
}

void ChatRoom::removeUser(User user) {
    users.erase(remove(users.begin(), users.end(), user), users.end());
}

void CtrlCat::registerUser(User user) {
    ChatRoom::registerUser(user);
    cout << "CtrlCat: " << user.getName() << " has joined the kitten kontrol klub (kkk)." << endl;
}

void CtrlCat::sendMessage(string message, User fromUser) {
    cout << "CtrlCat: " << fromUser.getName() << " purrs: " << message << endl;
    ChatRoom::sendMessage(message, fromUser);
}

void CtrlCat::saveMessage(string message, User fromUser) {
    string formattedMessage = "CtrlCat: " + fromUser.getName() + ": " + message;
    chatHistory.push_back(formattedMessage);
}

void CtrlCat::removeUser(User user) {
    ChatRoom::removeUser(user);
    cout << "CtrlCat: " << user.getName() << " has ran out of lives." << endl;
}

void Dogorithm::registerUser(User user) {
    ChatRoom::registerUser(user);
    cout << "Dogorithm: " << user.getName() << " was fed a bone." << endl;
}

void Dogorithm::sendMessage(string message, User fromUser) {
    cout << "Dogorithm: " << fromUser.getName() << " barks: " << message << endl;
    ChatRoom::sendMessage(message, fromUser);
}

void Dogorithm::saveMessage(string message, User fromUser) {
    string formattedMessage = "Dogorithm: " + fromUser.getName() + ": " + message;
    chatHistory.push_back(formattedMessage);
}

void Dogorithm::removeUser(User user) {
    ChatRoom::removeUser(user);
    cout << "Dogorithm: " << user.getName() << " ate chocolate." << endl;
}