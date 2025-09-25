#include "Command.h"

Command::Command(ChatRoom chatRoom, User user, string msg) 
{
    this->room = chatRoom;
    this->fromUser = user;
    this->message = msg;
}

SendMessageCommand::SendMessageCommand(ChatRoom chatRoom, User user, string msg) 
    : Command(chatRoom, user, msg) { }

void SendMessageCommand::execute() 
{
    room.sendMessage(message, fromUser);
}

LogMessageCommand::LogMessageCommand(ChatRoom chatRoom, User user, string msg) 
    : Command(chatRoom, user, msg) { }

void LogMessageCommand::execute() 
{
    room.saveMessage(message, fromUser);
}
