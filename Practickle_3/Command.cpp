#include "Command.h"

void SendMessageCommand::execute() 
{
    room.sendMessage(message, fromUser);
}

void LogMessageCommand::execute() 
{
    room.saveMessage(message, fromUser);
}
