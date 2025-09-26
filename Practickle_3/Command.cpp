#include "Command.h"
#include "ChatRoom.h"
#include "Users.h"

void SendMessageCommand::execute() 
{
    room->sendMessage(message, *fromUser);
}

void LogMessageCommand::execute() 
{
    room->saveMessage(message, *fromUser);
}
