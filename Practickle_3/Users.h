#ifndef USER_H
#define USER_H

#include "ChatRoom.h"
#include "Command.h"
class Users {
    protected:
        vector<ChatRoom*> chatRooms;
        string name;
        vector<Command*> commandQueue; 
    public:
        virtual void send(string message, ChatRoom* room) = 0;
        virtual void receive(string message, User* fromUser, ChatRoom* room) = 0;
        virtual void addCommand(Command* command) = 0;
        virtual void executeAll() = 0;
};

class User : public Users {
    public:
        void send(string message, ChatRoom* room);
        void receive(string message, User* fromUser, ChatRoom* room);
        void addCommand(Command* command);
        void executeAll();
        string getName() { return name; }
};
 
#endif