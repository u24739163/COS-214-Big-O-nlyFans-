#ifndef DISCOUNTSTRATEGY_H
#define DISCOUNTSTRATEGY_H

#include <vector>
#include "Pizza.h"

class DiscountStrategy 
{
    protected:
        vector<Pizza*> pizzas;
    public:
        DiscountStrategy();
        virtual ~DiscountStrategy();
        virtual double applyDiscount() = 0;
};

class FamilyDiscount : public DiscountStrategy 
{
    public:
        double applyDiscount() override;
};

class RegularDiscount : public DiscountStrategy 
{
    public:
        double applyDiscount() override;
};

class BulkDiscount : public DiscountStrategy 
{
    public:
        BulkDiscount(vector<Pizza*> p);
        double applyDiscount() override;
};

#endif