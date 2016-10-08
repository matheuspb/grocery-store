#ifndef CASHIER_HPP
#define CASHIER_HPP

#include <iostream>
#include "linked_queue.h"
#include "client.hpp"

/*
 *
 *  TODO: Receber o tempo de espera do cliente no momento de retirada dele
 *        da fila.
 *
 */

class Cashier
{
    public:
        Cashier(int, double, std::string);

        std::size_t clientsQueueSize();
        void insertClient(Client);
        void removeFirstClient();
        void update();
        double averageGain();
        double totalGain();
        int cashierEfficiency();
        int clientsQueueTime();

    private:
        int cashierEfficiency_, totalClientsNumber_{0};
        int clientsQueueTime_{0}, actualClientTime_{0};
        double salary_, totalGain_{0.0};
        std::string ID_;
        structures::LinkedQueue<Client> *clientsQueue_;
};

#endif
