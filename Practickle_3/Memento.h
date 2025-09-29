#ifndef MEMENTO_H
#define MEMENTO_H

#include "ChatRoom.h"
#include <vector>

class Memento {

    public:
        VectorFather<string> getMemento() const;
        ~Memento();
    private:
    friend class ChatRoom;
        VectorFather<string> history;
        Memento(VectorFather<string> elements);
};

#endif