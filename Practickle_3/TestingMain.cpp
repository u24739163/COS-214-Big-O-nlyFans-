#include "ChatRoom.h"
#include "Caretaker.h"
#include <iostream>

int main() 
{
    // iterator testing
    // cout << "Iterator Demo:\n";
    // VectorFather<Users*> userVector;
    
    
    // userVector.addItem(&user1);
    // userVector.addItem(&user2);
    // userVector.addItem(&user3);
    
    // Stepper<Users*>* userStepper = userVector.createStepper();
    // cout << "created the iterator using Stepper interfacing VectorStepper\n";
    // cout << "first item: " << userStepper->first()->getName() << endl;
    
    // int count = 1;
    // while (userStepper->hasNext())
    // {
        //     cout << " User nr" << count << ": " << userStepper->current()->getName() << endl;
        //     userStepper->next();
        //     count++;
        // }
        
        // delete userStepper;
        
        ////////////////////////////////////////
    Michael user1("Alice");
    Mulondi user2("Bob");
    Mundael user3("Charlie");
    Mulondi user4("David");

    CtrlCat* catRoom = new CtrlCat();
    catRoom->registerUser(user1);
    catRoom->registerUser(user2);
    catRoom->registerUser(user3);
    catRoom->registerUser(user4);

    Dogorithm* dogRoom = new Dogorithm();
    dogRoom->registerUser(user1);
    dogRoom->registerUser(user3);


    user1.send("Hello everyone!", catRoom);
    Caretaker c1;
    c1.addMemento(catRoom->captureCurrent());
    user2.send("Hi Alice!", catRoom);
    user3.send("Hey folks!", catRoom);
    user1.send("Woof woof!", dogRoom);
    dogRoom->registerUser(user2);
    user3.send("Bark bark!", dogRoom);
    user2.send("Nah yall are weird", dogRoom);
    dogRoom->removeUser(user2);
    catRoom->undoAction(c1.getMemento());
    catRoom->printChatHistory();
    catRoom->printUsers();
    dogRoom->printChatHistory();
    dogRoom->printUsers();

    delete catRoom;
    delete dogRoom;

    return 0;
}
