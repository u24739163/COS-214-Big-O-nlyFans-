#ifndef CHATROOM_H
#define CHATROOM_H

#include "Users.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class ChatRoom {
    protected:
        vector<User> users;
        vector<string> chatHistory;
    public:
        virtual void registerUser(User user);
        virtual void sendMessage(string message, User fromUser);
        virtual void saveMessage(string message, User fromUser);
        virtual void removeUser(User fromUser); 
};

class CtrlCat : public ChatRoom {
    private:
        void registerUser(User user);
        void sendMessage(string message, User fromUser);
        void saveMessage(string message, User fromUser);
        void removeUser(User fromUser);
    public:
};

class Dogorithm : public ChatRoom {
    private:
        void registerUser(User user);
        void sendMessage(string message, User fromUser);
        void saveMessage(string message, User fromUser);
        void removeUser(User fromUser);
    public:
};

#endif