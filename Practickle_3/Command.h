#ifndef COMMAND_H
#define COMMAND_H

#include "ChatRoom.h"
#include "Users.h"
class Command {
    protected:
        ChatRoom* room;
        string message;
        User fromUser;
    public:
        virtual void execute() = 0;
};

class SendMessageCommand : public Command {
    public:
        void execute();
};

class LogMessageCommand : public Command {
    public:
        void execute();
};

#endif