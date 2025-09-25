#ifndef CHATROOM_H
#define CHATROOM_H

#include <iostream>
#include <vector>
#include "Users.h"
#include <string>
using namespace std;

class ChatRoom {
    protected:
        vector<User*> users;
        vector<string> chatHistory;
    public:
        virtual void registerUser(User* user) = 0;
        virtual void sendMessage(string message, User* fromUser) = 0;
        virtual void saveMessage(string message, User* fromUser) = 0;
        virtual void removeUser(User* user) = 0; 
};

class CtrlCat : public ChatRoom {
    private:
        void registerUser(User* user);
        void sendMessage(string message, User* fromUser);
        void saveMessage(string message, User* fromUser);
        void removeUser(User* user);
    public:
};

class Dogorithm : public ChatRoom {
    private:
        void registerUser(User* user);
        void sendMessage(string message, User* fromUser);
        void saveMessage(string message, User* fromUser);
        void removeUser(User* user);
    public:
};

#endif