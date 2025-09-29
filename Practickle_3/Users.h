/**
 * @file Users.h
 * @brief User classes implementing different user types for the chat system
 * @author Micheal Neto
 * @date 2025-09-29
 */
#ifndef USER_H
#define USER_H

#include <iostream>
#include <vector>
using namespace std;

class ChatRoom;
class Command;

/**
 * @class Users
 * @brief Abstract base class representing a user in the chat system
 * 
 * This class provides the basic functionality for users to send and receive
 * messages, manage chat room memberships, and handle command queues.
 */
class Users {
    protected:
        vector<ChatRoom*> chatRooms;   ///< List of chat rooms the user belongs to
        string name;                   ///< The user's display name
        vector<Command*> commandQueue; ///< Queue of commands to execute
    
    public:
        /**
         * @brief Send a message to a specific chat room
         * @param message The message content to send
         * @param room Pointer to the target chat room
         * 
         * Creates and queues SendMessageCommand and LogMessageCommand
         * for the specified message and chat room.
         */
        void send(string message, ChatRoom* room);
        
        /**
         * @brief Receive a message from another user
         * @param message The received message content
         * @param fromUser The user who sent the message
         * @param room Pointer to the chat room where message was sent
         * 
         * Handles incoming messages and displays them to the user.
         */
        void receive(string message, Users fromUser, ChatRoom* room);
        
        /**
         * @brief Add a command to the user's command queue
         * @param command Pointer to the command to add
         * 
         * Adds the command to the queue for later execution.
         */
        void addCommand(Command* command);
        
        /**
         * @brief Execute all queued commands
         * 
         * Processes and executes all commands in the command queue,
         * then clears the queue.
         */
        void executeAll();
        
        /**
         * @brief Inequality operator for comparing users
         * @param other The user to compare with
         * @return true if users are different, false otherwise
         */
        bool operator!=(const Users& other) const;
        
        /**
         * @brief Equality operator for comparing users
         * @param other The user to compare with
         * @return true if users are the same, false otherwise
         */
        bool operator==(const Users& other) const;
        
        /**
         * @brief Get the user's display name
         * @return The user's name as a string
         */
        virtual string getName() const { return name; }
};

/**
 * @class Mulondi
 * @brief Concrete user class representing Mulondi user type
 * 
 * Specific implementation of Users class with Mulondi-specific behavior.
 */
class Mulondi : public Users {
    public:
        /**
         * @brief Constructor for Mulondi user
         * @param userName The display name for this user
         */
        Mulondi(string userName) { name = userName; }
        
        /**
         * @brief Get the user's name
         * @return The user's name as a string
         */
        string getName() const override { return name; }
};

/**
 * @class Michael
 * @brief Concrete user class representing Michael user type
 * 
 * Specific implementation of Users class with Michael-specific behavior.
 */
class Michael : public Users {
    public:
        /**
         * @brief Constructor for Michael user
         * @param userName The display name for this user
         */
        Michael(string userName) { name = userName; }
        
        /**
         * @brief Get the user's name
         * @return The user's name as a string
         */
        string getName() const override { return name; }
};

/**
 * @class Mundael
 * @brief Concrete user class representing Mundael user type
 * 
 * Specific implementation of Users class with Mundael-specific behavior.
 */
class Mundael : public Users {
    public:
        /**
         * @brief Constructor for Mundael user
         * @param userName The display name for this user
         */
        Mundael(string userName) { name = userName; }
        
        /**
         * @brief Get the user's name
         * @return The user's name as a string
         */
        string getName() const override { return name; }
};

#include "ChatRoom.h"
#include "Command.h"
#endif