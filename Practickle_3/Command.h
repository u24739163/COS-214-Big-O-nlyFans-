#ifndef COMMAND_H
#define COMMAND_H

#include "ChatRoom.h"
#include "Users.h"
class Command {
    protected:
        ChatRoom * ChatRooms;
        string message;
        User fromUser;
    public:
        virtual void execute() = 0;
};

class SendMessageCommand : public Command {

};

class LogMessageCommand : public Command {

};

#endif