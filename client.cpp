#include "client.hpp"

Client::Client(int arrivalTime)
{
    items_ = (std::rand()%99) + 2;
    arrivalTime_ = arrivalTime;
    totalPurchaseValue_ = allProductsCost();
    payWithMoney_ = paymentMethod();
    searchSmallestQueue_ = queueChoice();
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

double Client::allProductsCost()
{
    double value = 0.0;
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

double Client::totalPurchaseValue()
{
    return totalPurchaseValue_;
}

void Client::departureTime(int time)
{
    departureTime_ = time;
}

bool Client::payWithMoney()
{
    return payWithMoney_;
}
