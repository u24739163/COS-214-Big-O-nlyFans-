#include "Command.h"
#include "Users.h"
#include "ChatRoom.h"
#include <iostream>

int main() {
    Michael user1("michaelsRISEup");
    Mulondi user2("mulondiMurrrondi");
    Mundael user3("epicMundaelchatter");
    
    CtrlCat catRoom;
    catRoom.registerUser(user1);
    catRoom.registerUser(user2);

    Dogorithm dogRoom;
    dogRoom.registerUser(user1);
    dogRoom.registerUser(user3);

    SendMessageCommand* send = new SendMessageCommand(catRoom, user1, "goodbyw wworld");
    LogMessageCommand* log = new LogMessageCommand(chatRoom, user1, "yo save ths shit pls");
    
    user1.addCommand(send);
    user1.addCommand(log);
    
    user1.executeAll();
    
    delete send;
    delete log;
    
    return 0;
}
