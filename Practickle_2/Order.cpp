#include "Order.h"

Order::Order()
{
    discountStrategy = new RegularDiscount();
    state = new Ordered();
}

Order::~Order()
{
    delete state;
    delete discountStrategy;
    for (int i = 0; i < pizzas.size(); i++) 
    {
        delete pizzas[i];
    }
    pizzas.clear();
}

Order::Order(DiscountStrategy* discountStrategy)
{
    discountStrategy = new RegularDiscount();
    vector<Pizza*> pizzas;
}

void Order::addPizza(Pizza* pizza)
{
    pizzas.push_back(pizza);
    if (pizzas.size() >= 5) 
    {
        delete discountStrategy;
        discountStrategy = new BulkDiscount(pizzas);
    }
    else 
    {
        delete discountStrategy;
        discountStrategy = new RegularDiscount();
    }
};

void Order::removePizza(Pizza* pizza)
{
    for (int i = 0; i < pizzas.size(); i++) 
    {
        if (pizzas[i] == pizza) 
        {
            pizzas.erase(pizzas.begin() + i);
            break;
        }
    }
    if (pizzas.size() < 5) 
    {
        delete discountStrategy;
        discountStrategy = new RegularDiscount();
    }
    else
    {
        delete discountStrategy;
        discountStrategy = new BulkDiscount(pizzas);
    }
};

void Order::clearOrder()
{
    pizzas.clear();
    delete discountStrategy;
    discountStrategy = new RegularDiscount();
};

double Order::applyDiscount()
{
    
    return discountStrategy->applyDiscount();

};

void Order::printOrder()
{
    for (int i = 0; i < pizzas.size(); i++) 
    {
        pizzas[i]->printPizza();
    }   
}

void Order::setState(State* state)
{
    delete this->state;
    this->state = state;
}

string Order::getState()
{
    return state->getState();
}

void Order::changeState()
{
    state->handleChange(this);
}

void Order::calculateTotal()
{
    double total = 0.0;
    for (int i = 0; i < pizzas.size(); i++) 
    {
        total += pizzas[i]->getPrice();
    
    }
    std::cout << "Total price before discount: " << total << "\n";

    double discounted = total - (total * applyDiscount());
    double saved = total * applyDiscount();

    std::cout << "You Saved: " << saved << "\n";

    std::cout << "Total price after discount: " << discounted << "\n";
};
