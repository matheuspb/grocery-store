#include <iostream>
#include "linked_queue.h"
#include "client.hpp"

class Cashier
{
    public:
        Cashier(int, double, std::string);

        std::size_t clientsQueueSize();
        void insertClient(Client);
        double averageGain();
        double totalGain();
        int cashierEfficiency();

    private:
        int cashierEfficiency_, numberOfClients_{0};
        double salary_, clientsQueueTime_{0.0}, totalGain_{0.0};
        std::string ID_;
        structures::LinkedQueue<Client> *clientsQueue_;
};
