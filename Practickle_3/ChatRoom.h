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
        VectorFather<Users> users;
        VectorFather<string> chatHistory;
    public:
        virtual void registerUser(Users user);
        virtual void sendMessage(string message, Users fromUser);
        virtual void saveMessage(string message, Users fromUser);
        virtual void removeUser(Users fromUser);
        virtual void printChatHistory();
        virtual void printUsers();
};

class CtrlCat : public ChatRoom {
    private:

    public:
        void registerUser(Users user) override;
        void sendMessage(string message, Users fromUser) override;
        void saveMessage(string message, Users fromUser) override;
        void removeUser(Users fromUser) override;
        void printChatHistory() override;
        void printUsers() override;
};

class Dogorithm : public ChatRoom {
    private:
    
    public:
        void registerUser(Users user) override;
        void sendMessage(string message, Users fromUser) override;
        void saveMessage(string message, Users fromUser) override;
        void removeUser(Users fromUser) override;
        void printChatHistory() override;
        void printUsers() override;
};

#endif