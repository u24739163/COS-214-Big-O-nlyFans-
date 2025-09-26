#include "Users.h"
#include "Command.h"
void Users::send(string message, ChatRoom room) {
    addCommand(new SendMessageCommand(*this, room, message));
    addCommand(new LogMessageCommand(room, *this, message));
}

void Users::receive(string message, User fromUser, ChatRoom room) {
    Command *receiveCmd = new ReceiveMessageCommand(room, fromUser, *this, message);
    addCommand(receiveCmd);
}

void Users::addCommand(Command* command) {
    commandQueue.push_back(command);
}

void Users::executeAll() {
    for (Command* command : commandQueue) {
        command->execute();
    }
    commandQueue.clear();
}

bool User::operator!=(const User& other) const {
    return name != other.name;
}