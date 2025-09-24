#include <iostream>
#include "PizzaComponent.h"
#include "Pizza.h"
#include "State.h"
#include "Order.h"
#include "Menus.h"

using namespace std;

int main() {
    // Create pizza components
    ToppingGroup* pepperoni = new ToppingGroup("Pepperoni");
    pepperoni->add(new Topping("Dough",10));
    pepperoni->add(new Topping("Cheese",10));
    pepperoni->add(new Topping("Sauce",10));
    pepperoni->add(new Topping("Pepperoni",20));
    
    ToppingGroup* vegetarian = new ToppingGroup("Vegetarian");
    vegetarian->add(new Topping("Dough",10));
    vegetarian->add(new Topping("Cheese",10));
    vegetarian->add(new Topping("Sauce",10));
    vegetarian->add(new Topping("Mushrooms",10));
    vegetarian->add(new Topping("Green Peppers",10));
    vegetarian->add(new Topping("Onions",10));

    ToppingGroup* meatLovers = new ToppingGroup("Meat Lovers");
    meatLovers->add(pepperoni->clone());
    meatLovers->add(new Topping("Beef Sausage",30));
    meatLovers->add(new Topping("Salami",20));

    ToppingGroup* vegetarianDeluxe = new ToppingGroup("Vegetarian Deluxe");
    vegetarianDeluxe->add(vegetarian->clone());
    vegetarianDeluxe->add(new Topping("Feta Cheese",15));
    vegetarianDeluxe->add(new Topping("Olives",15));

    // Create pizza bases
    BasePizza* pepperoniBase = new BasePizza(pepperoni->clone());
    BasePizza* vegetarianBase = new BasePizza(vegetarian->clone());
    BasePizza* meatLoversBase = new BasePizza(meatLovers->clone());
    BasePizza* vegetarianDeluxeBase = new BasePizza(vegetarianDeluxe->clone());

    // Test Order functionality
    cout << "=== ORDER FUNCTIONALITY TEST ===" << endl;
    Order* orderUp = new Order();
    orderUp->addPizza(pepperoniBase);
    orderUp->addPizza(vegetarianBase);
    orderUp->addPizza(meatLoversBase);
    orderUp->addPizza(vegetarianDeluxeBase);
    orderUp->addPizza(new ExtraCheese(new StuffedCrust(new BasePizza(vegetarianDeluxe->clone()))));

    orderUp->printOrder();
    orderUp->calculateTotal();

    // Test State functionality
    cout << "\n=== STATE FUNCTIONALITY TEST ===" << endl;
    cout << "Initial state: " << orderUp->getState() << endl;
    orderUp->changeState();
    cout << "After first change: " << orderUp->getState() << endl;
    orderUp->changeState();
    cout << "After second change: " << orderUp->getState() << endl;
    orderUp->changeState();
    cout << "After third change: " << orderUp->getState() << endl;

    // Test Menu functionality - OBSERVER PATTERN
    cout << "\n=== MENU OBSERVER PATTERN TEST ===" << endl;
    
    // Create menus
    PizzaMenu* pizzaMenu = new PizzaMenu();
    SpecialMenu* specialMenu = new SpecialMenu();
    
    // Create observers
    Customer* customer1 = new Customer();
    Customer* customer2 = new Customer();
    Website* website = new Website();
    
    // Register observers to pizza menu
    cout << "Registering observers to Pizza Menu..." << endl;
    pizzaMenu->addObserver(customer1);
    pizzaMenu->addObserver(website);
    
    // Register observers to special menu
    cout << "Registering observers to Special Menu..." << endl;
    specialMenu->addObserver(customer2);
    specialMenu->addObserver(website);
    
    // Test adding pizzas to menus (should trigger notifications)
    cout << "\nAdding pizzas to Pizza Menu..." << endl;
    pizzaMenu->addPizza(new BasePizza(pepperoni->clone()));
    pizzaMenu->addPizza(new BasePizza(vegetarian->clone()));
    
    cout << "\nAdding pizzas to Special Menu..." << endl;
    specialMenu->addPizza(new ExtraCheese(new BasePizza(meatLovers->clone())));
    specialMenu->addPizza(new StuffedCrust(new BasePizza(vegetarianDeluxe->clone())));
    
    // Test removing pizzas from menus (should trigger notifications)
    cout << "\nRemoving pizza from Pizza Menu..." << endl;
    BasePizza* tempPizza = new BasePizza(pepperoni->clone());
    pizzaMenu->addPizza(tempPizza);
    pizzaMenu->removePizza(tempPizza);
    
    // Test removing observers
    cout << "\nRemoving customer1 from Pizza Menu observers..." << endl;
    pizzaMenu->removeObserver(customer1);
    
    cout << "Adding another pizza to Pizza Menu (only website should be notified)..." << endl;
    pizzaMenu->addPizza(new BasePizza(meatLovers->clone()));
    
    // Test multiple observers receiving updates
    cout << "\nTesting multiple observers on Special Menu..." << endl;
    specialMenu->addPizza(new ExtraCheese(new StuffedCrust(new BasePizza(pepperoni->clone()))));
    
    // Test Discount Strategy functionality
    cout << "\n=== DISCOUNT STRATEGY TEST ===" << endl;
    
    // Test with less than 5 pizzas (Regular discount)
    Order* smallOrder = new Order();
    smallOrder->addPizza(new BasePizza(pepperoni->clone()));
    smallOrder->addPizza(new BasePizza(vegetarian->clone()));
    cout << "Small order discount: " << (smallOrder->applyDiscount() * 100) << "%" << endl;
    
    // Test with exactly 5 pizzas (Bulk discount)
    Order* bulkOrder = new Order();
    for (int i = 0; i < 5; i++) {
        bulkOrder->addPizza(new BasePizza(pepperoni->clone()));
    }
    cout << "Bulk order discount: " << (bulkOrder->applyDiscount() * 100) << "%" << endl;
    
    // Test removing pizza from bulk order
    cout << "Removing one pizza from bulk order..." << endl;
    BasePizza* removePizza = new BasePizza(pepperoni->clone());
    bulkOrder->addPizza(removePizza);
    cout << "After adding 6th pizza: " << (bulkOrder->applyDiscount() * 100) << "%" << endl;
    bulkOrder->removePizza(removePizza);
    cout << "After removing 1 pizza: " << (bulkOrder->applyDiscount() * 100) << "%" << endl;
    
    // Cleanup
    cout << "\n=== CLEANUP ===" << endl;
    delete orderUp;
    delete smallOrder;
    delete bulkOrder;
    delete tempPizza;
    delete removePizza;
    
    delete pepperoni;
    delete vegetarian;
    delete meatLovers;
    delete vegetarianDeluxe;
    
    delete pizzaMenu;
    delete specialMenu;
    delete customer1;
    delete customer2;
    delete website;
    
    cout << "All tests completed successfully!" << endl;
    
    return 0;
}