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
        /**
         * @brief Check if a user is registered in this chat room
         * @param user The user to check
         * @return true if user is registered, false otherwise
         */
        bool isUserRegistered(Users user);
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
        /**
         * @brief Register a new user to the CtrlCat chat room
         * @param user The user to register
         */
        void registerUser(Users user) override;
        /**
         * @brief Send a message in the CtrlCat chat room
         * @param message The message to send
         * @param fromUser The user sending the message
         */
        void sendMessage(string message, Users fromUser) override;
        /**
         * @brief Save a message to the CtrlCat chat history
         * @param message The message to save
         * @param fromUser The user who sent the message
         */
        void saveMessage(string message, Users fromUser) override;
        /**
         * @brief Remove a user from the CtrlCat chat room
         * @param fromUser The user to remove
         */
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
        /**
         * @brief Register a new user to the Dogorithm chat room
         * @param user The user to register
         */
        void registerUser(Users user) override;
        /**
         * @brief Send a message in the Dogorithm chat room
         * @param message The message to send
         * @param fromUser The user sending the message
         */
        void sendMessage(string message, Users fromUser) override;
        /**
         * @brief Save a message to the Dogorithm chat history
         * @param message The message to save
         * @param fromUser The user who sent the message
         */
        void saveMessage(string message, Users fromUser) override;
        /**
         * @brief Remove a user from the Dogorithm chat room
         * @param fromUser The user to remove
         */
        void removeUser(Users fromUser) override;
};

#endif