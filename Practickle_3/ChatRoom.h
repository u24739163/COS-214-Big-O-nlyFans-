#ifndef CHATROOM_H
#define CHATROOM_H

#include "Users.h"
#include "StepFather.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class ChatRoom {
    protected:
        std::vector<Users> users;
        std::vector<string> chatHistory;
    public:
        virtual void registerUser(Users user);
        virtual void sendMessage(string message, Users fromUser);
        virtual void saveMessage(string message, Users fromUser);
        virtual void removeUser(Users fromUser);
};

class CtrlCat : public ChatRoom {
    private:
        void registerUser(Users user);
        void sendMessage(string message, Users fromUser);
        void saveMessage(string message, Users fromUser);
        void removeUser(Users fromUser);
    public:
};

class Dogorithm : public ChatRoom {
    private:
        void registerUser(Users user);
        void sendMessage(string message, Users fromUser);
        void saveMessage(string message, Users fromUser);
        void removeUser(Users fromUser);
    public:
};

#endif