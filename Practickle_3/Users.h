#ifndef USER_H
#define USER_H

#include "ChatRoom.h"
#include "Command.h"
class ChatRoom;
class Command;
class Users {
    protected:
        vector<ChatRoom*> chatRooms;
        string name;
        vector<Command*> commandQueue; 
    public:
        void send(string message, ChatRoom room);
        void receive(string message, Users fromUser, ChatRoom room);
        void addCommand(Command* command);
        void executeAll();
        bool operator!=(const Users& other) const;
};

class Mulondi : public Users {
    private:
        string name;
    public:
        Mulondi(string userName) : name(userName) {}
        string getName() { return name; }
};

class Michael : public Users {
    private:
        string name;
    public:
        Michael(string userName) : name(userName) {}
        string getName() { return name; }
};

class Mundael : public Users {
    private:
        string name;
    public:
        Mundael(string userName) : name(userName) {}
        string getName() { return name; }
};
 
#endif