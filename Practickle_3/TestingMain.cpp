#include "Command.h"
#include "Users.h"
#include "ChatRoom.h"
#include <iostream>

int main() {
    User user1("michaelsRISEup");
    
    CtrlCat chatRoom;
    
    SendMessageCommand* send = new SendMessageCommand(chatRoom, user1, "goodbyw wworld");
    LogMessageCommand* log = new LogMessageCommand(chatRoom, user1, "yo save ths shit pls");
    
    user1.addCommand(send);
    user1.addCommand(log);
    
    user1.executeAll();
    
    delete send;
    delete log;
    
    return 0;
}
