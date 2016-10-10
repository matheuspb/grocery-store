#include <iostream>
#include "grocery_store.hpp"

int main() {
    structures::CircularList<Cashier>* cashiers =
		new structures::CircularList<Cashier>();
    cashiers->push_front(*(new Cashier(1, 800, "joao")));
    cashiers->push_front(*(new Cashier(3, 800, "maria")));
    GroceryStore store(3600, 60, cashiers);
    store.simulate();
}

