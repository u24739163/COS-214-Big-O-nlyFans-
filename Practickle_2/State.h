#ifndef STATE_H
#define STATE_H

#include <string>
#include "Order.h"
using namespace std;

class Order;
class State {
    public:
        virtual void handleChange(Order* order) = 0;
        virtual string getState() = 0;
};

class Ordered : public State {
    public:
        void handleChange(Order* order) override;
        string getState() override;
};

class Preparing : public State {
    public:
        void handleChange(Order* order) override;
        string getState() override;
};

class Delivering : public State {
    public:
        void handleChange(Order* order) override;
        string getState() override;
};

class Delivered : public State {
    public:
        void handleChange(Order* order) override;
        string getState() override;
};

#endif