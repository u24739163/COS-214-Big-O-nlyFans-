#include "ChatRoom.h"
#include <iostream>

int main() 
{
    // iterator testing
    cout << "Iterator Demo:\n";
    VectorFather<Users*> userVector;
    
    Michael user1("michaelsRISEup");
    Mulondi user2("mulondiMurrrondi");
    Mundael user3("epicMundaelchatter");

    userVector.addItem(&user1);
    userVector.addItem(&user2);
    userVector.addItem(&user3);

    Stepper<Users*>* userStepper = userVector.createStepper();
    cout << "created the iterator using Stepper interfacing VectorStepper\n";
    cout << "first item: " << userStepper->first();

    while (userStepper->hasNext())
    {
        cout << "Current User: " << userStepper->current()->getName() << endl;
        userStepper->next();
    }

    delete userStepper;
    
    ////////////////////////////////////////
    // CtrlCat catRoom;
    // catRoom.registerUser(user1);
    // catRoom.registerUser(user2);

    // Dogorithm dogRoom;
    // dogRoom.registerUser(user1);
    // dogRoom.registerUser(user3);

    // SendMessageCommand* send = new SendMessageCommand(catRoom, user1, "goodbyw wworld");
    // LogMessageCommand* log = new LogMessageCommand(chatRoom, user1, "yo save ths shit pls");
    
    // user1.addCommand(send);
    // user1.addCommand(log);
    
    // user1.executeAll();
    
    // delete send;
    // delete log;
    
    return 0;
}
