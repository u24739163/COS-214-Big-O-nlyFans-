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
        void send(string message, ChatRoom* room);
        void receive(string message, User fromUser, ChatRoom* room);
        void addCommand(Command* command);
        void executeAll();
};

class User : public Users {
    private:
        string name;
    public:
        User(string userName) : name(userName) {}
        bool operator!=(const User& other) const;
        string getName() { return name; }
};
 
#endif