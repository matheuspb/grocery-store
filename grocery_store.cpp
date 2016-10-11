#include "grocery_store.hpp"

GroceryStore::GroceryStore(unsigned int timeToBeSimulated,
        unsigned int paceToCreateClients,
        structures::CircularList<Cashier>&& cashierList):
    timeToBeSimulated_{timeToBeSimulated},
    paceToCreateClients_{paceToCreateClients},
    cashierList_{std::move(cashierList)} {

}

void GroceryStore::simulate() {
    while (timePassed < timeToBeSimulated_) {
        for (unsigned int i = 0; i < cashierList_.size(); ++i) {
            cashierList_.next().update();
        }
        if (timePassed % paceToCreateClients_ == 0) {
            createClient();
        }
        ++timePassed;
    }
}

void GroceryStore::createClient() {
    Client newClient(timePassed);
    if (newClient.queueChoice()) {
        // choose by number of people
        int smallestQueue = 0;
        std::size_t min = -1; // greatest int possible
        for (unsigned int i = 0; i < cashierList_.size(); ++i) {
            std::size_t actual = cashierList_.next().clientsQueueSize();
            if (actual < min) {
                smallestQueue = i;
                min = actual;
            }
        }
        if (min < 10) {
            cashierList_.at(smallestQueue).insertClient(newClient);
        } else {
            ++numberOfClientsGone;
            lostShoppingValue += newClient.totalPurchaseValue();
        }
    } else {
        // choose by number of items (time left in queue)
        int smallestQueue = 0;
        std::size_t min = -1; // greatest int possible
        for (unsigned int i = 0; i < cashierList_.size(); ++i) {
            std::size_t actual = cashierList_.next().clientsQueueTime();
            if (actual < min) {
                smallestQueue = i;
                min = actual;
            }
        }
        cashierList_.at(smallestQueue).insertClient(newClient);
    }
}

