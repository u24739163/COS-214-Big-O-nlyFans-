
#include "Users.h"
void Users::send(string message, ChatRoom room) {
    addCommand(new SendMessageCommand(room, *this, message));
    addCommand(new LogMessageCommand(room, *this, message));
}

void Users::receive(string message, Users fromUser, ChatRoom room) {
    cout << name << " received a message from " << fromUser.getName() << " in chat room: " << message << endl;
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

bool Users::operator!=(const Users& other) const {
    return name != other.name;
}