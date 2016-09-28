#include <iostream>
#include "client.hpp"

Client::Client(double arrivalTime, double clientsQueueTime, int cashierEfficiency)
{
    departureTime_ = clientsQueueTime + purchaseTime(cashierEfficiency);
    arrivalTime_ = arrivalTime;
    totalItemsValue_ = totalItemsValue();
    payWithMoney_ = paymentMethod();
    searchSmallestQueue_ = queueChoice();
    items_ = (rand()*99) + 2;
}

//! Returns the 'paymant method' to a client.
/*!
 *  Just return 'true' if the client will pay with money and 'false'if he will
 *pay with check, with a percentage of 80 to pay with money.
 */
bool Client::paymentMethod()
{
    if (std::rand() < 0.20) return false;
    return true;
}

//! Returns the queue choice criterion.
/*!
 *  Returns 'true' if the client choose the queue by the number of people in,
 *and 'false' if the client choose the queue by the items number.
 */
bool Client::queueChoice()
{
    if (std::rand() < 0.50) return false;
    return true;
}

double Client::totalItemsValue()
{
    double value = 0.0;
    for (auto i = 0; i < items_; ++i) {
        value += (rand()*90) + 1;
    }
    return value;
}

double Client::purchaseTime(int cashierEfficiency)
{
    double time = 0.0;
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
