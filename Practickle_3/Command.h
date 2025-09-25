#ifndef COMMAND_H
#define COMMAND_H

#include "ChatRoom.h"
#include "Users.h"
class User;
class ChatRoom;
class Command {
    protected:
        ChatRoom room;
        string message;
        User fromUser;
    public:
        Command(ChatRoom chatRoom, User user, string msg);
        virtual void execute() = 0;
};

class SendMessageCommand : public Command {
    public:
        SendMessageCommand(ChatRoom chatRoom, User user, string msg);
        void execute();
};

class LogMessageCommand : public Command {
    public:
        LogMessageCommand(ChatRoom chatRoom, User user, string msg);
        void execute();
};

#endif