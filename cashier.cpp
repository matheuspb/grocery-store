#include "cashier.hpp"

Cashier::Cashier(int cashierEfficiency, int salary, std::string ID):
    cashierEfficiency_{cashierEfficiency},
    salary_{salary},
    ID_{ID}
{
}

std::size_t Cashier::clientsQueueSize() const
{
    return clientsQueue_.size();
}

void Cashier::insertClient(Client& newClient)
{
    clientsQueueTime_ += newClient.purchaseTime(cashierEfficiency_);
    clientsQueue_.enqueue(newClient);
    ++totalClientsNumber_;
}

void Cashier::removeFirstClient()
{
    auto oldClient = clientsQueue_.dequeue();
    totalQueueTime_ += oldClient.purchaseTime(cashierEfficiency_);
    totalGain_ += oldClient.totalPurchaseValue();
}

void Cashier::update()
{
    if (clientsQueueSize() != 0) {
        clientsQueueTime_--;
        if (clientsQueue_.front().purchaseTime(cashierEfficiency_) ==
                actualClientTime_) {
            removeFirstClient();
            actualClientTime_ = 1;
        } else {
            actualClientTime_++;
        }
    }
}

int Cashier::averageGain() const
{
    return totalGain_/totalClientsNumber_;
}

int Cashier::totalGain() const
{
    return totalGain_;
}

int Cashier::cashierEfficiency() const
{
    return cashierEfficiency_;
}

int Cashier::clientsQueueTime() const
{
    return clientsQueueTime_;
}

int Cashier::averageTime() const
{
    return totalQueueTime_/totalClientsNumber_;
}

std::string Cashier::name() const
{
    return ID_;
}

int Cashier::salary() const
{
    return salary_;
}

