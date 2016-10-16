#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <iostream>

class Client {
public:
    Client() = default;
    Client(int);


    //! Returns the queue choice criterion.
    /*!
     *  Returns 'true' if the client choose the queue by the number of people in,
     *and 'false' if the client choose the queue by the items number.
     */
    bool searchSmallestQueue();
    bool payWithMoney();
    int purchaseTime(int);
    int totalPurchaseValue();

private:
    //! Returns the 'paymant method' to a client.
    /*!
     *  Just return 'true' if the client will pay with money and 'false'if he will
     *pay with check, with a percentage of 80 to pay with money.
     */
    bool paymentMethod();
    bool genQueueChoice();
    int allProductsCost();

    bool payWithMoney_;
    bool searchSmallestQueue_;
    int items_;
    int arrivalTime_{0};
    int totalPurchaseValue_;
};

#endif

