#include "Command.h"

void SendMessageCommand::execute() {
    room->sendMessage(fromUser, message);
}

void LogMessageCommand::execute() {
    room->logMessage(fromUser, message);
}
