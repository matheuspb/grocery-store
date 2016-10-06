#include "cashier.hpp"

Cashier::Cashier(int cashierEfficiency, double salary, std::string ID)
{
    cashierEfficiency_ = cashierEfficiency;
    salary_ = salary;
    ID_ = ID;
    clientsQueue_ = new structures::LinkedQueue<Client>();
}

std::size_t Cashier::clientsQueueSize()
{
    return clientsQueue_->size();
}

void Cashier::insertClient(Client newClient)
{
    clientsQueueTime_ = newClient.departureTime();
    totalGain_ += newClient.totalPurchaseValue();
    clientsQueue_->enqueue(newClient);
    numberOfClients_++;
}

double Cashier::averageGain()
{
    return totalGain_/numberOfClients_;
}

double Cashier::totalGain()
{
    return totalGain_;
}

int Cashier::cashierEfficiency()
{
    return cashierEfficiency_;
}
