#ifndef MENUS_H
#define MENUS_H

#include <string>
#include <vector>
#include <iostream>
#include "Pizza.h"

using namespace std;

class Observer;
class Menus {
    public:
        void addObserver(Observer* observer);
        void removeObserver(Observer* observer);
        void addPizza(Pizza * pizza);
        void removePizza(Pizza * pizza);
        virtual void notifyObserver(string message) = 0;
        ~Menus();
    protected:
        vector<Observer*> observers;    
        vector<Pizza*> pizzas;
};

class Observer {
    public:
        virtual void update(string message) = 0;
        virtual ~Observer() {}
};

class PizzaMenu : public Menus {
    public:
        void notifyObserver(string message); 
    private:
};

class SpecialMenu : public Menus {
    public:
        void notifyObserver(string message);
    private:
};

class Customer : public Observer {
    public:
        void update(string message) override;
    private:
};

class Website : public Observer {
    public:
        void update(string message) override;
    private:
};

#endif