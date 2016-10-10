#include <iostream>
#include "grocery_store.hpp"

int main() {
    structures::CircularList<Cashier>* cashiers =
        new structures::CircularList<Cashier>();
    Cashier* joao = new Cashier(1, 800, "joao");
    Cashier* maria = new Cashier(1, 800, "maria");
    cashiers->push_front(*joao);
    cashiers->push_front(*maria);
    GroceryStore store(3600, 60, cashiers);
    store.simulate();
}

