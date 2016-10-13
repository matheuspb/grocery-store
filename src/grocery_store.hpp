#ifndef GROCERY_STORE_HPP
#define GROCERY_STORE_HPP

#include "circular_list.hpp"
#include "cashier.hpp"

class GroceryStore {
public:
    GroceryStore(unsigned int timeToBeSimulated,
            unsigned int paceToCreateClients,
            structures::CircularList<Cashier>& cashierList);
    void simulate();
    void showResults() const;

private:
    void createClient();
    bool willGiveUp(const Client&) const;
    std::size_t queueSize(const Cashier&, bool) const;

    unsigned int timePassed{0u}; // in seconds
    unsigned int numberOfClientsGone{0u};
    unsigned int lostShoppingValue{0u};
    const unsigned int timeToBeSimulated_{0u};
    const unsigned int paceToCreateClients_{0u};
    structures::CircularList<Cashier> cashierList_{};
};

#endif

