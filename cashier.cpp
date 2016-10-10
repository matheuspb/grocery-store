#include "cashier.hpp"

Cashier::Cashier() {
    clientsQueue_ = new structures::LinkedQueue<Client>();
}

Cashier::Cashier(int cashierEfficiency, int salary, std::string ID)
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

void Cashier::insertClient(Client* newClient)
{
    clientsQueueTime_ += newClient->purchaseTime(cashierEfficiency_);
    clientsQueue_->enqueue(*newClient);
    totalClientsNumber_++;
}

void Cashier::removeFirstClient()
{
    auto oldClient = clientsQueue_->dequeue();
    totalQueueTime_ += oldClient.purchaseTime(cashierEfficiency_);
    totalGain_ += oldClient.totalPurchaseValue();
}

void Cashier::update()
{
    if (clientsQueueSize() != 0) {
        clientsQueueTime_--;
        if (clientsQueue_->front().purchaseTime(cashierEfficiency_) ==
                actualClientTime_) {
            removeFirstClient();
            actualClientTime_ = 1;
        } else {
            actualClientTime_++;
        }
    }
}

int Cashier::averageGain()
{
    return totalGain_/totalClientsNumber_;
}

int Cashier::totalGain()
{
    return totalGain_;
}

int Cashier::cashierEfficiency()
{
    return cashierEfficiency_;
}

int Cashier::clientsQueueTime()
{
    return clientsQueueTime_;
}

int Cashier::averageTime()
{
    return totalQueueTime_/totalClientsNumber_;
}
