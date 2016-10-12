#include "grocery_store.hpp"
#include <iostream>

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

void GroceryStore::showResults() {
    std::cout << "Number of clients who gave up: " << numberOfClientsGone;
    std::cout << "\nTotal value of the shopping of the clients who gave up: ";
    std::cout << lostShoppingValue << "\n";
}

void GroceryStore::createClient() {
    Client newClient(timePassed);

    if (willGiveUp(newClient)) {
        ++numberOfClientsGone;
        lostShoppingValue += newClient.totalPurchaseValue();
    } else {
        unsigned int smallestQueue = 0;
        std::size_t min = -1; // greatest int possible

        for (unsigned int i = 0; i < cashierList_.size(); ++i) {
            std::size_t actual = queueSize(cashierList_.next(),
                    newClient.queueChoice());
            if (actual < min) {
                smallestQueue = i;
                min = actual;
            }
        }

        cashierList_.at(smallestQueue).insertClient(newClient);
    }
}

bool GroceryStore::willGiveUp(const Client& client) {
    std::size_t smallestQueueSize = -1;

    for (unsigned int i = 0; i < cashierList_.size(); ++i) {
        std::size_t actualNumberOfPeople =
            cashierList_.next().clientsQueueSize();
        if (actualNumberOfPeople < smallestQueueSize) {
            smallestQueueSize = actualNumberOfPeople;
        }
    }

    return smallestQueueSize > 10;
}

std::size_t GroceryStore::queueSize(const Cashier& cashier, bool choice) {
    if (choice) {
        return cashier.clientsQueueSize();
    } else {
        return cashier.clientsQueueTime();
    }
}

