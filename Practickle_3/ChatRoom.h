/**
 * @file ChatRoom.h
 * @brief This file contains the declaration of the ChatRoom class and its derived classes CtrlCat and Dogorithm.
 * @authors Micheal Neto, Mulondi Makhado
 * @date 2025-09-29
 */
#ifndef CHATROOM_H
#define CHATROOM_H

#include "Users.h"
#include "StepFather.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;
/**
 * @class ChatRoom
 * @brief Abstract base class for chat room implementations using the Mediator design pattern
 * 
 * This class serves as the mediator between users, handling message routing
 * and user management within chat rooms.
 */
class Memento;
class ChatRoom {
    protected:
        VectorFather<Users> users; ///< Collection of users in the chat room
        VectorFather<string> chatHistory; ///< Collection of chat messages
    public:
        /**
         * @brief Register a new user to the chat room
         * @param user The user to register
         */
        virtual void registerUser(Users user);
        /**
         * @brief Send a message from a user to the chat room
         * @param message The message to send
         * @param fromUser The user sending the message
         */
        virtual void sendMessage(string message, Users fromUser);
        /**
         * @brief Save a message to the chat history
         * @param message The message to save
         * @param fromUser The user who sent the message
         */
        virtual void saveMessage(string message, Users fromUser);
        /**
         * @brief Remove a user from the chat room
         * @param fromUser The user to remove
         */
        virtual void removeUser(Users fromUser);
        /**
         * @brief Print the chat history
         */
        void printChatHistory();
        /**
         * @brief Print the list of users in the chat room
         */
        void printUsers();
        /**
         * @brief Capture the current state of the chat room
         * @return A Memento object representing the current state
         */
        Memento* captureCurrent();
        /**
         * @brief Restore the chat room to a previous state
         * @param prev The Memento object representing the previous state
         */
        void undoAction(Memento* prev);
        /**
         * @brief Clear the chat history
         */
        void clearHistory();
};

/**
 * @class CtrlCat
 * @brief Concrete implementation of ChatRoom for the CtrlCat chat room
 * 
 * Extends ChatRoom with cat-themed messages and behaviors.
 */
class CtrlCat : public ChatRoom {
    private:

    public:
        void registerUser(Users user) override;
        void sendMessage(string message, Users fromUser) override;
        void saveMessage(string message, Users fromUser) override;
        void removeUser(Users fromUser) override;
};
/**
 * @class Dogorithm
 * @brief Concrete implementation of ChatRoom for the Dogorithm chat room
 * 
 * Extends ChatRoom with dog-themed messages and behaviors.
 */
class Dogorithm : public ChatRoom {
    private:
    
    public:
        void registerUser(Users user) override;
        void sendMessage(string message, Users fromUser) override;
        void saveMessage(string message, Users fromUser) override;
        void removeUser(Users fromUser) override;
};

#endif