#include "Command.h"

Command::Command(ChatRoom chatRoom, User user, string msg) 
{
    room = chatRoom;
    fromUser = user;
    message = msg;
}

SendMessageCommand::SendMessageCommand(ChatRoom chatRoom, User user, string msg) 
    : Command(chatRoom, user, msg) { }

void SendMessageCommand::execute() 
{
    room.sendMessage(fromUser, message);
}

LogMessageCommand::LogMessageCommand(ChatRoom chatRoom, User user, string msg) 
    : Command(chatRoom, user, msg) { }

void LogMessageCommand::execute() 
{
    room.saveMessage(fromUser, message);
}
