#include "grocery_store.hpp"

GroceryStore::GroceryStore(unsigned int timeToBeSimulated,
        unsigned int paceToCreateClients,
        structures::CircularList<Cashier> cashierList):
    timeToBeSimulated_{timeToBeSimulated},
    paceToCreateClients_{paceToCreateClients},
    cashierList_{cashierList} {

}

void GroceryStore::simulate() {
    while (timePassed < timeToBeSimulated_) {
        for (int i = 0; i < cashierList_.size(); ++i) {
            cashierList_.next().update(); // update not implemented
        }
        if (timePassed % paceToCreateClients_ == 0) {
            createClient();
        }
        ++timePassed;
    }
}

void GroceryStore::createClient() {
    /* TODO Generate client and add to the correct cashier, and compute the
     * number of clients who give up, and the value of their purchase
     */
}

