#ifndef PIZZACOMPONENT_H
#define PIZZACOMPONENT_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class PizzaComponent {
    public:
        virtual PizzaComponent* clone() const = 0;
        virtual string getName() = 0;
        virtual double getPrice() = 0;
        virtual ~PizzaComponent() {};
    protected:
        string name;
        double price;
};

class ToppingGroup : public PizzaComponent {
    public:
        ToppingGroup(string groupName);
        ToppingGroup(const ToppingGroup& other);
        ToppingGroup* clone() const override;
        void add(PizzaComponent * component);
        string getName() override;
        double getPrice() override;
        ~ToppingGroup();
    private:
        vector<PizzaComponent*> toppings;
};

class Topping : public PizzaComponent {
    public:
        Topping(string name, double price);
        Topping(const Topping& other);
        Topping* clone() const override;
        string getName() override;
        double getPrice() override;
};
#endif