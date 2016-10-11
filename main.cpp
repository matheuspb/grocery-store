#include <iostream>
#include "grocery_store.hpp"

int main() {
    structures::CircularList<Cashier> cashiers;
    Cashier joao(1, 800, "joao");
    Cashier maria(1, 800, "maria");
    cashiers.push_front(joao);
    cashiers.push_front(maria);
    GroceryStore store(3600, 60, std::move(cashiers));
    store.simulate();
}
