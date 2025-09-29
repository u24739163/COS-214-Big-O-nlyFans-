/**
 * @file Memento.h
 * @brief Memento pattern implementation for state preservation
 * @author Mulondi Makhado
 * @date 2025-09-29
 */
#ifndef MEMENTO_H
#define MEMENTO_H

#include "ChatRoom.h"
#include <vector>

/**
 * @class Memento
 * @brief Memento class for preserving chat room state
 * 
 * This class implements the Memento pattern to capture and restore
 * the state of chat room history. It provides a way to save and
 * restore chat messages for undo functionality.
 */
class Memento {
    public:
        /**
         * @brief Get the preserved chat history
         * @return VectorFather containing the saved chat messages
         * 
         * Returns a copy of the chat history that was saved when
         * this memento was created.
         */
        VectorFather<string> getMemento() const;
        
        /**
         * @brief Destructor for Memento
         * 
         * Cleans up the stored history data when the memento
         * is destroyed.
         */
        ~Memento();
    
    private:
        friend class ChatRoom;  ///< Allow ChatRoom to access private members
        
        VectorFather<string> history;  ///< Stored chat history state
        
        /**
         * @brief Private constructor for Memento
         * @param elements The chat history to preserve
         * 
         * Creates a memento with the specified chat history.
         * Only ChatRoom can create Memento objects due to
         * the private constructor and friend relationship.
         */
        Memento(VectorFather<string> elements);
};

#endif