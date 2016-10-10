#ifndef GROCERY_LIST_HPP
#define GROCERY_LIST_HPP

#include "circular_list.hpp"
#include "cashier.hpp"

class GroceryStore {
public:
    GroceryStore(unsigned int timeToBeSimulated,
            unsigned int paceToCreateClients,
            structures::CircularList<Cashier>* cashierList);
    void simulate();
private:
    void createClient();

    unsigned int timePassed{0u}; // in seconds
    unsigned int timeToBeSimulated_;
    unsigned int paceToCreateClients_;
    structures::CircularList<Cashier>* cashierList_;
};

#endif

