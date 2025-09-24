#include "PizzaComponent.h"

Topping::Topping(string name, double price)
{
    this->name = name;
    this->price = price;
}

Topping::Topping(const Topping& other)
{
    this->name = other.name;
    this->price = other.price;
}

Topping* Topping::clone() const 
{
    return new Topping(*this);
}

string Topping::getName()
{
    return name;
}

double Topping::getPrice()
{
    return price;
}

void ToppingGroup::add(PizzaComponent * component)
{
    toppings.push_back(component);
};

string ToppingGroup::getName()
{
    string out = name + " (";
    for(size_t i = 0; i < toppings.size(); i++) {
        out += toppings[i]->getName() + ", ";
    }
    out += ")";
    return out;
}

double ToppingGroup::getPrice()
{
    double total = 0;
    for(size_t i = 0; i < toppings.size(); i++) {
        total += toppings[i]->getPrice();
    }
    return total;
}

ToppingGroup::~ToppingGroup() {
    for(size_t i = 0; i < toppings.size(); i++) {
        if(toppings[i]) {
            delete toppings[i];
        }
    }
    toppings.clear();
}

ToppingGroup::ToppingGroup(string groupName)
{
    this->name = groupName;
    this->price = 0;
}

ToppingGroup::ToppingGroup(const ToppingGroup& other)
{
    this->name = other.name;
    this->price = other.price;
    for (const auto& topping : other.toppings) {
        this->toppings.push_back(topping->clone());
    }
}

ToppingGroup* ToppingGroup::clone() const 
{
    return new ToppingGroup(*this);
}
