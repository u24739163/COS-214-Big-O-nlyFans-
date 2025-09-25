#include "Users.h"
#include "Command.h"
void Users::send(string message, ChatRoom* room) 
{
        
}

void Users::receive(string message, User fromUser, ChatRoom* room) 
{
        
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