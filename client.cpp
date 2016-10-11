#include "client.hpp"

Client::Client(int arrivalTime):
    payWithMoney_{paymentMethod()},
    searchSmallestQueue_{queueChoice()},
    items_{(std::rand()%99) + 2},
    arrivalTime_{arrivalTime},
    totalPurchaseValue_{allProductsCost()}
{
}

bool Client::paymentMethod()
{
    if (std::rand() < 0.20) return false;
    return true;
}

bool Client::queueChoice()
{
    if (std::rand() < 0.50) return false;
    return true;
}

bool Client::payWithMoney()
{
    return payWithMoney_;
}

int Client::allProductsCost()
{
    auto value = 0;
    for (auto i = 0; i < items_; ++i) {
        value += (std::rand()%90) + 1;
    }
    return value;
}

int Client::purchaseTime(int cashierEfficiency)
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

int Client::totalPurchaseValue()
{
    return totalPurchaseValue_;
}
