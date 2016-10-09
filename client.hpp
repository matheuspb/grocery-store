#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <iostream>

class Client
{
    public:
        Client(int);

        //! Returns the 'paymant method' to a client.
        /*!
         *  Just return 'true' if the client will pay with money and 'false'if he will
         *pay with check, with a percentage of 80 to pay with money.
         */
        bool paymentMethod();

        //! Returns the queue choice criterion.
        /*!
         *  Returns 'true' if the client choose the queue by the number of people in,
         *and 'false' if the client choose the queue by the items number.
         */
        bool queueChoice();
        bool payWithMoney();
        int purchaseTime(int);
        int totalPurchaseValue();

    private:
        int allProductsCost();
        bool payWithMoney_, searchSmallestQueue_;
        int items_, arrivalTime_, totalPurchaseValue_;
};
#endif
