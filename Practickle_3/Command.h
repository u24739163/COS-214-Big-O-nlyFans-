/**
 * @file Command.h
 * @brief Command pattern implementation for chat room operations
 * @author Micheal Neto
 * @date 2025-09-29
 */
#ifndef COMMAND_H
#define COMMAND_H

#include <string>
using namespace std;

class ChatRoom;
class Users;

/**
 * @class Command
 * @brief Abstract base class for implementing the Command pattern
 * 
 * This class encapsulates chat room operations as command objects,
 * allowing for queuing, logging, and undoing of operations.
 */
class Command {
    protected:
        ChatRoom* room;     ///< Pointer to the chat room where command executes
        string message;     ///< The message content for the command
        Users* fromUser;    ///< Pointer to the user who initiated the command
    
    public:
        /**
         * @brief Constructor for Command objects
         * @param chatRoom Pointer to the target chat room
         * @param user Pointer to the user executing the command
         * @param msg The message content for the command
         */
        Command(ChatRoom* chatRoom, Users* user, string msg) : room(chatRoom), fromUser(user), message(msg) {};
        
        /**
         * @brief Pure virtual function to execute the command
         * 
         * This method must be implemented by concrete command classes
         * to define their specific behavior.
         */
        virtual void execute() = 0;
};

/**
 * @class SendMessageCommand
 * @brief Concrete command for sending messages to chat rooms
 * 
 * This command handles the distribution of messages from one user
 * to all other users in a chat room.
 */
class SendMessageCommand : public Command {
    public:
        /**
         * @brief Constructor for SendMessageCommand
         * @param chatRoom Pointer to the target chat room
         * @param user Pointer to the user sending the message
         * @param msg The message content to send
         */
        SendMessageCommand(ChatRoom* chatRoom, Users* user, string msg) : Command(chatRoom, user, msg) {};
        
        /**
         * @brief Execute the send message operation
         * 
         * Calls the chat room's sendMessage method to distribute
         * the message to all users in the room.
         */
        void execute();
};

/**
 * @class LogMessageCommand
 * @brief Concrete command for logging messages to chat history
 * 
 * This command handles saving messages to the chat room's
 * persistent message history.
 */
class LogMessageCommand : public Command {
    public:
        /**
         * @brief Constructor for LogMessageCommand
         * @param chatRoom Pointer to the target chat room
         * @param user Pointer to the user whose message to log
         * @param msg The message content to log
         */
        LogMessageCommand(ChatRoom* chatRoom, Users* user, string msg) : Command(chatRoom, user, msg) {};
        
        /**
         * @brief Execute the log message operation
         * 
         * Calls the chat room's saveMessage method to store
         * the message in the chat history.
         */
        void execute();
};

#endif