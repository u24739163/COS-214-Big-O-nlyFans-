#include "State.h"

void Ordered::handleChange(Order* order)
{
    order->setState(new Preparing());
}
string Ordered::getState()
{
    return "Order is in the Ordered state.";
}

void Preparing::handleChange(Order* order)
{
    order->setState(new Delivering());
}
string Preparing::getState()
{
    return "Order is being prepared.";
}

void Delivering::handleChange(Order* order)
{
    order->setState(new Delivered());
}
string Delivering::getState()
{
    return "Order is out for delivery.";
}

void Delivered::handleChange(Order* order)
{
    order->setState(new Delivered());
}
string Delivered::getState()
{
    return "Order has been delivered.";
}

