#ifndef CASHIER_HPP
#define CASHIER_HPP

#include <iostream>
#include "linked_queue.h"
#include "client.hpp"

class Cashier
{
    public:
		Cashier() = default;
        Cashier(int, int, std::string);

        std::size_t clientsQueueSize();
        void insertClient(Client&);
        void removeFirstClient();
        void update();
        int averageGain();
        int totalGain();
        int cashierEfficiency();
        int clientsQueueTime();
        int averageTime();
    private:
        int cashierEfficiency_{1}, totalClientsNumber_{0};
        int clientsQueueTime_{0}, actualClientTime_{1}, totalQueueTime_{0};
        int totalGain_{0}, salary_{0};
        std::string ID_{};
        structures::LinkedQueue<Client> clientsQueue_{};
};

#endif
