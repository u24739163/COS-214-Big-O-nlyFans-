/**
 * @file Caretaker.h
 * @brief Definition of the Caretaker class for managing Memento objects.
 * @author Mulondi
 * @date 2025-09-29
 */
#ifndef CARETAKER_H
#define CARETAKER_H

#include "Memento.h"
#include <list>

/**
 * @class Caretaker
 * @brief Manages Memento objects to save and restore the state of an Originator.
 */
class Caretaker {
    public:
        /**
         * @brief Adds a Memento to the list of saved states.
         * @param memento Pointer to the Memento object to be added.
         */
        void addMemento(Memento* memento);
        /**
         * @brief Retrieves the most recently saved Memento.
         * @return Pointer to the most recently saved Memento object.
         */
        Memento* getMemento() const;

        /**
         * @brief Destructor to clean up allocated Memento objects.
         */
        ~Caretaker();
    private:
        list<Memento*> savedMementos; ///< List of saved Memento objects
};

#endif