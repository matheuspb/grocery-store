#include "client.hpp"
#include <cstdlib> // std::rand()

Client::Client(int arrivalTime):
    payWithMoney_{std::rand() >= 0.20},
    searchSmallestQueue_{std::rand() >= 0.50},
    items_{(std::rand()%99) + 2},
    arrivalTime_{arrivalTime},
    totalPurchaseValue_{allProductsCost()}
{}

bool Client::payWithMoney() const
{
    return payWithMoney_;
}

int Client::totalPurchaseValue() const
{
    return totalPurchaseValue_;
}

bool Client::searchSmallestQueue() const
{
    return searchSmallestQueue_;
}

int Client::purchaseTime(int cashierEfficiency) const
{
    int time = 0;
    if (cashierEfficiency == 1) {
        time += items_;
        if (!payWithMoney_) time += 10;
    } else if (cashierEfficiency == 2) {
        time += items_ * 2;
        if (!payWithMoney_) time += 25;
    } else {
        time += items_ * 4;
        if (!payWithMoney_) time += 60;
    }
    return time;
}

int Client::allProductsCost() const
{
    auto value = 0;
    for (auto i = 0; i < items_; ++i) {
        value += (std::rand()%90) + 1;
    }
    return value;
}
