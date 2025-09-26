#ifndef COMMAND_H
#define COMMAND_H

#include <string>
using namespace std;

class ChatRoom;
class Users;

class Command {
    protected:
        ChatRoom* room;
        string message;
        Users* fromUser;
    public:
        Command(ChatRoom* chatRoom, Users* user, string msg) : room(chatRoom), fromUser(user), message(msg) {};
        virtual void execute() = 0;
};

class SendMessageCommand : public Command {
    public:
        SendMessageCommand(ChatRoom* chatRoom, Users* user, string msg) : Command(chatRoom, user, msg) {};
        void execute();
};

class LogMessageCommand : public Command {
    public:
        LogMessageCommand(ChatRoom* chatRoom, Users* user, string msg) : Command(chatRoom, user, msg) {};
        void execute();
};

#endif