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
    clientsQueueTime_ += newClient.purchaseTime(cashierEfficiency_);
    totalGain_ += newClient.totalPurchaseValue();
    clientsQueue_->enqueue(newClient);
    totalClientsNumber_++;
}

void Cashier::removeFirstClient()
{
    clientsQueue_->dequeue();
}

void Cashier::update()
{
    clientsQueueTime_--;
    if (clientsQueue_->front().purchaseTime(cashierEfficiency) == actualClientTime_) {
        removeFirstClient();
        actualClientTime_ = 0;
    } else {
        actualClientTime_++;
    }
}

double Cashier::averageGain()
{
    return totalGain_/totalClientsNumber_;
}

double Cashier::totalGain()
{
    return totalGain_;
}

int Cashier::cashierEfficiency()
{
    return cashierEfficiency_;
}

int Cashier::actualClientsNumber()
{
    return actualClientsNumber_;
}

int Cashier::clientsQueueTime()
{
    return clientsQueueTime_;
}
