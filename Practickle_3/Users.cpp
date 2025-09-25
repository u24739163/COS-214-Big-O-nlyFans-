#include "Users.h"
#include "Command.h"
void User::send(string message, ChatRoom* room) {
    
}

void User::receive(string message, User* fromUser, ChatRoom* room) {
    
}

void User::addCommand(Command* command) {
    commandQueue.push_back(command);
}

void User::executeAll() {
    for (Command* command : commandQueue) {
        command->execute();
    }
    commandQueue.clear();
}