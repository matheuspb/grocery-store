#ifndef GROCERY_LIST_HPP
#define GROCERY_LIST_HPP

#include "circular_list.hpp"

class GroceryStore {
public:
    GroceryStore(unsigned int timeToBeSimulated,
            unsigned int paceToCreateClients);
    //~GroceryStore();
    void simulate();
private:
    void createClient();

    structures::CircularList<Cashier> cashierList;
    unsigned int timePassed{0u}; // in seconds
    unsigned int timeToBeSimulated_;
    unsigned int paceToCreateClients_;
};

#endif

