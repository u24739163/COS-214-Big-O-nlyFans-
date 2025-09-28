#ifndef USER_H
#define USER_H

#include <iostream>
#include <vector>
using namespace std;
class ChatRoom;
class Command;
class Users {
    protected:
    vector<ChatRoom*> chatRooms;
    string name;
    vector<Command*> commandQueue; 
    public:
    void send(string message, ChatRoom& room);
    void receive(string message, Users fromUser, ChatRoom& room);
    void addCommand(Command* command);
    void executeAll();
    bool operator!=(const Users& other) const;
    bool operator==(const Users& other) const;
    virtual string getName() const { return name; }
};

class Mulondi : public Users {
    public:
    Mulondi(string userName) { name = userName; }
    string getName() const override { return name; }
};

class Michael : public Users {
    public:
    Michael(string userName) { name = userName; }
    string getName() const override { return name; }
};

class Mundael : public Users {
    public:
    Mundael(string userName) { name = userName; }
    string getName() const override { return name; }
};

#include "ChatRoom.h"
#include "Command.h"
#endif